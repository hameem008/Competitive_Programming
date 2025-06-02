ll presum[1008][1008];
void grid_presum(ll row, ll column)
{
	for (ll i = 2; i <= row; i++)
	{
		presum[i][1] = presum[i][1] + presum[i - 1][1];
	}
	for (ll i = 2; i <= column; i++)
	{
		presum[1][i] = presum[1][i] + presum[1][i - 1];
	}
	for (ll i = 2; i <= row; i++)
	{
		for (ll j = 2; j <= column; j++)
		{
			presum[i][j] = presum[i][j] + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
		}
	}
}
ll query(pair<ll, ll> p1, pair<ll, ll> p2)
{
	return presum[p2.first][p2.second] + presum[p1.first - 1][p1.second - 1] - presum[p2.first][p1.second - 1] - presum[p1.first - 1][p2.second];
}