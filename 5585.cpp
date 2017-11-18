#include <stdio.h>
#include <stdlib.h>

int profit[6] = {500, 100, 50, 10 ,5 ,1};
int n;
int m = 0;

int main(void) {
	scanf("%d", &n);
	n = 1000 - n;
	for (int i = 0; i < 6; i++) {
		while (profit[i] <= n) {
			n -= profit[i];
			m++;
		}
	}
	printf("%d", m);
}