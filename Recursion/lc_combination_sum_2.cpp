// https://leetcode.com/problems/combination-sum-ii/

void subsetSum(vector <int> c, int ind, int target, vector<int>subset, vector<vector<int>> &final_ans)
{
    if(ind>c.size() || target<=0)
    {
        if(target==0)
            final_ans.push_back(subset);
        return;
    }
    
    for(int i=ind; i<c.size(); i++)
    {
        if(i!=ind && c[i]==c[i-1])
            continue;
        if(c[i] > target) break;
        subset.push_back(c[i]);
        subsetSum(c,i+1,target-c[i],subset,final_ans);
        subset.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) 
    {
        sort(c.begin(), c.end());
        vector<int>subset;
        vector<vector<int>> final_ans;
        subsetSum(c,0,target,subset,final_ans);
        return final_ans;
        
    }
};