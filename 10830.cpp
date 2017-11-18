#include <stdio.h>
#include <vector>
using namespace std;

#define matrix vector<vector<long long>>

matrix multiple(matrix &a, matrix &b) {
	long long n, m, l;
	n = a.size();
	m = a[0].size();
	l = b[0].size();
	matrix ret(n, vector<long long>(l));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++) {
			for (int k = 0; k < m; k++) {
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= 1000LL;
			}
		}
	}
	return ret;
}
long long n, b;
matrix mat[40];
matrix ans;

int main() {
	scanf("%lld %lld", &n, &b);
	//값 입력받음
	for (int i = 0; i < n; i++) {
		vector<long long> tmpv;
		for (int j = 0; j < n; j++) {
			long long tmp;
			scanf("%lld", &tmp);
			tmpv.push_back(tmp);
		}
		mat[0].push_back(tmpv);
	}
	//ans 초기화
	for (int i = 0; i < n; i++) {
		vector<long long> tmpv;
		for (int j = 0; j < n; j++) {
			long long tmp =0;
			if (i == j) { tmp = 1; };
			tmpv.push_back(tmp);
		}
		ans.push_back(tmpv);
	}
	for (int i = 1; i <= 39; i++) {
		mat[i] = multiple(mat[i - 1], mat[i - 1]);
	}
	for (int i = 0; i < 37; i++) {
		if (b&(1LL << i)) {
			ans = multiple(ans, mat[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%lld ", ans[i][j]);
		}
		printf("\n");
	}
}