class Solution {
public:
    
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n,0);
        stack<int> S;
        int cnt = 1;
        for(int i=0;i<seq.size();i++){
            if(seq[i] == '('){
                S.push(i);
                cnt++;
            }
            else{
                ans[i] = cnt%2;
                ans[S.top()] = cnt%2;
                S.pop();
                cnt--;
            }
        }
        return ans;
    }
};

//Logic: If it is an even depth bracket, assign it to A, else assign it to B. 
//Using this alternating assigning logic to A or B, we achieve the minimum depth possible for max(depth(A),depth(B)).
