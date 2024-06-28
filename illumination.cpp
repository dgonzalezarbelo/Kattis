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

struct TwoSat {
    int N;
    vvi gr;
    vi values;
    TwoSat(int n = 0) : N(n), gr(2*n) {}

    void either(int f, int j) {
        f = max(2*f, -1-2*f);
        j = max(2*j, -1-2*j);
        gr[f].push_back(j^1);
        gr[j].push_back(f^1);
    }
    
    void setValue(int x) {either(x, x);}

    vi val, comp, z; int time = 0;
    int dfs(int i) {
        int low = val[i] = ++time, x; z.push_back(i);
        for(int e : gr[i]) if(!comp[e])
            low = min(low, val[e] ? : dfs(e));
        if (low == val[i]) do {
            x = z.back(); z.pop_back();
            comp[x] = low;
            if(values[x>>1] == -1) 
                values[x>>1] = x&1;
        } while(x != i);
        return val[i] = low;
    }

    bool solve() {
        values.assign(N, -1);
        val.assign(2*N, 0); comp = val;
        rep(i,0,2*N) if(!comp[i]) dfs(i);
        rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
        return 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r, k; cin >> n >> r >> k;
    vii v(k);
    rep(i,0,k) cin >> v[i].first >> v[i].second;
    TwoSat ts(2 * k); // 2*i -> Horizontal, 2*i+1 -> Vertical
    rep(i,0,k) {
        ts.either(2 * i, 2 * i + 1); // Horizontal o vertical
    }
    rep(i,0,k) {
        rep(j,i+1,k) {
            if(v[i].first == v[j].first && abs(v[i].second - v[j].second) <= 2*r)
                ts.either(~(2 * i), ~(2 * j));
            else if(v[i].second == v[j].second && abs(v[i].first - v[j].first) <= 2*r)
                ts.either(~(2 * i + 1), ~(2 * j + 1));
            // else if(abs(v[i].first - v[j].first) <= r && abs(v[i].second - v[j].second) <= r) {
            //     ts.either(~(2 * i), ~(2 * j + 1));
            //     ts.either(~(2 * i + 1), ~(2 * j));
            // }
        }
    }
    cout << ts.solve() << '\n';
    return 0;
}