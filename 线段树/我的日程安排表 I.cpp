#include<bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    unordered_set<int>tree,lazy;
    MyCalendar() {

    }
    bool query(int start,int end,int l,int r,int idx){
        if(l>end||r<start){
            return false;
        }
        if(lazy.count(idx)){//该区间已被预订
            return true;
        }
        if(start<=l&&end>=r){
            return tree.count(idx);
        }
        int m=l+(r-l)/2;
        return query(start,end,l,m,idx*2)||query(start,end,m+1,r,idx*2+1);
    }

    void update(int start,int end,int l,int r,int idx){
        if(l>end||r<start){
            return;
        }
        if(l>=start&&r<=end){
            tree.emplace(idx);
            lazy.emplace(idx);
        }else{
            int m=l+(r-l)/2;
            update(start,end,l,m,idx*2);
            update(start,end,m+1,r,idx*2+1);
            tree.emplace(idx); 
            if(lazy.count(2*idx)&&lazy.count(2*idx+1)){
                lazy.emplace(idx);
            }
        }
       
    }

    bool book(int start, int end) {
        if(query(start,end-1,0,1e9,1)){
            return false;
        }
        update(start,end-1,0,1e9,1);
        return true;
    }
};


int main(){

    return 0;
}
