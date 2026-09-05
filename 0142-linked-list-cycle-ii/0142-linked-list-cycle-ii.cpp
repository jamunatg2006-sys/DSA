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
    ListNode *detectCycle(ListNode *head)
    {
        //step 1 DETECT CYCLE EXIST OR NOT USING SLOW FAST APPROACH
        ListNode *slow=head;
        ListNode *fast=head;
         bool isCycle=false;

        while(fast!=NULL and fast->next !=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;

            //CYCLE FOUND
            if(slow==fast){
                 isCycle=true;
                break;
            }
        }
        if(!isCycle){
            return NULL;
        }

        //MAIN PART
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;//RETURNS THE START NODE OF THE CYCLE

        //IF WE WANT TO REMOVE THE CYCLE
        //EXTRA PART
        slow=head;
        ListNode *prev=NULL;
        while(slow!=fast){
            slow=slow->next;
            
            //main
            prev=fast;

            fast=fast->next;
        }
        prev->next=NULL;
        //tail is poinnting to null
        return slow;

    }
};