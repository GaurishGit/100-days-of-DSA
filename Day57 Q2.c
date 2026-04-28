void flatten(struct TreeNode* root) {
    if (root == NULL) return;

    flatten(root->left);
    flatten(root->right);

    struct TreeNode* leftSubtree = root->left;
    struct TreeNode* rightSubtree = root->right;

    root->left = NULL;
    root->right = leftSubtree;

    struct TreeNode* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }

    temp->right = rightSubtree;
}