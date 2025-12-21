#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;           //数据域
    struct node *next;  //指针域
} node;
int main()
{
    //初始化链表
    int len = 0;                                //链表长度归零
    node *head = (node *)malloc(sizeof(node));  //创建头结点
    head->next = NULL;                          //头结点指针域为NULL
    node *p = head;                             //p指向头结点，其中p为链表操作指针

    //创建链表，插入节点
    node* node1 = (node *)malloc(sizeof(node));
    len++;
    node* node2 = (node *)malloc(sizeof(node));
    len++;
    node* node3 = (node *)malloc(sizeof(node));
    len++;
    node* node4 = (node *)malloc(sizeof(node));
    len++;
    node* node5 = (node *)malloc(sizeof(node));
    len++;
    //申请了五个空间用于储存节点

    //下面将为他们分配值
    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;
    node5->data = 5;

    //连接节点
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    
    //遍历链表
    /* while(p->next != NULL) {
        p = p->next;
        printf("%d\n", p->data);
    } */
    
    //插入节点
    node* newNode = (node *)malloc(sizeof(node));
    newNode->data = 666;
    //现在我们要将newNode插入到node3后面
    node* temp = node3;
    newNode->next = temp->next;
    node3->next = newNode;
    len++;
    //遍历链表检查
    /* while(p->next != NULL) {
        p = p->next;
        printf("%d\n", p->data);
    } */

    //删除节点
    //这里我们假设要删除刚刚加进来的数据域为666的节点，但是我们加点难度，假设不知道删除的节点是哪一个
    node* q = head;                     //获取一个1指针用于遍历
    while(q->next != NULL) {            //遍历链表
        if(q->next->data == 666) {      //判断下一个节点的数据域是否为666
            node* temp = q->next;       //如果遇到了666，那么我们现用临时变量temp保存下一个节点的指针
            q->next = temp->next;
            free(temp);
            len--;
            printf("删除成功!\n");
            break;
        } else {
            q = q->next;                  //如果没有遇到，那么q指针继续往下
        }
    }
    //遍历链表检查
    /* while(p->next != NULL) {
        p = p->next;
        printf("%d\n", p->data);
    } */

    // 清空链表
    node *current = head->next; // 从第一个有效节点开始
    while (current != NULL)
    {
        node *temp = current;    // 保存当前节点
        current = current->next; // 移动到下一个节点
        free(temp);              // 释放当前节点内存
    }
    head->next = NULL; // 头节点指向NULL
    len = 0;           // 长度归零
    printf("链表清空完成!\n");
}