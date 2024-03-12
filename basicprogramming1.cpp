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
    int N;
    int t;
    cin >> N >> t;
    vll v(N);
    ll sum = 0, even = 0;
    for (ll & x : v) {
        cin >> x;
        sum += x;
        if(x % 2 == 0) even += x;
    }
    if(t == 1) {
        cout << 7 << endl;
    }
    if(t == 2) {
        if(v[0] > v[1]) cout << "Bigger\n";
        else if(v[0] == v[1]) cout << "Equal\n";
        else cout << "Smaller\n";
    }
    if(t == 3) {
        vll m = {v[0], v[1], v[2]};
        sort(all(m));
        cout << m[1] << endl;
    }
    if(t == 4) {
        cout << sum << endl;
    }
    if(t == 5) {
        cout << even << endl;
    }
    if(t == 6) {
        for(ll x : v) {
            int mod = x % 26;
            char letra = 'a';
            letra += mod;
            cout << letra;
        }
        cout << endl;
    }
    if(t == 7) {
        vi visited(N, false);
        int i = 0;
        visited[0] = true;
        while(true) {
            i = int(v[i]);
            if(i >= N) {
                cout << "Out\n";
                break;
            }
            if(visited[i]) {
                cout << "Cyclic\n";
                break;
            }
            if(i == N - 1) {
                cout << "Done\n";
                break;
            }
            visited[i] = true;
        }
    }
    return 0;
}