#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    /*
    In order to solve this problem, you need to have a clear concept of how permutations are calculated
    */ 

    /*
    A problem arises how to seperate a string
    Consider the string to be abcde
    Now, if we take c, then how will we extract the remaining string?
    That can be done using the substr function
    for any ith character, the remaining string can be extracted using the method substr(0,i)+substr(i+1);
    */ 

    if(str.length()==0){
        cout<<asf<<endl;
        return;
    }
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        string lp=str.substr(0,i);
        string rp=str.substr(i+1);
        string rems=lp+rp;
        printPermutations(rems,asf+ch);
        
    }

}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}