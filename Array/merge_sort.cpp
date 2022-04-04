#include <bits/stdc++.h>
using namespace std;

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




int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr,0,n-1);
    for(int i=0; i<n; i++)
    	cout<<arr[i]<<" ";
    return 0;
}