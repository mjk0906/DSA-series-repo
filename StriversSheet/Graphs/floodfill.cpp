class Solution {
public:
    void fill(vector<vector<int>>&image,int i,int j,int newColor,int orgColor){
        int m = image.size();
        int n = image[0].size();

        if(i>=m || j>=n || i<0 || j<0 || image[i][j]!=orgColor || image[i][j]==newColor){
            return ;
        }
        image[i][j]=newColor ;
        
        fill(image,i+1,j,newColor,orgColor);
        fill(image,i-1,j,newColor,orgColor);
        fill(image,i,j+1,newColor,orgColor);
        fill(image,i,j-1,newColor,orgColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgColor = image[sr][sc];
        fill(image,sr,sc,color,orgColor);
        return image;
    }
};