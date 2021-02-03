#include<bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int>vec,int L,int R,int x){
	if(R>=L){
		int mid = L + (R-1) / 2;
		if(vec[mid]==x)
			return x;
		else if(x > vec[mid])
			return BinarySearch(vec,mid+1,R,x);
		else
			return BinarySearch(vec,L,mid-1,x);
	}
	return -1;
}
int main(){
	int num,n,m;
	cin>>num;
	vector<int>out;
	while(num--){
		cin>>n>>m;
		vector<int>elements;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			elements.push_back(x);
		}
		for(int i=0;i<n;i++){
			cout<<elements[i]<<" "<<endl;
		}
		for(int i=0;i<m;i++){
			int ele ;
			cin>>ele;
			if(BinarySearch(elements,0,n,ele)!=-1)
				out.push_back(1);
			else
				out.push_back(0);
		}
	}
	for(int i=0;i<out.size();i++)
		cout<<out[i]<<endl;
	return 0;
}
