#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    /*
    After line no 39 goes on executing, we finally rech the base case
    when sr and sc equals to dr and dc
    In that case, we need to declare an empty vector of string and that
    empty vector would be received by the hpath and vpath depending on
    the conditions
    */

    //Base case
    if(sr==dr && sc==dc){
        vector<string>bans;
        bans.push_back("");
        return bans;
    }


    /*We have a faith that reciursion would return the vector of strings
    after taking a horizontal path or a vertical path

    After taking some number of horizontal or vertical steps, we wont be able
    to move further horizontal or vertical.
    So we need to put this condition check
    */ 
    vector<string> hpath;
    vector<string> vpath;

    //Horizontal move->column increases
    if(sc<dc){
        hpath=getMazePaths(sr,sc+1,dr,dc);
    }

    //Vertical move->row increases
    if(sr<dr){
        vpath=getMazePaths(sr+1,sc,dr,dc);

    }

    

    /*
    Finally we got the string that is the paths after taking one 
    horizontal or vertical path.So now, we just need to put h in front 
    of individual elements of hpath and v in individual elements of
    vpath
    So we will be putting these answers on a new vector of strings
    names ans;
    */ 

    vector<string>ans;

    for(int i=0;i<hpath.size();i++){
        ans.push_back("h"+hpath[i]);
    }

    for(int i=0;i<vpath.size();i++){
        ans.push_back("v"+vpath[i]);
    }

    return ans;
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
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}