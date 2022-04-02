// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& m) 
    {

        reverse(m.begin() , m.end());
        for(int i=0; i<m.size(); i++)
        {
            for(int j=0; j<m[0].size(); j++)
            {
                if(i!=j)
                {
                    swap(m[i][j], m[j][i]);
                }
                else if(i==j)
                    break;
            }
        }
    }
};