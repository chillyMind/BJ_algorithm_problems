#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t;
int n;
int count;
int res[BUFSIZ];

void dp(int w, int m) {
	if (w > m) {
		return;
	}
	m -= w;
	if (m == 0) {
		count++;
		return;
	}
	for (int i = 1; i < 4; i++) {
		dp(i, m);
	}
}

int main(void) {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int curr;
		scanf("%d", &curr);
		dp(0, curr);
		res[i] = count;
		count = 0;
	}
	for (int i = 0; i < t; i++) {
		printf("%d\n", res[i]);
	}
}