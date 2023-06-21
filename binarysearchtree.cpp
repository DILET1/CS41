#include <bits/stdc++.h>
using namespace std;
struct BSTNode{
	int data;
	BSTNode* left = NULL;
	BSTNode* right = NULL;
};
class BST{
	private:
		BSTNode* root = NULL;
	public:
		BSTNode* add(int data){
			BSTNode* nnode = new BSTNode;
			nnode->data = data;
			if(root == NULL){
				root = nnode;
			}
			else{
				BSTNode* cur = root;
				while(true){
					if(data >= cur->data){
						if(cur->right == NULL){
							cur->right = nnode;
							break;
						}
						else{
							cur = cur->right;
						}
					}
					else{
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
		void print(BSTNode* node){
			if(node == NULL){
				return;
			}
			print(node->left);
			cout<<node->data<<" ";
			print(node->right);
		}
};
int main(){
	BST tree;
	BSTNode* root = tree.add(1);
	tree.add(2);
	tree.add(0);
	tree.add(-1);
	tree.print(root);
	
	
}
