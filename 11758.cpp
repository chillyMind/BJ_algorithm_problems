#include <stdio.h>
#include <vector>
using namespace std;

pair<int,int> p[3];

int main() {
	for (int i = 0; i < 3; i++) {
		int tmpa, tmpb;
		scanf("%d %d",&tmpa,&tmpb);
		p[i].first = tmpa;
		p[i].second = tmpb;
	};
	int s = (p[1].first - p[0].first)*(p[2].second-p[0].second) - (p[1].second-p[0].second)*(p[2].first - p[0].first);
	if(s==0){
		printf("%d", 0);
	}
	else {
		printf("%d", s > 0 ? 1 : -1);
	}
}