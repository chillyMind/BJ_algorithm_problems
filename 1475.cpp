#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int t;
vector<int> ans;


int main() {
	scanf("%d", &t);
	while (t--) {
		bool isSquare = true;
		int mode = 0;
		int a, b, c, d;
		int dx, dy;
		int ds;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		dx = a - c;
		dy = b - d;
		//printf(" %d %d / %d %d / %d %d / %d %d\n", a - dy, b + dx, a + dy, b - dx, c - dy, d + dx, c + dy, d - dx);
		int tmpx, tmpy, tmpx2, tmpy2;
		scanf("%d %d %d %d", &tmpx, &tmpy, &tmpx2, &tmpy2);
		//printf("%d", ((tmpx == a - dy && tmpy == b + dx) && (tmpx2 == c - dy && tmpy2 == d + dx)) || ((tmpx == a + dy && tmpy == b - dx) && (tmpx2 == c + dy && tmpy2 == d - dx)));
		if (!(
			((tmpx == a - dy && tmpy == b + dx) && (tmpx2 == c - dy && tmpy2 == d + dx)) || ((tmpx2 == a - dy && tmpy2 == b + dx) && (tmpx == c - dy && tmpy == d + dx)) ||
			((tmpx == a + dy && tmpy == b - dx) && (tmpx2 == c + dy && tmpy2 == d - dx)) || ((tmpx2 == a + dy && tmpy2 == b - dx) && (tmpx == c + dy && tmpy == d - dx))
			)) {
			int td1 = pow((a - tmpx), 2) + pow((b - tmpy), 2);
			int td2 = pow((c - tmpx), 2) + pow((d - tmpy), 2);
			int td3 = pow((a - tmpx2), 2) + pow((b - tmpy2), 2);
			int td4 = pow((c - tmpx2), 2) + pow((d - tmpy2), 2);
			//printf("%d %d %d %d\n", td1, td2,td3,td4);
			if (td1 == td2 && td3 == td4) {
				//printf(" both same");
				int tmpscale = dx*dx + dy*dy;
				if (!(2 * td1 == tmpscale && 2*td3 == tmpscale)) {
					//printf("false");
					isSquare = false;
				}
			}else { isSquare = false; }
		}
		ans.push_back(isSquare ? 1 : 0);
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
}