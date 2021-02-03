#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int num,sum=0,x=0;
	cin>>num;
	for(int i=0;i<num;i++){		
		cin>>x;
		sum+=x;
	}
	cout<< ceil(sum/4.0)<<endl;
	return 0;
}
