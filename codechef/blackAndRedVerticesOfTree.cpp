// https://www.codechef.com/problems/BLREDSET

#include <bits/stdc++.h>
using namespace std;

const int mxn = 2 * 1e5 + 10;
const long long mod = 1000000007;
vector<int> adj[mxn];
int parent[mxn];
int black[mxn], red[mxn], col[mxn];
bool cr[mxn];
long long dp[mxn][2];

void dfs(int u, int p)
{
    parent[u] = p;
    black[u] = red[u] = 0;
    if (col[u] == 1)
        black[u] = 1;
    else if (col[u] == 2)
        red[u] = 1;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v == p)
            continue;
        dfs(v, u);
        black[u] += black[v];
        red[u] += red[v];
    }
}

bool check(int u)
{
    if (col[u])
        return false;
    //cout<<" fucked "<<u<<endl;
    if (red[1] - red[u] > 0 && black[u] > 0)
        return true;
    //cout<<" fucked "<<u<<endl;
    if (black[1] - black[u] > 0 && red[u] > 0)
        return true;
    int l1 = 0, l2 = 0;
    //cout<<" fucked "<<u<<endl;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v == parent[u])
            continue;
        l1 += black[v];
        l2 += red[v];
        //cout<<u<<" "<<v<<endl;
        if (red[u] - l2 > 0 && l1 > 0)
            return true;
        if (black[u] - l1 > 0 && l2 > 0)
            return true;
    }
    return false;
}

long long solve(int u)
{
    dp[u][0] = dp[u][1] = 0;
    if (col[u] == 0)
    {
        dp[u][0] = 1;
        if (!cr[u])
            dp[u][1] = 1;
    }
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (parent[u] == v)
            continue;
        solve(v);
        dp[u][0] += (dp[v][0] * dp[u][0]);
        //while(dp[u][0] >= mod) dp[u][0] -= mod;
        dp[u][0] %= mod;

        dp[u][1] += (dp[v][1] * dp[u][1]);
        //while(dp[u][1] >= mod) dp[u][1] -= mod;
        dp[u][1] %= mod;
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int n, v, u;
        //cin>>n;
        scanf("%d", &n);
        for (int i = 1; i < n; i++)
        {
            //cin>>u>>v;
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &col[i]);
        }
        dfs(1, 0);
        for (int i = 1; i <= n; i++)
        {
            cr[i] = check(i);
        }

        solve(1);
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (col[i] == 0)
            {
                ans = ans + dp[i][0] - dp[i][1];
                ans %= mod;
            }
        }
        ans += mod;
        ans %= mod;

        printf("%lld\n", ans);
        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }
    }
}