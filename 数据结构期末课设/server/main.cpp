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
	
	while (true) {
		SOCKET id = sock.accepts();
		//cout << "connect" << endl;d
		stringstream ss(sock.receives(id));
		string s;
		ss >> s;
		if (s == "add") {
			ss >> s;
			dict.addDict(s);
		}
		else {
			ss >> s;
			vector<string*>* v = dict.solve(++uid, s);
			string temp="\n";
			for (auto x : *v) {
				temp += *x+"\n";
			}
			delete v;
			sock.sends(id, temp);
			cout << temp << endl;
		}
		sock.closes(id);
	}
	return 0;
}