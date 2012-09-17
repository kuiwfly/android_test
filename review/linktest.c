#include <stdio.h>
#include <memory.h>
typedef struct link_node {
	struct link_node *next ;
	int data ;
}LinkNode ;
struct link_node *create_linklist(int *data, int len){
	if(data == NULL){
		printf("%s:data can't be null!\n",__func__) ;
		return NULL ;
	}
	struct link_node *p_head = (struct link_node*) malloc(sizeof(struct link_node)*(len+1)) ;
	memset(p_head,0,sizeof(struct link_node)*(len+1)) ;
	int i = 0 ;
	struct link_node *p_tmp = p_head ;
	for(i=0 ; i<len ; i++){
		p_tmp->next = &(p_head[i+1]) ;
		p_tmp->next->data = data[i] ;
		p_tmp = p_tmp->next ;
	}
	return p_head ;
}
struct link_node *create_looplinklist(int *data , int len, int loop_position){
	if( data == NULL ){
		return NULL ;
	}
	struct link_node *p_head = (struct link_node*) malloc(sizeof(struct link_node)*(len+1)) ;
	memset(p_head,0,sizeof(struct link_node)*(len+1)) ;
	int i = 0 ;
	struct link_node *p_tmp = p_head ;
	for(i=0 ; i<len ; i++){
		p_tmp->next = &(p_head[i+1]) ;
		p_tmp->next->data = data[i] ;
		p_tmp = p_tmp->next ;
	}
	p_head[len].next = &(p_head[loop_position+1]) ;

	return p_head ;
}
void print_linklist(struct link_node *p_head) {
	if(p_head == NULL){
		printf("%s:phead can't be null!\n",__func__) ;
		return ;
	}
	struct link_node *ptmp = p_head->next ;
	while(ptmp != NULL){
		printf("%d,",ptmp->data) ;	
		ptmp = ptmp->next ;
	}
	printf("\n") ;
}

