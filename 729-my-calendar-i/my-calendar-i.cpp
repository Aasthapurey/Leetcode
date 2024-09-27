class Node {
public:
    pair<int, int> val;
    Node* next;

    Node(int x, int y) {
        val.first = x;
        val.second = y;
        next = NULL;
    }

};

class MyCalendar {
    Node* head;

public:
    MyCalendar() { head = NULL; }

    bool book(int start, int end) {
        Node* temp = new Node(start, end);
        if (head == NULL) {
            head = temp;
            return true;
        }
   
        if (head->next == NULL) {
          
            if ((temp->val.first >= head->val.first &&
                 temp->val.first < head->val.second) ||
                (temp->val.second > head->val.first &&
                 temp->val.second <= head->val.second))
                return false;
            if (temp->val.first > head->val.first)
                head->next = temp;
            else
                temp->next = head, head = temp;
            return true;
        }
        Node* temp1 = head;
       
        Node* temp2 = head->next;
       
        if (temp->val.first < head->val.first && temp->val.second<=head->val.first) {
           
            temp->next = head, head = temp;
            return 1;
        }
        while (temp2) {
            if (temp->val.first>=temp1->val.second && temp->val.second <=temp2->val.first){
                temp1->next=temp;
                temp->next=temp2;
               return true;
            }
            temp2=temp2->next;
            temp1=temp1->next;
        }
       if(temp1->val.second <= temp->val.first){ temp1->next=temp ; return true;}
        
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */