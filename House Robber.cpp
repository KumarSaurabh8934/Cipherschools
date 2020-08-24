class Solution {
public:
    int rob(vector<int>& nums) {
      
        int f0=0,f1=0;
        if(nums.size()>0) f0=nums[0];
        if(nums.size()>=2) f1=max(f0,nums[1]);
        for(int i=2;i<nums.size();i++){
            int temp=f1;
            f1=max(f0+nums[i],f1);
            f0=temp;
        }
        return max(f0,f1);
    }
};
