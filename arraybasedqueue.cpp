#include <bits/stdc++.h>
using namespace std;
class arraybasedqueue{
	private:
		const int maxSize = 10;
		int arr[10] = {};
		int count = 0;
		int front = 0;
		int back = 0;
	public:
		void enqueue(int query){
			if(back > 8){
				throw "Queue is full!";
			}
			else{
				count++;
				back++;
				arr[back] = query;
				return;
			}
		}
		int dequeue(){
			if(count < 1){
				throw "Queue is empty!";
			}
			else{
				int f = arr[0];
				arr[0] = arr[1];
				arr[1] = arr[2];
				arr[2] = arr[3];
				arr[3] = arr[4];
				arr[4] = arr[5];
				arr[5] = arr[6];
				arr[6] = arr[7];
				arr[7] = arr[8];
				arr[8] = arr[9];
				arr[9] = arr[10];
				arr[10] = 0;
				count--;
				return f;
			}
		}
};
int main(){
	arraybasedqueue a;
	try{
		a.enqueue(1);
		cout<<a.dequeue()<<'\n';
		cout<<a.dequeue()<<'\n';	
	}
	catch(const char* error){
		cout<<error<<'\n';
	}
	try{
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
		a.enqueue(4);
		a.enqueue(5);
		a.enqueue(6);
		a.enqueue(7);
		a.enqueue(8);
		a.enqueue(9);
		a.enqueue(10);
		a.enqueue(11);
	}
	catch(const char* e2){
		cout<<e2<<'\n';
	}
	
}
