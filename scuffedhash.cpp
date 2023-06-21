#include <bits/stdc++.h>
using namespace std;
class scuffedHash{
	public:
		bool add(int num){
			if(ht[hash(num)] == -1){
				ht[hash(num)] = num;
				return true;
			}
			else{
				return chain(hash(num), num);
			}
		}
		int lookup(int query){
			if(ht[hash(query)]  == query){
				return hash(query);
			}
			else{
				return lookupChain(hash(query), query);
			}
		}
	private:
		int tablesize = 27;
		int ht[27] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
		int hash(int value){
			return value%tablesize;
		}
		bool chain(int hash, int val){
			int ci = hash+1;
			while(ci!=hash){
				ci%=tablesize;
				if(ht[ci] == -1){
					ht[ci] = val;
					return true;
				}
				else{
					ci++;
				}
			}
			return false;
		}
		int lookupChain(int hash, int val){
			int ci = hash+1;
			while(ci!=hash){
				ci%=tablesize;
				if(ht[ci] == val){
					return ci;
				}
				else{
					ci++;
				}
			}
			return -1;
		}
};
int main(){
	scuffedHash myScuff;
	string choice;
	while(choice != "q" || choice!="Q"){
		cout<<"Add item to table with A, or lookup with L. Q to quit."<<'\n';
		cin>>choice;
		if(choice == "A" || choice == "a"){
			cout<<"What number to add:";
			int n;
			cin >> n;
			if(myScuff.add(n)){
				cout<<"Added "<<n<<" to table."<<'\n';
			}
			else{
				cout<<"Error, table is full."<<'\n';
			}
		}
		else if(choice == "L" || choice == "l"){
			cout<<"What number to lookup:";
			int n;
			cin >> n;
			int res = myScuff.lookup(n);
			if(res == -1){
				cout<<"Query not found"<<'\n';
			}
			else{
				cout<<"Query at location "<<res<<'\n';
			}
		}
		else if(choice == "Q" || choice == "q"){
			break;
		}
	}
}
