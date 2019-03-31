#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct treeNode{
    int key;
    struct treeNode *left;
    struct treeNode *right;
};
typedef struct treeNode treeNode;
treeNode* Insert (treeNode* currentNode, int key)
{
    if(currentNode==NULL)
    {
        treeNode *temp;
        temp = (treeNode *)malloc(sizeof(treeNode));
        temp->key = key;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if(key >(currentNode->key)){
        currentNode->right = Insert(currentNode->right,key);
    }else if(key < (currentNode->key)){
        currentNode->left = Insert(currentNode->left,key);
    }
    return currentNode;
}


treeNode * Find(treeNode * currentNode, int key){
    if(currentNode ==NULL){
    // Element is not found
    return NULL;
}
    printf("Access node %d \n", currentNode->key);
    if(key > currentNode->key){
        return Find(currentNode->right , key);
    }else if(key < currentNode->key){
        return Find(currentNode->left , key);
        
    }else{
        // Element Found
        return currentNode;
    } }

treeNode* FindMin(treeNode *currentNode){
    if(currentNode==NULL){
        return NULL;
    }
    if(currentNode->left != NULL)
        return FindMin(currentNode->left);
    else
        return currentNode;
}

treeNode* FindMax(treeNode *currentNode){
    if(currentNode==NULL){
        return NULL;
    }
    if(currentNode->right != NULL)
        return FindMax(currentNode->right);
    else
        return currentNode;
}

int main(){
    treeNode *root = NULL;
    int i;
    for (i=1; i<=10000 ; i++){
        root = Insert(root,i);
    }
    int searchItem = 10000;
    treeNode *temp = Find(root,searchItem);
    if(temp==NULL)
        printf("Element %d not found\n",searchItem);
    else
        printf("Element %d Found\n",searchItem);
    
}
