#include <bits/stdc++.h>
using namespace std;
vector<int> vec[1000001];
int vis[1000001],cc[1000001], _curr_cc;
void dfs(int i)
{
    cc[i] = _curr_cc;
    vis[i] = 1;
    for (auto k : vec[i])
    {
        if (!vis[k])
        {
            dfs(k);
        }
    }
}
int main()
{
    string op;
    int t, n, m, a, b;
    cin >> t;
    while (t--)
    {
        _curr_cc = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            vis[i] = 0, vec[i].clear();
        }
        vector<pair<int, int>> EdgeList;
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> op >> b;
            if (op == "=")
            {
                vec[a].push_back(b);
                vec[b].push_back(a);
            }
            else
            {
                EdgeList.push_back({a, b});
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                _curr_cc++;
                dfs(i);
            }
        }
        bool flag = true;
        for (int i = 0; i < EdgeList.size(); i++)
        {
            a = EdgeList[i].first;
            b = EdgeList[i].second;
            if (cc[a] == cc[b])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}