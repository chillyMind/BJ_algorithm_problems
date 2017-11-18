#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
int n, k, curr = 0;
vector<int> v[10];
int node[1100];

// root index = (2^k-1)/2
void find(int s, int e ,int depth) {
	//printf("[s (%d) to e (%d) depth %d]\n", s, e, depth);
	int m = (s + e) / 2;
	if (s == e) {
		v[depth].push_back(node[curr]);
		curr++;
		return;
	}
	find(s, m-1, depth + 1);
	v[depth].push_back(node[curr]);
	curr++;
	find(m+1, e, depth + 1);
}

int main() {
	scanf("%d", &k);
	int n = pow(2, k) - 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &node[i]);
	}
	find(0, n-1, 0);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < v[i].size();j++) {
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
}