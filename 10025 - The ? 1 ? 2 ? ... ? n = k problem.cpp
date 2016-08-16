/* ***************************************************************
 * Program Name : Level 2
 * Date:  8,15,2016
 * Author: Mahmoud Ismail
 *Copyright: Your copyright notice
 ***************************************** *******************/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main() {

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int k, n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &k);
		if (k < 0) {
			k *= -1;
		}

		if (k == 0) {
			k = 6;
		}
		long long l = 1, r = 1e6;
		int f = 0;
		long long sol = 0;
		while (l <= r) {
			long long m = (l + r) / 2;

			if (k == (m * (m + 1) / 2)) {

				sol = m;
				break;
			} else if (k < (m * (m + 1) / 2)) {
				if (k > ((m - 1) * (m - 1 + 1) / 2)) {
					f = 1;
					sol = m;

					break;

				}
				r = m - 1;
			} else {
				l = m + 1;
			}

		}

		if (f) {

			long long mm = (sol * (sol + 1) / 2);
			mm -= k;
			while (mm % 2 != 0) {
				sol++;
				mm += sol;

			}

		}

		//printf("%lld\n",sol);
		cout << sol << endl;
		if (n != 0)
			cout << endl;

	}

	return 0;
}
