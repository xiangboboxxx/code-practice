// Z字形O(m+n)
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

    int target;
    cin >> target;
    int result = 0;
    int i = 0, j = n - 1;
    while (i < m && j >= 0)  //路径最多（n-1）+（m-1）
    {
        if (matrix[i][j] > target)//向左，最多向左n-1
        {
            j--;
        }
        else if (matrix[i][j] < target)//向下,最多向下m-1
        {
            i++;
        }
        else
        {
            result = 1;
            break;
        }
    }

    cout << (result ? "true" : "false") << endl; // 三目运算

    return 0;
}

// //二分法O（mlogn)
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int>> matrix(m, vector<int>(n));
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> matrix[i][j];
//         }
//     }
//     int target;
//     cin >> target;

//     int min_j, k = 0;

//     for (int i = 0; i < m; i++)
//     {
//         int left = 0, right = n - 1;

//         while (left <= right)   //闭区间
//         {
//             min_j = left + (right - left) / 2;//安全模式，防止溢出
//             if (matrix[i][min_j] == target)
//             {
//                 k = 1;
//                 break;
//             }

//             else if (matrix[i][min_j] < target)
//             {
//                 left = min_j + 1;
//             }
//             else if (matrix[i][min_j] > target)
//             {
//                 right = min_j - 1;
//             }
//         }
//     }

//     if (k == 1)
//     {
//         cout << "true" << endl; // cout<<true;输出结果为“1”
//     }
//     else
//     {
//         cout << "false" << endl;
//     }

//     return 0;
// }