class Solution {
public:
    void fill(vector<vector<int>>& image,int sr,int sc,int& newcolor,int& orgcolor){
        int n = image.size();
        int m = image[0].size();
        if(sr<0 || sc<0 || sc>=m || sr>=n || image[sr][sc]!=orgcolor || image[sr][sc]==newcolor){
            return ;
        }
        image[sr][sc]=newcolor;
        fill(image,sr-1,sc,newcolor,orgcolor);
        fill(image,sr+1,sc,newcolor,orgcolor);
        fill(image,sr,sc-1,newcolor,orgcolor);
        fill(image,sr,sc+1,newcolor,orgcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgcolor = image[sr][sc];
        fill(image,sr,sc,color,orgcolor);
        return image ;
    }
}; //flood fill problem