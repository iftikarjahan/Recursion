#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s){

    if(s.length()==0){
        vector<string>bcase;
        bcase.push_back("");
        return bcase;
    }
    /*
    This is a recursive problem in which we need to populate a vector
    of string that wound contain the subsequences.

    If we closeley observe the problem, we find that we need to simplly
    concatenate the 0th element of the given string to the smaller problem
    */ 

    //char ch=s[0];
    string smallString=s.substr(1);
    vector<string>smallAns=gss(smallString);
    
    /*
    Now, in smallAns, we have["",b,c,bc]
    We need to simply concatenate a to the individual elemnts of
    smallAns to generate["",b,c,bc,a,ab,ac,abc]
    */ 

    vector<string>ans;
    /*Copying the elements of smallAns in ans*/ 

    
    for(int i=0;i<smallAns.size();i++){
        ans.push_back(smallAns[i]);
    }
    for(int i = 0;i<smallAns.size();i++){
        ans.push_back(s[0]+smallAns[i]);
    }

    return ans;
    // write your code here
    
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << "[";
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << "]";
}