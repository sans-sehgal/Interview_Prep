// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

void builder(int ind, vector <string> &ans, string &build, string arr[], string nums)
{
    if(build.length() >= nums.size() || ind>=nums.size())
    {
        if(build.length() == nums.size())
            ans.push_back(build);
        cout<<"returning"<<endl;
        return;
    }    
    int digit = nums[ind] - '0';
    for(auto ch: arr[digit])
    {
        build+=ch;
        cout<<build<<" first "<<ind<<endl;
        builder(ind+1, ans,build , arr,nums);
        build = build.substr(0, build.length() - 1);
      
        
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector <string> ans;

        if(digits == "" || digits == " ")
            return ans;
        // vector <string> ans;
        string build;
        string arr[] = {"0","1" , "abc" , "def" , "ghi" , "jkl", "mno" , "pqrs", "tuv" , "wxyz"};
        builder(0, ans, build, arr, digits);
        return ans;
    }
};