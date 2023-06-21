#include <bits/stdc++.h>
using namespace std;
class arrayBasedStack{
	private:
		const int MaxSize = 10;
		int* arr = new int[MaxSize];
		int count = 0;
	public:
		void push(int n){
			if(count == 10){
				cout<<"Sorry, unable to push, stack is full. \n";
			}
			else{
				arr[count] = n;
				count++;
			}
		}
		int pop(){
			if(count == 0){
				cout<<"Sorry, unable to pop, stack is empty. \n";
				return 0;
			}
			else{
				int tp = arr[count];
				arr[count] = 0;
				count--;
				return tp;	
			}
		}
		bool isEmpty(){
			if(count == 0){
				return true;
			}
			return false;
		}
};
//int main(){
//	arrayBasedStack s1;
//	s1.push(1);
//	s1.push(2);
//	s1.push(3);
//	s1.push(4);
//	s1.push(5);
//	s1.push(6);
//	s1.push(7);
//	s1.push(8);
//	s1.push(9);
//	s1.push(10);
//	s1.push(11);
//	s1.pop();
//	s1.pop();
//	s1.pop();
//	s1.pop();
//	s1.pop();
//	s1.pop();
//	s1.pop();
//	s1.pop();
//	s1.pop();
//	s1.pop();
//	s1.pop();
//	cout<<s1.isEmpty();
//}
