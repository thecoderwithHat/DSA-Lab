#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int height(struct Node *root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
void currlevel(struct Node *root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        currlevel(root->left, level - 1);
        currlevel(root->right, level - 1);
    }
}


struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    return root;
}
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
void preorder(struct Node* root){
    if(root != NULL){
       
    
        
        printf("%d,",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root){
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d,",root->data);
    }
    
}
void levelOder(struct Node* root){
    int h = height(root);
    for (int i = 1; i <= height; i++)
    {
        currlevel(root,i);
    }
    
}

int main()
{
    struct Node *root = NULL;

    root = insertNode(root, 50);
    insertNode(root, 20);
    insertNode(root, 100);
    insertNode(root,45);
    insertNode(root,67);

    //inorderTraversal(root);
   // preorder(root);
   // postorder(root);
   levelOder(root);

}