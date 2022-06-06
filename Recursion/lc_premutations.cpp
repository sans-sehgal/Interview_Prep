// https://practice.geeksforgeeks.org/viewSol.php?subId=879b3f3734afdba2b3a979e0631b925f&pid=703569&user=sanskaarsehgal0099

class Solution
{
	public:
		static void permutations(string s, vector<char>str, vector<string> &permutes, map<int,int>&mp, map<string,int>& new_mp)
		{
		    if(str.size() == s.length())
		    {
		        
		        string str_new;
		        for(auto i:str)
		        {
		           str_new+=i;
		        }
		        if(new_mp[str_new] == 0)
		        {
		            permutes.push_back(str_new);
		            new_mp[str_new]++;
		            
		        }
		        
		    }
		    for(int i=0; i<s.length(); i++)
		    {
		      //  if(i!=0 && s[i]==s[i-1])continue;
		        if(mp[i] == 0)
		        {
		            mp[i] = 1;
		            str.push_back(s[i]);
		            permutations(s, str, permutes, mp,new_mp);
		            mp[i] = 0;
		            str.pop_back();
		        }
		    }
		    
		}
		
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<char>str;
		    vector<string> permutes; 
		    map<int,int>mp;
		    map<string,int>new_mp;
		    permutations(S, str, permutes, mp, new_mp);
		    sort(permutes.begin() , permutes.end());
		    return permutes;
		}
};
