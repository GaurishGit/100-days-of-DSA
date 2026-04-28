int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    int capacity = 100;
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        if (*returnSize >= capacity) {
            capacity *= 2;
            result = (int**)realloc(result, sizeof(int*) * capacity);
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * capacity);
        }

        int size = rear - front;

        result[*returnSize] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[*returnSize] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            result[*returnSize][i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        (*returnSize)++;
    }

    return result;
}