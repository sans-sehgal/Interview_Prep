// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector <vector <int>> vec;
        for(int i=1; i<=numRows; ++i)
        {
            vector<int> v;
            if(i==1)
            {
                v.push_back(1);
                vec.push_back(v);
                continue;
            }
            else if(i==2)
            {
                v.push_back(1);
                v.push_back(1);
                vec.push_back(v);
                continue;
            }
            else
            {
                // cout<<"here";
                v.push_back(1);
                // cout<<vec[i-2].size();
                for(int j=0; j<vec[i-2].size()-1; j++)
                {
                    cout<<"now";
                    int sum = 0;
                    sum = vec[i-2][j] + vec[i-2][j+1];
                    cout<<sum;
                    v.push_back(sum);
                }
                v.push_back(1);
                vec.push_back(v);
            }
            
        }
        
        return vec;
    }
};