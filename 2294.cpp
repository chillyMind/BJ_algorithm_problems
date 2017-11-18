#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 100000

using namespace std;
vector<int> v;
int n, k;
int dp[100001];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i <= k; i++)
		dp[i] = INF;
	for (int i = 0; i < v.size(); i++)
		dp[v[i]] = 1;
	for (int j = 0; j < v.size(); j++) {
		for (int i = 1; i <= k; i++) {
			if (v[j] > i) continue;
			dp[i] = min(dp[i - v[j]] + 1, dp[i]);
		}
	}
	printf("%d", dp[k]==INF ? -1 : dp[k]);
}