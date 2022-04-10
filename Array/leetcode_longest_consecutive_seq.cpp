// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        map<int,int> mp;
        for(auto i : nums)
            mp[i] = i;
        if(nums.size() == 0)
            return 0;
  
        int length_elems = 0;
        int largest_elems = 0;

        for(auto itr = mp.begin(); itr!=mp.end(); itr++)
        {

            int prev = itr->first;
            cout<<itr->first<<" ";
            auto temp = ++itr;
            if(temp==mp.end())
                {itr--;
                continue;}
            int net = (itr)->first;
            itr--;
            if(net - prev == 1)
                length_elems++;
            else
                length_elems = 0;
            if(largest_elems < length_elems)
                largest_elems = length_elems;
        }
        return largest_elems+1;
    }
};