#include<iostream>
#include<string>
#include"DictFind.h"
using namespace std;

int main() {
	DictFind dict;
	int n;
	cin >> n;
	for (int a = 1; a <= n; ++a) {
		string s;
		cin >> s;
		dict.addDict(s);
	}

	int m;
	cin >> m;
	for (int ac = 1; ac <= m; ++ac) {
		string s;
		cin >> s;
		auto v=dict.solve(ac,s);
		for (auto& x : *v) {
			cout << x << endl;
		}
		delete v;
	}
	return 0;
}