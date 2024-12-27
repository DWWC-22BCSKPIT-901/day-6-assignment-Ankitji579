#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to return the right-side view of a binary tree
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) return result;

    queue<TreeNode*> q; // Queue for level-order traversal
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            // If it's the last node at the current level, add it to the result
            if (i == levelSize - 1) {
                result.push_back(current->val);
            }

            // Add the child nodes to the queue
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    return result;
}

// Driver code for testing
int main() {
    // Example: Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    // Get the right-side view
    vector<int> result = rightSideView(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
