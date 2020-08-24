class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer,Integer> mp = new HashMap<>();
        for(int i : nums) {
            mp.put(i,mp.getOrDefault(i,0)+1);
        }
        int res = 0,max = Integer.MIN_VALUE;
        for(int i : nums) {
            int t = mp.get(i);
            if(t > max) {
                res = i;
                max = Math.max(max,t);
            }
        }
        return res;
    }
}
