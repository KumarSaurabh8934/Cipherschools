class Solution {
    public int fib(int N) {
        if(N <= 1) return N;
        int[] dp = new int[N + 1];
         dp[0] = 0;
        
     dp[1] = 1;
        
           for(int j = 2; j <= N; j++) {
              dp[j] = dp[j-1] + dp[j - 2];
        } 
        return dp[N];
        }
}
