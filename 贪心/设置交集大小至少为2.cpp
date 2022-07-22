#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](vector<int>a,vector<int>b){
            return a[1]<b[1];
        });
        int a=intervals[0][1]-1,b=intervals[0][1],ans=2;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>b){
                ans+=2;
                a=intervals[i][1]-1,b=intervals[i][1];
            }else if(intervals[i][0]==b){
                ans+=1;
                a=b,b=intervals[i][1];
            }else if(intervals[i][0]>a){
                ans+=1;
                a=b-1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>>nums={{4,7},{5,8},{7,9},{2,6},{0,1},{1,4},{1,9},{0,5},{5,10},{7,8}};
    s.intersectionSizeTwo(nums);
    return 0;
}