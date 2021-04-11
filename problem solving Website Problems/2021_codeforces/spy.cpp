#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n=0;
    int StoF=0;
    int FtoS=0;
    cin>>n;
    string pattern;
    cin>>pattern;
    for(int i=1;i<n;i++){
        if(pattern[i-1]=='F' && pattern[i]== 'S'){
            FtoS++;
        }
        if(pattern[i-1]=='S' && pattern[i]== 'F'){
            StoF++;
        }
    }
    if(StoF > FtoS){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
return 0;
}
