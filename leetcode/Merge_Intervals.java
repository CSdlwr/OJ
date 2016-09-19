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
	public void check(List<Interval> intervals) {
		int t = 0;
		for (Interval itl : intervals) {
			if (itl.start > itl.end) {
				t = itl.start;
				itl.start = itl.end;
				itl.end = t;
			}
		}
	}

	public List<Interval> merge(List<Interval> intervals) {
		List<Interval> ans = new ArrayList<Interval>();
		if (intervals == null || intervals.size() == 0)
			return ans;
		//check(intervals);
		//System.setProperty("java.util.Arrays.useLegacyMergeSort", "true");
		Collections.sort(intervals, new Comparator<Interval>() {
			@Override
			public int compare(Interval o1, Interval o2) {
				// TODO Auto-generated method stub
				if (o1.start == o2.start)
					return o1.end - o2.end;
				return o1.start - o2.start;
			}
			
		});
		ans.add(intervals.get(0));
		Interval cur = null;
		for (int i = 1; i < intervals.size(); ++i) {
			cur = ans.get(ans.size() - 1);
			if (cur.end >= intervals.get(i).start)
				cur.end = cur.end > intervals.get(i).end ? cur.end : intervals
						.get(i).end;
			else ans.add(intervals.get(i));				
		}
		return ans;
	}
}
