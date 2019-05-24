#include <iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cstdio>

using namespace std;

class ti {
public:
    ti(int a, int b) : h(a), m(b) {}

    int h, m;

    ti plus(int s) {
        ti temp=*this;
        temp.h = (temp.h + (temp.m += s) / 60);
        temp.m %= 60;
        return temp;
    }

    ti mul(int s) {
        ti temp=*this;
        (temp.m -= s) < 0 ? temp.h -= 1 : 0;
        temp.m = (temp.m + 60) % 60;
        temp.h = (temp.h + 24) % 24;
        return temp;
    }

    bool operator<(const ti &b) const { return h != b.h ? (h < b.h) : (m < b.m); }

    bool operator==(const ti &b) const { return h == b.h && m == b.m; }

    int operator-(const ti &b) const {
        int x = (*this < b) ?
                (24 * 60 - (b.h * 60 + b.m) + h * 60 + m+1)
                            : (h * 60 + m - (b.h * 60 + b.m)+1);
        return x;
    }
};

class tp {
public:
    tp(ti a, ti b) : s(a), t(b) {}

    ti s, t;

    bool operator<(const tp &b) const { return t < b.t; }
};

int main() {
    int A, B;
    while (cin >> A >> B) {
        int n;
        cin >> n;
        vector<tp> v;
        for (int a = 1; a <= n; ++a) {
            int q, w, e, r;
            char c;
            cin >> q >> c >> w >> c >> e >> c >> r;
            v.emplace_back(tp(ti(q, w), ti(e, r)));
        }
        sort(v.begin(), v.end());
        v.push_back(v.at(0));
        vector<tp> ans;
        ti st = v.at(0).s;
        ti firstS(-1,-1);
        bool flag = true;
        for (auto it = v.begin(); next(it) != v.end() && flag; ++it) {
            flag = it->t - it->s <= B * 60;
            flag = it->t - st <= B * 60;
            if (next(it)->s - it->t >= A * 60+2) {//can sleep?
                ans.emplace_back(tp(it->t.plus(1), (next(it)->s).mul(1)));
                st = (next(it)->s);
                if(firstS.h==-1)firstS=it->t;
            }
        }
        if(ans.size()==0)flag=false;
        if(firstS-st>B*60)flag=false;
        if (flag) {
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for (auto x:ans)printf("%02d:%02d-%02d:%02d\n", x.s.h, x.s.m, x.t.h, x.t.m);
        } else cout << "No" << endl;
    }

    return 0;
}
/*
 1 4
 3
 00:00-01:00
 02:00-3:00
 23:00-23:59



  */