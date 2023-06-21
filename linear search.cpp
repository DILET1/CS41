#include <bits/stdc++.h>
using namespace std;
int a[] = {4,7,2,3,8,5};
int pos(int query){
	for(int i = 0; i < 6; i++){
		if(a[i] == query){
			return i;
		}
	}
	return -1;
}
int main(){
	cout<<"Search for what number? ";
	int n;
	cin >> n;
	cout<<pos(n);
}
