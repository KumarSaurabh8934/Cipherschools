class Solution {
public:
    struct Node{
      Node* children[27];
        bool isEnd;
        Node(){
            for(int i = 0;i<27;i++){
                children[i] = NULL;
            }
            isEnd = false;
        }
    };

    void insert(Node* root, string s, bool allowed[]){
        Node* t = root;
        for(int i = 0;i<s.length();i++){
            allowed[s[i] - 'a'] = true; 
            if (t->children[s[i] - 'a'] == NULL){
                t->children[s[i] - 'a'] = new Node();
            }
            t = t->children[s[i] - 'a'];
        }
        t->isEnd = true;
    }
    void update(list<pair<Node*,int>>& activeList, string& s, int& ind, bool& ans, vector<string> ansList[]){
        auto n = activeList.begin();
        while(n != activeList.end()){
            int search = s[ind-1] - 'a';
            if ((*n).first->children[search] != NULL){
                (*n).first = (*n).first->children[search];
                if ((*n).first->isEnd){
                    int prevInd = ind - (*n).second -1;
                    string formed = s.substr(prevInd, (*n).second) + s[ind-1];
                    ans = true;
    
                    for(auto i = ansList[prevInd].begin();i != ansList[prevInd].end();i++){
                        if ((*i) == ""){
                            ansList[ind].push_back(formed);
                        } else{
                            ansList[ind].push_back((*i) + " " + formed);
                        }
                    }
                }
                (*n).second++;
                ++n;                
            } else {
                n = activeList.erase(n);
            }  
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        bool allowed[27] = {false};
        Node* root = new Node();
        for(string s : wordDict){
            insert(root,s,allowed);
        }
        int l = s.length();
        for(char c : s){
            if (!allowed[c - 'a']){
                return {};
            }
        }
        list<pair<Node*,int>> activeList;
        vector<string> ansList[l+1];
        ansList[0].push_back("");
        bool lastResult = true;
        for(int i = 1;i<=l;i++){
            bool ans = false;
            if (lastResult) {
                activeList.push_back({root,0});
            }
            
            update(activeList, s, i, ans, ansList);
            if (activeList.empty()){
                
                return {};
            }
            lastResult = ans;
        }
        return ansList[l];
    }
};
