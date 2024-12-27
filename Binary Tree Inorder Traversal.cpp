#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function for inorder traversal
void inorderHelper(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    inorderHelper(root->left, result);  // Traverse the left subtree
    result.push_back(root->val);       // Visit the current node
    inorderHelper(root->right, result); // Traverse the right subtree
}

// Function to return inorder traversal of a binary tree
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderHelper(root, result);
    return result;
}

// Driver code for testing
int main() {
    // Example: Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Get the inorder traversal
    vector<int> result = inorderTraversal(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
