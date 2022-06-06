// https://leetcode.com/problems/palindrome-partitioning/

bool isPalin(string str)
{
    int l = 0;
    int r = str.length() - 1;
    while(l<=r)
    {
        if(str[l] == str[r])
        {   
            l++;
            r--;
            continue;
        }
         else
            return false;
    }
    return true;
}

void substring(int ind, string s, vector<vector<string>> &final_ans, vector<string> parts )
{
    if(ind >= s.length())
    {
        final_ans.push_back(parts);
        return;
    }
    for(int i=ind; i<s.length(); i++)
    {
        string str;
        for(int j=ind; j<=i; j++)
            str+=s[j];
        if(isPalin(str))
        {
            parts.push_back(str);
            substring(i+1,s, final_ans,parts);
            parts.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> final_ans;
        vector<string> parts;
        substring(0,s, final_ans,parts);
        return final_ans;
        
    }
};