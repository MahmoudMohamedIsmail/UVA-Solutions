/* ***************************************************************
 * Program Name : Level 2
 * Date:  7,13,2016
 * Author: Mahmoud Ismail
 *Copyright: Your copyright notice
 ***************************************** *******************/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

void con(string s, vector<int> &arr) {
	int sz = s.size(), i = 0, n = 0;
	while (i < sz) {
		if (s[i] == ' ') {
			arr.push_back(n);
			n = 0;

		} else {
			n *= 10;
			n += (s[i] - '0');
		}
		i++;
	}

	arr.push_back(n);
}
int main() {

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string a, b;
	while (getline(cin, a)	&& getline(cin, b)) {
		vector<int> aa, bb, ans(100000);
		vector<int>::iterator it;
		con(a, aa);
		con(b, bb);
		sort(aa.begin(), aa.end());
		sort(bb.begin(), bb.end());

		it = set_intersection(aa.begin(), aa.end(), bb.begin(), bb.end(),
				ans.begin());
		ans.resize(it - ans.begin());

		if ((aa.size() == bb.size()) && bb.size() == ans.size()) {
			printf("A equals B\n");
		} else if (ans.size() == 0) {
			printf("A and B are disjoint\n");
		} else if (aa.size() < bb.size() && aa.size() == ans.size()) {
			printf("A is a proper subset of B\n");
		}

		else if (aa.size() > bb.size() && bb.size() == ans.size()) {
			printf("B is a proper subset of A\n");
		} else {
			printf("I'm confused!\n");
		}
	}
	return 0;
}
