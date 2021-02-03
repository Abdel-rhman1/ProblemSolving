#include<bits/stdc++.h>
using namespace std;
int greter(vector<int>v, int elem,int index){
	for(int i=index+1;i<v.size();i++){
		if(v[i] > elem) return v[i];
		else continue;
	}
	return -1;
}
void greaterthan(vector<int>v){
	for(int i=0;i<v.size();i++){
		cout<<greter(v,v[i],i)<<" ";
	}
}
int main(){
//	int test=0;
//	cin>>test;
//	while(test--){
		int elements,element;
		cin>>elements;
		vector<int>v(elements);
		for(int i=0;i<elements;i++){
			cin>>element;
			v.push_back(element);
		}
		greaterthan(v);
//	}
	return 0;
}
