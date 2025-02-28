// Solución de Jorge Hernández Palop

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define vb vector<bool>
#define vbb vector<vb>

vector<int> medalWinner;
set<pii> pq;
vector<int> cont;
vector<int> res;
vector<int> ownerMedal;
vii g;

void dfs(int i, int p) {
    int owner = ownerMedal[i];
    cont[owner] += p - i;
    pq.insert({cont[owner], -owner});

    pii maxi = *(--pq.end());
    medalWinner[i] = -maxi.second;
    res[-maxi.second]++;

    for(int j : g[i]) {
        dfs(j, i);
    }

    pq.erase({cont[owner], -owner});
    cont[owner] -= p - i;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> lastMedal(n, -1);
    res = vector<int>(n, 0);
    ownerMedal = vector<int>(m, -1);
    medalWinner = vector<int>(m, -1);
    cont = vector<int>(n, 0);
    g = vii(m);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if(lastMedal[b] != -1) g[i].push_back(lastMedal[b]);
        if(lastMedal[a] != -1) g[i].push_back(lastMedal[a]);
        
        ownerMedal[i] = a;
        lastMedal[a] = i;
        lastMedal[b] = -1;
    }

    for(int i = m - 1; i >= 0; i--) {
        if(medalWinner[i] == -1) dfs(i, m);
    }

    for(int i = 0; i < n; i++) {
        cout << res[i];

        if(i != n - 1) cout << " ";
        else cout << endl;
    }
}