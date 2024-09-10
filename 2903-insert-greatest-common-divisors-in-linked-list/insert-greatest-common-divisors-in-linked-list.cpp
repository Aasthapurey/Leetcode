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
    // GCD FUNCTION
     int gcd(int a, int b) {
    
    while (b != 0) {
        int temp = b;
        b = a % b;  
        a = temp;
    }
    return a; 
}

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* p = head;

    while (p != nullptr && p->next != nullptr) {
        ListNode* q = p->next;         
        int gcd_value = gcd(p->val, q->val); //Using STL, 
        ListNode* temp = new ListNode(gcd_value);  
        p->next = temp;                
        temp->next = q;                
        p = q;                        
    }

    return head;

    }
};