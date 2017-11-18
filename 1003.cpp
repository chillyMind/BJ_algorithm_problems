#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t, curr[BUFSIZ];
int zero[41];
int one[41];

void fib(int a) {
	if(zero[a] == -1){
		zero[a] = zero[a - 1] + zero[a - 2];
		one[a] = one[a - 1] + one[a - 2];
		return;
	}
	return;
}

int main() {
	scanf("%d", &t);
	memset(zero, -1, sizeof(zero));
	memset(one, -1, sizeof(one));
	zero[0] = 1;
	zero[1] = 0;
	one[0] = 0;
	one[1] = 1;

	for (int i = 0; i < t; i++) {
		scanf("%d",&curr[i]);
		for (int j = 2; j<= curr[i]; j++) {
			fib(j);
		}
	}
	for (int i = 0; i < t; i++) {
		printf("%d %d\n", zero[curr[i]], one[curr[i]]);
	}
	

}