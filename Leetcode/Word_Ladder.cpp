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
    map<string, vector<string>> graph;
    map<string, int> dist;
    void bfs(string beginWord)
    {
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 1;
        while (q.size())
        {
            string str = q.front();
            q.pop();
            for (auto x : graph[str])
                if (dist[x] == 0)
                {
                    q.push(x);
                    dist[x] = 1 + dist[str];
                }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        bool flag = false;
        for (auto x : wordList)
            if (x == endWord)
                flag = true;
        if (!flag)
            return 0;
        flag = false;
        for (auto x : wordList)
            if (x == beginWord)
                flag = true;
        if (!flag)
            wordList.push_back(beginWord);
        for (int i = 0; i < wordList.size(); i++)
        {
            string str = wordList[i];
            char ch = '#';
            for (int j = 0; j < str.size(); j++)
            {
                swap(ch, str[j]);
                graph[wordList[i]].push_back(str);
                graph[str].push_back(wordList[i]);
                swap(ch, str[j]);
            }
        }
        bfs(beginWord);
        if (dist[endWord] == 0)
            return 0;
        return (dist[endWord] - dist[beginWord]) / 2 + 1;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string beginWord = "cat";
    string endWord = "sag";
    vector<string> wordList = {"bat", "bag", "sat", "dag", "dot"};
    Solution sl;
    sl.ladderLength(beginWord, endWord, wordList);
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