#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int k[3];
int cnt = 0;

int main() {
	scanf("%d %d %d", &k[0], &k[1], &k[2]);
	while (1) {
		int dis1 = k[1] - k[0];
		int dis2 = k[2] - k[1];
		if (dis1 == 1 && dis2 == 1) break;
		if (dis1 > dis2) {
			k[2] = k[1];
			k[1] -= 1;
		}
		else {
			k[0] = k[1];
			k[1] += 1;
		}
		cnt++;
	}
	printf("%d", cnt);
}