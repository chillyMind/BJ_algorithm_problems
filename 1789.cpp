#include <stdio.h>
long long S,ans;
int main() {
	scanf("%lld", &S);
	long long a=2, b=0;
	for (long long i = 1; i <= S; i++) {
		b++;
		if (a == b) {
			b = 0;
			a++;
		}
	}
	printf("%lld", a - 1);
}