class Solution {
public:
    vector<int> twoSum(vector <int> nums, int target){
    for (int a = 0; a<size(nums); a++){
        int n = target - nums[a];
        for (int b = a+1; b<size(nums); b++) {
            if (nums[b] == n){
                return {a,b};
        }
        }
    }return {};
