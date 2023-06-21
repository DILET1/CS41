#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
};
class sll{
	private:
		node* start = NULL;
		node* end = NULL;
	public:
		void add(int query){
			if(start == NULL){
				node* n = new node;
				n->data = query;
				start = n;
				end = start;
				return;
			}
			else{
				node* cp = start;
				if(start == end){
					node* n = new node;
					n->data = query;
					if(query <= start->data){
						n->next = start;
						start = n;
					}
					else{
						start->next = n;
						end = n;
					}
					return;
				}
				if(query <= start->data){
					node* n = new node;
					n->data = query;
					n->next = start;
					start = n;
					return;
				}
				while(cp!=end){
//					cout<<cp->data <<" "<<(cp->next)->data<<" "<<query<<'\n';
					if(query <= (cp->next)->data){
						node* temp = (cp->next);
						node* n = new node;
						n->data = query;
						cp->next = n;
						n->next = temp;
						return;
					}
					else{
						cp = cp->next;
					}
				}
				node* n = new node;
				n->data = query;
				end->next = n;
				end = n;
				return;
			}
		}
		void print(){
			node* cp = start;
			while(cp!=end){
				cout<<cp->data<<" ";
				cp = cp->next;
			}
			cout<<cp->data<<'\n';
		}
		
};
int main(){
	sll s2;
	int i;
	while(true){
		cin >> i;
		if(i == -1){
			return 0;
		}
		else{
			s2.add(i);
			s2.print();
		}
	}
	
}
