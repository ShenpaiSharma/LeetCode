#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryS(vector<int> v,int s,int l,int x);
    int countNegatives(vector<vector<int>>& v);
};

int Solution::binaryS(vector<int> v,int s,int l,int x){
    if(s <= l){
        int mid = (s+l)/2;
        if(x == v[mid]){
            return mid;
        }
        else if(x > v[mid]){
            return binaryS(v,s,mid-1,x);
        }
        else return binaryS(v,mid+1,l,x);
    }
    return -1;
}

int Solution::countNegatives(vector<vector<int>> &v){
    int m = v[0].size()-1;
    int ans = 0;
    for(int i=0;i<v.size();i++){
        auto it = lower_bound(v[i].rbegin(),v[i].rend(),0);
    	ans += v[i].size()-1 - binaryS(v[i],0,m,*it);
    }	
    return ans;
}

int main() {
    int n,r;
    cin>>n>>r;
    vector<vector<int>> v;
    v.resize(n,vector<int>(r,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            cin>>v[i][j];
        }
    }
    Solution S;
    cout<<S.countNegatives(v);
	return 0;
}
