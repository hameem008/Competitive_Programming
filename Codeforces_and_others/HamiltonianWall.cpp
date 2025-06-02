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
    string row_1, row_2;
    cin >> row_1;
    cin >> row_2;
    reverse(row_1.begin(), row_1.end());
    reverse(row_2.begin(), row_2.end());
    while (1)
    {
        if (row_1.back() == 'W' && row_2.back() == 'W')
        {
            row_1.pop_back();
            row_2.pop_back();
        }
        else
            break;
        if (row_1.size() == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }
    reverse(row_1.begin(), row_1.end());
    reverse(row_2.begin(), row_2.end());
    ll current_row = 1;
    ll black_cnt_1 = 0, black_cnt_2 = 0;
    for (i = 0; i < row_1.size(); i++)
    {
        if (row_1[i] == 'B' && row_2[i] == 'B')
        {
            if (current_row == 1)
                current_row = 2;
            else
                current_row = 1;
            black_cnt_1 += 2;
            continue;
        }
        if (current_row == 1)
        {
            if (row_1[i] == 'B')
                black_cnt_1++;
            else
                break;
        }
        else if (current_row == 2)
        {
            if (row_2[i] == 'B')
                black_cnt_1++;
            else
                break;
        }
    }
    current_row = 2;
    for (i = 0; i < row_1.size(); i++)
    {
        if (row_1[i] == 'B' && row_2[i] == 'B')
        {
            if (current_row == 1)
                current_row = 2;
            else
                current_row = 1;
            black_cnt_2 += 2;
            continue;
        }
        if (current_row == 1)
        {
            if (row_1[i] == 'B')
                black_cnt_2++;
            else
                break;
        }
        else if (current_row == 2)
        {
            if (row_2[i] == 'B')
                black_cnt_2++;
            else
                break;
        }
    }
    ll total_black = 0;
    for (i = 0; i < row_1.size(); i++)
    {
        if (row_1[i] == 'B')
            total_black++;
        if (row_2[i] == 'B')
            total_black++;
    }
    if (total_black == black_cnt_1 || total_black == black_cnt_2)
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

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}