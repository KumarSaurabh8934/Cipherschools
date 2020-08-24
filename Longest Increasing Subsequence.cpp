class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int>dp(nums.size(),1);   // If no two elements of array satisfies the condition then length would be 1 , that's why we intialized it with 1
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)  //We will traverse the array only before index i and check whether condition satisfies or not  
            { 
                if(nums[i]>nums[j])    
                    dp[i]=max(dp[i],1+dp[j]); //Check whether the new obtained length is greater or not 
              }
         }
        return *max_element(dp.begin(),dp.end());  //Return the subsequence with maximum length
    }
};
