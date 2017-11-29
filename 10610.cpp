#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
string ts;
int num[10];

int main() {
	int n = 0;
	int sum = 0;
	cin >> ts;
	for (int i = 0; i < ts.size(); i++) {
		int tmp = ts[i] - '0';
		num[tmp]++;
		sum += tmp;
	}
	if (sum % 3 != 0 || !num[0]) {
		printf("-1");
		return 0;
	}
	else {
		for (int i = 9; i >= 0; i--) {
			while (num[i] > 0) {
				printf("%d", i);
				num[i]--;
			}
		}
	}
	return 0;
}