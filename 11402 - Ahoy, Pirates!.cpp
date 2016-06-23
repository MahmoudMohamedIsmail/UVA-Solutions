/* ***************************************************************
 * Program Name : Training
 * Date:  5,16,2016
 * Author: Mahmoud Ismail
 *Copyright: Your copyright notice
 ***************************************** *******************/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
struct node {
	int val, len;
	char type;
};
struct node tree[5194304];
int arr[1024005];
void init(int node, int s, int e) {

	if (s > e)
		return;

	if (s == e) {

		tree[node].val = arr[s];
		tree[node].len = 1;
		tree[node].type = 0;

		return;
	}

	init(node * 2, s, (int) (s + e) / 2);
	init(node * 2 + 1, (int) (s + e) / 2 + 1, e);
	tree[node].val = tree[node * 2].val + tree[node * 2 + 1].val;
	tree[node].len = e - s + 1;
	tree[node].type = 0;
}

void set_type(int node, char type) {

	if (type == 'I') {
		if (tree[node].type == 'F') {
			tree[node].type = 'E';
		} else if (tree[node].type == 'E') {
			tree[node].type = 'F';

		} else if (tree[node].type == 'I') {
			tree[node].type = 0;
		} else if (tree[node].type == 0) {
			tree[node].type = 'I';

		}
	} else {
		tree[node].type = type;

	}

}
void update_node(int node) {

	if (tree[node].type == 'F') {
		tree[node].val = tree[node].len;
	} else if (tree[node].type == 'E') {
		tree[node].val = 0;
	} else if (tree[node].type == 'I') {
		tree[node].val = tree[node].len - tree[node].val;
	} else {
		return; //CZ if type=0 we don't have a permission to update its child  
	}

	set_type(node * 2, tree[node].type);
	set_type(node * 2 + 1, tree[node].type);

	tree[node].type = 0;

}

void update(int node, int s, int e, int i, int j, char type) {

	update_node(node); //at any time we have to update the node
	if (s > e || i > e || j < s)
		return;

	if (s >= i && e <= j) {

		set_type(node, type);
		update_node(node);

		return;
	}

	update(node * 2, s, (s + e) / 2, i, j, type);
	update(node * 2 + 1, (s + e) / 2 + 1, e, i, j, type);
	tree[node].val = tree[node * 2].val + tree[node * 2 + 1].val;

}
int query(int node, int s, int e, int i, int j) {

	update_node(node); //at any time we have to update the node
	if (j < s || i > e)
		return 0;
	if (s >= i && e <= j) {
		return tree[node].val;
	}
	int mid = (s + e) / 2;

	return query(node * 2, s, mid, i, j) + query(node * 2 + 1, mid + 1, e, i, j);

}

int main() {

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	int tc = 1;
	while (t--) {

		int m;
		scanf("%d", &m);
		int i = 0;
		while (m--) {
			int c;
			string s;
			scanf("%d", &c);
			cin >> s;
			while (c--) {
				int j = 0, sz = s.size();
				sz += i;
				for (; i < sz; i++, j++)
					arr[i] = s[j] - '0';	//concatenated to array

			}

		}

		init(1, 0, i - 1);
		int q;
		scanf("%d", &q);
		int qc = 1;
		printf("Case %d:\n", tc);
		while (q--) {
			int a, b;
			char k;
			cin >> k;
			scanf("%d%d", &a, &b);
			if (k != 'S') {

				update(1, 0, i - 1, a, b, k);
			} else {
				printf("Q%d: %d\n", qc, query(1, 0, i - 1, a, b));
				qc++;
			}

		}

		tc++;
	}
	return 0;
}

