#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to build the tree recursively
TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
                          int preStart, int preEnd, 
                          int inStart, int inEnd, 
                          unordered_map<int, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    // Root value is the first element in preorder
    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    // Find the index of root in inorder array
    int inRoot = inMap[rootVal];
    int numsLeft = inRoot - inStart; // Number of nodes in the left subtree

    // Recursively build left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, 
                                 preStart + 1, preStart + numsLeft, 
                                 inStart, inRoot - 1, 
                                 inMap);
    root->right = buildTreeHelper(preorder, inorder, 
                                  preStart + numsLeft + 1, preEnd, 
                                  inRoot + 1, inEnd, 
                                  inMap);

    return root;
}

// Main function to build the tree
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap; // Map to store index of each value in inorder
    for (int i = 0; i < inorder.size(); ++i) {
        inMap[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, inorder, 
                           0, preorder.size() - 1, 
                           0, inorder.size() - 1, 
                           inMap);
}

// Function to print the tree in level-order for verification
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    vector<TreeNode*> level = {root};
    while (!level.empty()) {
        vector<TreeNode*> nextLevel;
        for (TreeNode* node : level) {
            if (node) {
                cout << node->val << " ";
                nextLevel.push_back(node->left);
                nextLevel.push_back(node->right);
            } else {
                cout << "null ";
            }
        }
        level = nextLevel;
    }
}

// Driver code
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);

    // Print the tree in level-order
    printLevelOrder(root);
    return 0;
}
