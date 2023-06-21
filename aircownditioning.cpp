#include <bits/stdc++.h>
class BinaryNode{
	public:
		int value;
		BinaryNode* left, * right;
		BinaryNode(){
			value = 0;
			left = right = 0;
		}
};
class Bst{
	private:
		BinaryNode* root;
		int FindLeftMostLeaf(BinaryNode* sub){
			int tr = -1;
			if(sub->left != 0){
				tr = FindLeftMostLeaf(sub->left);
			}
			else if (sub->right != 0){
				tr = FindLeftMostLeaf(sub->right);
			}
			else{
				tr = sub->value;
			}
			return tr;
		}
	public:
		int FindLeftMostLeaf(){
			return FindLeftMostLeaf(root);
		}
};
int main(){
	Bst a;
	a.Traverse();
}
