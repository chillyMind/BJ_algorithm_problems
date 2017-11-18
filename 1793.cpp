#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int n;
string dp[251];

string rev(string str) {
	string r = "";
	int len1 = str.length();
	for (int i = len1 - 1; i >= 0; i--)
		r += str[i];
	return r;
}

string add(string str1, string str2) {
	string ret = "";
	long long len1 = str1.length() - 1;
	long long len2 = str2.length() - 1;
	int tmp, carry = 0;
	while (1) {
		if (len1 >= 0 && len2 >= 0)
			tmp = (str1[len1--] - '0') + (str2[len2--] - '0') + carry;
		else if (len1 < 0 && len2 >= 0)
			tmp = (str2[len2--] - '0') + carry;
		else if (len2 < 0 && len1 >= 0)
			tmp = (str1[len1--] - '0') + carry;
		else break;
		if (tmp > 9) {
			carry = 1;
			tmp -= 10;
		}
		else {
			carry = 0;
		}
		ret += (tmp + '0');
	}
	if (carry) ret += (carry + '0');
	return rev(ret);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	dp[0] = "1";
	dp[1] = "3";
	dp[2] = "5";
	for (int i = 3; i <= 251; i++) {
		dp[i] = add(dp[i - 1], add(dp[i - 2],dp[i - 2]));
	}
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			cout << "1" << endl; continue;
		}
		cout << dp[n - 1] << endl;
	}
}