// square matrix nXn
vector<vector<ll>> matrix_multiplication(vector<vector<ll>> &a, vector<vector<ll>> &b, ll n)
{
    vector<vector<ll>> ans(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}
vector<vector<ll>> binExp(vector<vector<ll>> &a, ll b, ll n)
{
    if (b == 1)
        return a;
    vector<vector<ll>> ans = binExp(a, b / 2, n);
    if (b % 2 != 0)
    {
        vector<vector<ll>> v = matrix_multiplication(ans, ans, n);
        return matrix_multiplication(v, a, n);
    }
    else
    {
        return matrix_multiplication(ans, ans, n);
    }
}