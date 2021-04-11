#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int n =0,number=0;
    string st1 , st2;
    cin>>n;
    vector<int>res(n);

    while(n--){
        cin>>st1>>st2;
        int localCounter = 0;
        if(st1.length() == st2.length()){
            for(int i=0;i<st1.length();i++){
                if((st1[i] == st2[i] )|| (st1[i]-32 == st2[i] ) || (st1[i] == st2[i]-32 )){
                    localCounter++;
                }else if (((st1[i] == 'P' || st1[i] == 'p') && (st2[i] == 'B' || st2[i] == 'b') ) ||
                ((st2[i] == 'P' || st2[i] == 'p') && (st1[i] == 'B' || st1[i] == 'b'))){
                    localCounter++;
                }else if(
                    ((st1[i] == 'E' || st1[i] == 'e') && (st2[i] == 'I' || st2[i] == 'i') ) ||
                    ((st2[i] == 'E' || st2[i] == 'e') && (st1[i] == 'I' || st1[i] == 'i'))
                ){
                    localCounter++;
                }
            }
            if(localCounter == st1.length()){
                res[number++] = 1;
            }else{
                res[number++] = 0;
            }
        }else{
            res[number++] = 0;
        }
    }

    for(int i=0;i<res.size();i++){
        if(res[i]==1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
return 0;

}
