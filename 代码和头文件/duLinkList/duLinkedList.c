#include "duLinkedList.h"

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L)
{
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	(*L)->prior=NULL;
	(*L)->next=NULL;
	return SUCCESS;
}

/**
 *  @name        : Status CreatList_DuL(LinkedList *L)
 *	@description : Create a linkedlist by tail insert method
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status CreatList_DuL(DuLinkedList *L)
{
	Status ret;
	ElemType input;		/* Check if the input is legal */
	int num;		/* the number of the node you want to creat */
	DuLNode *p,*q;	/* p is the new node, q points to the last of the existing nodes */
	q = *L;
	int i;		/* Count the number of nodes created now */
	if(*L) {
		printf("请输入你要构建的节点数：");
		input = scanf("%d",&num);
		if(!input) {
			printf("你的输入有误！请检查你的输入。\n");
			fflush(stdin);
		}
		for(i=0; i<num; i++) {
			p = (DuLNode*)malloc(sizeof(DuLNode));
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
			p->prior = q;
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
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L)
{
	DuLNode *p,*q;	/* q after and p before,Iterate to delete the node */
	for(p=(*L); p; p=q) {
		q = p->next;
		free(p);
	}
	(*L) = NULL; /* delete the head node */
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
	Status ret=ERROR; /* result */
	if(p&&q) {
		/* Add q to the middle of p and p->prior */
		q->next = p;
		q->prior = p->prior;
		p->prior->next = q;
		p->prior = q;
		ret = SUCCESS;
	}
	return ret;

}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	Status ret=ERROR; /* result */
	if(p&&q) {
		/* Add q to the middle of p and p->next */
		q->next = p->next;
		q->prior = p;
		if(p->next) {
			p->next->prior = q;
			p->next = q;
		} else {
			p->next = q;
		}
		ret = SUCCESS;
	}
	return ret;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	Status ret=ERROR;
	DuLNode *q;
	q=p->next;
	if(!q) {
		ret = ERROR;
	} else {
		p->next = q->next;
		if(q->next) {
			q->next->prior = p;
		}
		*e = q->data;
		free(q);
		ret = SUCCESS;
	}
	return ret;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	if(!L) {
		printf("当前没有链表！\n");
		return;
	} else {
		printf("当前链表为：");
		for(L=L->next; L; L=L->next) {	/* Iterate over and output the values of the nodes */
			if(L->next) {
				visit(L->data);
				printf("<-->");
			} else {
				visit(L->data);
				printf("-->");
			}
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
 *  @name        : FindNode_DuL(ElemType e,LinkedList L)
 *	@description : find the node in the linked list
 *	@param		 : e(the data which will be finded),L(the head node)
 *	@return		 : LNode
 *  @notice      : none
 */
DuLNode* FindNode_DuL(ElemType e,DuLinkedList L)
{
	DuLNode *tar_node=NULL;
	for(L; L; L=L->next) {
		if(L->data==e) {
			tar_node=L;
			break;
		}
	}
	return tar_node;
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
	printf("			*********************双向链表菜单*********************\n");
	printf("			------------------------------------------------------\n");
	printf("			    ***********************************************\n");
	printf("			    *  1.创建新链表       * *    2.后插节点       *\n");
	printf("			    ***********************************************\n");
	printf("			    *  3.输出链表         * *    4.前插节点       *\n");
	printf("			    ***********************************************\n");
	printf("			    *                  5.删除节点                 *\n");
	printf("			    ***********************************************\n");
	printf("                            ***********************************************\n");
	printf("			    *              0.删除链表并退出系统           *\n");
	printf("			    ***********************************************\n");
	printf("			------------------------------------------------------\n");
	printf("			请选择菜单编号:");
}
