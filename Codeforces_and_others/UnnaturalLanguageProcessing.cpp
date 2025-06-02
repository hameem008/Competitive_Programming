#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    cin >> n;
    cin >> str;
    vector<string> syl;
    for (i = str.size() - 1; i >= 0; i--)
    {
        string dum;
        if (str[i] == 'a' || str[i] == 'e')
        {
            dum.push_back(str[i]);
            dum.push_back(str[i - 1]);
            i--;
        }
        else if (str[i] == 'b' || str[i] == 'c' || str[i] == 'd')
        {
            dum.push_back(str[i]);
            dum.push_back(str[i - 1]);
            dum.push_back(str[i - 2]);
            i--;
            i--;
        }
        reverse(dum.begin(), dum.end());
        syl.push_back(dum);
    }
    reverse(syl.begin(), syl.end());
    for (i = 0; i < syl.size(); i++)
    {
        cout << syl[i];
        if (i != syl.size() - 1)
            cout << '.';
    }
    cout << endl;
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