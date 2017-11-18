#include <stdio.h>
#include <algorithm>
using namespace std;
int N;
int box[1001];
int dp[1001];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &box[i]);

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (box[i] > box[j] && dp[i] < dp[j]+1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	int mx = -1;
	for (int i = 0; i < N; i++) {
		mx = mx > dp[i] ? mx : dp[i];
	}
	printf("%d", mx);
}	