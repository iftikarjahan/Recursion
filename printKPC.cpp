#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    if(ques.length()==0){
        cout<<asf<<endl;
        return;
    }
    
    char ch=ques[0];
    string options=codes[ch-'0'];

    string remq=ques.substr(1);

    for(int i=0;i<options.length();i++){
        printKPC(remq,asf+options[i]);
    }
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}