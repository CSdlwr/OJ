#include <iostream>
using namespace std;
#define MAX_NUM 20

char inst[MAX_NUM][MAX_NUM];
int step = 0;
int r, c, e;
int steps[MAX_NUM][MAX_NUM];
void move(int i, int j);

int main() {

	while (cin>>r>>c>>e) {
		memset(steps, 0, sizeof(steps));
		if (r == 0 && c == 0 && e == 0)
			break;
		for (int i = 0; i < r; ++i)
			cin>>inst[i];
		move(0, e-1);
		step = 0;
	}
	return 0;
}

void move(int i, int j) {
	++step;
	if (inst[i][j] != 'I')
		steps[i][j] = step;
	if (i < 0 || i >= r ||j < 0 || j >= c) {
		cout<<--step<<" step(s) to exit"<<endl;
		return ;
	}
	switch(inst[i][j]) {
		case 'N': 
			inst[i][j] = 'I';
			move(i-1, j);	break;
		case 'S':
			inst[i][j] = 'I';
			move(i+1, j);	break;
		case 'W':
			inst[i][j] = 'I';
			move(i, j-1);	break;
		case 'E':
			inst[i][j] = 'I';
			move(i, j+1);	break;
		default:
			cout<<steps[i][j]-1<<" step(s) before a loop of "<<step-steps[i][j]<<" step(s)"<<endl;
			return ;
	}
	
	
}