 #include<iostream>
 using namespace std;
 struct e {
 	int v1, v2, c;
 }es[350005];
 int bellman_ford();
 char mp[305][305];
 int m, n;
 int st, ed;
 char ch;
 int cnt;
 int d[200000];
 int main() {
 	while (scanf("%d %d", &m, &n)) {
 		if (m == 0 && n == 0) break;
 		ch = getchar();
 		for (int i = 0; i < m; ++i) {
 			for (int j = 0; j < n; ++j) {
 				if ((ch = getchar()) == 'Y')
 					st = i*n+j;
 				else if (ch == 'T')
 					ed = i*n+j;
 				mp[i][j] = ch;
 			}
 			ch = getchar();
 		}
 		cnt = 0;
 		for (int i = 0; i < m; ++i) {
 			for (int j = 0; j < n; ++j) {
 				if (j < n-1) {
 					es[cnt].v1 = i*n+j;
 					es[cnt].v2 = i*n+j+1;
 					if (mp[i][j+1] == 'S' || mp[i][j+1] == 'R' 
 						|| mp[i][j] == 'R' || mp[i][j] == 'S') 
 						es[cnt].c = 999999;
 					else if (mp[i][j+1] == 'B')
 						es[cnt].c = 2;
 					else es[cnt].c = 1;
 					++cnt;
 					es[cnt].v1 = es[cnt-1].v2;
 					es[cnt].v2 = es[cnt-1].v1;
 					es[cnt].c = es[cnt-1].c;
 					++cnt;
 				}
 				if (i < m-1) {
 					es[cnt].v1 = i*n+j;
 					es[cnt].v2 = (i+1)*n+j;
 					if (mp[i+1][j] == 'S'|| mp[i+1][j] == 'R'
 						|| mp[i][j] == 'R' || mp[i][j] == 'S') 
 						es[cnt].c = 999999;
 					else if (mp[i+1][j] == 'B')
 						es[cnt].c = 2;
 					else es[cnt].c = 1;
 					++cnt;
 					es[cnt].v1 = es[cnt-1].v2;
 					es[cnt].v2 = es[cnt-1].v1;
 					es[cnt].c = es[cnt-1].c;
 					++cnt;
 				}
 			}
 		}
 		int ans = bellman_ford();
 		if (ans == 999999) printf("-1\n");
 		else printf("%d\n", ans);
 	}
 	return 0;
 }
 
 int bellman_ford() {

 	//memset(d, 0x0f, sizeof(d));
 	for (int i = 0; i < n*m; ++i)
 		d[i] = 999999;
 	d[st] = 0;
 	int t;
 	bool f;
 	for (int i = 0; i < n*m - 1; ++i) {
 		f = false;
 		for (int j = 0; j < cnt; ++j) {
 			t = d[es[j].v1]+es[j].c;
 			if (t<d[es[j].v2]) {
 				d[es[j].v2] = t;
 				f = true;
 			}
 		}
 		if (!f) return d[ed];
 	}
 	return d[ed];
 }