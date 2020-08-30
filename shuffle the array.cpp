lass Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v;
        for(int i = 0; i < nums.size() - n; i++){
            v.push_back(nums[i]);
            v.push_back(nums[n + i]);
        }
        return v;
    }
};
