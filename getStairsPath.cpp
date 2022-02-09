#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> get_stair_paths(int n){

    /*
    Now after doing the recursive calls, a state comes when n=0, i.e we 
    dont have any steps to move. So in that case we return a string with
    no elemnts.
    
    When n gets negative in certain calls, we return an empty string
    */ 

    if(n==0){
        vector<string>bcase;
        bcase.push_back("");
        return bcase;
    }
    else if(n<0){
        vector<string>bcase;
        return bcase;
    }

    /*
    We take one, two or three step and give the rest of the work 
    to recursion.
    Once you get the string from recursion result, you simply need
    to put 1,2 and 3 respectively before the recursive results

    So in line no 31, I concatenated 1 before each elemnts of the 
    vector step1.
    Simlarly I did it for 2 and 3 steps in the remaining loops

    Here step1, step2 and step3 receives answer in the form of
    vector of strings. It is the recursion result.
    */ 
    vector<string>step1=get_stair_paths(n-1);
    vector<string>step2=get_stair_paths(n-2);
    vector<string>step3=get_stair_paths(n-3);

    vector<string>ans;
    for(int i=0;i<step1.size();i++){
        ans.push_back(to_string(1)+step1[i]);
    }
    for(int i=0;i<step2.size();i++){
        ans.push_back(to_string(2)+step2[i]);
    }
    for(int i=0;i<step3.size();i++){
        ans.push_back(to_string(3)+step3[i]);
    }

    return ans;
    

    //Write your code here
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = get_stair_paths(n);
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