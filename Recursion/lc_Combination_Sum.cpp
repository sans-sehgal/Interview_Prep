// https://leetcode.com/problems/combination-sum/

void subset_sum(int id, vector<vector<int>> &target_sum, int target, vector <int> carry, vector<int>c, int sum)
{
    if(id>=c.size() || sum>=target)
    {
        if(target==sum)
            target_sum.push_back(carry);
        return;
    }
    carry.push_back(c[id]);
    sum+=c[id];
    subset_sum(id, target_sum, target, carry, c, sum);
    carry.pop_back();
    sum-=c[id];
    subset_sum(id+1, target_sum, target, carry, c,sum);
}


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> target_sum;
        vector <int> carry;
        subset_sum(0, target_sum, target, carry, candidates,0);
        return target_sum;
    }
};