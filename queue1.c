#include<stdio.h>
#include<stdlib.h>

//初始化
typedef struct QNode{
    int data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct{
    QueuePtr front;//对头指针域
    QueuePtr rear;//队尾指针域
} *LinkQueue;

void InitQueue(LinkQueue Q){ 
    Q->front = Q->rear = NULL;
    printf("队列初始化成功！");
}

//入队
void append(LinkQueue Q, int e){
    if(Q->front == NULL){//
        printf("队列为空！");
    }
    QNode *p = (QNode *)malloc(sizeof(QNode));//申请空间
    p->data = e;//把数据存储到数据域
    p->next = NULL;//该节点的下一节点置空指向NULL
    Q->rear->next = p;//队尾指针域的next指向新节点
    Q->rear = p;
}

//出队
// 出队
void pop(LinkQueue Q, int *e){
    // 检查队列是否为空或队列指针是否有效，如果为空则无法进行出队操作
    if(Q == NULL || Q->front == NULL){
        printf("队列为空！\n");
    }
    
    QNode *p = Q->front;     // 保存当前队头节点的地址，准备删除
    *e = p->data;            // 将要删除节点的数据赋值给输出参数e
    Q->front = p->next;      // 将队头指针指向下一个节点，实现队头出队
    
    // 如果删除的是最后一个节点(即删除后队列变空)，则rear也需要置为NULL
    if(Q->front == NULL) {   // 判断删除后队列是否为空
        Q->rear = NULL;      // 重要：同时将队尾指针也设为NULL，保持一致性
    }
    
    free(p);                 // 释放被删除节点占用的内存空间
    printf("元素 %d 出队成功\n", *e);  // 输出出队成功的提示信息
}

//取对头
void getHead(LinkQueue Q, int *e){
    //判队空
    if(Q == NULL || Q->front == NULL){
        printf("队列为空！\n");
    }
    *e = Q->front->data;
    printf("队头元素为：%d\n", *e);
}

//遍历
void traverse(LinkQueue Q){
    if(Q == NULL || Q->front == NULL){
        printf("队列为空！\n");
    }
    for(QNode *p = Q->front; p != NULL; p = p->next){
        printf("%d ", p->data);
        printf("\n");
    }
}

//销毁
// 销毁队列
void destroy(LinkQueue Q) {
    if(Q == NULL) {
        printf("队列指针为空，无需销毁\n");
        return;
    }
    
    // 循环删除所有节点
    while(Q->front != NULL) {
        QNode *temp = Q->front;      // 保存当前队头节点
        Q->front = Q->front->next;   // 移动队头指针到下一个节点
        free(temp);                  // 释放当前节点内存
    }
    
    // 队列为空时，rear也应该为NULL
    Q->rear = NULL;
    
    printf("队列销毁成功！\n");
}