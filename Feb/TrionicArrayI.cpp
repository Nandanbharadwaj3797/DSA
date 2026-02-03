// https://leetcode.com/problems/trionic-array-i/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 1;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        int p = i - 1;
        if (p == 0) return false;   

        
        while (i < n && nums[i - 1] > nums[i]) {
            i++;
        }
        int q = i - 1;
        if (q == p) return false;   

        
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        int flag = i - 1;

        
        return (flag == n - 1 && flag != q);
    }
};
