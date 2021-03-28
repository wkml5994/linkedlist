#include "duLinkedList.h"
int main()
{
	DuLinkedList head=NULL;
	int input;
	int temp;	/* Check if the input is legal */
	int sign=1;
	while(sign) {
		menu();
		temp = scanf("%d",&input);
		if(!temp) {
			printf("你的输入有误，请检查输入！\n");
			fflush(stdin);
			system("pause");
			system("cls");
		} else {
			switch(input) {
					// init
				case 1: {
					system("cls");
					if(InitList_DuL(&head)) {
						printf("初始化链表成功！\n");
					}
					CreatList_DuL(&head);
					fflush(stdin);
					system("pause");
					system("cls");
					break;
				}
				// insertafter
				case 2: {
					system("cls");
					DuLNode *p,*q;
					int pre_data;
					printf("请输入你要插入到的位置的前一个结点的数据：");
					temp = scanf("%d",&pre_data);
					if(!temp) {
						printf("你的输入有误，请检查输入！\n");
						fflush(stdin);
						system("pause");
						system("cls");
						break;
					}
					p = FindNode_DuL(pre_data,head);
					if(!p) {	/* p is not found */
						printf("没有找到你要插入的前节点！请检查输入！\n");
					} else {
						q = (DuLNode *)malloc(sizeof(DuLNode));
						printf("请输入你要插入节点的数据：\n");
						temp = scanf("%d",&q->data);
						if(!temp) {
							printf("你的输入有误，请检查输入！\n");
							free(q);
							fflush(stdin);
							system("pause");
							system("cls");
							break;
						}
						q->prior = NULL;
						q->next = NULL;
						if(InsertAfterList_DuL(p, q)) {
							printf("插入成功！\n");
						} else {
							printf("插入失败！\n");
						}
					}
					fflush(stdin);
					system("pause");
					system("cls");
					break;
				}
				// output
				case 3: {
					system("cls");
					TraverseList_DuL(head,visit);
					fflush(stdin);
					system("pause");
					system("cls");
					break;
				}
				//insertbefore
				case 4: {
					system("cls");
					DuLNode *p,*q;
					int aft_data;
					printf("请输入你要插入到的位置的后一个结点的数据：");
					temp = scanf("%d",&aft_data);
					if(!temp) {
						printf("你的输入有误，请检查输入！\n");
						fflush(stdin);
						system("pause");
						system("cls");
						break;
					}
					p = FindNode_DuL(aft_data,head);
					if(!p) {	/* p is not found */
						printf("没有找到你要插入的后节点！请检查输入！\n");
					} else {
						q = (DuLNode *)malloc(sizeof(DuLNode));
						printf("请输入你要插入节点的数据：\n");
						temp = scanf("%d",&q->data);
						if(!temp) {
							printf("你的输入有误，请检查输入！\n");
							free(q);
							fflush(stdin);
							system("pause");
							system("cls");
							break;
						}
						q->prior =NULL;
						q->next = NULL;
						if(InsertBeforeList_DuL(p, q)) {
							printf("插入成功！\n");
						} else {
							printf("插入失败！\n");
						}
					}
					fflush(stdin);
					system("pause");
					system("cls");
					break;
				}
				//delete
				case 5: {
					system("cls");
					int pre_data;
					DuLNode *p;
					ElemType record,*recorded=&record;
					printf("请输入你要删除后节点的前节点数据：");
					temp = scanf("%d",&pre_data);
					if(!temp) {
						printf("你的输入有误，请检查输入！\n");
						fflush(stdin);
						system("pause");
						system("cls");
						break;
					}
					p = FindNode_DuL(pre_data,head);
					if(!p) { /* p is no found */
						printf("没有找到你所输入的节点！\n");
					} else {
						if(DeleteList_DuL(p,recorded)) {
							printf("已经成功删除数据：%d\n",*recorded);
						} else {
							printf("删除失败！\n");
						}
					}
					fflush(stdin);
					system("pause");
					system("cls");
					break;
				}
				// exit
				case 0: {
					system("cls");
					DestroyList_DuL(&head);
					fflush(stdin);
					system("cls");
					sign=0;
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
	}
	printf("感谢使用本系统！");
	return 0;

}
