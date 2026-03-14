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
    int ans = 0;
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left_depth = 0, right_depth = 0;
        if (root->left != nullptr)
        {
            left_depth = 1 + maxDepth(root->left);
        }
        if (root->right != nullptr)
        {
            right_depth = 1 + maxDepth(root->right);
        }
        ans = max(ans, left_depth + right_depth);
        return max(left_depth, right_depth);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        maxDepth(root);
        return ans;
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
    // solve starts
    Solution sl; // [1,null,2,3,4,5]
    cout << sl.diameterOfBinaryTree(build_tree({0, 1, 1, -2, 2, -3})) << endl;
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