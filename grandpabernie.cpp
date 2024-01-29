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
    int n; cin >> n;
    unordered_map<string, vector<int>> m;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int y; cin >> y;
        m[s].push_back(y);
    }
    for(auto& p : m) {
        sort(p.second.begin(), p.second.end());
    }
    int q; cin >> q;
    while(q--) {
        string s;
        int y;
        cin >> s >> y;
        cout << m[s][--y] << endl;
    }
    return 0;
}