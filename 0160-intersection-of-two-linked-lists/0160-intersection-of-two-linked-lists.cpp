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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *ca=headA, *cb=headB;
    unordered_set<ListNode*> us;
    while(ca!=NULL)
    {
        us.insert(ca);
        ca=ca->next;
    }
    while(cb!=NULL)
    {
        if(us.find(cb)!=us.end())
            return cb;
        cb=cb->next;
    }
    return NULL;
}
};