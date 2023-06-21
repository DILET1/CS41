#include <bits/stdc++.h>
using namespace std;
struct node{
	int value;
	node* next;
};
class lbq{
	private:
		int count = 0;
		node* first = NULL;
		node* last = NULL;
	public:
		void enqueue(int query){
			if(count == 0){
				count++;
				node n;
				n.value = query;
				last = &n;
				first = last;
			}
			else{
				count++;
				node n;
				n.value = query;
				(*last).next = &n;
				last = &n;	
			}
		}
		int dequeue(){
			if(count == 0){
				throw "queue is empty";
			}
			count--;
			int rv = first->value;
			first = first->next;
			return rv;
		}
		bool isEmpty(){
			if(count == 0){
				return true;
			}
			return false;
		}
};
int main(){
	lbq q;
	try{
		q.enqueue(1);
		q.enqueue(2);
		cout<<q.dequeue()<<'\n';
		cout<<q.dequeue()<<'\n';
		cout<<q.isEmpty()<<'\n';
		q.dequeue();
	}
	catch(const char* err){
		cout<<err<<'\n';
	}
	
}
