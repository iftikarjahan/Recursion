#include <iostream>
using namespace std;

void printSS(string ques, string ans){

    /*Here our work is only done when the base case hits*/
    /*Undrestanding it by dry running is really really important*/  

    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }
    
    /*
    We need to understand a very imporatant concept.When we are storing the results in a 
    seperate vector, a huge huge amount of space is required. If the input has 31 characters,
    we would need 31gb of ram which is litreally not possible because as the no of characters
    increase in input, the memory requirement increases exponentially.

    So instead of storing the results in a seperate vector, we can to simply print the outputs.
    In this case we require far far less memory. 
    */ 

    /*
    Now another important concept to be hilighted is if we are given two items to choose,
    the no of ways we can choose any item essentially depends upon the fact that whether we are 
    taking one item or not.
    Visualise this problem as if its an offer given to you where you need to choose choclates out of
    two given choclates.
    */ 

    /*
    So in this problem, we need to make two calls
    ->First call would be the case when we are taking a certain character
    ->Second call would be the case when we are not taking the character
    And eventually other decisions would be taken by the recursive calls
    */ 

    //Firstly, we need to seperate the string


    string p2=ques.substr(1);

    printSS(p2,ans+ques[0]);
    printSS(p2,ans);
    //Now take decisions with the recursive calls

    
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}