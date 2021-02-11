#include<bits/stdc++.h>
using namespace std;
bool checkMinHeap(int array[],int n,int i){
	if(2*i+2 > n)
		return true;
	bool left=(array[i]<=array[2*i+1]) && checkMinHeap(array,n,i*2+1);
	bool right=( (2*i+2==n) || (array[i]<=array[2*i+2])) && checkMinHeap(array,n,i*2+2);
	return left&&right;
}
int main(){
	int Array[5]={1,2,3,4,5};
	cout<<checkMinHeap(Array,5,0)<<endl;
	return 0;
}
