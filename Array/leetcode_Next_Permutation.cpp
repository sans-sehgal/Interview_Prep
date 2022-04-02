// https://leetcode.com/problems/next-permutation/

void func(vector<int>& nums, int swap_id, int curr_id)
{
    swap(nums[swap_id] , nums[curr_id]);
    auto itr = nums.begin();
    while(swap_id>=0)
    {
        itr++;
        swap_id--;
    }
    sort(itr, nums.end());
    return;
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int swap_id = -1;
        int curr_id = -1;
        for(int i=nums.size()-1; i>0; i--)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(nums[j] < nums[i] && j>swap_id)
                {
                    swap_id = j;
                    curr_id = i;
                }
            }
        }
        if(swap_id!=-1)
        {
            func(nums, swap_id, curr_id);
            return;
        }
        sort(nums.begin() , nums.end());
    }
    
};