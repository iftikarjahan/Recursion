#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf){
    /*
    Its kind of a good question because in this question, we need to put some conditions on the recursive calls 
    */ 

    /*
    Here we need to do two recursive calls
    ->In the first recursive call, we need to seperate the first character of the string and give the remaining work to 
    recursion
    ->In the second call, we need to extract the first two characters of the string and then also put a check if the
    combined two characters have an ascii value less than equal to 26
    */ 

    /*
    Now the extraction of two characters and combining them is also a good task that we need to take into consideration
    */ 

    /*
    We would also have an edge case where if the string starts with 0, we should do nothing and return;
    */ 

    char ch=str[0];
    //Edge Case
    if(ch=='0'){
        return;
    }

    //BaseCase
    if(str.length()==0){
        cout<<asf<<endl;
        return;
    }

    //FirstCall
    //Converting the 0th character into corresponding code
    int num=ch-'0';
    char code=char(num+'a'-1);
    printEncoding(str.substr(1),asf+code);



    //Second Call
    //Combining the 0th and the 1st character
    //In the second call, we would be using 2 characters. So the string length should be greater than 1
    if(str.length()>1){
        int num2=str[1]-'0';
        int numf=num*10+num2;
        if(numf<=26){
        char code2=char(numf+'a'-1);
        printEncoding(str.substr(2),asf+code2);
        }
    }
    


    
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}