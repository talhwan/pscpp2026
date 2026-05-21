#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(const vector<int> &nodes, int index)
{
    if (index >= nodes.size() || nodes[index] == 0)
        return nullptr;
    TreeNode *root = new TreeNode(nodes[index]);
    root->left = buildTree(nodes, 2 * index + 1);
    root->right = buildTree(nodes, 2 * index + 2);
    return root;
}

void inorder(TreeNode *root, bool &first)
{
    if (!root)
        return;
    inorder(root->left, first);
    if (!first)
        cout << " ";
    cout << root->val;
    first = false;
    inorder(root->right, first);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nodes(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nodes[i];
    }

    TreeNode *root = buildTree(nodes, 0);

    bool first = true;
    inorder(root, first);
    cout << endl;

    return 0;
}