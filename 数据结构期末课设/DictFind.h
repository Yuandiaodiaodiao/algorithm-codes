#pragma once
#include"hashlist.h"
#include<vector>
class DictFind {
public:
	DictFind() {
		hashDone = new int[100008];
		fill_n(hashDone, 100008, 0);
	}
	void addDict(string& s) {
		hashstr.add(s);
	}
	vector<string>* solve(int ac, string& s) {
		vector<string>* ans = new vector<string>;
		ull hashP = hashstr.hashP;
		ull* hasharray = new ull[s.length()];
		hasharray[0] = s[0] - 'a' + 1;
		int len = s.length();
		for (int a = 1; a < len; ++a) {
			hasharray[a] = hasharray[a - 1] * hashP + s[a] - 'a' + 1;
		}
		for (int a = 0; a <= len; ++a) {
			for (int chr = 'a'; chr <= 'z'; ++chr) {
				//change
				if (a < len)
				{
					ull hashi = hasharray[len - 1] + (chr - s[a]) * hashstr.bin[len - 1 - a];
					solvedone(ans, ac, hashi);
				}
				//insert
				{
					ull hashi = ((a - 1 >= 0) ? hasharray[a - 1] * hashstr.bin[len - (a - 1)] : 0) + (chr - 'a' + 1) * hashstr.bin[len - a] + hashstr.getsub(a, len - 1, hasharray);
					solvedone(ans, ac, hashi);
				}
			}
			//delete
			{
				ull hashi = ((a - 1 >= 0) ? hasharray[a - 1] * hashstr.bin[len - 1 - (a - 1) - 1] : 0) + hashstr.getsub(a + 1, len - 1, hasharray);
				solvedone(ans, ac, hashi);
			}
		}
		delete[]hasharray;
		return ans;
	}
private:
	void solvedone(vector<string> * ansv, int ac, ull hashi) {
		if (hashDone[hashi % hashstr.maxsize] != ac) {
			string& ans = hashstr.find(hashi);
			if (!ans.empty()) {
				hashDone[hashi % hashstr.maxsize] = ac;
				ansv->push_back(ans);
			}
		}
	}
	HashList hashstr;
	int* hashDone;
};