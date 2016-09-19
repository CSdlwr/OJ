public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
    	int sum = 0;
    	int n = gas.length;
    	boolean f = false;
    	for (int i = 0; i < n; ++i) {
    		cost[i] = gas[i] - cost[i];
    		if (cost[i] >= 0) f = true;
    		sum += cost[i];
    	}
    	if (!f || sum < 0) return -1;
    	sum = 0;
    	f = false;
    	for (int st = 0, i = st; ;) {
    		sum += cost[i];
    		if (++i >= n) {
    			f = true;
    			i %= n;
    		}
    		if (i == st) return st;
    		if (sum < 0 && f) return -1;
    		else if (sum < 0) {
    			sum = 0;
    			st = i;
    		}
    	}
    }
}
