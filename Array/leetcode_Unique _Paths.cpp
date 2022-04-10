// https://leetcode.com/problems/unique-paths/

long long int factorial(int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    return factorial(n-1) * n;
}
class Solution {
public:
    int uniquePaths(int m, int n) 
    {

        if(n>m) swap(n,m);
        int numer = m+n-2, denom1 = m-1, denom2 = 1; 
        long long result = 1;
        while(numer > denom1)
        {
            result*=numer;
            numer--;
            if(denom2 <= n-1)
            {
                result/=denom2;
                denom2++;
            }
                
        }
        return result;
    }
};