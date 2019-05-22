#include<iostream>
#include<string>
using namespace std;
using ull=unsigned long long;
class HashList {
	//¹þÏ£±í
public:
	HashList(int maxs = 100007) {
		maxsize = maxs;
		array = new string[maxs];
		array2 = new string[maxs];
		bin = new ull[maxs];
		bin[0] = 1;
		for (int a = 1; a < maxs; ++a) {
			bin[a] = bin[a - 1] * hashP;
		}
	}
	~HashList() {
		delete[]bin;
		delete[]array;
	}
	void add(string s) {
		if (!array[hash(s) % maxsize].empty()) {
			array2[hash(array[hash(s) % maxsize]) % (maxsize - 10)] = array[hash(s) % maxsize];
			array2[hash(s) % (maxsize - 10)] = s;
			array[hash(s) % maxsize].clear();
		}
		else {
			array[hash(s) % maxsize]=s;
		}
		cout << "¹þÏ£Öµ" << hash(s) << endl;
	}
	ull hash(string& s) {
		ull hashint = 0;
		for (auto& x : s) {
			hashint = (x - 'a'+1) + hashint * hashP;
		}
		return hashint;
	}
	string& find(ull hashint) {
		if (array[hashint % maxsize].empty()) {
			return array2[hashint % (maxsize - 10)];
		}
		else return array[hashint % maxsize];
	}
	ull getsub(int l, int r, ull * hasha) {
		if (r < l)return 0;
		return hasha[r] - (l - 1 >= 0 ? hasha[l - 1] : 0) * bin[r - l + 1]; }
	ull * bin;
	int maxsize = 100007;
	const ull hashP = 131;
private:
	string* array;
	string* array2;


};
int hashDone[100008];

void solvedone(HashList& hashstr, int ac, ull hashi) {
	if (hashDone[hashi % hashstr.maxsize] != ac) {
		string& ans = hashstr.find(hashi);
		if (!ans.empty()) {
			cout << ans << endl;
		}
		hashDone[hashi % hashstr.maxsize] = ac;
	}
}
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
		ull hashP = hashstr.hashP;
		string s;
		cin >> s;
		ull* hasharray = new ull[s.length()];
		hasharray[0] = s[0] - 'a'+1;
		int len = s.length();
		for (int a = 1; a < len; ++a) {
			hasharray[a] = hasharray[a - 1] * hashP + s[a] - 'a'+1;
		}

		for (int a = 0; a <=len; ++a) {
			for (int chr = 'a'; chr <= 'z'; ++chr) {
				//change
				if(a<len)
				{
					ull hashi = hasharray[len - 1] + (chr - s[a]) * hashstr.bin[len - 1 - a];
					solvedone(hashstr, ac, hashi);
				}
				//insert
				{
					ull hashi = ((a - 1 >= 0) ? hasharray[a - 1] * hashstr.bin[len  - (a - 1) ] : 0) + (chr - 'a'+1) * hashstr.bin[len - a] + hashstr.getsub(a, len - 1, hasharray);
					solvedone(hashstr, ac, hashi);
				}
			}
			
			//delete
			{
				ull hashi = ((a - 1 >= 0) ? hasharray[a - 1] * hashstr.bin[len - 1 - (a - 1) - 1] : 0) + hashstr.getsub(a + 1, len - 1, hasharray);
				solvedone(hashstr, ac, hashi);
			}
		}
		delete[]hasharray;
	}

}