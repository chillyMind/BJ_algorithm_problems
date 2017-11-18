#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <iostream>

int n;
int m;
int c;
std::map<std::string, int> mm;
std::vector<std::string> v;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		std::string tmp;
		std::cin >> tmp;
		mm[tmp];
	}
	for (int i = 0; i < m; i++) {
		std::string tmp;
		std::cin >> tmp;
		if (mm.count(tmp)) {
			v.push_back(tmp);
			c++;
		}
	}
	printf("%d\n", c);
	std::sort(v.begin(), v.end());
	for (int i = 0; i < c; i++) {
		std::cout << v[i] << std::endl;
	}

	return 0;

}