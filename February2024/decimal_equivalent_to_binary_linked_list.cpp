/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
           // Your Code Here
           
           Node * temp = head;
           
           long long unsigned int mod = 1e9+7;
           long long unsigned int ans = 0;
           
           while(temp != nullptr) {
               
            //   bool nodeData = temp -> data;
               ans = (ans * 2 + temp -> data)  % mod;
               temp = temp -> next;
           }
        //   cout << str << " " << endl;
            
            return ans;
           
        }
};
