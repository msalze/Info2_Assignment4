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

struct Queue{
	struct node* stack1;
	struct node* stack2;
};


void enQueue(struct Queue *q, int key){
	push(&(q->stack1),key);
}

int deQueue(struct Queue *q){
    if(isEmpty(q->stack1) == -1){return -1;}
    int t = 0;
    while(isEmpty(q->stack1) == 1){
	t = pop(&(q->stack1));
	push(&(q->stack2), t);
    }

    int val = pop(&(q->stack2));
    while(isEmpty(q->stack2) == 1){
	t = pop(&(q->stack2));
	push(&(q->stack1), t);
    }
    
    return val;
}

void printQueue(struct Queue *q){
	printStack(q->stack1);
}

int main(){
	struct Queue*q = malloc(sizeof(struct Queue));
	q->stack1 = NULL;
	q->stack2 = NULL;
	enQueue(q,2);
	enQueue(q,8);
	enQueue(q,11);
	enQueue(q,15);
	int val = deQueue(q);
	printf("%d\n", val);
	val = deQueue(q);
	printf("%d\n", val);
	enQueue(q,1);
	enQueue(q,5);
	printQueue(q);
	
	return 0;
}




