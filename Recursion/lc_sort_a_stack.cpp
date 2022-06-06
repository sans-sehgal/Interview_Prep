// https://practice.geeksforgeeks.org/problems/sort-a-stack/1/?page=1&category[]=Recursion&sortBy=submissions

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insertElement(stack<int> &s, int elem)
{
    if(s.empty() || (!s.empty() && elem > s.top()))
    {    
        s.push(elem);
        return;
        
    }
    int topmost = s.top();
    s.pop();
    insertElement(s , elem);
    s.push(topmost);
}
void SortedStack :: sort()
{
   //Your code here
    if(s.size() == 1)
        return;
    int top_elem = s.top();
    s.pop();
    sort();
    if(top_elem > s.top())
    {
        s.push(top_elem);
    }
    else
    {
        insertElement(s , top_elem);
    }
}