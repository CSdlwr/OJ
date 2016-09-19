/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
		List<Interval> ans = new ArrayList<Interval>();
		if (intervals == null || intervals.size() == 0) {
			ans.add(newInterval);
			return ans;
		}
		int i = 0;
		for (; i < intervals.size(); ++i) {
			if (intervals.get(i).start < newInterval.start)
				ans.add(intervals.get(i));
			else break;
		}
		if (ans.size() == 0 || ans.get(ans.size() - 1).end < newInterval.start)
			ans.add(newInterval);
		else
			ans.get(ans.size() - 1).end = Math.max(ans.get(ans.size() - 1).end,
					newInterval.end);
		Interval cur = null;
		for (; i < intervals.size(); ++i) {
			cur = ans.get(ans.size() - 1);
			if (cur.end >= intervals.get(i).start)
				cur.end = Math.max(cur.end, intervals.get(i).end);
			else
				ans.add(intervals.get(i));
		}
		return ans;
    }
}
