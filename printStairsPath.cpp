#include <iostream>
using namespace std;

void printStairPaths(int n, string psf){

    /*The whole purpose of the RecursionOnWayUp is to save memory allocations. So instead of
    saving the outputs in a vector of strings, we simply print the outputs
    */
    if(n==0){
        cout<<psf<<endl;
        return;
    }
    if(n<0){
        return;
    }
    for(int i=1;i<=3;i++){
        printStairPaths(n-i,psf+to_string(i));
    }
}

int main(){

    int n;
    cin >> n;
    printStairPaths(n, "");
}