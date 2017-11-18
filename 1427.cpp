#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector<int> v;

int main() {
	std::string s;
	std::cin >> s;
	std::sort(s.begin(), s.end());
	std::reverse(s.begin(), s.end());
	std::cout << s;
}