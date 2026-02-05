// https://leetcode.com/problems/transformed-array/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);

        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                ans[i] = nums[i];
            }else if(nums[i] > 0){
                int r = i , k = nums[i];
                while(k--){
                    r = (r+1)%n;
                }
                ans[i] = nums[r];
            }else{
                int l = i , k = abs(nums[i]);
                while(k--){
                    if(l-1 == -1){
                        l = n-1;
                        continue;
                    }
                    l = (l-1)%n;
                }
                ans[i] = nums[l];
            }
        }
        return ans;
    }
};