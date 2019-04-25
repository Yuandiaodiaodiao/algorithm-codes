#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class ip {
public:
	ip(long long ipi, int lenx) {
		ipint = ipi, len = lenx;
	}
	ip(string s) {
		int bit = 3;
		string temp;
		for (auto x : s) {
			if (x == '.' || x == '/') {
				ipint += atoll(temp.c_str()) * ((long long)1 << bit-- * 8);
				temp.clear();
			} else {
				temp += x;
			}
		}
		if (s.find('/')!=-1) {
			len = atoi(temp.c_str());
		}
		else {
			
			ipint += atoll(temp.c_str()) * ((long long)1 << bit-- * 8);
			len = 32 - (bit+1) * 8;
		}
	}
	bool operator < (const  ip& b)const {
		if (ipint != b.ipint)return ipint < b.ipint;
		else return len < b.len;
	}
	void output() {
		for (int a = 3; a >= 0; --a) {
			cout << (ipint >> a * 8)%256;
			if (a != 0)cout << '.';
		}
		cout << '/' << len;
	}
	long long ipint = 0;
	int len = 0;
};
list<ip>ls;
long long match(ip ipi) {
	return ipi.ipint + (1ll << (32 - ipi.len)) - 1;
}
bool isip(ip ipi) {
	return ipi.ipint == ipi.ipint >> (32-ipi.len) << (32-ipi.len);
}
int main() {
	int n;
	cin >> n;
	for (int a = 1; a <= n; ++a) {
		string s;
		cin >> s;
		ls.push_back(ip(s));
	}
	ls.sort();
	for (auto it = ls.begin(); next(it) != ls.end();) {
		if (match(*next(it)) <= match(*it)) {
			ls.erase(next(it));
		}
		else {
			++it;
		}
	}

	for (auto it = ls.begin(); next(it) != ls.end();) {
		ip newip = ip(it->ipint, max(it->len - 1, 0));
		if (next(it)->len==it->len && isip(newip) &&match(*it)>=next(it)->ipint-1 && max(match(*it),match(*next(it)))==match(newip) ) {
			ls.erase(next(it));
			*it = newip;
			if (it != ls.begin())--it;
		}
		else {
			++it;
		}
	}


	for (auto& x : ls) {
		x.output();
		cout << endl;
	}
	return 0;
}