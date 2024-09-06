class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        //create a hash that stores all the values of the array for time efficiency
        unordered_map<int, int> hash;
        for(auto i: nums) {
            hash[i] = 1;
        }

        // create a previous node with a value 0 and point it to the head, in case head value exists in the array
        ListNode* list = head;
        ListNode* prev = new ListNode(0);
        prev->next = head;
        head = prev;
        //iterate the node list
        while(list) {
            // if the current value is equal to the value that exists in the array
            if(hash.find(list->val) != hash.end()) {
                //discard it by pointing the previous value to the currents next
                prev->next = list->next;
                list = prev->next;
            } else {
                prev = list;
                list = list->next;
            }
        }
        return head->next;
    }
};