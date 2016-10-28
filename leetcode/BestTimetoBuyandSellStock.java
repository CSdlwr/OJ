
public class BestTimetoBuyandSellStock {

    public static void main(String[] args) {
	BestTimetoBuyandSellStock main = new BestTimetoBuyandSellStock();
	System.out.println(main.maxProfit(new int[] {7, 6, 4, 3, 1}));
	System.out.println(main.maxProfit(new int[] {7, 1, 5, 3, 6, 4}));
    }

    public int maxProfit(int[] prices) {
	if (prices == null || prices.length == 0) {
	    return 0;
	}
	// d[i] 表示第i天卖出股票能获得的最大收益
	int[] d = new int[prices.length];
	d[0] = 0;
	int max = d[0];
	for (int i = 1; i < prices.length; ++i) {
	    if (prices[i] > prices[i - 1]) {
		d[i] = d[i - 1] + prices[i] - prices[i - 1];
	    } else {
		int buyInPrice = prices[i - 1] - d[i - 1];
		if (buyInPrice < prices[i]) {
		    d[i] = prices[i] - buyInPrice;
		}
	    }
	    // System.out.println("d[i] = " + d[i]);
	    if (d[i] > max) {
		max = d[i];
	    }
	}
	return max;
    }
}
