#include<bits/stdc++.h>
using namespace std;
// jump search 
int jumpsearch(int arr[],int n,int x){
	int step=sqrt(n);
	int prev=0;
	while(arr[step-1] < x){
		prev=step;
		step+=sqrt(n);
		if(prev >=n)
			return -1;
	}
	while(arr[prev] < x){
		prev++;
		if(prev== min(step,n)) return -1;
	}
	if(arr[prev]==x) return prev;
	return -1;
}
// Binary Search
int BinarySearch(int arr[],int l,int r,int x){
	if( r>=l ){
		int mid = l + (r - l) / 2; 
		if(arr[mid]==x) return mid;
		else if(arr[mid] < x) return BinarySearch(arr,mid+1,r,x);
		else return BinarySearch(arr,l,mid-1,x);
	}
	return -1;
}
// linaer Search
int LinearSearch(int arr[],int n,int x){
	for(int i=0;i<n;i++){
		if(arr[i]==x)
			return i;
	}
	return -1;
}
int main(){
	int arr[]={1,2,3,5,6,8,9};
	cout<<jumpsearch(arr,8,5)<<endl;
	cout<<BinarySearch(arr,0,7,9)<<endl;
	cout<<LinearSearch(arr,8,5)<<endl;
	return 0;
}
