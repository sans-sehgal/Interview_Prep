// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1/?page=1&category[]=Recursion&sortBy=submissions

void delete_elem(stack<int>&s, int mid)
{
    if(mid == 0)
    {    
        s.pop();
        return;
    
    }
    int top_elem = s.top();
    s.pop();
    delete_elem(s, mid-1);
    s.push(top_elem);
    
}

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        int mid;
        if(sizeOfStack%2 == 0)
            mid = (sizeOfStack+1)/2;
        else
            mid = (sizeOfStack+1)/2 -1;
        delete_elem(s, mid);
    }
};