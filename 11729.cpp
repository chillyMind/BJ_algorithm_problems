#include <stdio.h>
#include <math.h>

void hanoi(int from, int to, int num) {
	if (num == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	int tmp = 0;
	tmp = tmp |(1 << from);
	tmp = tmp |(1 << to);
	tmp = tmp ^ 14;
	tmp = (int)(log(tmp)/log(2.0));
	hanoi(from, tmp, num - 1);
	printf("%d %d\n", from, to);
	hanoi(tmp, to, num - 1);
	
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", (int)(pow(2, n) - 1));
	hanoi(1, 3, n);
}