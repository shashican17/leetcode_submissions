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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode res;
        ListNode* temp = &res;
        while(1){
            bool flag = false;
            int value = INT_MAX;
            int j = 0;
            for(int i=0;i<n;i++){
                if(lists[i] && lists[i]->val < value){
                    value = lists[i]->val;
                    j = i;
                    flag = true;
                }
            }
            if(!flag){
                break;
            }
            temp->next = lists[j];
            lists[j] = lists[j]->next;
            temp = temp->next;
        }
        return res.next;
    }
};