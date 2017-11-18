#include <stdio.h>
#include <string.h>


int t, n;
int select[100001];
bool preF[100001];
bool postF[100001];
int groupedN = 0;
int result[BUFSIZ];

void dfs(int i) {
	preF[i] = true;
	if (preF[select[i]]) {
		if (!postF[select[i]]) {
			int tmp = select[i];
			while (tmp != i) {
				tmp = select[tmp];
				groupedN++;
			}
			groupedN++;
		}
	}else {
		dfs(select[i]);
	}
	postF[i] = true;
}

int main() {
	scanf("%d", &t);
	for(int k = 0 ; k < t ; k++){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &select[i]);
		}
		for (int i = 1; i <= n; i++) {
			dfs(i);
		}
		result[k] = n - groupedN;
		memset(preF, false, sizeof(bool) * 100001);
		memset(postF, false, sizeof(bool) * 100001);
		groupedN = 0;
	}
	for (int i = 0; i < t; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}