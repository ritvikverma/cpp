#include "stdio.h"
#include "stdlib.h"
#define DEBUG 0
struct treeNode{
    int key;
    struct treeNode * left;
    struct treeNode * right;
};
typedef struct treeNode treeNode;

int maximum(int a, int b){
    return (a > b ? a : b);
}

int get_height(treeNode *currentNode){
    if(currentNode == NULL)
        return -1;
    else{
        int height = 1 + maximum(get_height(currentNode->left) , get_height(currentNode->right));
        return height;
    }
}

int get_balance(treeNode *currentNode){
    if(currentNode == NULL)
        return 0;
    else
        return (get_height(currentNode->left) - get_height(currentNode->right));
}

treeNode* R_rotation(treeNode* parent)
{
    #if DEBUG
        printf("R_rotation on %d\n", parent->key);
    #endif
    treeNode *child = parent->left;
    parent->left = child->right;
    child->right = parent;
    return child;
}

treeNode* L_rotation(treeNode *parent){
    #if DEBUG
        printf("L_rotation on %d\n", parent->key);
    #endif
    treeNode *child = parent->right;
    parent->right = child->left;
    child->left = parent;
    return child;
}

treeNode* LR_rotation(treeNode *parent){
    #if DEBUG
        printf("LR_rotation on %d\n", parent->key);
    #endif
    treeNode *child = parent->left;
    parent->left= L_rotation(child);
    return R_rotation(parent);
}

treeNode* RL_rotation(treeNode *parent){
#if DEBUG
    printf("RL_rotation on %d\n", parent->key);
#endif
    treeNode *child = parent->right;
    parent->right= R_rotation(child);
    return L_rotation(parent);

}

treeNode* balance_tree( treeNode * currentNode ){
    int height_diff = get_balance( currentNode );
    if( height_diff > 1 ){
        if(get_balance( currentNode -> left ) > 0){
            // Case 1 Right rotation
            currentNode = R_rotation(currentNode);
        }else{
            // Case 3 Double rotation: Left + Right
            currentNode = LR_rotation(currentNode );
        }
    }else if( height_diff < -1 ){
        if(get_balance( currentNode ->right ) < 0){
            // Case 2 Left rotation
            currentNode = L_rotation(currentNode);
        }else{
            // Case 4 Double rotation: Right + Left
            currentNode = RL_rotation(currentNode );
        } }
    return currentNode ;
}

treeNode* Insert(treeNode *currentNode ,int key){ if(currentNode == NULL){
#if DEBUG
    printf("Added key %d\n",key);
#endif
    currentNode = (treeNode*)malloc(sizeof(treeNode)); currentNode ->key = key;
    currentNode ->left = currentNode ->right = NULL;
}else if(key > currentNode ->key){
    currentNode ->right = Insert(currentNode ->right, key);
    currentNode = balance_tree( currentNode );
}else if(key < currentNode ->key){
    currentNode ->left = Insert(currentNode ->left,key);
    currentNode = balance_tree( currentNode );
}else{
    printf("fail! - duplicated key\n");
    exit(-1);
}
    return currentNode ;
}

treeNode * Find(treeNode * currentNode, int key){
    if(currentNode==NULL){
        /* Element is not found */
        return NULL;
    }
    printf("Access node %d \n", currentNode->key);
    if(key > currentNode->key){
        /* Search in the right sub tree. */
        return Find( currentNode->right , key );
    }else if(key < currentNode->key){
        /* Search in the left sub tree. */
        return Find( currentNode->left , key );
    }else{
        /* Element Found */
        return currentNode;
    } }

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
    
    
