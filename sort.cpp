#include <bits/stdc++.h>
using namespace std;
void asort(int arr[], int size){
	for(int i = 0; i < size; i++){
		for(int j = i; j < size; j++){
			if(i != j && arr[i] > arr[j]){
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}
int main(){
	int myArray[] = {1, 5, 4, 2, 9, 7};
	asort(myArray, 6);
	for(int i = 0; i < 6; i++){
		cout<<myArray[i]<<'\n';
	}
}
