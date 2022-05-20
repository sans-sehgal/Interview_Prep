// https://leetcode.com/problems/remove-duplicates-from-sorted-array/class Solution {

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int swap_id = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] != nums[i-1])    
            {
                nums[swap_id] = nums[i];
                swap_id++;
            }
        }
        return swap_id;
    }
};