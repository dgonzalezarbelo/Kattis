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

vector<vector<int>> al;
vector<bool> visited;

void dfs(int a) {
    if(visited[a]) return;
    visited[a] = true;
    for(int b : al[a])
        dfs(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    al.assign(n, vector<int>());
    visited.assign(n, false);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    dfs(0);
    int no_visitados = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            cout << i + 1 << '\n';
            no_visitados++;
        }
    }
    if(no_visitados == 0) cout << "Connected\n";
    return 0;
}