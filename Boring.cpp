#include<bits/stdc++.h>
using namespace std;
int compute(vector<int>ve){
	int lastIndex=-1;
	int befor=0;
	int Res=0;
	for(int i=0;i<ve.size();i++){
		if(ve[i]==1){
			lastIndex=i;
			Res+=befor;
		}else{
			befor++;
		}
	}
	return Res;
}
int main(){
	int test=0;
	cin>>test;
	vector<int>ve;
	while(test--){
		int number;
		cin>>number;
		vector<int>inputs;
		for(int i=0;i<number;i++){
			int x=0;
			cin>>x;
			inputs.push_back(x);
		}
		ve.push_back(compute(inputs));
	}
	for(int i=0;i<ve.size();i++)
		cout<<ve[i]<<endl;
	return 0;
}
