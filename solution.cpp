class TrieNode {
    public:
    char val;
    int count;
    unordered_map<char, TrieNode*> mp;
    bool isTerminal;

    TrieNode(char ch) {
        this->val = ch;
        this->count = 0;
        this->isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode(NULL);
    }

    void insert(string word) {
        int n = word.size();
        TrieNode* temp = root;

        for(int i = 0; i < n; i++) {
            char ch = word[i];
            if(temp->mp.find(ch) == temp->mp.end()) {
                temp->mp[ch] = new TrieNode(ch);
            }
            
            
            temp = temp->mp[ch];
            temp->count++;
            //cout << ch << " " << temp->count << " ";
        }
        temp->isTerminal = true;
    }

    int search(string word) {
        int n = word.size();
        TrieNode* temp = root;

        for(int i = 0; i < n; i++) {
            
            char ch = word[i];
            if(temp->mp.find(ch) == temp->mp.end()) {
                return false;
            }
            
            
            temp = temp->mp[ch];

            if(temp->count == 1) {
                return i;
            }
            
        }

        if(temp->isTerminal) {
            return true;
        }

        return false;
    }
};

vector<string> Solution::prefix(vector<string> &A) {
    int n = A.size();
    Trie *trie = new Trie();
    vector<string> res(n, "");

    for(int i = 0; i < n; i++) {
        trie->insert(A[i]);
    }

    for(int i = 0; i < n; i++) {
        int index = trie->search(A[i]);
        res[i] = A[i].substr(0, index+1);
    }

    return res;
}
