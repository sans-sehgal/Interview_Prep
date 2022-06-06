https://practice.geeksforgeeks.org/problems/subset-sums2234/1

class Solution
{
public:
    
    static int sum(vector<int> v)
    {
        int sum = 0;
        for(auto i : v)
            sum+=i;
        return sum;
    }
    static void sub_sum(int id, int N, vector <int> subarray, vector<int> arr, vector<int> &sum_vec)
    {
        if(id>=N)
        {
            sum_vec.push_back(sum(subarray));
            // for(auto i: subarray)
            //     cout<<i<<" ";
            return;
        }
        // cout<<arr[id]<<" ";
        subarray.push_back(arr[id]);
        sub_sum(id+1, N , subarray, arr, sum_vec);
        subarray.pop_back();
        sub_sum(id+1, N , subarray, arr, sum_vec);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector <int> sum_vec;
        vector <int> subarray;
        sub_sum(0,N,subarray,arr,sum_vec);
        // for(auto i: sum_vec)
        //     cout<<i<<" ";
        // sort(sum)
        return sum_vec;
    }
};