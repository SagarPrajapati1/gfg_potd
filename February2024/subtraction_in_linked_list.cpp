class Solution {
public:

    // int makeNumber(Node* head) {
        
    //     int ans = 0;
    //     if(head == nullptr) return 0;
        
    //     Node* temp = head;
        
    //     while(temp != nullptr) {
    //         ans = ans*10 + temp -> data;
    //         temp = temp -> next;
    //     }
    //     return ans;
        
        
    // } 
    
    // Node* makeLinkedList(int num) {
          
    //     int n = num;
        
    //     int value = 0;
        
    //     Node* head = nullptr;
    //     Node* tail = head;
        
    //     while(n > 0){
            
    //         int rem = n%10;
            
    //         if(head == nullptr){
    //             head = new Node(rem);
    //             tail = head;
    //         }
    //         else {
    //             tail = new Node(rem);
    //             tail = tail -> next;
    //         }
            
    //         n /= 10;
    //     }
    //     return head;
    // }
    
    
    
    int length(Node* head){
        Node* temp =head;
        if(temp == nullptr) return 0;
        
        int cnt = 0;
        
        while(temp != nullptr) {
            cnt++;
            temp = temp -> next;
        }
        return cnt;
    }
    
    
    Node* removeZeros(Node* head) {
        Node* temp = head;
        if(temp == nullptr) return temp;
        
        while(temp && temp -> data == 0) temp = temp -> next;
        return temp;
    }
    
    Node* reverse(Node* head){
        
        Node* temp = head;
        
        if(head == nullptr) return nullptr;
        
        Node* curr = temp;
        Node* currNext = nullptr;
        Node* prev = nullptr;
        
        while(curr != nullptr) {
            currNext = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = currNext;
        }
        
        return prev;
        
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        
        if(head1 == nullptr || head2 == nullptr) return NULL;
        
        // remove leading zeros
        
        head1 = removeZeros(head1);
        head2 = removeZeros(head2);
        
        // find length
        
        int len1 = length(head1);
        int len2 = length(head2);
        
        
        if(len1 < len2) 
        {
            swap(head1, head2);
        }
        else if(len1 == len2) 
        {
            Node* c1 = head1, *c2 = head2;
            
            while(c1 && c2 && c1 -> data == c2 -> data){
                c1 = c1->next;
                c2 = c2->next;
            }
            
            if(c1 == nullptr && c2 == nullptr) return new Node(0);
            if(c1->data < c2->data) swap(head1, head2);
            
        }
        
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        Node* d = new Node(-1);
        
        Node* curr = d;
        
        int carry = 0;
        
        while(head1!= NULL && head2 != NULL)
        {
            int d1 = head1->data-carry;
            int d2 = head2->data;
            
            int value;
            if(d1>=d2)
            {
                value = d1-d2;
                carry = 0;
            }
            else 
            {
                value = d1+10-d2;
                carry = 1;
            }
            
            curr -> next = new Node(value);
            curr = curr -> next;
            
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        while(head1 != NULL)
        {
            int d1 = head1 -> data - carry;
            
            if(d1 < 0)
            {
                d1 = d1 + 10;
                carry = 1;
            }
            else 
            {
                carry = 0;
            }
            curr -> next = new Node(d1);
            curr = curr -> next;
            head1 = head1 -> next;
        }
        
        Node *res = d -> next;
        res = reverse(res);
        res = removeZeros(res);
        return res;
        
        
    }
};
