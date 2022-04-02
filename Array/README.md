## Arrays – Important notes and Questions

1) How to pass a 2D array to function by value or by ref? <br>
 https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function

2) In vector: <br>
→ largest element is: *max_element(nums.begin() , nums.end()); <br>
→ smallest element is *min_element(nums.begin() , nums.end()); <br>
-> last element is given by nums.back();


3) to sort any array or vector: <br>
→ sort(arr, arr+n); <br>
→ sort(nums.begin(), nums.end());

4) Passing comparator to sort function: <br>
```
    bool comperator(int a ,int b)
    {
        return a > b;
    }
    void merge(vector<int>& intervals) 
    {
        sort(intervals.begin() , intervals.end() , comperator);
        // sort function will now sort in descending order. 
    }
```

5) To reverse a vector: <br>
-> reverse(m.begin() , m.end());

6) Kedane’s algorithm for largest sum of contiguous array elements. <br>
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
7) Sieve of Eratosthenes
```
    int countPrimes(int n) 
    {
        if (n == 0 || n == 1)
        {
            return 0;
        }
        int arr[n];
        int count = 0;
        for(int i=0; i<n; i++)
            arr[i] = 1;
        arr[0] = 0;
        arr[1] = 0;
        for (int i=2; i<n; i++)
        {
            if(arr[i]==1)
            {
                for(int j=2; i*j<n; j++)
                {
                    arr[j*i] = 0;
                }
            }

        }
        for(int i=0; i<n; i++)
            if(arr[i] == 1)
                count++;
    return count;
    }
    
```
 

### Important Questions
* https://www.interviewbit.com/problems/flip/


