#include <stdio.h>
int M, D,day, dates;
int main() {
	scanf("%d %d", &M, &D);
	dates = (M - 1) * 31;
	dates += D;
	if (M > 2) dates -= 2;
	if (M > 7) {
		dates -= 3;
		dates -= (M - 8) / 2;
	}
	else {
		dates -= (M - 1) / 2;
	}
	day = dates % 7;
	switch (day)
	{
	case 1:
		printf("%s", "MON");
		break;
	case 2:
		printf("%s", "TUE");
		break;
	case 3:
		printf("%s", "WED");
		break;
	case 4:
		printf("%s", "THU");
		break;
	case 5:
		printf("%s", "FRI");
		break;
	case 6:
		printf("%s", "SAT");
		break;
	case 0:
		printf("%s", "SUN");
		break;
	default:
		break;
	}
}