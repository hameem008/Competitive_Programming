#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<TreeNode *> v_st;
    bool flag;
    void dfs(TreeNode *root, TreeNode *node)
    {
        if (root == nullptr)
            return;
        if (flag)
            v_st.push_back(root);
        if (root->val == node->val)
            flag = false;

        dfs(root->left, node);
        dfs(root->right, node);
        if (flag)
            v_st.pop_back();
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        flag = true;
        v_st.clear();
        dfs(root, p);
        vector<TreeNode *> vp = v_st;

        flag = true;
        v_st.clear();
        dfs(root, q);
        vector<TreeNode *> vq = v_st;

        int len = min(vp.size(), vq.size());
        TreeNode *parrent;
        for (int i = 0; i < len; i++)
        {
            if (vp[i]->val == vq[i]->val)
                parrent = vp[i];
        }

        return parrent;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts

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