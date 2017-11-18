#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int n;
std::vector<int> v;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	std::sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
}