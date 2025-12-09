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
        for (char c : word)
        {
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