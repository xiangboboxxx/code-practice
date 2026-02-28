// 使用Kadane算法，解决最大子数组和问题的经典算法，局部最优+全局最优
#include <bits/stdc++.h>
using namespace std;
int main(){
    //input
    int n;
    cin >> n;
    vector<int> a(n); // 标准
    // int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //process
    long long maxsum = a[0]; // 防止溢出
    long long currentsum = a[0];
    for (int i = 1; i < n; i++) // ！！从1开始，避免重复计算9
    { 
        // 核心：要么从当前元素重新开始，要么继续累加
        currentsum = max((long long)a[i], currentsum + a[i]); // 强制转换，防止整数溢出
        maxsum = max(currentsum, maxsum);
    }

    //output
    cout << maxsum << endl;
    return 0;
}

// //时间复杂度大，使用双层for循环，AC:8 TLM:2 >=1100ms
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//
//     //input
//     int n;
//     cin>>n;
//     int a[n];
//     int max=INT_MIN;
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//         //scanf("%d",&a[i]);
//     }
//
//     //process
//     for(int i=0;i<n;i++){
//         int sum=0;//！在每层内循环结束后需要初始化
//         for(int j=i;j<n;j++){
//             sum+=a[j];
//             if(sum>=max)
//                 max=sum;
//         }
//     }
//
//     //output
//     //printf("%d",max);
//     cout<<max;
//     return 0;
// }