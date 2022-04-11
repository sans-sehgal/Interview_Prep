// https://www.codingninjas.com/codestudio/problems/920321?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
int LongestSubsetWithZeroSum(vector < int > arr) 
{

  // Write your code here
	int abs_ma = 0;
	for(int i=0; i<arr.size(); i++)
	{
		int sum = arr[i];
		int curr_length = 1, ma_length = 0;
		ma_length = sum == 0? 1 : 0; 
		for(int j=i+1; j<arr.size(); j++)
		{

			sum += arr[j];
			curr_length++;
			if(sum == 0 && ma_length < curr_length)
				ma_length = curr_length;			
				
		}
		if(ma_length > abs_ma)
			abs_ma = ma_length;
	}
// 	cout<<abs_ma;
	return abs_ma==0 ?  0 :  abs_ma;
}

// much better silution 
#include <unordered_map>
int LongestSubsetWithZeroSum(vector < int > arr) 
{
//   Write your code here
	unordered_map <int,int> mp;
	int max_length = 0 , sum = 0;
	for(int i=0; i<arr.size(); i++)
	{
		sum+=arr[i];
		if(sum==0)
			max_length = i+1;
		else if(arr[i]==0 && max_length == 0)
			max_length =1;
		if(mp.count(sum))
			max_length = max(max_length , i-mp[sum]);
		else
			mp[sum] = i;
	}
	return max_length;
	
}