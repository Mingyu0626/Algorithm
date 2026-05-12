/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root != nullptr) {
            connectLeft(root->left, root);
            connectRight(root->right, root);
        }
        return root;
    }

    void connectLeft(Node* cur, Node* parent) {
        if (cur == nullptr) {
            return;
        }
        cur->next = parent->right;
        if (cur->left == nullptr) {
            return;
        }
        connectLeft(cur->left, cur);
        connectRight(cur->right, cur);
    }

    void connectRight(Node* cur, Node* parent) {
        if (cur == nullptr) {
            return;
        }
        if (parent->next != nullptr) {
            cur->next = parent->next->left;
        }
        connectLeft(cur->left, cur);
        connectRight(cur->right, cur);
    }   
};