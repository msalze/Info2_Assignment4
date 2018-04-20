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

/*-------------------------------------------------------------------*/

struct TreeNode * maximum(struct TreeNode *n){
	if (n == NULL){
		return n;
	}
	struct TreeNode * p = n;
	while (p->right != NULL){
		p=p->right;
	}
	return(p);
}

struct TreeNode * minimum(struct TreeNode *n){
	if (n == NULL){
		return n;
	}
	struct TreeNode * p = n;
	while (p->left != NULL){
		p=p->left;
	}
	return(p);
}

struct TreeNode * successor(struct TreeNode * root, struct TreeNode*n){
	struct TreeNode *max = maximum(root);
	struct TreeNode *p = root;
	struct TreeNode *b = NULL;
	if (max == n){return b;}
	if (n->right != NULL){
		return minimum(n->right);
	}
	
	if(n->val < root->val){
		while(p != n){
	    	if(n->val < p->val){
				b = p;
				p = p->left;
	    	}else{
				p = p->right;
		    }
		}
	return b;
    }else{
	while(p != n){
	    if(n->val >= p->val){
		p = p->right;
	    }else{
		b = p;
		p = p->left;
	    }
	}
	return(b);
		
	}
}

struct TreeNode * ith_smallest(struct TreeNode* root, int i){
	if (root != NULL){
		struct TreeNode * p = minimum(root);
		while (i>1 && p!= NULL){
			p = successor(root,p);
			i--;
		}
		return(p);
	}
}

int distanceToRoot(struct TreeNode * root, int x){
	if (root == NULL){return 0;}
	if (root->val == x){return 0;}
	if (x<= root->val){
		return distanceToRoot(root->left,x) +1;
	}else{
		return distanceToRoot(root->right,x) +1;
	}
}

int distance(struct TreeNode* n, int a, int b){
	int dis_a = distanceToRoot(n,a);
	int dis_b = distanceToRoot(n,b);
	int dis = dis_a+dis_b;
	if (n == NULL){return 0;}
	struct TreeNode *p = n;
	while ((p->val<=a && p->val<=b )|| (p->val>a && p->val>b)){
		dis= dis -2;
		if (dis==0){return 0;}
		if (p->val == a || p->val == b){return dis;}
		if (a<=p->val){p=p->left;}
		else{p=p->right;}
	}
	return dis;
}


int main(){
	struct TreeNode ** root = malloc(sizeof(struct TreeNode*));
	*root = NULL;
	insert(root,4);
	insert(root,2);
	insert(root,3);
	insert(root,8);
	insert(root,6);
	insert(root,7);
	insert(root,9);
	print(*root);
	/*
	struct TreeNode * max = maximum(*root);
	printf("max = %d", max->val);
    struct TreeNode * suc = successor(*root, max );
    
    struct TreeNode * ith = ith_smallest(*root,5);
    printf("%d", ith->val);
	return 0;*/
	int i = distance(*root,3,9);
	printf("distance = %d",i);
}











