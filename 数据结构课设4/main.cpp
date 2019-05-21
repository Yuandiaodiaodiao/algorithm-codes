#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<fstream>
using namespace std;
bool xyin(int x, int y, int arex, int arey, int len) {
	return x >= arex && x < arex + len && y >= arey && y < arey + len;
}
int mapp[5000][5000];
int totid = 1;
int color[5000000];
void dfs(int bx, int by, int sx, int sy, int len) {
	//已经占用的xy 区块起始坐标sx sy
	if (len == 1) {
		++totid;
		for (int a = 0; a <= 1; ++a) {
			for (int b = 0; b <= 1; ++b) {
				if (mapp[sx + a * len][sy + b * len] == 0) {
					mapp[sx + a * len][sy + b * len] = totid;
				}
			}
		}
		return;
	}
	int xid = ++totid;
	for (int a = 0; a <= 1; ++a) {
		for (int b = 0; b <= 1; ++b) {
			if (xyin(bx, by, sx + a * len, sy + b * len, len)) {
				dfs(bx, by, sx + a * len, sy + b * len, len / 2);
			}
			else {
				mapp[sx + len - (!a)][sy + len - (!b)] = xid;
				dfs(sx + len - (!a), sy + len - (!b), sx + a * len, sy + b * len, len / 2);
			}
		}
	}
}
int k;
int colorid = 1;
void dfscolor() {
	for (int a = 1; a <= 1 << k; ++a) {
		for (int b = 1; b <= 1 << k; ++b) {
			int& nowcol = color[mapp[a][b]];
			int id = mapp[a][b];
			if (nowcol != 0 || id==1)continue;
			//cout << "涂色坐标x=" << a << " y=" << b;
			for (int col = 1; col <= 4; ++col) {
				//尝试涂4种颜色
				int ok = 1;
				for (int i = -1; i <= 1; ++i) {
					for (int j = -1; j <= 1; ++j) {
						if (mapp[a + i][b + j] != id)continue;
						for (int ii = -1; ii <= 1; ++ii) {
							for (int jj = -1; jj <= 1; ++jj) {
								if (ii * jj != 0 || (ii == 0 && jj == 0))continue;
								if (color[mapp[a + i + ii][b + j + jj]] == col && mapp[a + i + ii][b + j + jj] != id)ok = 0;
							}
						}
					}
				}
				if (ok == 1) {
					nowcol = col;
					break;
				}
			}

			//cout << "涂色结果" << color[mapp[a][b]] << endl;
		}
	}
}
int main() {
	cin >> k;//2^k棋盘
	int sx, sy;
	cin >> sx >> sy; //残缺坐标 1~2^n
	mapp[sx][sy] = 1;
	dfs(sx, sy, 1, 1, 1 << (k - 1));
	for (int a = 1; a <= 1 << k; ++a) {
		for (int b = 1; b <= 1 << k; ++b) {
			cout << setw(2) << mapp[a][b];
		}
		cout << endl;
	}
	dfscolor();
	for (int a = 1; a <= 1 << k; ++a) {
		for (int b = 1; b <= 1 << k; ++b) {
			cout << setw(2) << color[mapp[a][b]];
		}
		cout << endl;
	}
	fstream fout("out.txt", ios::out);
	fout << k << endl;
	for (int a = 1; a <= 1 << k; ++a) {
		for (int b = 1; b <= 1 << k; ++b) {
			fout << mapp[a][b]<<" ";
		}
		fout << endl;
	}
	for (int a = 1; a <= 1 << k; ++a) {
		for (int b = 1; b <= 1 << k; ++b) {
			fout  << color[mapp[a][b]]<<" ";
		}
		fout << endl;
	}
	fout.close();
	return 0;
}