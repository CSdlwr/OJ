 #include <iostream>
 using namespace std;
 #define MAXNUM 105
 
 bool ma[MAXNUM][MAXNUM];
 bool v[MAXNUM][MAXNUM];
 int n, m;
 
 void dfs(int i, int j);
 
 int main() {
	 while (1) {
		 scanf("%d %d", &n, &m);
		 if (n == 0 && m == 0)
			 break;
		 char ch;
		 while ((int)getchar() != 10) ;
		 for (int i = 0; i < n; ++i) {
			 //getchar();
			 for (int j = 0; j < m; ++j) {
				 //scanf("%c", &ch);
				 do {
					ch = getchar();
				 } while (ch != '@' && ch != '*');
				 if (ch == '@')
					 ma[i][j] = true;
				 else ma[i][j] = false;
			 }
		 }
		 int count = 0;
		 memset(v, 1, sizeof(v));

		 for (int i = 0; i < n; ++i) {
			 for (int j = 0; j < m; ++j) {
				 if (ma[i][j] && v[i][j]) {
					 dfs(i, j);
					 ++count;
				 }
			 }
		 }
		 printf("%d\n", count);
	 }
 	
 	return 0;
 }
 
 void dfs(int i, int j) {
 	if (i < 0 || i >= n || j < 0 || j >= m)
 		return ;
 	if (v[i][j] && ma[i][j]) {
 		v[i][j] = false;
 		dfs(i, j+1);
 		dfs(i+1, j+1);
 		dfs(i+1, j);
 		dfs(i+1, j-1);
 		dfs(i, j-1);
 		dfs(i-1, j-1);
 		dfs(i-1, j);
 		dfs(i-1, j+1);
 	}
 }