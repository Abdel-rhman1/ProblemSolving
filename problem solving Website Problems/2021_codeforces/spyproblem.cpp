#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n=0,n2=0;
    cin>>n;
    vector<int>res(n);
    int number = 0;
    while(n--){
        cin>>n2;
        vector<int>element(n2);
        int arr[4];
        int firselement =0;
        cin>>firselement;
        arr[0] = firselement;
        element[0] = firselement;
        arr[1] = 1;
        arr[3] = 0;
        for(int i=1;i<n2;i++){
            cin>>element[i];
             if(element[i] == arr[0]){
                arr[1]++;
            }else{
                arr[2] = element[i];
                arr[3]++;
            }
        }
        int findele = 0;
        if(arr[1] > arr[3]){
            findele = arr[2];
        }else{
            findele = arr[0];
        }
        for(int i=0;i<element.size();i++){
            if(element[i] == findele){
                res[number++] = i+1;
                break;
            }
        }
    }
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;

return 0;
}



