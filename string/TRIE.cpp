#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    vector<int> child;
    bool isWord = false;
    TrieNode() : child(26,-1){}
};

vector<TrieNode> trie(1);

void insert(string S) {
    int cur = 0;
    for(int i=0; i<s.length(); i++){
        if(trie[cur].child[s[i]-'a'] == -1){
            trie[cur].child[s[i]-'a'] = trie.size();
            trie.emplace_back();
        }
        cur = trie[cur].child[s[i]-'a'];
    }
    trie[cur].isWord = 1;
}

bool lookup(string s){
    int cur = 0;
    for(int i=0; i<s.length(); i++){
        if(trie[cur].child[s[i]-'a'] == -1)return 0;
        cur = trie[cur].child[s[i]-'a'];
    }
    return trie[cur].isWord;
}
