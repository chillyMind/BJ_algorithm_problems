#include <stdio.h>
#include <math.h>

int n, r, c;
int dist = 0;

void solve(int sx, int sy, int size) {
	//printf("%d %d %d \n", sx, sy, size);
	if (size == 1) {
		return;
	}

	if ( sx <= size / 2 && sy <= size / 2) {
		//printf("1p %d\n", dist);
		solve(sx, sy, size / 2);
	}
	else if (sx > size / 2 && sy <= size / 2) {
		dist += (size/2) * (size/2);
		//printf("2p %d\n", dist);
		solve(sx - size / 2, sy, size / 2);
	}
	else if (sx <= size /2 && sy > size /2){
		dist += (size / 2) * (size / 2) * 2;
		//printf("3p %d\n", dist);
		solve(sx , sy - size / 2, size / 2);
	}
	else if (sx > size / 2 && sy > size / 2) {
		dist += (size / 2) * (size / 2) * 3;
		//printf("4p %d\n", dist);
		solve(sx - size / 2, sy - size / 2, size / 2);
	}
}


int main(void) {
	scanf("%d %d %d", &n, &c, &r);
	n = pow(2, n);
	solve(r+1, c+1, n);

	printf("%d", dist);
}