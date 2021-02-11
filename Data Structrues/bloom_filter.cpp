#include<iostream>
#include<string>
#include<cmath>
#define ll long long
using namespace std;
int hashingOne(string s , int arraySize){
	ll hash = 0;
	for (int i = 0; i < s.size(); i++) {
        hash = (hash + ((s[i] - 'a')));
        hash = hash % arraySize;
    }
    return hash;
}
int hashingTwo(string s , int arraySize){
	ll hash = 1;
	for(int i=0;i<s.size();i++){
		hash = (hash + (pow(13,i)*s[i]-'a'));
		hash = hash % arraySize ;
	}
	return hash;
}
int hashingThree(string s , int arraySize){
	ll int hash = 7;
	for(int i=0;i<s.length();i++){
		hash = (hash * 31 + s[i]) % arraySize;
	}
	return hash;
}
int hashingFour(string s, int arrSize)
{
    ll int hash = 3;
    int p = 7;
    for (int i = 0; i < s.size(); i++) {
        hash += hash * 7 + s[0] * pow(p, i);
        hash = hash % arrSize;
    }
    return hash;
}
bool lookup(bool *bitsarray , string s , int arraySize){
	int h1 = hashingOne(s,arraySize);
	int h2 = hashingTwo(s,arraySize);
	int h3 = hashingThree(s,arraySize);
	int h4 = hashingFour(s,arraySize);
	if(bitsarray[h1] && bitsarray[h2] && bitsarray[h3] && bitsarray[h4]){
		return true;
	}else{
		return false;
	}
}
void insert(string s,int arraySize , bool *bitsarray){
	if(lookup(bitsarray , s , arraySize)){
		cout<<"This string may be present"<<endl;
	}else{
		int h1 = hashingOne(s,arraySize);
		int h2 = hashingTwo(s,arraySize);
		int h3 = hashingThree(s,arraySize);
		int h4 = hashingFour(s,arraySize);
		bitsarray[h1] = true;
		bitsarray[h2] = true;
		bitsarray[h3] = true;
		bitsarray[h4] = true;
	}
}
int main(){
	bool bitarray[100] = {false};
	int arrsize = 100;
	string array[33]
        = { "abound",   "abounds",       "abundance",
            "abundant", "accessable",    "bloom",
            "blossom",  "bolster",       "bonny",
            "bonus",    "bonuses",       "coherent",
            "cohesive", "colorful",      "comely",
            "comfort",  "gems",          "generosity",
            "generous", "generously",    "genial",
            "bluff",    "cheater",       "hate",
            "war",      "humanity",      "racism",
            "hurt",     "nuke",          "gloomy",
            "facebook", "geeksforgeeks", "twitter" };
    for(int i=0;i<33;i++)
    	cout<<array[i]<<endl;
    for(int i=0;i<33;i++)
    	insert(array[i] , 100,bitarray);
	return 0;
}
