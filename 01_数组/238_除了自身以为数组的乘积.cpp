// 前缀积+后缀积
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

    vector<int> answer(n, 1); // 初始化

    // 计算左边乘积
    int left = 1;
    for (int i = 0; i < n; i++)
    {
        answer[i] = left;
        left *= nums[i]; // updata left
    }

    // 计算右边乘积，乘入answer
    int right = 1;
    for (int i = n - 1; i >= 0; i--)  //注意边界条件
    { 
        answer[i] *= right;
        right *= nums[i]; // updata right
    }

    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}

// 暴力解法O（n^2)   TLE:3
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

    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        int mul = 1;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
                mul *= nums[j];
        }
        array[i] = mul;
    }

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}