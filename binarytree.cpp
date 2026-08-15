#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
int height(Node* root) {
    // base case: empty tree
    if (root == nullptr) {
        return 0;
    }

    // recursively compute heights of left and right subtrees
    int leftHeight  = height(root->left);
    int rightHeight = height(root->right);

    // height at current node = max of subtree heights + 1 (for current node)
    int currHeight = max(leftHeight, rightHeight) + 1;
    return currHeight;
}

int countNodes(Node* root) {
    // base case: empty tree
    if (root == nullptr) {
        return 0;
    }

    // count in left and right subtrees
    int leftCount  = countNodes(root->left);
    int rightCount = countNodes(root->right);

    // total count = left + right + 1 (current node)
    int totalCount = leftCount + rightCount + 1;
    return totalCount;
}

int sumOfNodes(Node* root) {
    // base case: empty tree
    if (root == nullptr) {
        return 0;
    }

    // sum in left and right subtrees
    int leftSum  = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

    // total sum = left + right + current node data
    int totalSum = leftSum + rightSum + root->data;
    return totalSum;
}
int static ans = 0;
int diameterOFN(Node* root) {
    // base case: empty tree
    if (root == nullptr) {
        return 0;
    } 
    // compute heights of left and right subtrees
    int leftHeight  = height(root->left);
    int rightHeight = height(root->right);

    // compute diameters of left and right subtrees
    int leftDiameter  = diameterOFN(root->left);
    int rightDiameter = diameterOFN(root->right);

    // diameter at current node = max of:
    // 1. diameter in left subtree
    // 2. diameter in right subtree
    // 3. height of left subtree + height of right subtree + 1 (for current node)
    int currDiameter = max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
    return currDiameter;
}
void topView(Node* root, int level, int hd, map<int, pair<int, int>>& m)
{
    // base case: empty tree
    if (root == nullptr) {
        return;
    }

    // if this horizontal distance is not already present in the map,
    // add it with the current node's data and level
    if (m.find(hd) == m.end()) {
        m[hd] = {root->data, level};
    } else {
        // if this horizontal distance is already present, check if the current node is at a higher level
        if (level < m[hd].second) {
            m[hd] = {root->data, level};
        }
    }

    // recursively call for left and right subtrees with updated level and horizontal distance
    topView(root->left, level + 1, hd - 1, m);
    topView(root->right, level + 1, hd + 1, m);
}
void topView2(Node* root)
{
    queue<pair<Node* , int>> q; // queue to store nodes along with their horizontal distance
    map<int, int> m; // map to store the first node at each horizontal distance
    q.push({root,0});
    
    while(!q.empty()) {
        pair<Node*, int> p = q.front();
        q.pop();
        Node* node = p.first;
        int hd = p.second;

        if (m.find(hd) == m.end()) {
            m[hd] = node->data;
        }

        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    for (const auto& p : m) {
        cout << p.second << " ";
    }
}
int main() {
    // construct sample tree:
    //        1
    //       / \
    //      2   3
    //         / \
    //        4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    cout << "Height of tree: " << height(root) << "\n";
    cout << "Count of nodes: " << countNodes(root) << "\n";
    cout << "Sum of nodes: " << sumOfNodes(root) << "\n";

    return 0;
}