// find the length and center of all palindrome
vector<int> mancher(string s)
{
    string str;
    str.push_back('%');
    for (auto x : s)
    {
        str.push_back('#');
        str.push_back(x);
    }
    str.push_back('#');
    str.push_back('$');
    vector<int> p(str.size());
    int l = 0, r = 1, n = str.size() - 2;
    for (int i = 1; i <= n; i++)
    {
        p[i] = min(r - i, p[l + (r - i)]);
        while (str[i - p[i]] == str[i + p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > r)
        {
            l = i - p[i], r = i + p[i];
        }
    }
    return p;
}