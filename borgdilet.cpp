#include <bits/stdc++.h>
const int SIZE = 107;
struct chainLLNode{ //linked list node for chaining
	int data;
	std::string vname;
	chainLLNode* next;
	chainLLNode* prev;
};
class chainLL{ //class mostly lifted from my sorted linked list assignment. Just changed variable names and also assigned the vname variable of the chainLLNode when applicable.
	private:
		chainLLNode* start = nullptr;
		chainLLNode* end = nullptr;
	public:
		bool addNode(int query, std::string v){
			if(start == NULL){ //if list is empty, set node as the head/tail
				chainLLNode* n = new chainLLNode;
				n->data = query;
				n->vname = v;
				n->prev = nullptr;
				n->next = nullptr;
				start = n;
				end = start;
				return true;
			}
			else{
				chainLLNode* cp = start;
				if(start == end){ //if there is only one node
					chainLLNode* n = new chainLLNode;
					n->data = query;
					n->vname = v;
					if(query <= start->data){
						n->next = start;
						n->prev = nullptr;
						start = n;
					}
					else{
						start->next = n;
						end = n;
					}
					return true;
				} //if it's smaller than the head (value)
				if(query <= start->data){
					chainLLNode* n = new chainLLNode;
					n->data = query;
					n->next = start;
					start = n;
					return true;
				}
				while(cp!=end){ //if it isn't, look until we find somewhere it fits
//					cout<<cp->data <<" "<<(cp->next)->data<<" "<<query<<'\n';
					if(query <= (cp->next)->data){
						chainLLNode* temp = (cp->next);
						chainLLNode* n = new chainLLNode;
						n->data = query;
						cp->next = n;
						n->next = temp;
						return true;
					}
					else{
						cp = cp->next;
					}
				} //if it's the largest value
				chainLLNode* n = new chainLLNode;
				n->data = query;
				n->vname = v;
				end->next = n;
				end = n;
				n->next = nullptr;
				return true;
			}
		}
		int retVal(std::string v){
			chainLLNode* cp = start;
			if(cp!=NULL){ //we go through the LL until we find the correct variable name, then return the data 
				do{
					if(cp->vname == v){
						return cp->data;
					}
					else if(cp->next == nullptr){
						break;
					}
					else{
						cp = cp->next;
					}
				}while(cp!=end);	
			}
			return -2;
		}
		bool modvar(std::string v, int val){
//			if(v == "LIMON"){
//				std::cout<<"Hello"<<'\n';
//			}
			chainLLNode* cp = start;
			if(cp!=NULL){ //same as above but we modify the value of the data
				chainLLNode* cp = start;
				do{
					if(cp->vname == v){
						cp->data = val;
						return true;
					}
					else if(cp->next == nullptr){
						break;
					}
					else{
						cp = cp->next;	
					}
					
				}while(cp!=end);	
			}
			
			return false;
		}
};
struct HashLL_Node{
	std::vector<chainLL> HT; //this is our chained hash table 
	HashLL_Node* prev;
	HashLL_Node* next;
	HashLL_Node() : HT(107) {};
};
class HashLL{
	public:
		void newScope(){ //this essentially creates a new node at the head of the list. Called every time we read "START"
			HashLL_Node* n = new HashLL_Node;
			if(head != NULL){
				head->prev = n;
				n->next = head;
				head = n;	
			}
			else{
				head = n;
			}
			cs++;
		}
		void endScope(){ //destroys the head node. Called when we read "FINISH"
			if(cs > 1){
				(head->next)->prev = NULL;
				head = head->next;	
			}
			else{
				head = NULL;
			}
			cs--;
		}
		bool addVar(int value, std::string name){
			int hashedv = hashf(name);
			((head->HT)[hashedv]).addNode(value, name);
		}
		void test(){
			std::cout<<((head->HT)[65]).retVal("A");
		}
		bool modVar(int val, std::string v, int flags){ //all functions pertaining to modifying the value of a function
			int start = hashf(v);
			int cl = 0;
			HashLL_Node* curs = head;
			while(cl < cs){ //this loops through all scopes
				int ci = start;
				int cv = ((curs->HT)[start]).retVal(v);
				if(cv!=-2){
					//addition is 0
					if(val == 0){
						((curs->HT)[start]).modvar(v,cv+flags);
					}
					//subtraction is 1
					else if(val == 1){
						((curs->HT)[start]).modvar(v,cv-flags);
					}
					//multiplication is 2
					else if(val == 2){
						((curs->HT)[start]).modvar(v,cv*flags);
					}
					//division is 3
					else if(val == 3){
						((curs->HT)[start]).modvar(v,cv/flags);
					}
					//modulo is 5
					else if(val == 5){
						((curs->HT)[start]).modvar(v,cv%flags);
					}
					//exponent is 6
					else if(val == 6){
						((curs->HT)[start]).modvar(v,pow(cv,flags));
					}
					//4 and the rest are assignment
					else{
						((curs->HT)[start]).modvar(v,flags);
					}
					return true;
				}
				cl++;
				curs = curs->next; //moving to the next scope
			}
			curs = NULL;
			return false; //if not found
		}
		int retVar(std::string v){ //returns the value of the variable.
			int start = hashf(v);
			int cl = 0;
			HashLL_Node* curs = head;
			while(cl < cs){ //similar as above. Loop through all scopes, and in each scope all locations.
				int cv = ((curs->HT)[start]).retVal(v);
				if(cv!=-2){
					return cv;
				}
				cl++;
				curs = curs->next;
			}
			curs = NULL;
			return -2; 
		}
	private:
		HashLL_Node* head = NULL;
		int cs = 0; //current scope count
		int hashf(std::string name){ //the hashing function itself
			int nv = 0;
			for(int i = 0; i < name.size(); i++){
				nv+=name[i];
			}
			return nv % SIZE;
		}
};
int main(){
	HashLL myHash;
//	myHash.newScope();
//	myHash.addVar(7, "A");
//	myHash.test();
	std::string fName;
	std::cout<<"NAME OF FILE? ";
	std::cin >> fName;
    std::ifstream in; in.open(fName);
    if(!in.is_open()){
    	std::cout<<"INVALID FILE SPECIFIED. TERMINATING PROGRAM."<<'\n';
    	return -1;
	}
	std::ofstream out("prg4out.txt");
	std::string line;
    while (std::getline(in, line)) {
        std::stringstream s(line);
        std::string token;
        s >> token;
        //the command doesn't start with a variable
        if(token == "COM"){
        	//ignore
        	continue;
		}
		else if(token == "START"){
			myHash.newScope();
		}
		else if(token == "FINISH"){
			myHash.endScope();
		}
        else if(token == "VAR"){
        	std::string varName;
        	s >> varName;
        	char chaff;
        	s >> chaff;
        	int value;
        	s >> value;
        	myHash.addVar(value, varName);
		}
		else if(token == "PRINT"){
			std::string varName;
			s >> varName;
			int val = myHash.retVar(varName);
			if(val == -2){
				std::cout<<varName<<" IS UNDEFINED"<<'\n';
				out<<varName<<" IS UNDEFINED"<<'\n';
			}
			else{
				char mods;
				if(s >> mods){
					int adVal;
					s >> adVal;
					if(mods == '+'){
						std::cout<<varName<<" + "<<adVal<<" IS "<<val + adVal<<'\n';
						out<<varName<<" + "<<adVal<<" IS "<<val + adVal<<'\n';
					}
					if(mods == '-'){
						std::cout<<varName<<" - "<<adVal<<" IS "<<val - adVal<<'\n';
						out<<varName<<" - "<<adVal<<" IS "<<val - adVal<<'\n';
					}
					if(mods == '*'){
						std::cout<<varName<<" * "<<adVal<<" IS "<<val * adVal<<'\n';
						out<<varName<<" * "<<adVal<<" IS "<<val * adVal<<'\n';
					}
					if(mods == '/'){
						std::cout<<varName<<" / "<<adVal<<" IS "<<val / adVal<<'\n';
						out<<varName<<" / "<<adVal<<" IS "<<val / adVal<<'\n';
					}
					if(mods == '^'){
						std::cout<<varName<<" ^ "<<adVal<<" IS "<<pow(val, adVal)<<'\n';
						out<<varName<<" ^ "<<adVal<<" IS "<<pow(val, adVal)<<'\n';
					}
					if(mods == '%'){
						std::cout<<varName<<" % "<<adVal<<" IS "<<val % adVal<<'\n';
						out<<varName<<" % "<<adVal<<" IS "<<val % adVal<<'\n';
					}
				}
				else{
					std::cout<<varName<<" IS "<<val<<'\n';
					out<<varName<<" IS "<<val<<'\n';
				}	
			}
		}
		else{
			//command starts with var
			std::string varName = token;
			std::string next;
			s >> next;
			if(next == "="){
				int num1;
                int num2;
                char op = '\0';
                if (!(s >> num1)) {
                    std::string tf;
                    s.clear();
                    s >> tf;
                    int target;
                    target = myHash.retVar(tf);
                    if (target == -2) {
                        std::cout << "THE VARIABLE " << tf << " COULD NOT BE FOUND"<<'\n';
                        out<<"THE VARIABLE " << tf << " COULD NOT BE FOUND"<<'\n';
                        continue;
                    } 
                    num1 = target;
                }

                s>> op; 

                if (op == '\0') {
                    /* The variable is the only operator */
                    myHash.modVar(7, varName, num1);
                    continue;
                }
                if (!(s >> num2)) {
                    std::string tf;
                    s.clear();
                    s >> tf;
                    int target;
                    target = myHash.retVar(tf);
                    if (target == -2) {
                        std::cout << "THE VARIABLE " << tf << " COULD NOT BE FOUND"<<'\n';
                        out<<"THE VARIABLE " << tf << " COULD NOT BE FOUND"<<'\n';
                        continue;
                    } 
                    num2 = target;
                }

                int newnum = num1;
                if (op == '*') { 
                    newnum *= num2;
                } else if (op == '+') { 
                    newnum += num2;
                } else if (op == '-') { 
                    newnum -= num2;
                } else if (op == '/') { 
                    newnum /= num2;
                } else if (op == '%') { 
                    newnum %= num2;
                } else if (op == '^') { 
                    newnum = pow(num1,num2);
                }
                myHash.modVar(7, varName, newnum);
			}
			else if(next == "++"){
				myHash.modVar(0, varName, 1);
			}
			else if(next == "--"){
				myHash.modVar(1, varName, 1);
			}
		}
    }
    in.close();
    return 0;
}
/**
Sample source program output is below. Other program output is found in prg4out.txt.
BORAMIR IS 25
LEGOLAS IS 101
GANDALF IS UNDEFINED
BORAMIR * 2 IS 52
GANDALF IS 49
BORAMIR IS 26
GANDALF IS UNDEFINED
LEGOLAS IS 1000
LEGOLAS IS 1000
LEGOLAS IS 999
**/
