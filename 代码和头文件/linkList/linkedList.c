#include "linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L)
{
	*L = (LinkedList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	return SUCCESS;
}

/**
 *  @name        : Status CreatList(LinkedList *L)
 *	@description : Create a linkedlist by tail insertion
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status CreatList(LinkedList *L)
{
	Status ret;
	int input;		/* Check if the input is legal */
	int num;		/* the number of the node you want to creat */
	LNode *p,*q;	/* p is the new node, q points to the last of the existing nodes */
	q = *L;
	int i;		/* Count the number of nodes created now */
	if(*L) {
		printf("请输入你要构建的节点数：");
		input = scanf("%d",&num);
		if(!input) {
			printf("你的输入有误！请检查你的输入。\n");
			fflush(stdin);
		}
		for(i = 0; i<num; i++) {
			p = (LNode*)malloc(sizeof(LNode));
			printf("请输入第%d个节点的数据：",i+1);
			input = scanf("%d",&p->data);
			if(!input) {
				printf("你的输入有误！请检查你的输入。\n");
				fflush(stdin);
				free(p);
				i--;
				continue;
			}
			p->next = NULL;
			q->next = p;
			q = p;
		}
		ret = SUCCESS;
	} else {
		ret = ERROR;
	}
	return ret;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L)
{
	LNode *p,*q;	/* q after and p before,Iterate to delete the node */
	for(p = (*L); p; p = q) {
		q = p->next;
		free(p);
	}
	(*L) = NULL; /* delete the head node */
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q)
{
	Status ret;
	if(p&&q) {
		q->next = p->next;
		p->next = q;
		ret = SUCCESS;
	} else {
		ret = ERROR;
	}
	return ret;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e)
{
	Status ret;		/* result */ 
	LNode *q;		/* q point to the node which will be delete */
	q = p->next;	
	if(!q) {
		ret = ERROR;
	} else {
		p->next = q->next;	/* p point to the node next one to be deleted */
		*e = q->data;		/* record the data */
		free(q);
		ret = SUCCESS;
	}
	return ret;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	if(!L) {
		printf("当前没有链表！\n");
		return;
	} else {
		printf("当前链表为：");
		for(L = L->next; L; L = L->next) {	/* Iterate over and output the values of the nodes */
			visit(L->data);
			printf("->");
		}
		printf("NULL\n");
	}
}

/**
 *  @name        : void visit(ElemType e)
 *	@description : output the value of the node
 *	@param		 : e(the data of node)
 *	@return		 : None
 *  @notice      : None
 */
void visit(ElemType e)
{
	printf("%d",e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e)
{
	Status ret = ERROR;	/* result */
	LNode *p = L;    /* Iterate over p until we find the node we are looking for */
	for(p; p; p = p->next) {
		if(p->data == e) {
			ret = SUCCESS;
			break;
		}
	}
	return ret;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L)
{
	Status ret = ERROR;	/* result */
	LNode *p,*q;	/* q before and p after traversing continuously */
	if(!*L||!(*L)->next||!(*L)->next->next) {	/* if the num of the node is less than 2*/
		printf("当前不能反序！\n");
	} else {
		q = *L;
		q = q->next->next;	/* q placed on the second node */
		(*L)->next->next=NULL;	/* Let the first (the last node after inversion)point to NULL*/
		while(q) {
			p = q;
			q = q->next;
			p->next = (*L)->next;
			(*L)->next = p;	/* The head node keeps moving with p until p is NULL indicating that it has gone to the end */
		}
		ret = SUCCESS;
	}
	return ret;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L)
{
	Status ret = ERROR; /* result */
	LNode *fast,*slow;	 	/* fast goes two nodes at a time, slow goes one node at a time */
	fast = slow = L;
	while(fast&&fast->next) {
		fast = fast->next;
		if(fast) {
			fast = fast->next;
		}
		slow = slow->next;
		if(slow == fast ) {		/* If fast encounters a slow, it means the chain is looped */ 
			ret = SUCCESS;
			break;
		}
	}
	return ret;
}

/**
 *  @name        : Status LoopList(LinkedList L)
 *	@description : looping the linkedlist
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status LoopList(LinkedList L)
{
	Status ret = ERROR;
	LNode *fast,*slow;
	fast = slow = L;
	while(fast) {
		if(fast->next) {	/* fast goes two node a time */
			fast = fast->next;
			if(fast->next) {
				fast = fast->next;
			} else {	/* if there is not a node for fast, point the fast to slow */
				fast->next = slow;
				ret = SUCCESS;
				break;
			}
		} else {	/* if there is not a node for fast, point the fast to slow */
			fast->next = slow;
			ret = SUCCESS;
			break;
		}
		slow =slow->next;
	}
	return ret;
}


/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L)
{
	LNode *t,*p,*q;		/* t point to the node before the node will be reserved */
	t = *L;
	while(t->next&&t->next->next) {		/* if there is no two node to reserved,break */
		q = t->next;		/* p,q point to the node will be reserved */
		p = q->next;
		t->next = p;		/* t->next points to the second one after */
		q->next = p->next;	/* Change the order of pq */
		p->next = q;
		t=q;
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L)
{
	LNode *fast,*slow,*mid;    /*fast goes two node at a time, slow goes one node at a time ,mid point to the middle node */
	fast = slow = *L;
	while(fast&&fast->next) {
		fast = fast->next;
		if(fast) {
			fast = fast->next;
		}
		slow = slow->next;
	}
	mid = slow;
	return mid;
}

/**
 *  @name        : LNode* FindNode(ElemType e,LinkedList L)
 *	@description : find the node in the linked list
 *	@param		 : e(the data which will be finded),L(the head node)
 *	@return		 : LNode
 *  @notice      : none
 */
LNode* FindNode(ElemType e,LinkedList L)
{
	LNode *ob_node = NULL,*p = L;	/* ob_node is the target node, p will iterate the linkedlist to find the target */
	for(p; p; p=p->next) {
		if(p->data == e) {
			ob_node = p;
			break;
		}
	}
	return ob_node;
}

/**
 *  @name        : oid menu()
 *	@description : creat a menu
 *	@param		 : none
 *	@return		 : none
 *  @notice      : none
 */
void menu()
{
	printf("\n\n                    \n\n");
	printf("			*********************系统功能菜单*********************\n");
	printf("			------------------------------------------------------\n");
	printf("			    ***********************************************\n");
	printf("			    *  1.创建新链表       * *    2.插入新节点     *\n");
	printf("			    ***********************************************\n");
	printf("			    *  3.输出链表         * *    4.将链表反向     *\n");
	printf("			    ***********************************************\n");
	printf("			    *  5.找到单链表中点   * *    6.判断是否成环   *\n");
	printf("			    ***********************************************\n");
	printf("			    *  7.删除节点取值     * *    8.奇偶反转       *\n");
	printf("			    ***********************************************\n");
	printf("			    ***********************************************\n");
	printf("			    *              9.查询数据是否在表中           *\n");
	printf("			    ***********************************************\n");
	printf("                            ***********************************************\n");
	printf("			    *              0.删除链表并退出系统           *\n");
	printf("			    ***********************************************\n");
	printf("			    *                 10.构造循环链表             *\n");
	printf("			    ***********************************************\n");
	printf("			------------------------------------------------------\n");
	printf("			请选择菜单编号:");
}

