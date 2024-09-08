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
    int lengthLL(ListNode* head){
        if(head == NULL) return 0;
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, NULL);
        int len = lengthLL(head);
        int baseSize = len/k;
        int extra = len%k;

        ListNode* cur = head;
        for(int i = 0; i<k; i++){
            ListNode* partHead = cur;
            int partSize = baseSize+(extra>0?1:0);
            extra--;

            for(int j = 1; j<partSize; j++){
                if(cur){
                    cur = cur->next;
                }
            }
            if(cur){
                ListNode* nextPartHead = cur->next;
                cur->next = NULL;
                cur = nextPartHead;
            }
            ans[i] = partHead;
        }
        return ans;
    }
};