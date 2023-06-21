#include <bits/stdc++.h>
using namespace std;
//node and lbs lifted from my link based stack lab, except on line 34 :|
struct node{
	double value;
	node* next;
};
class lbs{
	private:
		int count = 0;
		node* top = NULL;
	public:
		void push(double query){
			node *t = new node;
			t->value = query;
			if(isEmpty()){
				top = t;
			}
			else{
				t->next = top;
				top = t;
			}
			count++; 
		}
		double pop(){
			if(isEmpty()){
				return -2147483648;
			}
			double tr = top->value;
			node* temp;
			temp = top;
			top = temp->next;
			delete temp;
			count--; //somehow forgot this haha
			return tr;
		}
		bool isEmpty(){
			if(count == 0){
				return true;
			}
			return false;
		}
};
int main(){
	while(true){
	
		lbs* aah = new lbs;
		string expression;
		cout<<"Enter expression: ";
		getline(cin, expression);
		
		if(expression == "0"){
			return 0;
		}
		
		stringstream ss(expression);
		string cw;
		
		//the first two are to check at the end if we have a correct number of operators to operands. The third is to ensure that I don't attempt to pop when there isn't anything.
		int operands = 0;
		int operators = 0;
		int co = 0;
		
		//boolean flags for each error case
		bool divby0 = false;
		bool tmoperators = false;
		bool tmoperands = false;
		
		while(ss >> cw){
			stringstream c(cw);
			double cn;
			if(c >> cn){
				aah->push(cn);
				operands++;
				co++;
			}
			else{
				operators++;
				double n1, n2; //reversed order due to the nature of the stack
				if(co >= 2){
					n2 = aah->pop();
					n1 = aah->pop();
					co-=2;		
				}
				if(cw == "+"){
					aah->push(n1 + n2);
					co++;
				}
				if(cw == "-"){
					aah->push(n1-n2);
					co++;
				}
				if(cw == "*"){
					aah->push(n1 *  n2);
					co++;
				}
				if(cw == "/"){
					if(n2 == 0){ //checking for divby0
						divby0 = true;
						break;
					}
					else{
						aah->push(n1 / n2);	
						co++;
					}
				}
			}
		}
		//checking all the error cases
		if(operators > operands-1){
			tmoperators = true;
		}
		else if(operands > operators+1){
			tmoperands = true;
		}
		//"catching" errors
		if(divby0){
			cout<<"Division by 0 error!"<<'\n';
		}
		else if(tmoperators){
			cout<<"Too many operators!"<<'\n';
		}
		else if(tmoperands){
			cout<<"Too many operands!"<<'\n';
		}
		else{
			cout<<(aah->pop())<<'\n';	
		}
	}
}
//Program results:
/**
Enter expression: 10 15 +
25
Enter expression: 10 15 39 18 53 + + + -
-115
Enter expression: 2.5 3.5 +
6
Enter expression: 10 0 /
Division by 0 error!
Enter expression: 10 20 * /
Too many operators!
Enter expression: 12 20 30 /
Too many operands!
Enter expression: -10 -30 -
20
Enter expression: 100 10 50 25 / * - -2 /
-40
Enter expression: 0

--------------------------------
Process exited after 87.49 seconds with return value 0
Press any key to continue . . .
**/
