class Solution {
    public int maxProfit(int[] prices) {
        int answer = 0;

        for(int i = prices.length - 1; i > 0; i--) {
            if(prices[i] > prices[i-1]) {
                answer += prices[i] - prices[i-1];
            }
        }

        return answer;
    }
}