struct link_node* reverse_linklist(struct link_node *p_head){
	if(p_head == NULL){
		return  NULL ;
	}
	struct link_node *p_tmp = p_head ->next ;
	struct link_node *p_tmp1 ;
	p_head->next = NULL ;
	while(p_tmp!=NULL){
		p_tmp1 = p_tmp ;
		p_tmp = p_tmp->next ;
		p_tmp1->next = p_head->next ;
		p_head->next = p_tmp1 ;
	}
	return p_head ;
}
int has_loop(struct link_node *p_head){
	if(p_head == NULL){
		return 0 ;
	}
	struct link_node *p_tmp = p_head ->next ;
	struct link_node *p_tmp1 = p_head->next  ;
	while(1){
		if(p_tmp == NULL|| p_tmp1 == NULL||p_tmp1->next==NULL){
			printf("not loop!\n") ;
			return 0 ;	
		}
		p_tmp = p_tmp ->next ;
		p_tmp1 = p_tmp1 ->next ;
		p_tmp1 = p_tmp1->next ;
		if(p_tmp == p_tmp1){
			printf("has loop!\n") ;
			return 1 ;
		}
	}
		
}
int locate_loop(struct link_node *p_head){
	if(p_head == NULL){
		return -1 ;
	}
	struct link_node *p_tmp1 = p_head->next ;
	struct link_node *p_tmp2 = p_head->next ;
	while(1){
		if(p_tmp1 == NULL || p_tmp2 == NULL || p_tmp2->next == NULL){
			return -1 ;
		}
		p_tmp1 = p_tmp1->next ;
		p_tmp2 = p_tmp2->next->next ;
		if(p_tmp1 == p_tmp2){
			break ;
		}
	}
	p_tmp1 = p_head->next ;
	int location = 0 ;
	while(1){
		if(p_tmp1 == p_tmp2) {
			return location ;		
		}
		p_tmp1 = p_tmp1->next ;
		p_tmp2 = p_tmp2->next ;
		location ++ ;
	}
	
}
void bubblesort(struct link_node *p_head){
	struct link_node *p_tmp1 = p_head ;
	struct link_node *p_tmp2 = p_head ;
	struct link_node *p_tail = NULL ;
	if(p_tmp1->next == NULL || p_tmp1->next->next == NULL){
		return ;
	}
	while(p_tail != p_head->next->next){
		while(p_tail != p_tmp1->next->next){
			if(p_tmp1->next->data > p_tmp1->next->next->data){
				p_tmp2=p_tmp1->next ;
				p_tmp1->next = p_tmp1->next->next ;
				p_tmp2->next = p_tmp1->next->next ;
				p_tmp1->next->next = p_tmp2 ;
			}
			p_tmp1 = p_tmp1->next ;
		}		
print_linklist(p_head) ;
		p_tail = p_tmp1->next ;
		p_tmp1 = p_head ;
		
	}	
}
void insertsort(struct link_node *p_head){
	struct link_node *p_tmp1 = p_head ;
	struct link_node *p_tmp2 = NULL ;
	struct link_node *p_tail = p_head->next ;
	if(p_tmp1->next == NULL || p_tmp1->next->next == NULL){
		return ;
	}
	p_tail = p_tmp1->next ;
	while(p_tail!=NULL&&p_tail->next!=NULL){
		while(p_tmp1->next != p_tail->next){
			if(p_tmp1->next->data > p_tail->next->data){
				p_tmp2 = p_tail->next->next ;
				p_tail->next->next = p_tmp1->next ;
				p_tmp1->next = p_tail->next ;
				p_tail->next = p_tmp2 ;
				break ;
			}	
			p_tmp1 = p_tmp1->next ;
		}

		if(p_tmp1->next == p_tail->next){
			p_tail = p_tail->next ;
		}
		p_tmp1 = p_head ;
	}
}
void selectsort(struct link_node *p_head){
	struct link_node *p_tmp1 = p_head ;
	struct link_node *p_tmp2 = NULL ;
	struct link_node *p_tail = p_head->next ;
	while(p_tail != NULL){		
		
	}
}
struct duallink_node{
	int data ;
	struct duallink_node *pre ;
	struct duallink_node *next ;
} ;
struct duallink_node * create_duallinklist(const int *data,int len){
	if(data == NULL){
		return ;
	}	
	struct duallink_node *p_head = (struct duallink_node*)malloc(sizeof(struct duallink_node)) ;
	struct duallink_node *p_tmp = p_head ;
	
	p_head->pre = NULL ;

