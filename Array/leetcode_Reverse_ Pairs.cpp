// https://leetcode.com/problems/reverse-pairs/

int merge(vector <int> &v, int start, int mid, int end)
{
    int count = 0;
    int temp[end-start+1];
    int i=start,j = mid + 1, k=0;
    while(i<=mid && j<=end)
    {
        if((long) v[i]> (long) 2*v[j])
        {
            count += mid - i + 1;
            j++;
        }
        else
            i++;
    }
    sort(v.begin() + start, v.begin() + end + 1);
    return count;
}
int merge_sort(vector<int> &v, int start, int end)
{
    int count = 0;
    if(start < end)
    {
        int mid = (start+end)/2;
        count =  merge_sort(v, start, mid) + merge_sort(v, mid+1, end) + merge(v, start, mid,end);
    }
    return count;
}

class Solution {
public:
    int reversePairs(vector<int>& arr) 
    {
        
        return merge_sort(arr , 0, arr.size() - 1);
        
    }
};