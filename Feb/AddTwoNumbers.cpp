// https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*tempa=l1;
        ListNode*tempb=l2;
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        int sum;
        int carry=0;
        while(tempa||tempb){
            sum=0;
            if(tempa){
                sum+=tempa->val;
                tempa=tempa->next;
            }
            if(tempb){
                sum+=tempb->val;
                tempb=tempb->next;
            }
            sum+=carry;
            carry=sum/10;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
        }
        if(carry!=0){
            temp->next=new ListNode(carry);
            return dummy->next;
        }
        return dummy->next;
    }
};