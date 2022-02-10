#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Here first of all we need to have the keypad that would contain the 
//corresponding strings
vector<string>codes={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};


vector<string> getKPC(string s){

    //BaseCase
    if(s.length()==0){
        vector<string>bcase;
        bcase.push_back("");
        return bcase;
    }

    /*
    Lets take the case of 915.
    So in line 27, we take 15 in a new string and recursion brings us the result for 15
    After that we extract the first digit and find the corresponding string to the first digit
    Now, we simply need to concatenate each character of choices string with each string of the
    recursion result which is done in the the for loop
    */ 
    string sstr=s.substr(1);
    vector<string>rres=getKPC(sstr);

    int fd=s[0]-'0';
    string choices=codes[fd];
    vector<string>ans;

    for(int i=0;i<choices.length();i++){
        for(int j=0;j<rres.size();j++){
            ans.push_back(choices[i]+rres[j]);
        }
    }

    return ans;

    //Write your code here
}


int main(){
    string s;
    cin >> s;
    vector<string> ans = getKPC(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}