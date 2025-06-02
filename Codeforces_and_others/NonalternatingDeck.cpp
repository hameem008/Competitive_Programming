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
    ll alice = 0, bob = 0;
    ll alice_white = 0, alice_black = 0, bob_white = 0, bob_black = 0;
    n--;
    alice++;
    alice_white++;
    i = 2;
    bool flag = false;
    while (n > 0)
    {
        if (!flag)
        {
            if (n - 2 * i - 1 > 0)
            {
                bob_black += (2 * i + 1) / 2 + 1;
                bob_white += (2 * i + 1) / 2;
                // bob += 2 * i + 1;
                n -= 2 * i + 1;
            }
            else
            {
                if (n % 2 == 0)
                {
                    bob_black += n / 2;
                    bob_white += n / 2;
                }
                else
                {
                    bob_black += n / 2 + 1;
                    bob_white += n / 2;
                }
                // bob += n;
                n = 0;
            }
            flag = true;
        }
        else
        {
            if (n - 2 * i - 1 > 0)
            {
                alice_white += (2 * i + 1) / 2 + 1;
                alice_black += (2 * i + 1) / 2;
                // alice += 2 * i + 1;
                n -= 2 * i + 1;
            }
            else
            {
                if (n % 2 == 0)
                {
                    alice_black += n / 2;
                    alice_white += n / 2;
                }
                else
                {
                    alice_white += n / 2 + 1;
                    alice_black += n / 2;
                }
                // alice += n;
                n = 0;
            }
            flag = false;
        }
        i += 2;
    }
    cout << alice_white << gap << alice_black << gap << bob_white << gap << bob_black << endl;
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