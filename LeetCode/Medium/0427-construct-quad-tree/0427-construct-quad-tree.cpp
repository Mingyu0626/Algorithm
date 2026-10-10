/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        Node* node = new Node();
        split(node, grid, 0, 0, grid.size());
        return node;
    }

    void split(Node* node, vector<vector<int>>& grid, int r, int c, int s) {
        for (int i = r; i < r + s; ++i) {
            for (int j = c;  j < c + s; ++j) {
                if (grid[r][c] != grid[i][j]) {
                    node->val = true;
                    int newS = s / 2;
                    node->topLeft = new Node();
                    split(node->topLeft, grid, r, c, newS);

                    node->topRight = new Node();
                    split(node->topRight, grid, r, c + newS, newS);

                    node->bottomLeft = new Node();
                    split(node->bottomLeft, grid, r + newS, c, newS);

                    node->bottomRight = new Node();
                    split(node->bottomRight, grid, r + newS, c + newS, newS);

                    return;
                }
            }
        }
        node->isLeaf = true, node->val = grid[r][c];
    }
};