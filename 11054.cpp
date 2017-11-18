#include <stdio.h>
#include <algorithm>
using namespace std;

int dp_f[1001];
int dp_b[1001];
int dp[1001];
int arr[1001];
int N;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++) {
		dp_f[i] = 1;
		int max = 0;
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[i]) {
				max = max > dp_f[j] ? max : dp_f[j];
				dp_f[i] = max + 1;
			}
		}
	}
	for (int i = N; i >= 0; i--) {
		dp_b[i] = 1;
		int max = 0;
		for (int j = N; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				max = max > dp_b[j] ? max : dp_b[j];
				dp_b[i] = max + 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		dp[i] = dp_f[i] + dp_b[i] - 1;
		//printf("%d + %d [%d]\n", dp_f[i] , dp_b[i] ,dp[i]);
	}
	sort(dp + 1, dp + N + 1);
	printf("%d\n", dp[N]);
}