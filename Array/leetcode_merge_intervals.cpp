// https://leetcode.com/problems/merge-intervals/submissions/
// Custom comperator is not reqd here  
bool comperator(vector<int>a , vector<int> b)
{
    if(a[0]<b[0]) return true;
    else if(a[0] == b[0]) return a[1]<b[1];
    else return false;
}
vector<vector<int>> merge_intervals(vector<vector<int>> intervals)
{
    vector<vector<int>> new_intervals;
        
        int flag=0;
        for(int i=0; i<intervals.size()-1; i++)
        {
            vector <int> vec;

            if(flag==1)
            {
                flag = 0;
                continue;
            }
            if(intervals[i][1] >= intervals[i+1][0])
            {
                vec.push_back(intervals[i][0]);
                if(intervals[i+1][1] > intervals[i][1])
                    vec.push_back(intervals[i+1][1]);
                else
                    vec.push_back(intervals[i][1]);
                new_intervals.push_back(vec);
                // i+=1;
                flag=1;
            }
            else
                new_intervals.push_back(intervals[i]);
        
        }
        if(flag==0)
            new_intervals.push_back(intervals[intervals.size()-1]);
        return new_intervals;
}

bool check_intervals(vector<vector<int>> intervals)
{
    for(int i=0; i<intervals.size()-1; i++)
    {
        if(intervals[i][1] >= intervals[i+1][0])
        {
            return false;
        }
    }
    return true;
}
    
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        
        sort(intervals.begin() , intervals.end());
        while(!check_intervals(intervals))
        {
            intervals = merge_intervals(intervals);
        }
        
        return intervals;

    }
};

//Another much easier solution 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
       
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            if(output.back()[1] >= intervals[i][0]) output.back()[1] = max(output.back()[1] , intervals[i][1]);
            else output.push_back(intervals[i]); 
        }
        return output;
    
    }
};