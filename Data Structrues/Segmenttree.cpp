#include <iostream>
using namespace std;
int getSumHelper(int *segment, int ss, int se, int qs, int qe, int cs){
	if (qs <= ss && qe >= se)  
        return segment[cs];
        
    if (se < qs || ss > qe)  
        return 0;  
    int mid = ss + (se - ss)/2;
	return  getSumHelper(segment , ss , mid , qs, qe, (2*cs)+1)+
				getSumHelper(segment , mid+1 , se , qs, qe, (2*cs)+2);
}
int getSum(int *segment , int n , int qs , int qe ){
	if(qs < 0  || qe > n-1 || qs >qe){
		cout<<"Invalid Segment Interval"<<endl;
		return -1;
	}else{
		return getSumHelper(segment, 0, n-1, qs, qe, 0);  
	}
}
int constructSegment(int arr[] , int ss , int se , int *segment , int cs){
	if(ss == se){
		segment [cs] = arr[ss];
		return arr[ss];
	}
	int mid = ss + (se - ss)/2;
	segment[cs] = constructSegment(arr , ss , mid , segment , (2*cs)+1)+
				constructSegment(arr , mid+1 , se , segment , (2*cs)+2);
	return segment[cs];
}
int *constructST(int arr[] , int n){
	int x = 4 * n;
	int *segmant = new int[x];
	constructSegment(arr , 0 , n-1 ,segmant, 0);
	return segmant; 
}
int main(){
	int arr[] = {1, 3, 5, 7, 9, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);
    int *st = constructST(arr, n);
    cout<<"Sum of values in given range = "<<getSum(st, n, 1, 3)<<endl;
	return 0;
}
