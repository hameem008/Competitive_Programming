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
    char flag = 1;
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        root->val = 0;
        if (root->left != nullptr)
        {
            root->left->val = 1 + maxDepth(root->left);
            root->val = root->left->val;
        }
        if (root->right != nullptr)
        {
            root->right->val = 1 + maxDepth(root->right);
            root->val -= root->right->val;
        }
        if (abs(root->val) > 1)
            flag = 0;
        if (root->left != nullptr && root->right != nullptr)
            return max(root->left->val, root->right->val);
        else if (root->left != nullptr)
            return root->left->val;
        else if (root->right != nullptr)
            return root->right->val;
        else
            return 0;
    }
    bool isBalanced(TreeNode *root)
    {
        maxDepth(root);
        if (flag)
            return true;
        else
            return false;
    }
};

TreeNode *build_tree(vector<int> v)
{
    int n = v.size();
    vector<TreeNode *> v_nodes;
    TreeNode *zero = new TreeNode();
    v_nodes.push_back(zero);
    for (int i = 1; i < v.size(); i++)
    {
        TreeNode *node = new TreeNode(i);
        v_nodes.push_back(node);
        int _abs = abs(v[i]);
        if (_abs != i)
        {
            if (v[i] > 0)
            {
                v_nodes[_abs]->right = node;
            }
            else if (v[i] < 0)
            {
                v_nodes[_abs]->left = node;
            }
        }
    }
    return v_nodes[1];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts [1,2,3,null,null,4] 0, 1, -1, 1, -3
    Solution sl;
    cout << sl.isBalanced(build_tree({0, 1, -1, 1, -3, -4})) << endl;
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