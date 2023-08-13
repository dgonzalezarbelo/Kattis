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
    string s;
    unordered_map<string, int> m;
    unordered_set<string> sol;
    string linea;
    bool fin = false;
    while(getline(cin, linea) && !fin) {
        for(char c : linea) {
            if(isalpha(c)) s += c;
            else {
                string copia;
                for(char c : s) copia += tolower(c);
                if(s == "EndOfText") fin = true;
                if(fin) break;
                if(++m[copia] == n) {
                    if(copia != "") sol.insert(s);
                }
                else if(m[copia] == n + 1) sol.erase(s);
                s = "";
            }
        }
        string copia;
        for(char c : s) copia += tolower(c);
        if(s == "EndOfText") fin = true;
        if(fin) continue;
        if(++m[copia] == n) {
            if(copia != "") sol.insert(s);
        }
        else if(m[copia] == n + 1) sol.erase(s);
        s = "";
    }
    vector<string> v;
    for(string s : sol) v.push_back(s);
    sort(v.begin(), v.end());
    if(v.size() > 0)
        for(int i = 0; i < sz(v); i++) {
            if(i) cout << '\n';
            cout << v[i];
        }
    else cout << "There is no such word.";
    return 0;
}