#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
class BinarySearchTree{
public:
    TreeNode* root;
private:
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }
public:
    BinarySearchTree() : root(nullptr) {}
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void preorder(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(TreeNode* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void create_tree(vector<int>& values) {
        for (int val : values) {
            root = insert(root, val);
        }
    }
    
    bool search(TreeNode* node, int val){
        if(node == nullptr) return false;
        if(node->data == val) return true;
        if(val < node->data) return search(node->left,val);
        return search(node->right,val);
    }
    void delete_tree(TreeNode* node) {
        if (node == nullptr) return;
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }


    TreeNode* min_value_node(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }


    TreeNode* delete_node(TreeNode* root, int val) {
        if (root == nullptr) return root;
        if(root->data > val){
            root->left = delete_node(root->left, val);
        } else if(root->data < val){
            root->right = delete_node(root->right, val);
        } else {
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = min_value_node(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
        return root;
    }
    void inorder_to_array(TreeNode* node, vector<int>& arr) {
        if (node == nullptr) return;
        inorder_to_array(node->left, arr);
        arr.push_back(node->data);
        inorder_to_array(node->right, arr);
    }
    vector<int> merge_sorted_arrays(vector<int>& arr1, vector<int>& arr2) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                merged.push_back(arr1[i]);
                i++;
            } else {
                merged.push_back(arr2[j]);
                j++;
            }
        }
        while (i < arr1.size()) {
            merged.push_back(arr1[i]);
            i++;
        }
        while (j < arr2.size()) {
            merged.push_back(arr2[j]);
            j++;
        }
        return merged;
    }
    TreeNode* create_balanced_bst(vector<int>& arr, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = create_balanced_bst(arr, start, mid - 1);
        node->right = create_balanced_bst(arr, mid + 1, end);
        return node;
    }
    
    TreeNode* merge_binary_trees(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1;
        vector<int> arr2;
        inorder_to_array(root1, arr1);
        inorder_to_array(root2, arr2);
        vector<int> merged_arr = merge_sorted_arrays(arr1, arr2);
        TreeNode* new_root = create_balanced_bst(merged_arr, 0, merged_arr.size() - 1);
        return new_root;
    }
     
};
     



int main() {
    BinarySearchTree bst;
    vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    bst.create_tree(values);
    cout << "Inorder Traversal: ";
    bst.inorder(bst.root);
    cout << endl;
    int search_val = 1;
    if(bst.search(bst.root, search_val)){
        cout << search_val << " found in the tree." << endl;
    } else {
        cout << search_val << " not found in the tree." << endl;
    }
    cout << "Preorder Traversal: ";
    bst.preorder(bst.root);
    cout << endl;
    cout << "Postorder Traversal: ";
    bst.postorder(bst.root);
    cout << endl;
    return 0;
}