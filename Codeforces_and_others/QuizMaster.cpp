#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

vector<ll> emptyv;
vector<vector<ll>> allDivisors(1e5 + 10, emptyv);

void preCalc()
{
    for (int i = 1; i <= 1e5 + 5; i++)
    {
        for (int j = i; j <= 1e5 + 5; j += i)
        {
            allDivisors[j].push_back(i);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<ll> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }
    sort(v.begin(), v.end());
    vector<ll> hash(1e5 + 10, 0);
    set<ll> ans;
    flag = false;
    ll cnt = 0;
    for (auto x : allDivisors[v[0]])
    {
        if (x <= m)
        {
            if (hash[x] == 0)
                cnt++;
            hash[x]++;
        }
    }
    cnt == m ? flag = true : flag = false;
    i = 0, j = 1;
    while (1)
    {
        if (flag)
        {
            if (j > n || i >= n)
                break;
            ans.insert(v[j - 1] - v[i]);
            for (auto x : allDivisors[v[i]])
            {
                if (x <= m)
                {
                    hash[x]--;
                    if (hash[x] == 0)
                        cnt--;
                }
            }
            if (cnt != m)
                flag = false;
            i++;
        }
        else
        {
            if (j >= n)
                break;
            for (auto x : allDivisors[v[j]])
            {
                if (x <= m)
                {
                    if (hash[x] == 0)
                        cnt++;
                    hash[x]++;
                }
            }
            if (cnt == m)
                flag = true;
            j++;
        }
    }
    ans.size() ? cout << *ans.begin() << endl : cout << -1 << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    preCalc();
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}