#include <bits/stdc++.h>
using namespace std;
int numOfPy(int cards){
	int nextstep=2;
	while(cards >= nextstep){
		int tmp=nextstep;
		nextstep+=3;
		cards-=tmp;
	}
	return cards;
}
int compute(int cards){
	int num=0;
	while(cards>=2){
		int remain=numOfPy(cards);
		cards=remain;
		num+=1;
	}
	return num;
}
int main(){
	int text,input;
	cin>>text;
	vector<int>ve;
	while(text--){
		cin>>input;
		ve.push_back(compute(input));
	}
	for(int i=0;i<ve.size();i++)
		cout<<ve[i]<<endl;
	return 0;
}
