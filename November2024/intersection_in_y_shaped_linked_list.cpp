/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        Node* nodeA = head1; Node* nodeB = head2;
        while(nodeA != nodeB) {
            nodeA = nodeA->next==nullptr? head2 : nodeA->next;
            nodeB = nodeB->next == nullptr ? head1 : nodeB->next;
        }
        return nodeA->data;
    }
};
