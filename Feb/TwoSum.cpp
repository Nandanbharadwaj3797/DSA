//https://leetcode.com/problems/two-sum/description/

//Brute Force Approach
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target) return {i,j};
            }
        }
        return {};
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1)


// Optimized Approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            int rem=target-nums[i];

            if(mp.find(rem)!=mp.end()){
                ans.push_back(mp[rem]);
                ans.push_back(i);
            }
            else mp[nums[i]]=i;
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)