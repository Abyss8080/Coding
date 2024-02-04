#include <bits/stdc++.h>
using namespace std;
int p[1000010], k[2019];
set<int> s;
int n, m;

int main() {
	cin >> n >> m;
	int l = 1, r = n, cnt = 0, left = 1, right = n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		k[p[i]]++;
		if (!s.count(p[i]))
			cnt++;
		s.insert(p[i]);
		if (cnt == m) {
			r = i;
			while (k[p[l]] > 1) {
				k[p[l]]--;
				l++;
			}
			if (r - l < right - left)
				left = l, right = r;
		}
	}
	cout << left << " " << right << endl;
	return 0;
}
