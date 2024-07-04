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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* mod = head;
            int temp = 0;
        while(curr!=nullptr){
            temp = 0;
            while(curr->val!=0){
                temp+=curr->val;
                curr = curr->next;
                
            }
           
            mod->val = temp;
            curr = curr->next;
            if(curr==nullptr){
                break;
            }
            mod = mod->next;
        }
        mod->next = nullptr;
        return head;
    }
};