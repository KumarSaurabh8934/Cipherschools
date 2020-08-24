class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans; 
        vector<int> put; 
        combinations(ans,put,n,k,1);
        return ans;
    }
    
    void combinations( vector<vector<int>>&ans,vector<int>&put,int n,int k,int start)
    {
        if(k==put.size()&&n!=0)
            return;
        if(k==put.size()&&n==0) {
            ans.push_back(put);
            return;
        }
        for(int i=start;i<=9;i++)
        {
            put.push_back(i); 
            combinations(ans,put,n-i,k,i+1);
            put.pop_back();
        }
    }
};
