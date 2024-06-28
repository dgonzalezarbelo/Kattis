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
    int n, k; cin >> n >> k;
    vector<list<string>> preferencias(n);
    rep(i,0,n) {
        int q; cin >> q;
        while(q--) {
            string s; cin >> s;
            preferencias[i].push_back(s);
        }
    }
    list<string> lista;
    int p; cin >> p;
    rep(i,0,p) {
        string s; cin >> s;
        lista.push_back(s);
    }
    set<string> pillados;
    vector<vector<string>> sol(n, vector<string>(k));
    rep(j,0,k) {
        rep(i,0,n) {
            bool tiene = false;
            while(!tiene && !preferencias[i].empty()) {
                if(pillados.count(preferencias[i].front()))
                    preferencias[i].pop_front();
                else {
                    tiene = true;
                    pillados.insert(preferencias[i].front());
                    sol[i][j] = preferencias[i].front();
                    preferencias[i].pop_front();
                }
            }
            if(!tiene && preferencias[i].empty()) {
                while(pillados.count(lista.front()))
                    lista.pop_front();
                sol[i][j] = lista.front();
                pillados.insert(lista.front());
                lista.pop_front();
            }
        }
    }
    rep(i,0,n) {
        rep(j,0,k) {
            if(j) cout << ' ';
            cout << sol[i][j];
        }
        cout << '\n';
    }
    return 0;
}