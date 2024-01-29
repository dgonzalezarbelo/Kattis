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

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow()  { return max(oc - c, 0LL); }
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int & i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if( ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L, 0, 31) do {
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while(qi < qe && !lvl[t]) {
                int v = q[qi++];
                for(Edge e : adj[v])
                    if(!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while(ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while(lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s, t; cin >> n >> m >> s >> t;
    vector<unordered_set<int>> v(n);
    Dinic din(n);
    rep(i,0,m) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        din.addEdge(a, b, c);
        v[a].insert(b);
    }
    vector<vi> sol;
    ll flow = din.calc(s, t);
    rep(i,0,n) {
        rep(j,0,sz(din.adj[i])) {
            if(v[i].count(din.adj[i][j].to) && din.adj[i][j].c < din.adj[i][j].oc){
                sol.push_back({i, din.adj[i][j].to, int(din.adj[i][j].oc - din.adj[i][j].c)});
            }
        }
    }
    sort(all(sol));
    cout << n << ' ' << flow << ' ' << sz(sol) << endl;
    rep(i,0,sz(sol)) {
        cout << sol[i][0] << ' ' << sol[i][1] << ' ' << sol[i][2] << endl;
    }
    return 0;
}