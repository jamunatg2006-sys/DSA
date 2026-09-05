/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head){
        //SLOW FAST APPROCH METHOD
        ListNode *slow=head;
        ListNode*fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            //CONDITION WHEN MY FAST or last Node iS not pointing to null and where fast and slow becomes SAME SAME
            if(slow==fast){
                return true;//CYCLE EXIST CYCLE EXIST
            }

            
        }
        return false;
    }
};