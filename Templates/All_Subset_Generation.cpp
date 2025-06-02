vector<vector<ll>> subsetgen(vector<ll> &nums)
{
    ll n = nums.size();
    ll subsetCount = 1 << n;
    vector<vector<ll>> subsets;
    for (ll mask = 0; mask < subsetCount; ++mask)
    {
        vector<ll> subset;
        for (ll i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}