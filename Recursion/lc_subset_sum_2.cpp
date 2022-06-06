// https://leetcode.com/problems/subsets-ii/

void sub_sets(int id, vector <int> nums, vector<vector<int>> &subset, vector <int> subs)
{
  
    subset.push_back(subs);

    for(int i=id; i<nums.size(); i++)
    {
        if(i!=id && nums[i] == nums[i-1] ) continue;
        subs.push_back(nums[i]);
        sub_sets(i+1, nums, subset, subs);
        subs.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector <int> subs;
        vector<vector<int>> subset;
        sort(nums.begin(), nums.end());
        sub_sets(0,nums,subset,subs);
        
        return subset;
    }
};