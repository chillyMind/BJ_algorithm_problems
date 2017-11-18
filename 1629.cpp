#include <stdio.h>
#include <math.h>
#include <map>

using namespace std;
long long a,b,c;
map<long long, long long> mp;

long long dq(long long s, long long e) {
	if (s == e) {
		return a;
	}
	long long m = (s + e) / 2;
	if (mp[e-s+1] == 0) {
		mp[e - s + 1] = ((dq(s, m) % c) * (dq(m + 1, e) % c)) % c;
		return mp[e - s + 1];		
	}
	else {
		return mp[e-s+1];
	}	
}

int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	if (a == c) {
		printf("%d", 0);
	}
	else if (b == 1) {
		printf("%lld", a%c);
	}
	else {
		printf("%lld", dq(1, b));
	}
}