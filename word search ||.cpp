class Solution {
public:
    #define len length()
    
    vector<string> ans;
    
    int n,m;
    
    bool check;
    
    inline bool valid(int i,int j){
        return (i>=0 and j>=0 and i<n and j<m);
    }
    
    void dfs(vector<vector<char>> &b,string &name,int i,int j,int k){
        if(!valid(i,j)) return ;
        if(b[i][j]!=name[k]) return ;
        if(k==name.len-1){
            check=true;
            return;
        }
        char tmp=b[i][j];
        b[i][j]='.';
        if(valid(i+1,j) and b[i+1][j]==name[k+1]){
            if(k+1==name.len){
                check=true;
                return;
            }
            else
                dfs(b,name,i+1,j,k+1);
        }
        if(valid(i-1,j) and b[i-1][j]==name[k+1]){
            if(k+1==name.len){
                check=true;
                return;
            }
            else
                dfs(b,name,i-1,j,k+1);
        }
            
        if(valid(i,j+1) and b[i][j+1]==name[k+1]){
            if(k+1==name.len){
                check=true;
                return;
            }
            else
                dfs(b,name,i,j+1,k+1);
        }
            
        if(valid(i,j-1) and b[i][j-1]==name[k+1]){
            if(k+1==name.len){
                check=true;
                return;
            }
            else
                dfs(b,name,i,j-1,k+1);
        }
        b[i][j]=tmp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size()==0 or board[0].size()==0)
            return ans;
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<words.size();k++){
                    if(board[i][j]==words[k][0]){
                        check=false;
                        dfs(board,words[k],i,j,0);
                        if(check){
                            ans.push_back(words[k]);
                            words.erase(words.begin()+k);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
