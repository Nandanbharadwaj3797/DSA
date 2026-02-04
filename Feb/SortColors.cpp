//https://leetcode.com/problems/sort-colors/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
    // int n=nums.size();
    // int noz=0;
    // int noo=0;
    // int notw=0;
    // for(int i=0;i<n;i++){
    //     if(nums[i]==0) noz++;
    //     else if (nums[i]==1) noo++;
    //     else notw++;
    // }
    // for(int i=0;i<n;i++){
    //     if(i<noz)  nums[i]=0;
    //     else if(i<noz+noo) nums[i]=1;
    //     else   nums[i]=2;
    // }
    // return;

    //dutch flag algorithm

    int lo=0;
    int mid=0;
    int hi=nums.size()-1;
    while(mid<=hi){
        if(nums[mid]==2){
            int temp=nums[mid];
            nums[mid]=nums[hi];
            nums[hi]=temp;
            hi--;
        }
        else if(nums[mid]==0){
            int temp=nums[mid];
            nums[mid]=nums[lo];
            nums[lo]=temp;
            lo++;
            mid++;
        }
        else mid++;
    }
    return;
    }
};