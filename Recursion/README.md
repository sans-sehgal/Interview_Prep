## Recursion – Important notes and Questions

1) A subarray is a contiguous part of array. An array that is inside another array. For example, consider the array [1, 2, 3, 4], There are 10 non-empty sub-arrays. The subarrays are (1), (2), (3), (4), (1,2), (2,3), (3,4), (1,2,3), (2,3,4) and (1,2,3,4).<br>

2) A subsequence is a sequence that can be derived from another sequence by removing zero or more elements, without changing the order of the remaining elements. 
For the same example, there are 15 sub-sequences. They are (1), (2), (3), (4), (1,2), (1,3),(1,4), (2,3), (2,4), (3,4), (1,2,3), (1,2,4), (1,3,4), (2,3,4), (1,2,3,4). More generally, we can say that for a sequence of size n, we can have (2n-1) non-empty sub-sequences in total. <br>

3) A subarray or substring will always be contiguous, but a subsequence need not be contiguous. <br>

4) A subset is all subsequences + an empty set. <br>

5) Code to generate all subsets (the power set):
```
void sub_sets(int id, vector <int> nums, vector<vector<int>> &subset, vector <int> subs)
{
  
    subset.push_back(subs);

    for(int i=id; i<nums.size(); i++)
    {
        subs.push_back(nums[i]);
        sub_sets(i+1, nums, subset, subs);
        subs.pop_back();
    }
}

Input: [1,2,2]

Output: [[],[1],[1,2],[1,2,2],[1,2],[2],[2,2],[2]]

Note: Notice that similar elements leads to same subsets being printed multiple times.

```
6) code to generate all unique subsets : 
```
void sub_sets(int id, vector <int> nums, vector<vector<int>> &subset, vector <int> subs)
{
  
    subset.push_back(subs);

    for(int i=id; i<nums.size(); i++)
    {
        if(i!=id && nums[i] == nums[i-1] ) continue;
        subs.push_back(nums[i]);
        sub_sets(i+1, nums, subset, subs);
        subs.pop_back();
    }
}

Input: [1,2,2]

Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

```
7) Code to generate subsets using pick/ not-pick technique :
```
void subset(int id, int N, vector <int> subarray, vector<int> arr, vector<int> &ans)
{
    if(id>=N)
    {
        ans.push_back(subarray);
        return;
    }
    subarray.push_back(arr[id]);
    subset(id+1, N , subarray, arr, ans);
    subset.pop_back();
    sub_sum(id+1, N , subarray, arr, ans);
}

Input: [1,2,2]

Output: [[],[1],[1,2],[1,2,2],[1,2],[2],[2,2],[2]]
```

