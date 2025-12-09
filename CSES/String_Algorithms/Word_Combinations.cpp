#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll mod = 1e9 + 7;

#define number_of_alphabets 26 // 2 for bit string

class trie_node
{
public:
    char end_of_word;
    trie_node *children[number_of_alphabets];
    trie_node()
    {
        end_of_word = 0;
        for (int i = 0; i < number_of_alphabets; i++)
            children[i] = nullptr;
    }
};

class trie
{
private:
    trie_node *root;
    bool has_children(trie_node *node)
    {
        for (int i = 0; i < number_of_alphabets; i++)
            if (node->children[i])
                return true;
        return false;
    }
    bool delete_word(trie_node *node, string &word, int depth)
    {
        if (!node)
            return false;
        if (depth == word.length())
        {
            if (node->end_of_word)
            {
                node->end_of_word = 0;
                return !has_children(node);
            }
            return false;
        }
        int index = word[depth] - 'a'; // int index = word[depth] - '0';
        if (delete_word(node->children[index], word, depth + 1))
        {
            delete node->children[index];
            node->children[index] = nullptr;
            return !node->end_of_word && !has_children(node);
        }
        return false;
    }
    void destroy(trie_node *node)
    {
        if (!node)
            return;
        for (int i = 0; i < number_of_alphabets; i++)
            if (node->children[i])
                destroy(node->children[i]);
        delete node;
    }

public:
    trie()
    {
        root = new trie_node();
    }
    trie_node *get_root()
    {
        return root;
    }
    bool search_word(string word)
    {
        trie_node *node = root;
        for (char c : word)
        {
            int index = c - 'a'; // int index = c - '0';
            if (!node->children[index])
                return 0;
            node = node->children[index];
        }
        return node->end_of_word;
    }
    void insert_word(string word)
    {
        trie_node *node = root;
        for (int i = word.size() - 1; i >= 0; i--)
        {
            char c = word[i];
            int index = c - 'a'; // int index = c - '0';
            if (!node->children[index])
                node->children[index] = new trie_node();
            node = node->children[index];
        }
        node->end_of_word = 1;
    }
    void erase_word(string word)
    {
        delete_word(root, word, 0);
    }
    bool starts_with(string prefix)
    {
        trie_node *node = root;
        for (char c : prefix)
        {
            int index = c - 'a'; // int index = c - '0';
            if (!node->children[index])
                return 0;
            node = node->children[index];
        }
        return 1;
    }
    void clear()
    {
        destroy(root);
        root = new trie_node();
    }
    ~trie()
    {
        destroy(root);
    }
};

trie tr;
ll rec(int n, vector<ll> &dp, string &str)
{
    if (dp[n + 1] > -1)
        return dp[n + 1];
    string temp;
    ll cnt = 0;
    trie_node *node = tr.get_root();
    for (int i = n, j = 1; i >= 0; i--, j++)
    {
        int index = str[i] - 'a';
        if (!node->children[index])
            break;
        else
        {
            node = node->children[index];
            if (node->end_of_word)
                cnt = (cnt + rec(n - j, dp, str)) % mod;
        }
    }
    dp[n + 1] = cnt;
    return dp[n + 1];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    cin >> str;
    n = str.size();
    cin >> k;
    for (i = 0; i < k; i++)
    {
        string st;
        cin >> st;
        tr.insert_word(st);
    }
    vector<ll> dp(n + 1, -1);
    dp[0] = 1;
    cout << rec(n - 1, dp, str) << endl;
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