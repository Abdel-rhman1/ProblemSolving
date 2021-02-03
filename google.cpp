#include<iostream>
using namespace std;
int main()
{
	int test,num,bud=0,count=0,test2,j=0,cost=0,i=0;
	cin>>test;
	test2=test;
	int *v1=new int[test];
	//vector<int>v1(test);
	while(test--)
	{
		cin>>num;
		cin>>bud;
		//vector<int>v2(num);
		int * v2=new int [num];
		for(i=0;i<num;i++)
		{
			cin>>v2[i];
		}
		sort(v2,v2+num);
		i=0;
		cost=v2[i];
		while(bud>=cost)
		{
			count++;
			cost+=v2[++i];
		}
		v1[j++]=count;
		count=0;
		delete []v2;
	}
	for(i=0;i<test2;i++)
	{
		cout<<"Case #"<<i+1<<": "<<v1[i]<<endl;
	}
	delete []v1;
}

