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
private:
    void in_order(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
            return;
        if (root->left != nullptr)
        {
            in_order(root->left, v);
            v.push_back(root->left->val);
        }
        else
            v.push_back(-101);
        v.push_back(root->val);
        if (root->right != nullptr)
        {
            in_order(root->right, v);
            v.push_back(root->right->val);
        }
        else
            v.push_back(101);
    }

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        vector<int> vp, vq;
        in_order(p, vp);
        in_order(q, vq);
        if (vp.size() != vq.size())
            return false;
        else
        {
            for (int i = 0; i < vp.size(); i++)
                if (vp[i] != vq[i])
                    return false;
            return true;
        }
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}