#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // For reverse function
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to return zigzag level order traversal of the binary tree
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;

    queue<TreeNode*> q; // Queue for level-order traversal
    q.push(root);
    bool leftToRight = true; // Flag to determine the direction of traversal

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            level.push_back(current->val);

            // Add child nodes to the queue
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        // Reverse the level order if the direction is right to left
        if (!leftToRight) {
            reverse(level.begin(), level.end());
        }
        result.push_back(level);

        // Toggle the direction for the next level
        leftToRight = !leftToRight;
    }

    return result;
}

// Driver code for testing
int main() {
    // Example: Create a binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Get the zigzag level order traversal
    vector<vector<int>> result = zigzagLevelOrder(root);

    // Print the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
