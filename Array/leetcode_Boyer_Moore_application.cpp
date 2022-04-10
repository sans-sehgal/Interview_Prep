// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        int count1 = 1;
        int major_elem1 = nums[0];
        int count2 = 0, major_elem2 = 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == major_elem1)
                count1++;
            else if(nums[i] == major_elem2)
                count2++;
            else if(count1 == 0)
            {
                major_elem1 = nums[i];
                count1++;
            }
            else if(count2 == 0)
            {
                major_elem2 = nums[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector <int> vec;
        // vec.push_back(major_elem1);
        // vec.push_back(major_elem2);
        // return vec;
        count1 = 0, count2 = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == major_elem1)
                count1++;
            else if(nums[i] == major_elem2)
                count2++;
        }
        if(count1 > n/3)
           vec.push_back(major_elem1);
        if(count2 > n/3)
           vec.push_back(major_elem2);
        return vec;
    }
};