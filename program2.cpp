#include <bits/stdc++.h>
using namespace std;
bool compstr(string s1, string s2){
	int pointer = 0;
	//comparing each char in the name
	while(pointer < s1.size() && pointer < s2.size()){
		if(s1[pointer] < s2[pointer]){
			return true;
		}
		else if(s2[pointer] < s1[pointer]){
			return false;
		}
		else{
			pointer++;
		}
	}
	//true if s1 < s2, false if s1 > s2
	if(s1.size() > s2.size()){
		return false;
	}
	else{
		return true;
	}

}
struct Node {
    string name;
    int weight;
	Node* nprev = NULL; //two sets of two pointers, 2 for each list
	Node* nnext = NULL;
	Node* wprev = NULL;
	Node* wnext = NULL;
};
class SortedLL{
	private:
		Node* nHead = new Node;
		Node* wHead = new Node;
		int count = 0;
	public:
		void addByName(Node* n){
			if(compstr(nHead->name,n->name) == false){ //seeing if we need to replace the head
				nHead->nprev = n;
				n->nnext = nHead;
				nHead = n;
				return;
			}
			Node* cp = nHead;
			while(cp->nnext!=NULL){ //inserting the node in the middle of the list
				if(compstr(cp->name,n->name) == false){
//					if(n->name == "Steve"){
//						cout<<"Hello"<<" "<<cp->name<<'\n';
//					}
//					cout<<cp->prev->name<<'\n';
					n->nprev = cp->nprev;
					cp->nprev->nnext = n; //forgot to update this pointer
//					cout<<n->prev->name<<'\n';
					n->nnext = cp;
					cp->nprev = n;
//					cout<<n->prev->next->name<<" "<<n->next->prev->name<<'\n';
					return;
				}
				else{
					if(cp->nnext!=NULL){
						cp = cp->nnext; //this is so when we run out the loop, we won't point to a bad address
					}
					else{
						break;
					}
				}
			}
			//if we've reached the end without inserting
			cp->nnext = n;
			n->nprev = cp;
			return;
		}
		void addByWeight(Node* n){ //same as above, but with different pointer names and sorting
		    if(wHead->weight > n->weight){
		        n->wnext = wHead;
		        wHead->wprev = n;
		        wHead = n;
		        return;
		    }
		    Node* rp = wHead;
		    while(rp->wnext!=NULL){
		        if(rp->weight > n->weight){
		            n->wprev = rp->wprev;
		            rp->wprev->wnext = n;
		            n->wnext = rp;
		            rp->wprev = n;
		            return;
		        }
		        else{
		            if(rp->wnext!=NULL){
		                rp = rp->wnext;
		            }
		            else{
		                break;
		            }
		        }
		    }
		    rp->wnext = n;
		    n->wprev = rp;
		    return;
		}
		void add(string name, int weight){
			Node* temp = new Node;
			temp->name = name;
			temp->weight = weight;
			if(count == 0){
				nHead = temp;
				wHead = temp;
				count++;
				return;
			}
			else{
				//adding to the by name list
				addByName(temp);
				//addint to the by weight list
				addByWeight(temp);
				count++;
			}
		}
		void printByName(){
			Node* n = nHead;
			while(n!=NULL){ //End pointer is initialized as NULL
				cout<<n->name<<" "<<n->weight<<'\n';
				n = n->nnext;
			}	
		}
		void printByWeight(){
			Node* n = wHead;
			while(n!=NULL){
				cout<<n->name<<" "<<n->weight<<'\n';
				n = n->wnext;
			}
		}
		void print(){
			printByName();
			printByWeight();
		}
		
};

int main() {
	SortedLL sll;
	for(int i = 0; i < 15; i++){
		string name; int weight;
		cin >> name >> weight;
		sll.add(name, weight);
		sll.print();
	}
}
