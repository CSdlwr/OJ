public class Solution {
    public int maxProfit(int[] prices) {
    	if (prices == null|| prices.length == 0) return 0;
    	int cnt = 0, cur = prices[0]-1, l = prices.length;
    	for (int i = 0; i < l; ++i) { 
    		if (prices[i] > cur) {
	    		for (int j = 0; j <= i; ++j) 
	    			cnt = prices[i] - prices[j] > cnt ? prices[i] - prices[j] : cnt;
    		}
    		cur = prices[i];
    	}
    	return cnt;
    }
}
