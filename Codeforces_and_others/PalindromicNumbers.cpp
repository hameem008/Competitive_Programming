#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<ll> ans;

void Minus(vector<ll> A, vector<ll> B)
{
    while (1)
    {
        ll a = A.back();
        ll b = B.back();
        if (a < b)
        {
            ans.push_back(10 + a - b);
            A.pop_back();
            B.pop_back();
            if (B.size() != 0)
                B.back()++;
        }
        else
        {
            ans.push_back(a - b);
            A.pop_back();
            B.pop_back();
        }
        if (B.size() == 0)
            break;
    }
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    string str;
    cin >> n;
    cin >> str;
    vector<ll> v;
    for (i = 0; i < str.size(); i++)
    {
        v.push_back(str[i] - 48);
    }
    ll first = v.front();
    ll last = v.back();
    if (first == 9)
    {
        vector<ll> A(n + 1, 1);
        Minus(A, v);
        reverse(ans.begin(), ans.end());
        for (i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }
        ans.clear();
        cout << endl;
    }
    else
    {
        vector<ll> A(n + 1, 0);
        A.front()++;
        A.back()++;
        Minus(A, v);
        reverse(ans.begin(), ans.end());
        for (i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }
        ans.clear();
        cout << endl;
    }
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