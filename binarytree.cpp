#include <bits/stdc++.h>
using namespace std;
class BinaryTree {
private:
    int data[1000];
    int count = 0;
public:
    void add(int value) {
        data[count] = value;
        count++;
    }
    void preorder(int node) {
        if (node >= count) {
            return;
        }
        cout << data[node] << " ";
        preorder(2*node+1);
        preorder(2*node+2);
    }
};
int main(){
	BinaryTree b;
	b.add(1);
	b.add(2);
	b.add(3);
	b.add(4);
	b.add(5);
	b.add(6);
	b.preorder(0);
}
