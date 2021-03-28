#include "linkedList.h"
int main()
{
	LinkedList head = NULL;
	int input;
	int sign = 1;
	int looping = 0; /* judge the linkedlist whether is looped */
	while(sign) {
		menu();
		scanf("%d",&input);
		switch(input) {
				/* init */
			case 1: {
				system("cls");
				if(InitList(&head)) {
					printf("初始化链表成功！\n");
					looping = 0;
				}
				CreatList(&head);
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			/* insert */
			case 2: {
				system("cls");
				LNode *p,*q;
				int pre_node;
				printf("请输入你要插入到的位置的前一个结点的数据：");
				scanf("%d",&pre_node);
				p = FindNode(pre_node,head);
				if(!looping) {
					if(!p) {
						printf("没有找到你要插入的前节点！请检查输入！\n");
					} else {
						q = (LNode *)malloc(sizeof(LNode));
						printf("请输入你要插入节点的数据：\n");
						scanf("%d",&q->data);
						q->next = NULL;
						if(InsertList(p, q)) {
							printf("插入成功！\n");
						} else {
							printf("插入失败！\n");
						}
					}
				} else {
					printf("链表成环，无法操作！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			/* output */
			case 3: {
				system("cls");
				if(!looping) {
					TraverseList(head,visit);
				} else {
					printf("链表成环，无法操作！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			/* reserve */
			case 4: {
				system("cls");
				if(!looping) {

					if(ReverseList(&head)) {
						printf("反序成功！\n");
					}
				} else {
					printf("链表成环，无法操作！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			/* findmid */
			case 5: {
				system("cls");
				LNode *mid;	 	/* point to the middle */
				if(!looping) {
					mid = FindMidNode(&head);
					printf("中间节点的数据为：%d\n",mid->data);
				} else {
					printf("链表成环，无法操作！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			/* looping? */
			case 6: {
				system("cls");
				if(IsLoopList(head)) {
					printf("链表成环！\n");
				} else {
					printf("链表未成环！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			/* delete */
			case 7: {
				system("cls");
				int loca;
				LNode *p;
				ElemType record,*recorded=&record;
				if(!looping) {

					printf("请输入你要删除后节点的前节点数据：");
					scanf("%d",&loca);
					p = FindNode(loca,head);
					if(!p) {
						printf("没有找到你所输入的节点！\n");
					} else {
						if(DeleteList(p,recorded)) {
							printf("已经成功删除数据：%d\n",*recorded);
						} else {
							printf("删除失败！\n");
						}
					}
				} else {
					printf("链表成环，无法操作！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			/* reserve odd and even */
			case 8: {
				system("cls");
				if(!looping) {
					head = ReverseEvenList(&head);
					printf("对换成功！\n");
				} else {
					printf("链表成环，无法操作！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			/* search */
			case 9: {
				system("cls");
				ElemType target;
				printf("请输入你要查找的节点的数据：\n");
				scanf("%d",&target);
				if(SearchList(head,target)) {
					printf("该数据存在表中！\n");
				} else {
					printf("该数据不存在表中！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			/* exit */
			case 0: {
				system("cls");
				if(!looping) {

					DestroyList(&head);
				} else {
					printf("链表成环，销毁失败！\n");
				}
				fflush(stdin);
				system("cls");
				sign=0;
				break;
			}
			/* loop the linkedlist */
			case -1: {
				system("cls");
				if(LoopList(head)) {
					printf("构造循环链表成功！\n");
					looping = 1;
				} else {
					printf("构造失败！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			default: {
				printf("请输入1-9！\n");
				fflush(stdin);
				system("pause");
				system("cls");
			}
		}
	}
	printf("感谢使用本系统！");
	return 0;

}
