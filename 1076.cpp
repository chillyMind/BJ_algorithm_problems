#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

long long ans;
string tmpa, tmpb, tmpc;
map<string, pair<long long, long long>> mp;

int main() {
	mp["black"] = make_pair(0, 1);
	mp["brown"] = make_pair(1, 10);
	mp["red"] = make_pair(2, 100);
	mp["orange"] = make_pair(3, 1000);
	mp["yellow"] = make_pair(4, 10000);
	mp["green"] = make_pair(5, 100000);
	mp["blue"] = make_pair(6, 1000000);
	mp["violet"] = make_pair(7, 10000000);
	mp["grey"] = make_pair(8, 100000000);
	mp["white"] = make_pair(9, 1000000000);
	
	cin >> tmpa >> tmpb >> tmpc;
	ans = (mp[tmpa].first * 10 + mp[tmpb].first)*mp[tmpc].second;

	printf("%lld", ans);
}