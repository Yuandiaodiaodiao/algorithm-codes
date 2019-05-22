#include<iostream>
#include<string>
#include<sstream>
#include"SocketServer.h"
#include"../DictFind.h"
using namespace std;

int main() {
	DictFind dict;
	SocketServer sock;
	int uid = 0;
	SOCKET id=sock.accepts();
	while (true) {
		stringstream ss(sock.receives(id));
		string s;
		ss >> s;
		if (s == "add") {
			ss >> s;
			dict.addDict(s);
		}
		else {
			ss >> s;
			auto v = dict.solve(++uid, s);
			string temp="\n";
			for (auto& x : *v) {
				temp += x+"\n";
			}
			delete v;
			sock.sends(id, temp);
		}
	}
	return 0;
}