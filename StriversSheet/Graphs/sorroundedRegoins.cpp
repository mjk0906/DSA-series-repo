class Solution {
public:
    void modify(pair<int,int>src,vector<vector<char>>& board,int&m,int&n){

        int i = src.first;
        int j = src.second;

        if(i < 0 || i >= m || j < 0 || j >= n) return ;

        if(board[i][j]!='O') return ;

            board[i][j]= '#' ;

            modify({i-1,j},board,m,n);
            modify({i+1,j},board,m,n);
            modify({i,j-1},board,m,n);
            modify({i,j+1},board,m,n);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                modify({i,0},board,m,n);
            }
            if(board[i][n-1]=='O'){
                modify({i,n-1},board,m,n);
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                modify({0,i},board,m,n);
            }
            if(board[m-1][i]=='O'){
                modify({m-1,i},board,m,n);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X' ;
                }
                if(board[i][j]=='#'){
                    board[i][j]='O' ;
                }
            }
        }
    }
};