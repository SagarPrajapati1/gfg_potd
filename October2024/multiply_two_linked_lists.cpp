/* Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/* Multiply contents of two linked lists */
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long num1 = 0;
        long long num2 = 0;
        long long MOD = 1e9+7;
        
        Node*head1 = first;
        
        Node*head2 = second;
        
        while(head1){
            int val = head1 -> data;
            num1 = (num1*10 + val) % MOD;
            head1 = head1 -> next;
        }
        
        
        while(head2){
            int val = head2 -> data;
            num2 = (num2*10 + val) % MOD;
            head2 = head2 -> next;
        }
        
        long long fVal = (num1 * num2) % MOD;
        
        return fVal;
        
    }
};
