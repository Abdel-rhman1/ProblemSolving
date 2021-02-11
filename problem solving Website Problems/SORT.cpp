#include <iostream>
using namespace std;
template <class Tem>
void Print(Tem array[],int n){
	for(int i=0;i<n;i++){
		cout<<"->"<<array[i]<<endl;
	}
}
template <class Tem>
void InsertionSort(Tem data[],int n){
	for(int i=1;i<n;i++){
		Tem tem=data[i];
		int j=i;
		for(j=i;j>=0  && tem <data[j];j--){
			data[j-1]=data[j];
		}
		data[j]=tem;
		cout<<tem<<endl;
	}
}
int main(){
	int array[5]={4,1,8,90,12};
	InsertionSort(array,5);
	Print(array,5);
}
