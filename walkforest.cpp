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

vi dijkstra(int source, vvii const& al) {
    int n = sz(al);
    vi dist(n, INT_MAX);
    dist[source] = 0;
    vvi parents(n, vi());
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, source});
    while(!pq.empty()) {
        ii top = pq.top(); pq.pop();
        int d = top.first, u = top.second;
        if(d > dist[u]) continue;
        for(ii p : al[u]) {
            int c = p.first, v = p.second;
            if(d + c < dist[v]) {
                dist[v] = d + c;
                parents[v] = {u};
                pq.push({d + c, v});
            }
            else if(d + c == dist[v]) {
                parents[v].push_back(u);
            }
        }
    }
    return dist;
}

vi dp;

int caminos(int a, vvii const& al, vi const& dist) {
    if(a == 1) return 1;
    if(dp[a] != -1) return dp[a];
    int ret = 0;
    // cout << "a -> " << a << ' ' << dist[a] <<  endl;
    for(ii p : al[a]) {
        int b = p.second;
        if(dist[b] < dist[a])
            ret += caminos(b, al, dist);
    }
    return dp[a] = ret;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, m;
    while(cin >> n && n) {
        cin >> m;
        vvii al(n, vii());
        rep(i,0,m) {
            int a, b, c; cin >> a >> b >> c;
            a--; b--;
            al[a].push_back({c, b});
            al[b].push_back({c, a});
        }
        vi dist = dijkstra(1, al);
        dp.assign(n, -1);
        dp[1] = 1;
        cout << caminos(0, al, dist) << '\n';
    }   
    return 0;
}