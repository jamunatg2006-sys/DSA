/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */ 
 
class Solution 
{
public:
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
 {
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    //temp node to travserse
    ListNode* temp=list1;
    while(temp->next !=NULL)
    {
        temp=temp->next;
    }
    temp->next=list2;

    for(ListNode * i=list1 ;i!=NULL;i=i->next)
    {
        for(ListNode *j=i->next ;j!=NULL;j=j->next)
        {
            if(i->val > j->val){
                swap(i->val,j->val);
            }
        }
       
    }
    return list1;
  
    
}
};