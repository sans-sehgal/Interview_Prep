#include <bits/stdc++.h>
using namespace std; 

int min_index(int *arr, int start, int end)
{
	int min = INT_MAX; 
	int idc = start; 
	for(int i= start; i<end; i++)
	{
		if(arr[i] < min)
		{
			min = arr[i];  
			idc = i;
		}
	}
	return idc;
}

void selectionSort(int *arr , int start, int end)
{
	for(int i=start; i<end; i++)
	{
		int idc = min_index(arr, i , end);
		if(i!=idc)
		{
			swap(arr[i] , arr[idc]);
		}
	}

}


int main()
{
	int arr[] = {14, 7, 3, 12, 9, 11, 6, 2};
	selectionSort(arr, 0, 8);
	for(int i=0; i<8; i++)
		cout<<arr[i]<<" ";
}