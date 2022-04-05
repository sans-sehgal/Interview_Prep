#include <bits/stdc++.h>
using namespace std; 

int pivot_elem(int *arr, int low, int high)
{
	int pivot = arr[high];
	int j = low-1;
	for(int i=low; i<high; i++)
	{
		if(arr[i] < pivot)
		{
			j++; 
			swap(arr[i] , arr[j]);
		}
	}
	swap(arr[j+1] , arr[high]);

	return (j+1);
}

void quicksort(int *arr, int low, int high)
{
	if(low < high)
	{
		int pivot = pivot_elem(arr, low, high);
		quicksort(arr,low,pivot-1);
		quicksort(arr,pivot+1, high);

	}
}

int main()
{
	int arr[] = {14, 7, 3, 12, 9, 11, 6, 2};
	quicksort(arr, 0, 7);
	for(int i=0; i<8; i++)
		cout<<arr[i]<<" ";

}