#include<stdio.h>
#include<stdlib.h>

typedef struct LinkListNode_t LinkListNode_t;

struct LinkListNode_t{
	int data;
	LinkListNode_t *next;
};

void print_Linked_list(LinkListNode_t* node){
	while( node ){
		printf("El dato es:%d\n",node->data);
		node = node->next;
	}
}

LinkListNode_t* create_node(int data){
	LinkListNode_t* new = malloc(sizeof(LinkListNode_t));
	new->data = data;
	new->next = NULL;
	return new;
}

LinkListNode_t* insert_node_tail(LinkListNode_t* head,int data){
	if( head == NULL){
		head = create_node(data);		
		return head;
	}// In case list doesn't exist yet create a new one
	LinkListNode_t* HEAD = head;	
	while(head->next){
		head=head->next;
	}
	head->next = create_node(data);
	//printf("Data es:%d\n",head->data);
	//printf("HEAD al final es:%p\n",HEAD);
	//printf("head al final es:%p\n",head);
	return HEAD;
}

LinkListNode_t* insert_node_head(LinkListNode_t* head, int data){
	if( head == NULL ){
		LinkListNode_t* list = create_node(data);
		return list;
	}
	LinkListNode_t* second = head;
	LinkListNode_t* first = create_node(data);
	first->next = second;
	return first;	
}

/*
 *Function to insert a new node at certain position given a data value as well
 */
LinkListNode_t* insert_node_at(LinkListNode_t* head, int data, int position){
	LinkListNode_t* HEAD = head;
	int i = 0;
	while( i < (position-1)){
		head = head->next;	
	i++;
	}
	LinkListNode_t* after = head->next;
	LinkListNode_t* new = create_node(data);
	head->next = new;
	head = head->next;
	head->next = after;
	return HEAD;
}

/*
 * Function to delete the element at a given position
 */
LinkListNode_t* delete_node_at(LinkListNode_t* head, int position){
	if( 0 == position ){
		LinkListNode_t* following = head->next;
		free(head);	
		return following;
	}
	LinkListNode_t* HEAD = head;
	int i = 0;
	while( i < (position-1)){
		head = head->next;	
	i++;
	}
	//being a node before
	LinkListNode_t* copy = head;
	head = head->next;//nodo a eliminar
	LinkListNode_t* following = head->next;
	free(head);
	copy->next = following;
	return HEAD;
}

//Rotate K elements to the right 
LinkListNode_t* rotatelist(LinkListNode_t* head, int k){
	LinkListNode_t* HEAD,*first = head;
	int nodes = 1;
	while( head->next != NULL ){
		head = head->next;
		nodes++;
	}
	head->next = first;	//Here we have a circular Linked List
	if(k>nodes){
		k = k%nodes;
	}//If k is greater than the number of nodes, get necessary rotations without a lot of turns.
	for(int i = 1; i <= (nodes-k); i++){
		head = head->next;
	}
	HEAD = head->next;
	head->next = NULL;
	return HEAD;
}

int main(){
	LinkListNode_t* lista = NULL;
	for(int i = 0; i < 5; i++){
		lista = insert_node_tail(lista,(i)*10);
	}
	lista = insert_node_at(lista,100,2);	
	print_Linked_list(lista);	
	lista = delete_node_at(lista,2);	
	printf("La nueva lista es\n");
	print_Linked_list(lista);
	lista = rotatelist(lista,6);
	printf("La lista rotada es\n");
	print_Linked_list(lista);
	return 0;
}
