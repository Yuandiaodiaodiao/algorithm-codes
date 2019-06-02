#include<iostream>
#include<string>
#include<ctime>
#include<cstdio>
#include"../DictFind.h"
using namespace std;

int main() {
	DictFind dict;
	int n;
	cin >> n;
	char* cs = new char[n+5];
	string ss;
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= n; ++b) {
			cs[b - 1] = rand() % 26 + 'a';
		}
		ss = cs;
		dict.addDict(ss);
	}
	int m;
	cin >> m;

	clock_t startTime, endTime;
	startTime = clock();//计时开始
	for (int ac = 1; ac <= m; ++ac) {
		for (int b = 1; b <= n; ++b) {
			cs[b - 1] = rand() % 26 + 'a';
		}
		ss = cs;
		vector<string*>* v = dict.solve(ac, ss);

		/*for (auto& x : *v) {
			cout << x << endl;
		}*/
		delete v;
	}
	endTime = clock();//计时结束
	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}