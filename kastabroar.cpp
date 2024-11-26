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

vi ccs;
unordered_set<int> ccs_id;
vvi al;
set<ii> extra_edges;

void dfs(int a, int cc) {
    ccs[a] = cc;
    for(int b : al[a]) {
        if(ccs[b] == -1) {
            extra_edges.erase({min(a,b),max(a,b)});
            dfs(b, cc);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    al.assign(n, vi());
    ccs.assign(n, -1);
    rep(i,0,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        al[a].push_back(b);
        al[b].push_back(a);
        extra_edges.insert({min(a,b),max(a,b)});
    }
    if(m < n - 1) {
        cout << "Nej\n";
        return 0;
    }
    rep(i,0,n) {
        if(ccs[i] == -1) {
            dfs(i, i);
            ccs_id.insert(i);
        }
    }
    auto it = ccs_id.begin();
    auto it2 = ccs_id.begin(); it2++;
    auto it_e = extra_edges.begin();
    cout << "Ja\n";
    cout << ccs_id.size() - 1 << '\n';
    while(it2 != ccs_id.end()){
        cout << it_e->first + 1 << ' ' << it_e->second + 1 << ' ' << *it + 1 << ' ' << *it2 + 1 << '\n';
        it++; it2++; it_e++;
    }
    return 0;
}