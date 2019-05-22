#pragma once
#include<string>
#include<iostream>
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
			array[hash(s) % maxsize] = s;
		}
		cout << "¹þÏ£Öµ" << hash(s) << endl;
	}
	ull hash(string& s) {
		ull hashint = 0;
		for (auto& x : s) {
			hashint = (x - 'a' + 1) + hashint * hashP;
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
		return hasha[r] - (l - 1 >= 0 ? hasha[l - 1] : 0) * bin[r - l + 1];
	}
	ull * bin;
	int maxsize = 100007;
	const ull hashP = 131;
private:
	string* array;
	string* array2;


};