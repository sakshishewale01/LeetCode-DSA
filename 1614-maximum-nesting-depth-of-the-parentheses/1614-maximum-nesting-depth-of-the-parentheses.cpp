class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxdepth = 0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                depth ++;
                
                    if(depth > maxdepth)
                    {
                        maxdepth = depth;
                    }
                
            }
            else if (s[i] == ')')
            {
                depth--;
            }
        }
        
        return maxdepth;
    }
};