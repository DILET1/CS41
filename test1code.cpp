#include <bits/stdc++.h>
using namespace std;

int FindLast(int numbers[], int size, int key, int occurence) { //function should be renamed
    int seen = 0;
    for(int i = 0; i < size; i++){
       if(numbers[i] == key){
            seen++;
       }
       if(seen == occurence){
            return i;
       }
  	}
  	return -1;
}
int main(){
	int* arr = new int[5];
	arr[0] = 1;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 1;
	cout<<FindLast(arr, 5, 1, 3);
	
}
