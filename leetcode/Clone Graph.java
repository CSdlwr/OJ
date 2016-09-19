/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
	public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
		UndirectedGraphNode root = null;
		if (node == null) return root;
		Map<Object, Object> exists = new HashMap<Object, Object>();
		Set<Object> vs = new HashSet<Object>();
		root = new UndirectedGraphNode(node.label);
		exists.put(root.label, root);
		Queue<UndirectedGraphNode> que = new LinkedList<UndirectedGraphNode>();
		que.add(node);
		vs.add(node.label);
		UndirectedGraphNode cur = null, n1 = null, n2 = null;
		while (!que.isEmpty()) {
			cur = que.poll();
			for (UndirectedGraphNode gn : cur.neighbors) {
				if (!exists.containsKey(gn.label)) {
					n2 = new UndirectedGraphNode(gn.label);
					exists.put(n2.label, n2);
				}
				n1 = (UndirectedGraphNode) exists.get(cur.label);
				n2 = (UndirectedGraphNode) exists.get(gn.label);
				n1.neighbors.add(n2);
				if (!vs.contains(gn.label)) {
					que.add(gn);
					vs.add(gn.label);
				}
			}
		}
		return root;
	}
}
