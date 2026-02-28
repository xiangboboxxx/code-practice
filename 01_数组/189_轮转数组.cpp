// 反转数组
#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &nums, int k)//&直接修改原数组
{ 
    int n = nums.size();
    k = k % n; // 处理K大于n的情况
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k); //翻转前k个nums[0]-nums[k-1]
    reverse(nums.begin() + k, nums.end());  //索引k至最后一个
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n); // 创建n个元素的对象，无（n）表示创建空vector，需要push
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    
    reverseArray(nums, k);
    
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    
    return 0;
}

// //分段输出
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,k;
//     cin>>n;
//     int nums[n];
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     int x;
//     cin>>x;
//     for(int i=n-x;i<n;i++){//边界条件
//         cout<<nums[i]<<" ";
//     }
//     for(int i=0;i<n-x;i++){
//         cout<<nums[i]<<" ";
//     }
//     return 0;
// }