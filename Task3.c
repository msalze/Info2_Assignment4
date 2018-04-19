#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void insert(struct TreeNode ** root, int val){
	struct TreeNode *p = *root;
	struct TreeNode *r = NULL;
	struct TreeNode *q = malloc(sizeof(struct TreeNode));
	q->val = val;
	q->left = NULL;
	q->right = NULL;

	while (p!=NULL){
		r = p;
		if (val <= p->val){
			p=p->left;
		}
		else{
			p=p->right;
		}
	}
	if (*root == NULL){
		*root = q;
	}
	else if (val<= r->val){
		r->left = q;
	}
	else{
		r->right = q;
	}
}

struct TreeNode * search(struct TreeNode* root, int val){
	if (root==NULL || root->val == val){
		return root;
	}
	else{
		if (val <= root->val){
			return search(root->left, val);
		}
		else{
			return search(root->right, val);
		}
	}
}

void deleteVal(struct TreeNode **root, int val){
	struct TreeNode * u = *root;
	struct TreeNode *v= NULL;
	struct TreeNode *x = search(*root, val);
	if (x==NULL){}
	else{
		while (u!=x){
			v=u;
			if (val <= u->val){
				u=u->left;
			}
			else{
				u=u->right;
			}
		}
		if(u->right == NULL){
			if(v == NULL){*root = u->left;}
			else if(v->left == u){v->left = u->left;}
			else{v->right = u->left;}
    	}
	    else if(u->left == NULL){
			if(v == NULL){*root = u->right;}
			else if(v->left = u){v->left = u->right;}
			else{v->right = u->right;}
		}
		else{
			struct TreeNode *p = x->left;
			struct TreeNode *q = p;
			while(p->right != NULL){
		    q = p;
    		p = p->right;
			}
			if(v == NULL){
		    	*root = p;
			}else if(v->left == u){
			    v->left = p;
			}else{
	    		v->right = p;
			}
	
			p->right = u->right;
			if(q != p){
		    	q->right = p->left;
		    	p->left = u->left;
			}
		}
	}
	
	
}



void print(struct TreeNode * root){
	if (root != NULL){
		print(root->left);
		printf("%d ", root->val);
		print(root->right);
	}
}


void main(){
	struct TreeNode ** root = malloc(sizeof(struct TreeNode*));
	*root = NULL;
	insert(root,4);
	insert(root,2);
	insert(root,3);
	insert(root,8);
	insert(root,6);
	insert(root,7);
	insert(root,9);
	insert(root,12);
	insert(root,1);
	print(*root);
	printf("\n");
	deleteVal(root,4);
	deleteVal(root,7);
	deleteVal(root,2);
	print(*root);
	return 0;
}


