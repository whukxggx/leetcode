#include "head.h"

//208. 实现 Trie (前缀树)
//此处是假设均为小写英文字母
struct TrieNode
{
    TrieNode *next[26]={NULL};//注意必须将26个指针初始化下
    bool terminated;
    TrieNode() : terminated(false) {}
};
class Trie
{
private:
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *tmp = root;
        for (auto iter = word.begin(); iter != word.end(); ++iter)
        {
            if (tmp->next[*iter - 'a'] == NULL)
            { //如果此前缀存在，继续
                tmp->next[*iter - 'a'] = new TrieNode();
            }
            tmp = tmp->next[*iter - 'a'];
        }
        tmp->terminated = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *tmp=root;
        for(auto iter=word.begin();iter!=word.end();++iter){
            if(tmp->next[*iter-'a']==NULL)return false;
            tmp=tmp->next[*iter-'a'];
        }
        return tmp->terminated;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *tmp=root;
        for(auto iter=prefix.begin();iter!=prefix.end();++iter){
            if(tmp->next[*iter-'a']==NULL)return false;
            tmp=tmp->next[*iter-'a'];
        }
        return tmp!=NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */