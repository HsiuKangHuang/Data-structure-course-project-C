#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node *tree_pointer;
typedef struct node {
	int data;
	tree_pointer left, right;
} node;

void printPostorder(tree_pointer node)
{
  if (node == NULL)
     return;
 
  /* first recur on left child */
  printPostorder(node->left);
 
  /* now recur on right child */
  printPostorder(node->right);
  
  /* then print the data of node */
  printf("%c", node->data);
  
}

int search(char arr[], int strt, int end, char value);
tree_pointer newNode(char data);

tree_pointer buildTree(char in[], char pre[], int inStrt, int inEnd)
{
  static int preIndex = 0;
 
  if(inStrt > inEnd)
     return NULL;
 
  /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
  tree_pointer tNode = newNode(pre[preIndex++]);
 
  /* If this node has no children then return */
  if(inStrt == inEnd)
    return tNode;
 
  /* Else find the index of this node in Inorder traversal */
  int inIndex = search(in, inStrt, inEnd, tNode->data);
 
  /* Using index in Inorder traversal, construct left and
     right subtress */
  tNode->left = buildTree(in, pre, inStrt, inIndex-1);
  tNode->right = buildTree(in, pre, inIndex+1, inEnd);
 
  return tNode;
}

int search(char arr[], int strt, int end, char value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}

tree_pointer newNode(char data)
{
  tree_pointer node = (tree_pointer) malloc(sizeof(node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

void deleteTree(tree_pointer node) 
{
    if (node == NULL) return;
 
    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);
   
    /* then delete the node */
    //printf("\n Deleting node: %c", node->data);
    free(node);
} 

int main(int argc, char** argv) {
	int num, count = 0, size;
	char preorder_t[100], inorder_t[100], postorder_t[100];
	tree_pointer root;
	
	scanf("%d", &num);
	scanf("%s", preorder_t);
	scanf("%s", inorder_t);
	
	for (size = 0; ; size++){
		if(preorder_t[size] == 0)
			break;
	} 

/*	printf("%s\n", preorder_t);
	printf("%s\n", inorder_t);*/	

        int true=1;
	while (true==1){
//		printf("%d\n", count+1);
		root = buildTree(inorder_t, preorder_t, 0, size - 1);
		printPostorder(root);
		
		printf("\n");
		preorder_t[0] = '\0';
		inorder_t[0] = '\0';
		deleteTree(root);
		root = NULL;
		count++;	
		
		if(count == num){
			break;
		}			
		scanf("%s", preorder_t);
		scanf("%s", inorder_t);
		for (size = 0; ; size++){
			if(preorder_t[size] == 0)
				break;
		}			
	}
	return 0;
}
