/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/
// 1st Solution
class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        // make two list of vowel and consonants
        Node* dummy1 = new Node(-1);
        Node* vowel = dummy1;
        Node* dummy2 = new Node(-1);
        Node* consonant = dummy2;
        
        Node* temp = head;
        if(head == NULL) return head;
        
        while(temp){
            if(temp -> data == 'a' || temp -> data == 'e' || 
                temp -> data == 'i'|| temp -> data == 'o' || 
                temp -> data == 'u'){
                    Node* newNode = new Node(temp -> data);
                    vowel -> next = newNode;
                    vowel = vowel -> next;
            }
            else {
                Node* newNode = new Node(temp -> data);
                consonant-> next = newNode;
                consonant = consonant -> next;
            }
            temp = temp -> next;
        }
        
        
        temp = new Node(-1);
        head = temp;
        
        temp -> next = dummy1 -> next;
        while(temp -> next) temp = temp -> next;
        temp -> next = dummy2 -> next;
        
        return head -> next;
    }
};



// 2nd Solution
class Solution {
  public:
    // Function to check if a character is a vowel
    bool isVowel(char x) {
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
    }

    // Function to rearrange the linked list based on vowels
    struct Node *arrangeCV(Node *head) {
        Node *newHead = head;
        Node *latestVowel;
        Node *curr = head;

        // Return NULL if the linked list is empty
        if (head == NULL)
            return NULL;

        // If the first node is a vowel, set it as the latest vowel
        if (isVowel(head->data))
            latestVowel = head;
        else {
            // Find the next vowel node or reach the end of the linked list
            while (curr->next != NULL && !isVowel(curr->next->data))
                curr = curr->next;

            // Return the head if no vowel node is found
            if (curr->next == NULL)
                return head;

            // Set the next vowel node as the latest vowel
            latestVowel = newHead = curr->next;
            curr->next = curr->next->next;
            latestVowel->next = head;
        }

        // Iterate through the linked list to rearrange nodes
        while (curr != NULL && curr->next != NULL) {
            // If the next node is a vowel
            if (isVowel(curr->next->data)) {
                // If curr is the latest vowel, move the latestVowel pointer
                if (curr == latestVowel)
                    latestVowel = curr = curr->next;
                else {
                    // Rearrange the nodes
                    Node *temp = latestVowel->next;
                    latestVowel->next = curr->next;
                    latestVowel = latestVowel->next;
                    curr->next = curr->next->next;
                    latestVowel->next = temp;
                }
            }
            // Move to the next node
            else
                curr = curr->next;
        }
        return newHead;
    }
};

// 3rd Solution
class Solution {
public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    bool isVowel(char x)
    {
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o'
                || x == 'u');
    }

    struct Node* arrangeCV(Node* head)
    {
        // Code here
        vector<char> v;
        Node* head1 = head;

        while (head != NULL) {

            if (isVowel(head->data)) {
                v.push_back(head->data);
            }

            head = head->next;
        }

        head = head1;

        while (head != NULL) {

            if (!isVowel(head->data)) {
                v.push_back(head->data);
            }

            head = head->next;
        }

        Node* newHead1 = new Node('a');
        Node* newHead = new Node('a');
        newHead = newHead1;

        for (int i = 0; i < v.size(); i++) {
            Node* temp = new Node(v[i]);

            newHead1->next = temp;
            newHead1 = newHead1->next;
        }

        return newHead->next;
    }
};
