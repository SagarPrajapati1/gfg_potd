class Solution
{   private:
    void insertAtTail(struct Node*&head, struct Node*&tail, int digit){
        
        // create Node for sum
        struct Node* newNode = new Node(digit);
        
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        
        Node *firstHead = first;
        Node *secondHead = second;
        int carry = 0;
        
        // create andHead and ansTail for the ans list
        Node *ansHead = NULL;
        Node *ansTail = NULL;
        
        while(firstHead != NULL || secondHead != NULL || carry != 0){
        
            // find first value
            int value1 = 0;
            if(firstHead != NULL)
                value1 = firstHead -> data;
        
            // find second value
            int value2 = 0;
            if(secondHead != NULL) 
                value2 = secondHead -> data;
            
            // find sum
            int sum = value1 + value2 + carry;
            
            // find digit
            int digit = sum % 10;
            
            // create a node for ans;
            insertAtTail(ansHead, ansTail, digit);            
            
            // update carry
            carry = sum / 10;
            
            // update firstHead
           if(firstHead  != NULL) firstHead = firstHead -> next;
           
           // update secondHead
           if(secondHead != NULL) secondHead = secondHead -> next;
        }
        return ansHead;
    }
    struct Node *reverse(struct Node *head){
	    Node *curr = head;
	    Node *prev = NULL;
	    Node *next = NULL;
	    while(curr != NULL){
		    next = curr->next;
		    curr->next = prev;
	        prev = curr;
		    curr = next;
	    }
	    return prev;
    }
    struct Node* removeZero(Node* head1){
        Node* head = head1;
        while(head -> data == 0 && head -> next) head = head -> next;
        // if(head == NULL){
        //     Node* newNode = new Node(0);
	       // return newNode;
        // }
        return head;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {   
        //Step-1 reverse Lists
	    first = reverse(first);
	    second = reverse(second);

	    //Step-2 add lists
	    Node *ans = add(first, second);
	    Node* temp =  (reverse(ans));
	    return removeZero(temp);
	    
	    
    }
};
