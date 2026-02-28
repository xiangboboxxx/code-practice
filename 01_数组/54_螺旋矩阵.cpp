//时间复杂度O(m*n),空间复杂度O(1)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int k = m * n;
    
    //空间复杂度O(1)
    vector<int> result;
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    // 3.边界条件，唯一的允许条件
    while (top <= bottom && left <= right)
    {

        // left->right
        for (int i = left; i <= right; i++)
        {
            result.push_back(matrix[top][i]); // 行固定
        }
        top++;

        // top->bottom
        for (int i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]); // 列固定
        }
        right--;

        // right->left
        for (int i = right; i >= left; i--)
        {
            result.push_back(matrix[bottom][i]); // 行固定
        }
        bottom--;

        // bottom->top
        for (int i = bottom; i >= top; i--)
        {
            result.push_back(matrix[i][left]); // 列固定
        }
        left++;

        // //2.边界检查,证否很难，不满足的情况太多
        // if(bottom<=top&&left>=right)break;

        // 1.边界检查错误，可能导致填入重复元素
        //  if(result.size()==k){
        //      break;
        //  }
    }

    // output
    for (int i = 0; i < k; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}