#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //input
    int n;
    cin>>n;
    vector<pair<int,int>> interval(n);  //支持排序、随机访问
    for(int i=0;i<n;i++){
        cin>>interval[i].first>>interval[i].second; //pair !(.second())
    }
    sort(interval.begin(),interval.end()); //排序是合并区间的前提
    
    vector<pair<int,int>> result;
    result.push_back(interval[0]);

    for(int i=1;i<n;i++){   //初始化int i=1
        if(result.back().second>=interval[i].first){
            result.back().second=max(result.back().second,interval[i].second);
        }
        else{
            result.push_back(interval[i]);
        }
    }

    //output
    for(int i=0;i<result.size();i++){
        cout<<result[i].first<<" "<<result[i].second<<endl;
    }
    return 0;
}