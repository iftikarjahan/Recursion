#include<iostream>
using namespace std;


    void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        /*
        Here we do not need the checks whether we are going out of the maze or not, because the condition 
        comes inside the for loop
        */
       
        //Base Case
        if(sr==dr && sc==dc){
           
            cout<<psf<<endl;
            return;
        }
        //Horizontal Jumps
        //During horizontal jumps, only the column changes
        //here js denotes jumpSize
        for(int js=1;js<=dc-sc;js++){

            printMazePaths(sr,sc+js,dr,dc,psf+"h"+to_string(js));
        }

        //Vertical Jumps
        //During vertical jumps, only the row changes
        //here js denotes jumpSize
        for(int js=1;js<=dr-sr;js++){
            printMazePaths(sr+js,sc,dr,dc,psf+"v"+to_string(js));
        }

        //Diagonal Jumps
        //During diagonal jumps, both the row and column changes
        //here js denotes jumpSize
        for(int js=1; js<=dc-sc && js<=dr-sr ;js++){
            printMazePaths(sr+js,sc+js,dr,dc,psf+"d"+to_string(js));
        }

        
    }

int main() {
        int n ;
        int m ;
        cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }