#include <bits/stdc++.h>
using namespace std;

//struct for each node of the stack
struct lbsNode{
	
	int val;
	lbsNode* next  = nullptr;
	
};

//the stack class.
class lbs{
	
	private: 
	
		lbsNode* top = nullptr; 
	
		int returnTop(){
	
			if(top == nullptr){
	
				return -1; //error code
	
			}
	
			else{
	
				return top->val;
	
			}
	
		}
	
	public:
	
		int pop(){
			
			//checking if the stack is already empty
			if(top == nullptr){
	
				return -1;
	
			}
			
			//otherwise return the top, and set top to the the top's next pointer.	
			else{
	
				int tr = top->val;
				top = top->next;
				return tr;
	
			}
	
		}
	
		bool push(int ta){ //return false = could not push
	
			if(top == nullptr){ //if empty
	
				lbsNode* n  = new lbsNode;
				n->val = ta;
				n->next = nullptr; //to not run into issues when printing out the stack
				top = n;
	
				return true;
	
			}
	
			if(ta < top->val){ //checking the condition
	
				lbsNode* n = new lbsNode;
				n->val = ta;
				n->next = top;
				top = n;
				return true;
	
			}
	
			else{
	
				return false;
	
			}
	
		}
	
		void seestack(){
			//iterate through all nodes until we find a nullptr(which is why it was set earlier).
			lbsNode* cn = top; 
	
			while(cn!=nullptr){
	
				cout<<cn->val<<" -> ";
				cn = cn->next;
	
			}
	
			cout<<'\n';
	
		}
};
int main(){
	//initialization of our 3 stacks, pre-seeding of the alpha stack
	lbs alpha;
	lbs beta;
	lbs gamma;
	alpha.push(5);
	alpha.push(4);
	alpha.push(3);
	alpha.push(2);
	alpha.push(1);

	char in; //the choice of stack that we make to pop from

	do{

		//reporting current status
		cout<<"Current Stack States: "<<'\n';
		cout<<"ALPHA(a): ";
		alpha.seestack();
		cout<<"BETA(b): ";
		beta.seestack();
		cout<<"GAMMA(c): ";
		gamma.seestack();
		cout<<"WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.";

		cin >> in;
		bool badFirst = false; //checked if it is true after handling initial input. If true, we skip the rest of the loop.

		if(in != 'q' && in != 'Q'){ //extraneous inputs will make it through here

			//reacting to correct/expected inputs

			int pv;

			if(in == 'A' || in == 'a'){

				pv = alpha.pop();

			}

			else if(in == 'B' || in == 'b'){

				pv = beta.pop();

			}

			else if(in == 'C' || in == 'c'){

				pv = gamma.pop();

			}
			
			//all extraneous inputs will get down here
			
			else{

				cout<<"UNRECOGNIZED SYMBOL."<<'\n';
				badFirst = true;
				
			}
			
			//checking if our pop is successful.
			
			if(pv == -1){ //-1 returned as the value of lbs.pop() if it is empty.
			
				cout<<"ERROR, STACK IS EMPTY. UNABLE TO POP."<<'\n';
			
			}
			
			else if(!badFirst){ //the first choice was not quit, nor was it an extraneous input.
			
				char to;
				bool failpush = false;
				cout<<"WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?"<<'\n'<<"THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE."<<'\n';
				cin >> to;
				
				//once again handling all expected inputs
				
				if(to == 'A' || to == 'a'){
			
					if(alpha.push(pv)){ 
			
						cout<<"SUCCESSFUL PUSH TO ALPHA."<<'\n';
			
					}
			
					else{
						
						//lbs.push() returned false, therefore the action violates the rules.
						
						cout<<"COULD NOT ADD TO ALPHA."<<'\n';
						failpush = true;
					}
			
				}
			
				//same logic for beta and gamma.
				
				else if(to == 'B' || to == 'b'){
			
					if(beta.push(pv)){
			
						cout<<"SUCCESSFUL PUSH TO BETA."<<'\n';
						
					}
			
					else{
			
						cout<<"COULD NOT ADD TO BETA."<<'\n';
						failpush = true;
									
					}
			
				}
				else if(to == 'C' || to == 'c'){
		
					if(gamma.push(pv)){
			
						cout<<"SUCCESSFUL PUSH TO GAMMA."<<'\n';
		
					}
		
					else{
		
						cout<<"COULD NOT ADD TO GAMMA."<<'\n';
						failpush = true;
					
					}
		
				}
		
				//all inputs not alpha, beta, and gamma go to this else statement.
				//since we already popped the top of the first stack, we need to re-add the value, which will always go through.
				
				else{
		
					cout<<"UNRECOGNIZED SYMBOL."<<'\n';
					
					if(in == 'A' || in == 'a'){

						alpha.push(pv);

					}
		
					else if(in == 'B' || in == 'b'){
		
						beta.push(pv);
		
					}
		
					else if(in == 'C' || in == 'c'){
		
						gamma.push(pv);
		
					}
		
				}
				
				//similar situation as above, but for failure to push. Once again we re-add the top top the first node.
				
				if(failpush){
				
					if(in == 'A' || in == 'a'){

						alpha.push(pv);

					}
		
					else if(in == 'B' || in == 'b'){
		
						beta.push(pv);
		
					}
		
					else if(in == 'C' || in == 'c'){
		
						gamma.push(pv);
		
					}
				
				}
		
			}
		
		}
		
		else{ //we get here if the input is quit.
		
			return 0;
		
		}
		
	}while(in!='q' || in !='Q');
	
}
/********
SAMPLE INPUT:

Current Stack States:
ALPHA(a): 1 -> 2 -> 3 -> 4 -> 5 ->
BETA(b):
GAMMA(c):
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.b
ERROR, STACK IS EMPTY. UNABLE TO POP.
Current Stack States:
ALPHA(a): 1 -> 2 -> 3 -> 4 -> 5 ->
BETA(b):
GAMMA(c):
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.a
WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?
THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE.
b
SUCCESSFUL PUSH TO BETA.
Current Stack States:
ALPHA(a): 2 -> 3 -> 4 -> 5 ->
BETA(b): 1 ->
GAMMA(c):
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.b
WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?
THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE.
c
SUCCESSFUL PUSH TO GAMMA.
Current Stack States:
ALPHA(a): 2 -> 3 -> 4 -> 5 ->
BETA(b):
GAMMA(c): 1 ->
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.a
WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?
THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE.
b
SUCCESSFUL PUSH TO BETA.
Current Stack States:
ALPHA(a): 3 -> 4 -> 5 ->
BETA(b): 2 ->
GAMMA(c): 1 ->
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.b
WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?
THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE.
c
COULD NOT ADD TO GAMMA.
Current Stack States:
ALPHA(a): 3 -> 4 -> 5 ->
BETA(b): 2 ->
GAMMA(c): 1 ->
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.c
WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?
THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE.
b
SUCCESSFUL PUSH TO BETA.
Current Stack States:
ALPHA(a): 3 -> 4 -> 5 ->
BETA(b): 1 -> 2 ->
GAMMA(c):
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.c
ERROR, STACK IS EMPTY. UNABLE TO POP.
Current Stack States:
ALPHA(a): 3 -> 4 -> 5 ->
BETA(b): 1 -> 2 ->
GAMMA(c):
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.a
WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?
THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE.
b
COULD NOT ADD TO BETA.
Current Stack States:
ALPHA(a): 3 -> 4 -> 5 ->
BETA(b): 1 -> 2 ->
GAMMA(c):
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.b
WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?
THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE.
v
UNRECOGNIZED SYMBOL.
Current Stack States:
ALPHA(a): 3 -> 4 -> 5 ->
BETA(b): 1 -> 2 ->
GAMMA(c):
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.a
WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?
THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE.
c
SUCCESSFUL PUSH TO GAMMA.
Current Stack States:
ALPHA(a): 4 -> 5 ->
BETA(b): 1 -> 2 ->
GAMMA(c): 3 ->
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.b
WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?
THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE.
c
SUCCESSFUL PUSH TO GAMMA.
Current Stack States:
ALPHA(a): 4 -> 5 ->
BETA(b): 2 ->
GAMMA(c): 1 -> 3 ->
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.a
WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?
THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE.
b
COULD NOT ADD TO BETA.
Current Stack States:
ALPHA(a): 4 -> 5 ->
BETA(b): 2 ->
GAMMA(c): 1 -> 3 ->
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.b
WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?
THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE.
a
SUCCESSFUL PUSH TO ALPHA.
Current Stack States:
ALPHA(a): 2 -> 4 -> 5 ->
BETA(b):
GAMMA(c): 1 -> 3 ->
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.c
WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?
THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE.
b
SUCCESSFUL PUSH TO BETA.
Current Stack States:
ALPHA(a): 2 -> 4 -> 5 ->
BETA(b): 1 ->
GAMMA(c): 3 ->
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.b
WHERE WOULD YOU LIKE TO ADD THE POPPED VALUE?
THE TOP OF THE TARGET MUST BE LARGER THAN THE VALUE.
b
SUCCESSFUL PUSH TO BETA.
Current Stack States:
ALPHA(a): 2 -> 4 -> 5 ->
BETA(b): 1 ->
GAMMA(c): 3 ->
WHAT STACK WOULD YOU LIKE TO POP FROM (A/a, B/b, C/c)? q OR Q TO QUIT.q

--------------------------------
Process exited after 84.45 seconds with return value 0
Press any key to continue . . .
********/
