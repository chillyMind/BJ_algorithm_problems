#include <stdio.h>
#define MAX 5000
int N,ans;

int main() {
	scanf("%d", &N);
	ans = MAX;
	for (int i = 0; i <= N / 5; i++) {
		int remain = N - 5 * i;
		int tmp = remain % 3 == 0 ? i + remain / 3 : MAX;
		ans = tmp < ans ? tmp : ans;
	}
	printf("%d", ans == MAX ? -1 : ans);
}