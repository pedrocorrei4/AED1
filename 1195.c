#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void preorder(Node* root) {
    if (root) {
        printf("%d", root->val);
        if (root->left || root->right) printf(" ");
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d", root->val);
        if (root->right) printf(" ");
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->val);
        if (root->left || root->right) printf(" ");
    }
}

void process_case(int case_number, int* numbers, int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, numbers[i]);
    }
    printf("Case %d:\n", case_number);
    printf("Pre.: "); preorder(root); printf("\n");
    printf("In..: "); inorder(root); printf("\n");
    printf("Post: "); postorder(root); printf("\n\n");
    
    free(root);
}

int main() {
    int C, N;
    scanf("%d", &C);
    for (int case_number = 1; case_number <= C; case_number++) {
        scanf("%d", &N);
        int numbers[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &numbers[i]);
        }
        process_case(case_number, numbers, N);
    }
    return 0;
}
