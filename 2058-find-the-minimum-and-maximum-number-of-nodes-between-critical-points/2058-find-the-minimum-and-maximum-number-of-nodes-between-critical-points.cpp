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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr = head;
        vector<int> res;
        int min_dis = INT_MAX;
        int max_dis = INT_MIN;
        int max_pointer = INT_MAX;
        int min_pointer = INT_MAX;
        int i = 1;
        while (curr->next->next != nullptr) {
            if ((curr->next->val > curr->val &&
                 curr->next->val > curr->next->next->val) ||
                (curr->next->val < curr->val &&
                 curr->next->val < curr->next->next->val)) {
                    if(min_pointer!=INT_MAX){
                        min_dis = min(min_dis,i-min_pointer);
                    }
                    min_pointer = i;
                    if(max_pointer==INT_MAX){
                        max_pointer = i; 
                    }
                    max_dis = i-max_pointer;
            }
            curr = curr->next;
            i++;
        }
        if(min_dis==INT_MAX){
            min_dis = -1;
            max_dis= -1;
        }
        res.push_back(min_dis);
        res.push_back(max_dis);
        return res;
    }
};