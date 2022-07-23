#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n=nums.size();
        vector<unordered_set<int>>graph(n+1);
        vector<int>indegree(n+1,0);
        for(vector<int>&sequence:sequences){
            for(int i=1;i<sequence.size();i++){
                int pre=sequence[i-1],next=sequence[i];
                graph[pre].emplace(next);
                indegree[next]++;
            }
        }
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            if(q.size()>1){
                return false;
            }
            int num=q.front();q.pop();
            for(int next:graph[num]){
                if(--indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return true;
    }
};

int main(){
    
    return 0;
}