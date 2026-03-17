#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

class Solution
{
public:
    bool ret = false;
    string s_ret;
    vector<int> v;
    vector<vector<int>> graph;
    vector<bool> is_visited;
    vector<bool> is_in_stack;
    vector<int> end_time;
    void top_sort(int vertex, int &time)
    {
        if (is_visited[vertex])
            return;
        time++;
        is_visited[vertex] = true;
        for (auto x : graph[vertex])
            top_sort(x, time);
        time++;
        end_time[vertex] = time;
    }
    void cycle(int vertex)
    {
        if (is_visited[vertex])
        {
            if (is_in_stack[vertex])
                ret = true;
            return;
        }
        is_visited[vertex] = true;
        is_in_stack[vertex] = true;
        for (auto x : graph[vertex])
            cycle(x);
        is_in_stack[vertex] = false;
        is_visited[vertex] = false;
    }
    string foreignDictionary(vector<string> &words)
    {
        if (words.size() == 1)
            return words[0];
        graph.assign(26, v), is_visited.assign(26, false), is_in_stack.assign(26, false), end_time.assign(26, -1);
        vector<bool> has_parrent(26, false), present(26, false);
        set<pair<int, int>> edges;
        for (int i = 0; i < words.size() - 1; i++)
        {
            string a = words[i], b = words[i + 1];
            for (auto x : a)
                present[x - 'a'] = true;
            for (auto x : b)
                present[x - 'a'] = true;
            bool flag = false;
            for (int j = 0; j < min(a.size(), b.size()); j++)
                if (a[j] != b[j])
                {
                    edges.insert({a[j] - 'a', b[j] - 'a'});
                    flag = true;
                    break;
                }
            if (!flag && (a.size() > b.size()))
                return s_ret;
        }
        for (auto x : edges)
        {
            present[x.first] = present[x.second] = true;
            has_parrent[x.second] = true;
            graph[x.first].push_back(x.second);
        }
        int time = 0;
        for (int i = 0; i < 26; i++)
        {
            if (present[i] && !has_parrent[i])
            {
                cycle(i);
                if (ret)
                    return s_ret;
                top_sort(i, time);
            }
        }
        vector<pair<int, int>> vp;
        for (int i = 0; i < 26; i++)
        {
            if (end_time[i] != -1)
                vp.push_back({end_time[i], i});
        }
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        for (auto x : vp)
            s_ret.push_back('a' + x.second);
        int cnt = 0;
        for (auto x : present)
            if (x)
                cnt++;
        if (cnt != s_ret.size())
            s_ret.clear();
        return s_ret;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    Solution sl;
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt", "te"};
    sl.foreignDictionary(words);
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}