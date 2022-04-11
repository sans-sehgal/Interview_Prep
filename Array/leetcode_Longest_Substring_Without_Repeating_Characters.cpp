// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.empty())
            return 0;
        unordered_map <char , int> mp;
        int len = 0;
        vector <int> v;
        for(int i=0; i<s.length(); i++)
        {
            if(i==0)
            {
                v.push_back(i);
                mp[s[i]] = i;
                continue;
            }
            if(mp.count(s[i]))
            {
                v.push_back(min(i - mp[s[i]] - 1 , v.back() + 1));
                mp[s[i]] = i;
            }
            else
            {
                v.push_back(v.back() + 1);
                mp[s[i]] = i;
            }
        }
        return *max_element(v.begin() , v.end()) + 1 ;
    }
};