#include <stdio.h>

int matA[101][101];
int matB[101][101];
int matC[101][101];
int m, n, k;

void mat_print(int(*m)[101], int m_m, int m_n) {
	for (int i = 0; i < m_m; i++) {
		for (int j = 0; j < m_n; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

void mat_mult(int(*m1)[101], int(*m2)[101], int(*m3)[101], int m_m, int m_n ,int m_k, int s1, int s2) {
	for (int i = s1; i < m_m; i++) {
		for (int j = s2; j < m_k; j++) {
			for (int k = 0; k < m_n; k++) {
				m3[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &matA[i][j]);
		}
	}
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d", &matB[i][j]);
		}
	}
	mat_mult(matA, matB, matC, m, n, k , 0, 0);
	mat_print(matC,m,k);

	return 0;
}