// https://leetcode.com/problems/merge-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        int last=i+j-1;
        i=i-1;
        j=j-1;
       while(i+1>0 && j+1>0){
            if(nums1[i]>nums2[j]){
                nums1[last]=nums1[i];
                i--;
            }
            else{
                nums1[last]=nums2[j];
                j--;
            }
            last--;
       }
       while(j+1>0){
        nums1[last]=nums2[j];
        j--;
        last--;
       }
    }
};