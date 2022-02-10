#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {

    //BaseCase
    if(sr==dr && sc==dc){
        vector<string>bcase;
        bcase.push_back("");
        return bcase;
    }

    /*
    We can make dr-sr jumps in horizontal direction and dc-sc jumps in 
    vertical direction and dr-sr or dc-sc jumps in the diagonal direction.
    Lokk, here we dont need to check whether we are moving out
    of the maze or not because we are alredy mentioning the number of jumps
    in the looping condintion
    */


    /*
    Highlighting an important concept that when we declare any array or
    vector inside a loop, the scope of it remains only till that iteration.

    So, in the next iteration of the loop, new array is formed and the previous 
    contents are deleted.

    So in order to retain the previous contents, we need to declare a vector
    outside the loop and save the contents in that vector in each iteration
    
    For that we are declaring a vector outside the loop so that we can save the 
    contents of hpath in every iteration
    */ 

    vector<string>path;

    //Horizontal Jumps
    //js->jump size
    //Here, during horizontal moves, the colums are changing
    

    //Horizontal Moves
    for(int js=1;js<=dc-sc;js++){
        vector<string>hpath=get_maze_paths(sr,sc+js,dr,dc);

        for(int i=0;i<hpath.size();i++){
            path.push_back("h"+to_string(js)+hpath[i]);
        }
    }

    //Vertical Moves
    //During vertical moves, rows are changing
    for(int js=1;js<=dr-sr;js++){
        vector<string>vpath=get_maze_paths(sr+js,sc,dr,dc);

        for(int i=0;i<vpath.size();i++){
            path.push_back("v"+to_string(js)+vpath[i]);
        }
    }

    //Diagonal Moves
    //During diagonal moves, rows and columns-both are changing
    /*
    During diagonal moves, we can make dc-sc moves or dr-sr moves
    So checking both the condition is not necessary
    */ 
    for(int js=1;js<=dr-sr;js++){
        vector<string>dpath=get_maze_paths(sr+js,sc+js,dr,dc);

        for(int i=0;i<dpath.size();i++){
            path.push_back("d"+to_string(js)+dpath[i]);
        }
    }

    return path;

    

    }

    

    
void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = get_maze_paths(0,0,n-1,m-1);
    display(ans);

    return 0;
}