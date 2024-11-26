#include <bits/stdc++.h>
#pragma warning (disable : 4996)
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair

const double EPS = 1e-9;
const double INF = 1e9; //1e18 tambien suele ir bien
using ll = long long int;
using ull = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using db = double;
using vdb = vector<db>;
using ldb = long double; //100 ceros pero poca precision decimal

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<string> s;
    s.insert("phone");
    s.insert("wallet");
    s.insert("keys");
    int n; cin >> n;
    while(n--) {
        string st; cin >> st;
        s.erase(st);
    }
    if(sz(s) == 0) cout << "ready\n";
    else {
        bool first = true;
        for(auto it = s.begin(); it != s.end(); it++) {
            if(!first) cout << ' ';
            first = false;
            cout << *it;
        }
    }
    return 0;
}