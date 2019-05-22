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
			hashint = (x - 'a')+hashint*hashP;
		}
		return hashint;
	}
	bool find(ull hashint) {
		return (array[hashint % maxsize].length() != 0);
		
	}
	ull getsub(int l, int r,ull* hasha) { return hasha[r] - hasha[l - 1] * bin[r - l + 1]; }
	ull* bin;

private:
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
	for (int ac = 1; ac <= m; ++ac) {
		ull hashP = 131;
		string s;
		cin >> s;
		ull *hasharray=new ull[s.length()];
		ull* hasharrayL = new ull[s.length()];
		ull* hasharrayS = new ull[s.length()];
		hasharray[0] = s[0] - 'a';
		hasharrayL[0] = hasharray[0] * hashP;
		hasharrayS[0] = hasharray[0] / hashP;
		int len = s.length();
		for (int a = 1; a <len; ++a) {
			hasharray[a] = hasharray[a - 1] * hashP + s[a] - 'a';
			hasharrayL[a] = hasharray[a] * hashP;
			hasharrayS[a] = hasharray[a] / hashP;
		}
		
		for (int a = 0; a < len; ++a) {
			for (int chr = 'a'; chr <= 'z'; ++chr) {
				ull hashi=hasharray[len-1]+(chr-s[a])*hashstr.bin[]
			}
		}
	}
	
}