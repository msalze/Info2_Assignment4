#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void insert(struct TreeNode ** root, int val){
	struct TreeNode *p = *root;
	if (*root == NULL){
		*root = malloc(sizeof(struct TreeNode));
		(**root).left = NULL;
		(**root).right = NULL;
		(**root).val = val;
	}
	else{
		if (val <= (**root).val){
			struct TreeNode  *p= (**root).left;
			insert(&p, int val);
		}
		else{
			insert(*root->right, int val);
		}
	}
}

struct TreeNode * search(struct TreeNode* root, int val){
	if (root==NULL || root->key == key){
		return root;
	}
	else{
		if (val <= root->key){
			search(root->left, int val);
		}
		else{
			search(root->right, int val);
		}
	}
}

void deleteVal(struct TreeNode **root, int val){
	
}

void print(struct TreeNode * root){
	printf("[");
	if (root != NULL){
		if (root->left)!=NULL){
			print(root->left);
		}
		printf("%d, ", root->val);
		if (root->right != NULL){
			print(root->right);
		}
		
	}
	printf("]");
}

















