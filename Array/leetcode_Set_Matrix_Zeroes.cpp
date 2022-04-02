// https://leetcode.com/problems/set-matrix-zeroes/

void set_row_null(int row, int col, vector<vector <int>> &m , int **arr)
{
    int cols = m[0].size();
    if(m[row][col] == 0)
    {
        for(int i=0; i<cols; i++)
        {
            if(m[row][i]!=0)
            {
                m[row][i] = 0;
                arr[row][i] = 0;
        
            }
    
        }

    }
}
void set_col_null(int row, int col, vector<vector <int>> &m, int **arr)
{
    int rows = m.size();
    if(m[row][col] == 0)
    {
        for(int i=0; i<rows; i++)
        {
            if(m[i][col]!=0)
            {
                m[i][col] = 0;
                arr[i][col] = 0;
            }
        }
    }
}

class Solution {
public:
    void setZeroes(vector<vector<int>>& m) 
    {
        int rows = m.size();
        int cols = m[0].size();
        int **arr;
        arr = new int*[rows];
        for(int i=0; i<rows; i++)
            arr[i] = new int[cols];
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                arr[i][j]=-1;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(m[i][j] == 0 && arr[i][j]!=0)
                {
                    set_row_null(i , j , m, arr);
                    set_col_null(i , j , m, arr);
                }
            }
        }
    }
};