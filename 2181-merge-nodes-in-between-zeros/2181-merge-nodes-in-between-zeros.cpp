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
        ListNode* res = new ListNode();
        ListNode* curr = head->next;
        ListNode* res_head = res;
        int flag = 0;
        while(curr!=nullptr){
        int temp = 0;
        while(curr->val!=0){
            temp += curr->val;
            curr= curr->next;
        }
        cout<<temp<<" ";
        if(!flag){
        res->val = temp;
        flag = !flag;
        }
        else{
res->next = new ListNode(temp);
        res = res->next;
        }
        curr = curr->next;
        }
        return res_head;
    }
};