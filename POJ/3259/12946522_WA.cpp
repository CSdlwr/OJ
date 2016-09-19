	#include <iostream>
	using namespace std;
	#define MAXN 505
	#define MAXM 2505
	#define INF 0xfffffff
	struct e {
		int v1, v2, t;
	}es[MAXM];
	bool bellman_ford();
	int n, m, w;
	int main() {
		int f;
		scanf("%d", &f);
		while (f-- > 0) {
			scanf("%d %d %d", &n, &m, &w);
			int v1, v2, t;
			for (int i = 0; i < m; ++i) {
				scanf("%d %d %d", &v1, &v2, &t);
				//if (v1 == v2) t = 0;
				es[i].v1 = v1; es[i].v2 = v2; es[i].t = t;
				es[i+m].v1 = v2; es[i+m].v2 = v1; es[i+m].t = t;
			}
			m *= 2;
			for (int i = 0; i < w; ++i) {
				scanf("%d %d %d", &v1, &v2, &t);
				t = -t;
				bool fd = false;
				//m *= 2;
				for (int i = 0; i < m; ++i) {
					if (es[i].v1 == v1 && es[i].v2 == v2) {
						es[i].t += t;
						fd = true;
					}
				}
				if (!fd) {
					es[m].v1 = v1; 
					es[m].v2 = v2;
					es[m].t = t;
					++m;
				}
			}
			if (bellman_ford()) printf("YES\n");
			else printf("NO\n");
		}
		return 0;
	}

	bool bellman_ford() {
		int d[MAXN];
		d[1] = 1;
		for (int i = 2; i <= n; ++i)
			d[i] = INF;
		bool flag;
		for (int i = 0; i < n-1; ++i) {
			flag = false;
			for (int j = 0; j < m; ++j) {
				int tmp = d[es[j].v1] + es[j].t;
				if (tmp < d[es[j].v2]) {
					d[es[j].v2] = tmp;
					flag = true;
				}
			}
			if (!flag) return false;
		}

		for (int i = 0; i < m; ++i) {
			int tmp = d[es[i].v1] + es[i].t;
			if (tmp < d[es[i].v2]) return true;
		}
		return false;
	}