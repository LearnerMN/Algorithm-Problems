class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int c = 0;
        int t = 0;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[i].size(); j++){
                if (grid[i][j]){
                    t++;
                    if (i-1 >= 0){
                        c += grid[i-1][j];
                    }
                    if (i+1 < grid.size()){
                        c += grid[i+1][j];
                    }

                    if (j-1 >= 0){
                        c += grid[i][j-1];
                    }
                    if (j+1 < grid[i].size()){
                        c += grid[i][j+1];
                    }    
                }
                
            }
        }
        return t*4 - c;
    }
};