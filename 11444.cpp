#include <stdio.h>
#include <vector>
using namespace std;

#define matrix vector<vector<long long>>

const long long MOD = 1e9 + 7;

matrix multiple(matrix &a, matrix &b) {
	long long n, m, l;
	n = a.size();
	m = a[0].size();
	l = b[0].size();
	matrix ret(n, vector<long long>(l));
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < l; j++) {
			for (long long k = 0; k < m; k++) {
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}
long long n, b;
matrix mat[80];

int main() {
	scanf("%lld", &b);
	matrix tmp(2, vector<long long>(2));
	mat[0] = tmp;
	tmp[0][0] = tmp[0][1] = tmp[1][0] = 1;
	mat[0][0][0] = 1;
	mat[0][0][1] = 1;
	mat[0][1][0] = 1;
	mat[0][1][1] = 0;

	matrix ans(2, vector<long long>(2));
	ans[0][0] = 1;
	ans[1][1] = 1;
	int i = 0;
	while (b) {
		if (b & (1LL << i)) {

			ans = multiple(ans, tmp);
			b -= (1LL << i);
		}
		tmp = multiple(tmp, tmp);
		i++;
	}
	printf("%lld", ans[0][1]);
}