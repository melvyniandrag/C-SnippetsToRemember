#include <stdio.h>
#include <stdlib.h>

static int num_nodes = 0;

typedef struct node{
	int item;
	struct node *next;
} node ;

node *search_list(node *n, int x){
	if (n == NULL) return NULL;
	if(n->item == x)
		return n;
	else 
		return search_list(n->next, x);
}

void insert_node(node **head, int x){
	//Some wonderful pointer manipulation.
	node* p;

	p = malloc(sizeof(node)); 
	p->item = x;
	p->next = *head;

	*head = p;
	
	num_nodes++;
}

void print_list(node *n){
	if (n->next == NULL){
		printf("%i\n", n->item);
		printf("End.\n");
	}
	else{
		printf("%i\n", n->item);
		print_list(n->next);
	}
}

void init(node ** n1, node ** n2, node ** n3, node ** n4){
	// An initialization that shows a wonderful bit of pointer manipulation.
	*n1 = malloc(sizeof(node));
	*n2 = malloc(sizeof(node));
	*n3 = malloc(sizeof(node));
	*n4 = malloc(sizeof(node));

	(*n1)->item = 100;
	(*n1)->next = *n2;
	num_nodes++;

	(*n2)->item = 200;
	(*n2)->next = *n3;
	num_nodes++;

	(*n3)->item = 300;
	(*n3)->next = *n4;
	num_nodes++;

	(*n4)->item = 400;
	num_nodes++;
}

int main(int argc, char** argv){
	node *n1, *n2, *n3, *n4;
	init(&n1, &n2, &n3, &n4);
	printf("%i\n", search_list(n1, 300)->item);
	printf("%i\n", num_nodes);
	insert_node(&n1, 10);
	printf("%i\n", num_nodes);
	print_list(n1);
}