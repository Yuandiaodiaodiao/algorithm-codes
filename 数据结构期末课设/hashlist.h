#pragma once
#include<string>
#include<iostream>
using namespace std;
using ull=unsigned long long;
class HashList {
	//哈希表
public:
	HashList(int maxs = 100007);
	~HashList();
	void add(string s);//添加字符串
	ull hash(string& s);//计算hash
	string& find(ull hashint);//查找
	ull getsub(int l, int r, ull* hasha);//解析子串
	ull * bin;
	int maxsize = 100007;
	const ull hashP = 131;
private:
	string* array;
	string* array2;


};
HashList::HashList(int maxs ) {
	maxsize = maxs;
	array = new string[maxs];
	array2 = new string[maxs];
	bin = new ull[maxs];
	bin[0] = 1;
	for (int a = 1; a < maxs; ++a) {
		bin[a] = bin[a - 1] * hashP;
	}
}
HashList::~HashList() {
	delete[]bin;
	delete[]array;
}
void HashList::add(string s) {
	if (!array[hash(s) % maxsize].empty()) {
		array2[hash(array[hash(s) % maxsize]) % (maxsize - 10)] = array[hash(s) % maxsize];
		array2[hash(s) % (maxsize - 10)] = s;
		array[hash(s) % maxsize].clear();
	}
	else {
		array[hash(s) % maxsize] = s;
	}
	cout << "哈希值" << hash(s) << endl;
}
ull HashList::hash(string& s) {
	ull hashint = 0;
	for (auto& x : s) {
		hashint = (x - 'a' + 1) + hashint * hashP;
	}
	return hashint;
}
string& HashList::find(ull hashint) {
	if (array[hashint % maxsize].empty()) {
		return array2[hashint % (maxsize - 10)];
	}
	else return array[hashint % maxsize];
}
ull HashList::getsub(int l, int r, ull * hasha) {
	if (r < l)return 0;
	return hasha[r] - (l - 1 >= 0 ? hasha[l - 1] : 0) * bin[r - l + 1];
}