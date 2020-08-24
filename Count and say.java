class Solution {
    public String countAndSay(int n) {  
        if (n == 1) return "1";
        String previousResult = countAndSay(n-1);
        StringBuilder result = new StringBuilder();
        
        for (int i = 0, count = 1; i < previousResult.length(); count = 1) {
            char currentDigit = previousResult.charAt(i);
            while (++i < previousResult.length() && previousResult.charAt(i) == currentDigit) count++;
            result.append(count);
            result.append(currentDigit);
        }
        return result.toString();
    }
}
