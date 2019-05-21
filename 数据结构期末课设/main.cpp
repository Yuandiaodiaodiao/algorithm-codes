#include<iostream>
#include<string>
using namespace std;
using ull=unsigned long long;
class HashList {
	//¹þÏ£±í
public:
	HashList(int maxs=100008){
		maxsize = maxs;
		array = new string[maxs];
		bin = new ull[maxs];
		bin[0] = 1;
		for (int a = 1; a < maxs; ++a) {
			bin[a] = bin[a - 1]*hashP;
		}
	}
	void add(string s) {
		if (array[hash(s) % maxsize].length() > 0)cerr << "hash crashed" << endl;
		array[hash(s) % maxsize] = s;
	}
	ull hash(string& s) {
		ull hashint = 1;
		for (auto& x : s) {
			hashint = (x - '0')+hashint*hashP;
		}
		return hashint;
	}
	bool find(ull hashint) {
		return (array[hashint % maxsize].length() != 0);
		
	}
	ull getsub(int l, int r,ull* hasha) { return hasha[r] - hasha[l - 1] * bin[r - l + 1]; }
private:
	ull* bin;
	string* array;
	const ull hashP = 131;
	int maxsize = 100008;
};
int hashDone[100008];
int main() {
	int n;
	cin >> n;
	HashList hashstr;
	for (int a = 1; a <= n; ++a) {
		string s;
		cin >> s;
		hashstr.add(s);
	}

	int m;
	cin >> m;
	for (int a = 1; a <= m; ++a) {
		ull hashP = 131;
		string s;
		cin >> s;
		ull *hasharray=new ull[s.length()];
		ull* hasharrayL = new ull[s.length()];
		ull* hasharrayS = new ull[s.length()];
		hasharray[0] = s[0] - '0';
		hasharrayL[0] = hasharray[0] * hashP;
		hasharrayS[0] = hasharray[0] / hashP;
		for (int a = 1; a < s.length(); ++a) {
			hasharray[a] = hasharray[a - 1] * hashP + s[a] - '0';
			hasharrayL[a] = hasharray[a] * hashP;
			hasharrayS[a] = hasharray[a] / hashP;
		}
		for (int a = 0; a < s.length(); ++a) {
			for(int a)
		}
	}
	
}