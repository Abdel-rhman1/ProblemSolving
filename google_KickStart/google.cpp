#include<iostream>
#include<vector>
#include <string>
using namespace std;
int main(){

    int n = 0 , test =0;
    cin>>n;
    test = n;
    vector< vector<int> > res;
    while(n--){
        int n2 = 0;
        cin>>n2;
        vector<int> tempRes;
        string txt ;
        cin>>txt;
        int number = 1;
        tempRes.push_back(1);
        for(int i=0;i<txt.length()-1;i++){

            if(txt[i]- 'A' < txt[i+1] -'A'){
                number++;
                tempRes.push_back(number);
            }else{
                number = 1;
                tempRes.push_back(number);
            }
        }
        res.push_back(tempRes);

    }
    for(int i=0;i<test ;i++){
        cout<<"Case #"<<i+1<<": ";
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}
