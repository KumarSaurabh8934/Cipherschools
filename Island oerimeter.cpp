class Solution {
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int row = grid.size(), col = grid[0].size();
        int ans = 0;
        for(int i = 0; i < row; ++ i) {
            for(int j = 0; j < col; ++ j) {
                if(grid[i][j] == 0) continue;
                for(int k = 0; k < 4; ++ k) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if(x < 0 || y < 0 || x >= row || y >= col) {
                        ans ++;
                        continue;
                    }
                    if(grid[x][y]) continue;
                    ans ++;
                }
            }
        }
        return ans;
    }
};
