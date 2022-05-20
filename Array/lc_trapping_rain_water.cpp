// https://leetcode.com/problems/trapping-rain-water/

class Solution {
    int trap(vector<int>& height) 
    {
        if(height.size()==1)
            return 0;
        int water = 0;
        int flag = 0;
        int y = 0;
        for(int i=0; i<height.size(); i++)
        {
            int sum_of_bar = 0;
            if(height[i] == 0)
            {
                continue;
            }
            int j = 0;
            flag = 0;
            int set = 0;
            int large = INT_MAX;
            if(i!=height.size()-1)
                large = *max_element(height.begin()+i+1 , height.end());
            if(large < height[i])
                set = 1;
            if(!set)
            {    
                // cout<<"here"<<endl;
                for(j = i+1; j<height.size(); j++)
                {
                    // cout<<"height in front is "<<height[j]<<endl;
                    // cout<<height[j]<<" ";

                    if(height[j] >= height[i])
                    {
                        if(j==i+1)
                            break;
                        // cout<<(j-i-1) * height[i] - sum_of_bar<<endl;
                        water+= (j-i-1) * height[i] - sum_of_bar;
                        flag = 1;
                        break;
                    }
                    sum_of_bar+=height[j];
                }
            }
            if(flag == 0 && j!=i+1)
            {
                // int net_large = *max_element(height.begin()+i+1 , height.end());
                sum_of_bar = 0;

                int net_large = *max_element(height.begin()+i+1 , height.end());
                for(j = i+1; j<height.size(); j++)
                {

                    if(height[j] == net_large)
                        break;
                    sum_of_bar+=height[j];
                }
                
                water+= (j-i-1) * height[j] - sum_of_bar;
                flag = 1;
                
            }
            if(flag == 1)
                i = j-1;
        }
        return water;
    }
};