	int i = 0 ;
	for(i=0 ; i<len ; i++){
		p_tmp->next = (struct duallink_node*) malloc(sizeof(struct duallink_node)) ;
		p_tmp->next->data = data[i] ;
		p_tmp->next->pre = p_tmp ; 
		p_tmp = p_tmp->next ;
	}
	p_tmp->next = NULL ;
	return p_head ;	
/******************************THis method is wrong************************************************************
	struct duallink_node *p_head = (struct duallink_node*)malloc(sizeof(struct duallink_node)*(len+1)) ;
	struct duallink_node *p_tmp = p_head ;
	
	p_tmp->pre = NULL ;
	int i=0 ;
	for(i=0;i<len;i++){
		p_tmp->next = p_head+i+1 ;		
		p_tmp->next->data = data[i] ;
		p_tmp->next->pre = p_head+i ;
		p_tmp = p_tmp->next ;
	}
	p_head[i].next = NULL ;
	p_head[i].pre = p_head+i-1 ;

	p_head[0].pre = NULL ;
	return p_head ;
****************************This method is wrong*****************************************************************/
}
void print_duallinklist(struct duallink_node *p_head) {
	if(p_head == NULL){
		return ;
	}
	struct duallink_node *p_tmp = p_head;
/*
	while(p_tmp ->next != NULL){
		printf("%d,",p_tmp->data) ;
		p_tmp = p_tmp->next ;
	}
*/	
	do{
		p_tmp = p_tmp->next ;
		printf("%d,",p_tmp->data) ;
	}while(p_tmp->next!=NULL) ;
	printf("\n") ;
	while(p_tmp!=p_head){
		printf("%d,",p_tmp->data) ;
		p_tmp = p_tmp->pre ;
	}
	printf("\n") ;
/*
	while(p_tmp != p_head){
		printf("%d,",p_tmp->data) ;
		p_tmp = p_tmp->pre ;
	}
	printf("\n") ;
*/
}
void insert_duallinklist(struct duallink_node *p_head, int data) {
	if(p_head == NULL){
		return ;
	}
	struct duallink_node *p_tmp = (struct duallink_node*)malloc(sizeof(struct duallink_node)) ;
	p_tmp->data = data ;
	p_tmp->pre = p_head ;
	p_tmp->next = p_head->next ;
	p_tmp->next->pre = p_tmp ;
	p_head->next = p_tmp ;
}
void append_duallinklist(struct duallink_node *p_head, int data) {
	if(p_head == NULL){
		return ;
	}
	struct duallink_node *p_tmp = p_head->next ;
	do {
		p_tmp = p_tmp->next ;
	}while(p_tmp->next != NULL) ;
	p_tmp->next = (struct duallink_node*)malloc(sizeof(struct duallink_node)) ;
	p_tmp->next->data = data ;
	p_tmp->next->pre = p_tmp ;
	p_tmp->next->next = NULL ; 
}
void remove_duallinklist(struct duallink_node *p_head,int data){
	if(p_head == NULL){
		return ;
	}
	struct duallink_node *p_tmp = p_head ;
	struct duallink_node *p_tmp1 = NULL ;
	while(p_tmp->next!=NULL){
		if(p_tmp->next->data == data){
			p_tmp1 = p_tmp->next ;
			p_tmp->next = p_tmp1->next ;
			p_tmp->next->pre = p_tmp ;	
			free(p_tmp1) ;
			break ;
		}
		p_tmp = p_tmp->next ;
	}
}
void remove_all(struct duallink_node *p_head){
	if(p_head == NULL){
		return ;
	}
	struct duallink_node *p_tmp = p_head->next  ;
	do{
		p_tmp=p_tmp->next ;
		printf("delete:%d\n",p_tmp->pre->data) ;
		free(p_tmp->pre) ;
	}while(p_tmp->next!=NULL) ;
	printf("delete:%d\n",p_tmp->data) ;
	free(p_tmp) ;
}
int main()
{
	int data[] = {20 ,14, 32, 43,21, 79, 4,9,23,56,42} ;
	int len = sizeof(data)/sizeof(data[0]) ;
	struct duallink_node* p_head = create_duallinklist(data,len) ;
	print_duallinklist(p_head) ;
	
	insert_duallinklist(p_head,99) ;
	print_duallinklist(p_head) ;
	append_duallinklist(p_head,111) ;
	print_duallinklist(p_head) ;

	remove_duallinklist(p_head,32) ;
	print_duallinklist(p_head) ;
	remove_all(p_head) ;
/*
	struct link_node *p_head = create_linklist(data, len) ;
	int location = 4 ;
	printf("create loop link list! loop location at %d\n",location) ;
	struct link_node *p_loop_head = create_looplinklist(data,len,location) ;
	printf("origin order:") ;
	print_linklist(p_head) ;
	printf("reverse order:") ;
	reverse_linklist(p_head) ;
	print_linklist(p_head) ;
	
//	bubblesort(p_head) ;
	insertsort(p_head) ;
	print_linklist(p_head) ;
	has_loop(p_head) ;
	has_loop(p_loop_head) ;
	printf("loop location :%d\n",locate_loop(p_loop_head)) ;
*/
	return 0 ;
}
