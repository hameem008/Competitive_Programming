#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    string str;
    cin >> str;
    set<char> sa, sb;
    multiset<char> msa;
    for (auto x : str)
    {
        sa.insert(x);
        msa.insert(x);
    }
    set<ll> ans;
    for (auto x : str)
    {
        sb.insert(x);
        msa.erase(msa.find(x));
        if (msa.find(x) == msa.end())
            sa.erase(x);
        if (sa.size())
            ans.insert(sa.size() + sb.size());
    }
    cout << *(--ans.end()) << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}