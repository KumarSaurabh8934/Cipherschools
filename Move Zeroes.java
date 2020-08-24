class Solution {
    public void moveZeroes(int[] nums) {
        int z=0;
        for(int j=0; j<nums.length; j++){
            if(nums[j] != 0) {
                swap(nums, j, z);
                z++;
            }
        }
    }
    
    private void swap(int[] arr, int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}
