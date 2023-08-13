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
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using db = double;
using vdb = vector<db>;
using ldb = long double; //100 ceros pero poca precision decimal

ll cuenta;

set<ii>::iterator addInterval(set<ii>& is, int L, int R) {
    //if (L == R) return is.end();
    auto it = is.lower_bound({L, R}), bf = it;
    while (it != is.end() && it->first <= R) {
        cuenta -= (it->second - it->first + 1);
        R = max(R, it->second);
        bf = it = is.erase(it);
    }
    if (it != is.begin() && (--it)->second >= L) {
        cuenta -= (it->second - it->first + 1);
        L = min(L, it->first);
        R = max(R, it->second);
        is.erase(it);
    }
    cuenta += (R - L + 1);
    return is.insert(bf, {L,R});
}
void removeInterval(set<ii>& is, int L, int R) {
    //if (L == R) return;
    auto it = addInterval(is, L, R);
    auto r2 = it->second;
    if (it->first == L) is.erase(it);
    else (int&)it->second = L;
    if (R != r2) is.emplace(R, r2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cuenta = 0;
    int n, q; cin >> n >> q;
    set<ii> is;
    while(q--) {
        int tipo; cin >> tipo;
        if(tipo == 1) {
            int a, b; cin >> a >> b;
            auto it = addInterval(is, a, b);
        }
        else cout << cuenta << '\n';
    }
    return 0;
}