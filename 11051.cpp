#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
long long mat[1001][1001];
const long long MOD = 10007;
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	mat[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		mat[i][0] = 1;
		mat[i][i] = 1;
		for (int j = 1; j < i; j++) {
			mat[i][j] = (mat[i - 1][j - 1]%MOD + mat[i - 1][j]%MOD)%MOD;
		}
	}
	printf("%lld", mat[n][k]%MOD);
}