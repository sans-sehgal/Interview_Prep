// https://leetcode.com/problems/3sum/

void twoSum(unordered_map<int,int> mp , int num ,map <vector<int> , int> &vec_map)
{
    // vector <vector <int> > vec;
    vector <int> v;
    // map <vector<int> , int> vec_map;
    // cout<<num<<" "<<mp[-1*num]<<endl;
    for(auto itr: mp)
    {
        // cout<<"considering"<<" "<<itr.first<<" "<<itr.second<<endl;
        if(itr.second == 0)
            continue;
        int req = num - itr.first;
        
        if(mp.count(req))
        {
            
            if(mp[req]==0)
                continue;
            if(req == itr.first && itr.second<2)
            {    
            // cout<<"yooo"<<" "<<itr.first<<endl;
                continue;
            }
            v.push_back((-1*num));
            v.push_back(itr.first);
            v.push_back(req);
            // cout<<(num)<<" "<<itr.first<<" "<<req<<endl;
        }
        if(v.size() == 3){
            sort(v.begin() , v.end());
            vec_map[v]++;            
        }
        v.clear();
    }
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        unordered_map <int,int> mp;
        vector <vector<int>> final_vec;
        map <vector<int> , int> vec_map;
        for(auto i : nums)
        {
            mp[i]++;
        }
        for(auto itr : mp)
        {
            int num = itr.first;
            mp[itr.first]--;
            twoSum(mp, (-1*itr.first) , vec_map);
            mp[itr.first]++;
        }
      
        for(auto i : vec_map)
                final_vec.push_back(i.first);
        return final_vec;
    }
};