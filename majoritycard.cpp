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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    deque<pair<ll,ll>> q;
    map<ll, set<ll>> m;
    unordered_map<ll, ll> cantidades;
    string s;
    ll x, y, z;
    while(n--) {
        cin >> s;
        if(s == "PUT_TOP" || s == "PUT_BOTTOM") {
            cin >> x >> y;
            m[cantidades[y]].erase(y);
            if(m[cantidades[y]].empty()) m.erase(cantidades[y]);
            cantidades[y] += x;
            m[cantidades[y]].insert(y);
            if(s == "PUT_TOP") q.push_front(mp(x,y));
            else q.push_back(mp(x,y));
        }
        else {
            cin >> z;
            while(z) {
                pair<ll, ll> p;
                if(s == "REMOVE_TOP") {
                    p = q.front();
                    q.pop_front();
                }
                else {
                    p = q.back();
                    q.pop_back();
                }
                x = p.first;
                y = p.second;
                if(z >= x) {
                    m[cantidades[y]].erase(y);
                    if(m[cantidades[y]].empty()) m.erase(cantidades[y]);
                    cantidades[y] -= x;
                    m[cantidades[y]].insert(y);
                    z -= x;
                }
                else {
                    m[cantidades[y]].erase(y);
                    if(m[cantidades[y]].empty()) m.erase(cantidades[y]);
                    cantidades[y] -= z;
                    m[cantidades[y]].insert(y);
                    if(s == "REMOVE_TOP") q.push_front(mp(x - z, y));
                    else q.push_back(mp(x - z, y));
                    z = 0;
                }
            }
        }
        auto it = m.end();
        --it;
        cout << *(it->second.begin()) << '\n';
    }
    return 0;
}