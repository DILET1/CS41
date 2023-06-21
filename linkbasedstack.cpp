#include <bits/stdc++.h>
using namespace std;
struct node{
	int value;
	node* next;
};
class lbs{
	private:
		int count = 0;
		node* top = NULL;
	public:
		void push(int query){
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
		int pop(){
			if(isEmpty()){
				return -2147483648;
			}
			int tr = top->value;
			node* temp;
			temp = top;
			top = temp->next;
			delete temp;
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
	lbs s;
	try{
		s.push(4);
		s.push(2);
		cout<<s.pop()<<'\n';
		cout<<s.pop()<<'\n';
	}
	catch(const char* err){
		cout<<err<<'\n';
	}
	
}
