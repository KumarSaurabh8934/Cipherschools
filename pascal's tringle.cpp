class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;
        for(int i=0; i<numRows; i++) {
            vector<int> pas(i+1); 
            for(int j=0; j<i+1; j++) {
                if(j==0 || i == j) pas[j] = 1;
                else pas[j] = a[i-1][j-1] + a[i-1][j];
            }
            a.push_back(pas);
        }
        return a;
    }
};
