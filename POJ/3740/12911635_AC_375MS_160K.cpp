 #include <iostream>
 using namespace std;
 #define MAXM 305
 
 bool mp[MAXM][MAXM];
 bool vs[MAXM];
 int n = 0, m = 0;
 bool flag = false;
 void dfs(int i, int k);

 int main() {
	 while (scanf("%d %d", &m, &n) != EOF) {
		 int ti;
		 for (int i = 0; i < m; ++i)
			 for (int j = 0; j < n; ++j) {
				 scanf("%d", &ti);
				 if (ti) mp[i][j] = true;
				 else mp[i][j] = false;
			 }
		 memset(vs, 1, sizeof(vs));
		 flag = false;
		 dfs(0, n);
		 if (flag) printf("Yes, I found it\n");
		 else printf("It is impossible\n");
	 }
 	return 0;
 }
 
 void dfs(int i, int k) {
	 if (flag) return ;
	 bool rflag = true;
	 int rcnt = 0;
	 int site[MAXM];
	 if (k == 0) {
		 flag = true;
		 return ;
	 }
	if (i >= m)
		return ;
	int t = 0;
	for (int j = 0; j < n; ++j) {
		if (mp[i][j]) {
			if (!vs[j]) {
				rflag = false;
				break;
			} else {
				++rcnt;
				site[t++] = j;
			}
		}
	}
	if (rflag) {
		int ti = 0;
		for (ti = 0; ti < t; ++ti)
			vs[site[ti]] = false;
		dfs(i + 1, k - rcnt);
		for (ti = 0; ti < t; ++ti)
			vs[site[ti]] = true;
	}
	dfs(i + 1, k);
 }