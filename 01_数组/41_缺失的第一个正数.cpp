// // 原地翻转 时间O(n),空间O(1) 利用数组本身作为哈希表
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> nums[i];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) //边界条件
//         {
//             swap(nums[i], nums[nums[i] - 1]);
//         }
//     }
//     int missing = 1;//nums[i]>n

//     for (int i = 0; i < n; i++)
//     {
//         if (nums[i] != i + 1)
//         {
//             missing = i + 1;
//             break;
//         }
//     }

//     cout << missing << endl;

//     return 0;
// }

// 哈希表 时间复杂度O(n), 空间复杂度O(n)
// unordered_set hash_set,元素唯一，无序，快速查找
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_set<int> numSet;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            numSet.insert(nums[i]); // 插入元素
        }
    }

    int missing = 1;
    while (numSet.count(missing))//快速查找O(1)，集合中有则为1
    {
        missing++;
    }

    cout << missing;

    return 0;
}