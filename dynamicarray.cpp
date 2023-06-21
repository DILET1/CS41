#include <bits/stdc++.h>
using namespace std;
int main(){
	int size = 0;
	cout<<"Array size?";
	cin >> size;
	int* arr;
	int used = 0;
	arr = new int[size];
	for(int i = 0; i < size; i++){
		int in;
		cout<<"Enter a number to add to the array, or -1 to quit.";
		cin >> in;
		if(in == -1){
			cout<<"Finished adding numbers \n";
			break;
		}
		else{
			used++;
		arr[i] = in;
			cout<<"Added "<<in<<'\n';
			if(i == size-1){
				cout<<"Array filled\n";
			}	
		}
	}
	for(int i = 0; i < used; i++){
		cout<<arr[i]<<'\n';
	}
	delete(arr);
}
