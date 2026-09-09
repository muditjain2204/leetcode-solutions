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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head-> next) 
        return head;

        ListNode dummy (0);
        dummy.next = head;
        ListNode* curr = head;

        while(curr && curr -> next){
            //if the next node is alreadty in order just move forward
            if(curr -> val <= curr -> next->val){
                curr = curr -> next;
            }else {
                //Remove the out of order node
                ListNode* toInsert = curr -> next;
                curr -> next = toInsert->next;

                //Find the insertion point starting from the dummy head;
                ListNode* prev  = &dummy;
                while(prev -> next -> val  < toInsert -> val){
                    prev = prev -> next;
                }

                //Splice toInsert between prev and prev->next
                toInsert -> next = prev-> next;
                prev->next = toInsert;
            }
        }
        return dummy.next;
    }
};