class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        vector<int> len;
        for(int i=0; i<strs.size(); ++i)
        {
            len.push_back(strs[i].length());
        }
        if(strs.size() == 1)
        {   
            s = strs[0];
            return s;
        }
        else if(strs.size() == 0)
        {
            s = "";
            return s;
        }
        else
        {    
            s = strs[0];
            for(int i=1; i<strs.size(); ++i)
            {
                int j = 0;
                while(s[j] == strs[i][j] && j < (s.length() <= len[i] ? s.length() : len[i]))
                {
                    j++;
                }
                s.resize(j);
                if(s.size() == 0)
                {
                    break;
                }
            }
            return s;
        }
    }
};
