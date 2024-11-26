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

vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), ret;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	queue<int> q; // use priority_queue for lexic. largest ans.
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		int i = q.front(); // top() for priority queue
		ret.push_back(i);
		q.pop();
		for (int x : gr[i])
			if (--indeg[x] == 0) q.push(x);
	}
	return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vvi al(n);
    vi Ms(n);
    vvii al_p(n);
    vector<pair<double, double>> inout(n, mp(0.0, 0.0));
    rep(i,0,n) {
        int M; cin >> M;
        Ms[i] = M;
        int k; cin >> k;
        rep(_,0,k) {
            int j, prop; cin >> j >> prop;
            j--;
            al[i].push_back(j);
            al_p[i].push_back(mp(j,prop));
        }
    }
    vi topo = topoSort(al);
    set<int> sol;
    for(int x : topo) {
        if(inout[x].first == 0.0) {
            inout[x].first = (double)Ms[x];
        }
        if(inout[x].first >= (double)Ms[x]) {
            inout[x].second = (double)Ms[x];
            sol.insert(x);
        }
        else inout[x].second = inout[x].first;
        for(auto p : al_p[x]) {
            inout[p.first].first += inout[x].second * ((double)p.second) / 100.0;
        }
    }
    bool first = true;
    for(int x : sol) {
        if(!first) cout << ' ';
        first = false;
        cout << x + 1;
    }
    cout << '\n';
    return 0;
}