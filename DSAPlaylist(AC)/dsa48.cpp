#include <iostream>
#include <vector> 
using namespace std ;

void helper(vector<vector<int>>&mat,int r,int c,vector<string>ans,vector<vector<bool>>&vis,string path){
    int n = mat.size();
    if(r<0 || c<0 || r>=n || c>=n || mat[r][c]==0 || vis[r][c]==true){
        return ;
    }

    if (r==n-1 && c==n-1){
        ans.push_back(path);
        return ;
    }

    vis[r][c]==true ;

    //down
    helper(mat,r+1,c,ans,vis,path);
    //right 
    helper(mat,r,c+1,ans,vis,path);
    //left 
    helper(mat,r,c-1,ans,vis,path);
    //up 
    helper(mat,r-1,c,ans,vis,path);

    vis[r][c]==false ;
}

vector<string> findpath(vector<vector<int<&mat>>,vector<string>&ans){
    vector<string> ans ;
    string path = "" ;
    vector<vector<int< 
    int n = mat.size() ;
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    helper(mat,0,0,ans,vis,path);
    return ans ;

    for (string val : ans ){
        cout<< val << endl ;
    }
}

//code lite lelo logic ko samjho 