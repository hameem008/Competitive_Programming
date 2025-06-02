#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void dfs(int i, int j, vector<vector<int>> &image, int in, int nw)
{
    if (i < 0 || j < 0)
        return;
    if (i >= image.size() || j >= image[0].size())
        return;
    if (image[i][j] != in)
        return;
    image[i][j] = nw;
    dfs(i + 1, j, image, in, nw);
    dfs(i - 1, j, image, in, nw);
    dfs(i, j + 1, image, in, nw);
    dfs(i, j - 1, image, in, nw);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    dfs(sr, sc, image, image[sr][sc], color);
    return image;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<int> dum(3);
    vector<vector<int>> image(3, dum);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            cin >> image[i][j];
    }
    for (auto x : floodFill(image, 1, 1, 2))
    {
        for (auto y : x)
            cout << y << gap;
        cout << endl;
    }
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