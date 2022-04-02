## Arrays – Important notes and Questions

1) How to pass a 2D array to function by value or by ref?
 https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function

2) In vector → largest element is: *max_element(nums.begin() , nums.end());
	        → smallest element is *min_element(nums.begin() , nums.end());

3) to sort any array or vector → sort(arr, arr+n);
			           →sort(nums.begin(), nums.end());

4) Kedane’s algorithm for largest sum of contiguous array elements.
https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/#
```
 int maxSubArray(vector<int>& nums) 
    {
        int sum = 0;
        int largest_sum = 0;
        int large_elem = *max_element(nums.begin() , nums.end());
        if(large_elem < 0) return large_elem;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            if(sum<=0)
                sum = 0;
            if(sum > largest_sum)
                largest_sum = sum;
        }
        return largest_sum;
    }
```
https://www.interviewbit.com/problems/flip/


