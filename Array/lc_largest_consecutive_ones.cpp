// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int curr_nums = 0, high_nums = 0;
        for(auto i : nums)   
        {
            if(i==1)
                curr_nums++;
            else
            {
                // cout<<i<<" "<<"here"<<endl;
                high_nums = curr_nums > high_nums? curr_nums : high_nums;
                curr_nums = 0;
            }
        }
        high_nums = curr_nums > high_nums? curr_nums : high_nums;
        return high_nums;
    }
};