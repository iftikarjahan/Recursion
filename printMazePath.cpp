#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf){

    //BaseCase
    if(sr==dr && sc==dc){
        cout<<psf<<endl;
        return;
    }


    //Column changes for a horizontal move
    //So we concatenate h
    if(sc<dc){
        printMazePaths(sr,sc+1,dr,dc,psf+"h");
    }

    /*
    Row increases when we make a vertical move
    So we concatenate v
    */ 
    if(sr<dr){
        printMazePaths(sr+1,sc,dr,dc,psf+"v");
    }

    /*
    See when we are printing the outputs, we are saving a lot of memory space as we are not storing the
    outputs and hence output is printed everytime we hit the base case.
    Such a beautiful way
    */ 
    // write your code here
    
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}