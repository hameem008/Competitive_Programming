#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    string str;
    map<pair<char, char>, ll> mm;
    for (i = 0; i < n; i++)
    {
        cin >> str;
        set<char> s;
        for (j = 0; j < str.size(); j++)
        {
            s.insert(str[j]);
        }
        if (s.size() == 2)
        {
            auto it1 = s.begin();
            auto it2 = it1;
            it2++;
            auto it = mm.find({*it1, *it2});
            if (it == mm.end())
                mm.insert({{*it1, *it2}, str.size()});
            else
                it->second += str.size();
        }
        else if (s.size() == 1)
        {
            auto it1 = s.begin();
            auto it = mm.find({*it1, *it1});
            if (it == mm.end())
                mm.insert({{*it1, *it1}, str.size()});
            else
                it->second += str.size();
        }
    }
    for (auto x : mm)
    {
        cout << x.first.first << gap << x.first.second << gap << x.second << endl;
    }
    set<ll> answer;
    set<char> s;
    for (auto it1 = mm.begin(); it1 != mm.end(); it1++)
    {
        ll sum = it1->second;
        auto it2 = it1;
        it2++;
        s.insert(it1->first.first);
        s.insert(it1->first.second);
        for (; it2 != mm.end(); it2++)
        {
            s.insert(it2->first.first);
            if (s.size() > 2)
            {
                s.erase(it2->first.first);
                continue;
            }
            s.insert(it2->first.second);
            if (s.size() > 2)
            {
                s.erase(it2->first.second);
                continue;
            }
            sum += it2->second;
            auto it3 = it2;
            it3++;
            for (; it3 != mm.end(); it3++)
            {
                s.insert(it3->first.first);
                if (s.size() > 2)
                {
                    s.erase(it3->first.first);
                    continue;
                }
                s.insert(it3->first.second);
                if (s.size() > 2)
                {
                    s.erase(it3->first.second);
                    continue;
                }
                sum += it3->second;
            }
        }
        answer.insert(sum);
        s.clear();
    }
    if (answer.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    for (auto x : answer)
    {
        cout << x << endl;
    }
    auto ans = answer.end();
    ans--;
    cout << *ans << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}