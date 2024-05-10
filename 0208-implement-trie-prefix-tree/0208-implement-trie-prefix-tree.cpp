class Trie {
public:
        unordered_map<char,Trie*>m;
        bool is_end;
    Trie() {
    is_end =  false;
    }
    
    void insert(string word) {
        if(word.size()==0){
            return;
        }
        if(m.find(word[0])==m.end()){
            m[word[0]] = new Trie(); 
        }
        if(word.size()==1){
            m[word[0]]->is_end = true;
            return;
        }
        string new_word = word.substr(1,-word.size());
        m[word[0]]->insert(new_word);
    }
    
    bool search(string word) {
        if(word.size()==0){
            return true;
        }
        if(m.find(word[0])==m.end()){
            return false;
        }
        if(word.size()==1){
            if(m[word[0]]->is_end ==true){
                return true;
            }
            return false;
        }
        string new_word = word.substr(1,-word.size());
        return m[word[0]]->search(new_word);
    }
    
    bool startsWith(string word) {
           if(word.size()==0){
            return true;
        }
        if(m.find(word[0])==m.end()){
            return false;
        }
        if(word.size()==1){
            return true;
        }
        string new_word = word.substr(1,-word.size());
        return m[word[0]]->startsWith(new_word);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */