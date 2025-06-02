#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, n, p;
    // solve stars
    string str;
    cin >> str;
    cin >> k;
    map<char, deque<ll>> m;
    vector<ll> ans_index;
    ll have_to_pick = str.size() - k;
    for (i = 0; i < str.size(); i++)
    {
        m[str[i]].push_back(i);
    }
first_iteration:
    ll index = -1;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->first != '0' && k != 0)
        {
            if (it->second.front() <= k)
            {
                index = it->second.front();
                ans_index.push_back(index);
                k -= index;
                it->second.pop_front();
                break;
            }
        }
    }
rest_iteration:
    for (auto it = m.begin(); it != m.end(); it++)
    {
        while (it->second.size() != 0)
        {
            if (index < it->second.front() && (index + k + 1) >= it->second.front())
            {
                if (k == 0)
                    goto ans;
                k -= it->second.front() - index - 1;
                index = it->second.front();
                if (have_to_pick > ans_index.size())
                    ans_index.push_back(index);
                it->second.pop_front();
                if (k == 0)
                    goto ans;
                goto rest_iteration;
            }
            else if (it->second.front() < index)
                it->second.pop_front();
            else
                break;
        }
    }
ans:
    for (i = 0; i < ans_index.size(); i++)
    {
        cout << str[ans_index[i]];
    }
    for (i = index + 1; i < str.size(); i++)
    {
        cout << str[i];
    }
    cout << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}