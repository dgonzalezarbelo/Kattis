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

const ll mod = 1000003;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int Y, X, x; cin >> Y >> X >> x; cin.get();
    vector<pair<ll, bool>> dp(X, {0, false});
    string linea;
    vb marcas(X, false);
    for(int fila = 0; fila < Y; fila++) {
        getline(cin, linea);
        vector<bool> marcas (X, false);
        for(int col = 0; col < X; col++) {
            if(marcas[col]) continue;
            if(linea[col] == '#') dp[col] = {0,false};
            else if(linea[col] == '@') dp[col] = {1, true};
            else if(linea[col] == '>') {
                if(marcas[col + 1]) {
                    dp[col].first += dp[col + 1].first;
                    dp[col].second |= dp[col + 1].second;
                    dp[col].first %= mod;
                    marcas[col] = true;
                    continue;
                }
                int j = col;
                while(linea[j] == '>') {
                    j++;
                }
                if(linea[j] == '#') dp[j] = {0, false};
                else if(linea[j] == '@') dp[j] = {1, true};
                marcas[j] = true;
                j--;
                while(j >= col) {
                    dp[j].first += dp[j + 1].first;
                    dp[j].second |= dp[j + 1].second;
                    dp[j].first %= mod;
                    marcas[j] = true;
                    j--;
                }
            }
            else if(linea[col] == '<') {
                if(marcas[col - 1]) {
                    dp[col].first += dp[col - 1].first;
                    dp[col].second |= dp[col - 1].second;
                    dp[col].first %= mod;
                    marcas[col] = true;
                    continue;
                }
                int j = col;
                while(linea[j] == '<') {
                    j--;
                }
                if(linea[j] == '#') dp[j] = {0, false};
                else if(linea[j] == '@') dp[j] = {1, true};
                marcas[j] = true;
                j++;
                while(j <= col) {
                    dp[j].first += dp[j - 1].first;
                    dp[j].second |= dp[j - 1].second;
                    dp[j].first %= mod;
                    marcas[j] = true;
                    j++;
                }
            }
        }
    }
    if(dp[x].second) cout << dp[x].first;
    else cout << "begin repairs";
    return 0;
}