https://www.codingninjas.com/codestudio/problems/count-inversions_615?leftPanelTab=0
long long merge(long long * arr, int start, int mid, int end)
{
    int temp[end-start+1];
    int i=start,j=mid+1,k=0;
    long long inv_count=0;
    while(i<=mid && j<=end)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    	else
        {
            temp[k] = arr[j];
            j++;
            k++;
            inv_count += mid - i + 1; 
        }
    	
    }
		while(i<=mid)
        { 
            temp[k] = arr[i];
    		k++;
    		i++;
        }
    
    	while(j<=end)
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
        
	for(int i=start; i<=end; i++)
        arr[i] = temp[i-start];
    return inv_count;
}

long long merge_sort(long long *arr, int start, int end)
{
    long long inv_count = 0;
    if(start < end)
    {
        int mid = (start+end)/2;
        inv_count = merge_sort(arr,start,mid) + merge_sort(arr,mid+1,end) + merge(arr,start,mid,end);
    }
	return inv_count;
}

long long getInversions(long long *arr, int n)
{
    return merge_sort(arr, 0, n-1);
}


