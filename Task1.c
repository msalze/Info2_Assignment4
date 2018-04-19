/*Melanie Salzer, 16-922-593*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	struct node*next;
};

int isEmpty(struct node* stackTop){
	if (stackTop == NULL){return -1;}
	else{return 1;}
}

void push(struct node ** stackTop, int key){
	struct node * p = malloc(sizeof(struct node));
	p->key = key;
	p->next = *stackTop;
	*stackTop = p;
	
}

int pop(struct node ** stackTop){
	if (isEmpty(*stackTop) ==-1){return -1;}
	struct node *p = (**stackTop).next;
	int val = (*stackTop)->key;
	free(*stackTop);
	*stackTop = p;
	return val;
}

void printStack(struct node*stackTop){
	printf("[");
	struct node *p = stackTop;
	if (isEmpty(stackTop)!=-1){
		while (p->next != NULL){
			printf("%d, ", p->key);
			p=p->next;
		}
		printf("%d", p->key);
	}
	printf("]\n");
}

void main(){
	struct node**stack = malloc(sizeof(struct node*));
	*stack =NULL;
	push(stack, 3);
	push(stack, 4);
	push(stack, 6);
	push(stack, 9);
	push(stack, 10);
	
	int val = pop(stack);
	printf("%d\n", val);
	val = pop(stack);
	printf("%d\n", val);
	
	push(stack, 4);
	push(stack, 17);
	push(stack, 30);
	
	printStack(*stack);
	
	return 0;
}













