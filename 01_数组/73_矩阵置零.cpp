// 标记法  空间复杂度O（1） 时间复杂度O(m*n)
//记录需要置零的行/列，额外使用两数组空间复杂度为O(m+n)
//优化：利用矩阵本身的闲置空间，使用第一行和第一列进行标记，记录需要清零的列和行O（1）
// 第一行和第一列可标记所有
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));

    // input
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    bool firstrow = false, firstcul = false;

    // 若第一行/列存在0，则在后续清零行/列
    // 处理行
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstcul = true;//！注意
            break;
        }
    }
    // 处理列
    for (int i = 0; i < n; i++)
    {
        if (matrix[0][i] == 0)
        {
            firstrow = true;//！注意
            break;
        }
    }

    // 利用第一行/列进行标记
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0; // 标记行
                matrix[0][j] = 0; // 标记列
            }
        }
    }

    // 根据标记置零
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            { // 包含若第一行/列含0，将对应的列/行清零
                matrix[i][j] = 0;
            }
        }
    }

    // 处理第一行
    if (firstrow)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }

    // 处理第一列
    if (firstcul)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }

    // output
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// //暴力解法：使用辅助矩阵  空间复杂度O(m*n)  时间复杂度O(m*n)
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     int nums[m][n];
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> nums[i][j];
//         }
//     }

//     vector<vector<int>> nums2(m, vector<int>(n, 1));
//     //初始化二维数组为1，使用辅助矩阵
//     //vector<int>(n,1) 一维数组n个元素，每个元素为1
//     //vector<vector<int>> nums(m,vector<int>(n,1)) 外层vector的名字和大小（m行）
//     //重复m行 vector<int>(n,1)[[1,1,1,1,..n个],[1,1,1,1..]...m行]

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (nums[i][j] == 0)
//             {
//                 for (int k = 0; k < n; k++)
//                     nums2[i][k] = 0;
//                 for (int k = 0; k < m; k++)
//                 {
//                     nums2[k][j] = 0;
//                 }
//             }
//             else
//             {
//                 if (nums2[i][j] != 0)
//                     nums2[i][j] = nums[i][j];
//             }
//         }
//     }

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << nums2[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }