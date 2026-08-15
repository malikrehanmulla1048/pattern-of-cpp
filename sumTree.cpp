#include <iostream>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int sumTree(TreeNode* root) {
    if (!root) return 0;
    return root->val + sumTree(root->left) + sumTree(root->right);
}
int main()
{
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Calculate the sum of all nodes in the tree
    int totalSum = sumTree(root);
    cout << "Sum of all nodes in the tree: " << totalSum << endl;

    // Clean up memory (delete nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}