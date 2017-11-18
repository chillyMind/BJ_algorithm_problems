#include <stdio.h>
#include <math.h>
#include <map>
using namespace std;
int n, p;
int roopinit, ans = 0;
int D[1000000];

int main() {
	scanf("%d %d", &n, &p);
	int curr = n;
	while (1) {
		int a, b, c, sum = 0;
		a = curr / 1000000000;
		if (a != 0) sum += pow(a, p);
		for (int i = 1; i < 8; i++) {
			int tmpow = pow(10, i);
			int tmpa = (curr % (100000000 / tmpow)) / (10000000 / tmpow);
			//printf("%d ", tmpa);
			if (tmpa != 0) sum += pow(tmpa, p);
		}
		//printf("curr %d : %d\n",curr, sum);
		D[curr] = sum;
		if (D[sum] != 0) {
			roopinit = sum;
			break;
		}
		curr = sum;
	}
	curr = n;
	if (n == D[D[n]]) {
		printf("0");
		return 0;
	}
	while (1) {
		if (curr == roopinit) break;
		ans++;
		curr = D[curr];
	}
	printf("%d\n", ans);
}