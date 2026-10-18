
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
     ListNode *curr=head;
     ListNode *prev=NULL;
     
     while(curr!=NULL && curr->next!=NULL){
        if(curr->val==curr->next->val)
        {
            int x=curr->val;
        
            while(curr!=NULL && curr->val==x)
                curr=curr->next;
            if(prev==NULL)
            {
                head=curr;
            }
            else
            {
                prev->next=curr;
            }
        }
        
        else{
            prev=curr;
            curr=curr->next;
        }
            


     }
     return head;
    }
};

