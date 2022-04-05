## Arrays – Important notes and Questions

1) How to pass a 2D array to function by value or by ref? <br>
 https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function

2) In vector: <br>
→ largest element is: *max_element(nums.begin() , nums.end()); <br>
→ smallest element is *min_element(nums.begin() , nums.end()); <br>
→ last element is given by nums.back();


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
 8) Insertion Sort
```
     //Pseudo Code
     INSERTION-SORT(A)
     for i = 1 to n
        key ← A [i]
        j ← i – 1
        while j > = 0 and A[j] > key
            A[j+1] ← A[j]
            j ← j – 1
        End while 
        A[j+1] ← key
      End for 
 ```
 ```
     void insertionSort(int *arr , int n)
    {
        for(int i=1; i<n; i++)
        {
            int key = arr[i];
            int j = i-1;
            while(j>=0 && arr[j] > key)
            {
                arr[j+1] = arr[j];
                j--;            
            }
            arr[j+1] = key;
        }
    }
 ```
9) Merge Sort 
```
    // this function just merges two arrays, remember merging sorted LL's

    void merge(int *arr, int start , int mid, int end)
    {
        int temp[end-start+1];
        int i = start, j=mid+1;
        int k=0;
        while(i<=mid && j<=end)
        {
            if(arr[i] < arr[j])
            {
                temp[k] = arr[i];
                i++;
                k++;
            }
            else if(arr[i] > arr[j])
            {
                temp[k] = arr[j];
                k++;
                j++;
            }
        }

        while(i <= mid)
        {
            temp[k] = arr[i];
            k++;
            i++;
        }

        while(j <= end)
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
        for(int i=start; i<=end; i++)
            arr[i] = temp[i-start];
    }

    void merge_sort(int *arr, int start, int end)
    {
        if(start < end)
        {
            int mid = (start + end) / 2;
            merge_sort(arr , start , mid);
            merge_sort(arr , mid+1 , end);
            merge(arr, start, mid, end);
        }
    }
```
10) Quicksort 
```
    /**
    * The function selects the last element as pivot element, places that pivot element correctly in the array in such a way
    * that all the elements to the left of the pivot are lesser than the pivot and
    * all the elements to the right of pivot are greater than it.
    * @Parameters: array, starting index and ending index
    * @Returns: index of pivot element after placing it correctly in sorted array
    */
    partition (arr[], low, high)
    {
        // pivot - Element at right most position
        pivot = arr[high];  
        i = (low - 1);  // Index of smaller element
        for (j = low; j <= high-1; j++)
        {
            // If current element is smaller than the pivot, swap the element with pivot
            if (arr[j] < pivot)
            {
                i++;    // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
    /**
    * The main function that implements quick sort.
    * @Parameters: array, starting index and ending index
    */
    quickSort(arr[], low, high)
    {
        if (low < high)
        {
            // pivot_index is partitioning index, arr[pivot_index] is now at correct place in sorted array
            pivot_index = partition(arr, low, high);

            quickSort(arr, low, pivot_index - 1);  // Before pivot_index
            quickSort(arr, pivot_index + 1, high); // After pivot_index
        }
    }
```
11) Quick Sort 
```
    FindMinIndex(Arr[], start, end)    
        min_index = start    
        FOR i from (start + 1) to end:    
            IF Arr[i] < Arr[min_index]:    
                min_index = i    
            END of IF    
        END of FOR        
        Return min_index

    SelectionSort(Arr[], arr_size):    
        FOR i from 1 to arr_size:    
            min_index = FindMinIndex(Arr, i, arr_size)    
        
            IF i != min_index:    
                swap(Arr[i], Arr[min_index])    
            END of IF    
        END of FOR
```
### Important Questions
* https://www.interviewbit.com/problems/flip/


