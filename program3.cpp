#include <bits/stdc++.h>
using namespace std;
bool cmp1(string a, string b){ //string compare function. Goes through each individual char of each string and compares them. If the strings are equal until one ends, the shorter one is sorted first. 
	int cc = 0;
	while(cc < a.length() && cc < b.length()){
		if(a[cc] < b[cc]){
			return true;
		}
		else if(b[cc] < a[cc]){
			return false;
		}
		else{
			cc++;
		}
	}
	if(a.length() < b.length()){
		return true;
	}
	return false;
}
struct BSTNode{
	string name;
	int weight;
	BSTNode* left = NULL;
	BSTNode* right = NULL;
};
class BST{
	private:
		BSTNode* root = NULL;
	public:
		BSTNode* add(string name, int weight){
			BSTNode* nnode = new BSTNode;
			nnode->name = name;
			nnode->weight = weight;
			if(root == NULL){
				root = nnode;
			}
			else{
				BSTNode* cur = root;
				while(true){ //no need to worry about forever loops, it has to stop at the latest at the end of the tree
					if(cmp1(cur->name, name)){ //goes to the right of the cur node
						if(cur->right == NULL){ //if the right is empty
							cur->right = nnode;
							break;
						}
						else{ //we set the right node as our new cur
							cur = cur->right;
						}
					}
					else{ //same deal here, but with the left
						if(cur->left == NULL){
							cur->left = nnode;
							break;
						}
						else{
							cur = cur->left;
						}
					}
				}
			}
			return nnode;
		}
		//all the traversals, it's just where you call the function and where to print
		void preorder(BSTNode* node){
			if(node == NULL){
				return;
			}
			cout<<node->name<<" ";	
			preorder(node->left);
			preorder(node->right);
		}
		void inorder(BSTNode* node){
			if(node == NULL){
				return;
			}
			inorder(node->left);			
			cout<<node->name<<" ";
			inorder(node->right);			

		}
		void postorder(BSTNode* node){
			if(node == NULL){
				return;
			}
			postorder(node->left);
			postorder(node->right);			
			cout<<node->name<<" ";
		}
		
		
		int height(BSTNode *node, int ch){
			if(node == NULL){
				return 0;
			}
			int tr = ch;
			//each highest value gets fed up the tree recursively
			tr = max(tr, height(node->left,ch+1)); //it's ch+1 and not tr so the values don't change
			tr = max(tr, height(node->right,ch+1));
			return tr;
		}
		int leaves(BSTNode *node, int cl){
			//just a DFS through the tree, seeing which nodes have no children
			if(node == NULL){
				return 0;
			}
			int tr = cl;
			tr += leaves(node->left,0);
			tr += leaves(node->right,0);
			if(node->left == NULL && node -> right == NULL){
				tr++;
			}
			return tr;
		}
		int findWeight(string name, BSTNode *n, int weight){
			//DFS once more, and if we find the value, we return it to the previous recursive call, which then hands it over, etc. Value travels up the tree once found, otherwise it's -1.
			int tr = weight;
			if(n == NULL){
				return -1;
			}
			int cf = -1;
			if(n->name == name){
				tr = n->weight;
			}
			else{
				
				if(cmp1(name, n->name)){
					cf = findWeight(name, n->left, weight);
				}
				else{
					cf = findWeight(name,n->right, weight);
				}
				if(cf!=-1){
					tr = cf;
				}
			}
			return tr;
		}
		int findLowest(BSTNode *n, int cl){
			//another DFS, this time we find the min weight and pass it on up.
			int tr = cl;
			tr = min(cl, n->weight);
			if(n->left!=NULL){
				tr = min(tr, findLowest(n->left, tr));
			}
			if(n->right!=NULL){
				tr = min(tr, findLowest(n->right, tr));
			}
			return tr;
		}
		void findAlphabeticalFirst(BSTNode *cur){
			//it's a BST, how convenient. Just go left until you can't.
			if(cur->left == NULL){
				cout<<cur->name<<" "<<cur->weight<<'\n';
			}
			else{
				findAlphabeticalFirst(cur->left);
			}
		}
};
int main(){
	BST alpha;
	string name; int weight;
	int n;
	cout<<"Instances to add: ";
	cin >> n;
	cin >> name;
	cin >> weight;
	BSTNode* r = new BSTNode;
	r = alpha.add(name,weight);

	for(int i = 0; i < n-1; i++){
		string tn;
		int tw;
		cin >> tn;
		cin >> tw;
		alpha.add(tn, tw);
	}
	alpha.preorder(r);
	cout<<'\n';
	alpha.inorder(r);
	cout<<'\n';
	alpha.postorder(r);
	cout<<'\n';
	cout<<alpha.height(r,1)<<'\n';
	cout<<alpha.leaves(r,0)<<'\n';
	cout<<alpha.findWeight("Clovis",r,-1)<<'\n';
	cout<<alpha.findWeight("Bessie",r,-1)<<'\n';
	cout<<alpha.findLowest(r,1000000)<<'\n';
	alpha.findAlphabeticalFirst(r);	
}
/**
Results are as follows:
Instances to add: 8
Clovis
28
Rasputin
15
Malahaiyati
4
Charlemagne
6
Dilet
1
Charlie
14
Anastasia
8
Ericc
5
Clovis Charlemagne Anastasia Charlie Rasputin Malahaiyati Dilet Ericc
Anastasia Charlemagne Charlie Clovis Dilet Ericc Malahaiyati Rasputin
Anastasia Charlie Charlemagne Ericc Dilet Malahaiyati Rasputin Clovis
5
3
28
-1
1
Anastasia 8
**/
