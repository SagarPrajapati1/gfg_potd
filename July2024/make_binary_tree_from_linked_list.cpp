class Solution {
public:
    void convert(Node* head, TreeNode*& root) {
        if (head == NULL) {
            root = NULL;
            return;
        }

        root = new TreeNode(head->data);
        Node* temp = head->next;
        queue<TreeNode*> q;
        q.push(root);

        while (temp != NULL) {
            TreeNode* front = q.front();
            q.pop();

            TreeNode* lft = new TreeNode(temp->data);
            q.push(lft);

            TreeNode* rght = NULL;
            temp = temp->next; // Move to the next node in the list
            if (temp != NULL) {
                rght = new TreeNode(temp->data);
                q.push(rght);
                temp = temp->next; // Move to the next node in the list
            }

            front->left = lft;
            front->right = rght;
        }
    }
};
