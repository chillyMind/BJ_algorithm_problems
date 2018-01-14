#include <stdio.h>
#include <algorithm>
using namespace std;
int n, l,cnt=0;
int arr[1010];
bool isTaped[2010];

int main() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	for (int i = 0; i < n; i++) {
		int d = (arr[i] - 1) * 2;
		if (!isTaped[d]) {
			for (int k = 0; k < l * 2 - 1; k++) {
				isTaped[d + k] = true;
			}
			cnt++;
		}
	}
	printf("%d", cnt);
}

/*
4 1
1 2 100 101

3 2
1 2 3

1 1
1000

4 1
101 1 2 100
*/