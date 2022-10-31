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
class Solution {
public:
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    ListNode *res, *n1=list1, *n2=list2;
    if(list1->val<=list2->val)
    {
        res=n1;
        n1=n1->next;
    }
    else
    {
        res=n2;
        n2=n2->next;
    }
    ListNode *cr=res;
    while(n1!=NULL && n2!=NULL)
    {
        if(n1->val<=n2->val)
        {
            cr->next=n1;
            cr=cr->next;
            n1=n1->next;
        }
        else
        {
            cr->next=n2;
            cr=cr->next;
            n2=n2->next;
        }
    }
    if(n1==NULL)
        cr->next=n2;
    else cr->next=n1;
    return res;
}
};