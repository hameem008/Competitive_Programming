#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> k;
    string str;
    cin >> str;
    string check = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFB";
    flag = false;
    for (i = 0; i < check.size(); i++)
    {
        for (j = 0; j < k; j++)
        {

            if (i + j >= check.size() || str[j] != check[i + j])
                break;
        }
        if (j == k)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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