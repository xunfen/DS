#include <stdio.h>
#include <stdlib.h>

// 初始化链表
typedef struct node
{
    int data;          // 数据域
    struct node *next; // 指针域
} node;

// 初始化栈
typedef struct stack
{
    node *top; // 栈顶指针
    int size;
} stack;

int main()
{
    stack stack;
    stack.top = NULL; // 初始化栈顶指针为NULL
    stack.size = 0;   //  初始化栈大小为0

    /* //入栈
    node *p = (node *)malloc(sizeof(node));//申请一个链表的空间
    p ->data = 1;//数据域我们填1
    p ->next = stack.top;//指针域我们指向栈顶
    stack.top = p;//栈顶指针我们指向这个节点
    stack.size++;//栈大小加1
    printf("success!\n"); */

    // 循环入栈5个元素
    for (int i = 0; i < 5; i++)
    {
        node *p = (node *)malloc(sizeof(node));
        p->data = i + 1;
        p->next = stack.top;
        stack.top = p;
        stack.size++;
        printf("%d success!\n", i + 1);
    }

    // 退栈
    // 判栈空
    if (stack.top == NULL)
    {
        printf("stack is empty!\n");
    }
    else
    {
        node *temp = stack.top; // 保存栈顶节点
        int data = temp->data;  // 取出要退栈的数据值
        stack.top = temp->next; // 把栈顶指针指向下一个元素
        stack.size--;           // 栈大小要减一
        free(temp);
        printf("seccess!\n");
    }

    // 获取栈顶元素以及遍历栈
    // 取栈顶
    if (stack.top == NULL)
    {
        printf("stack is empty!\n");
    }
    else
    {
        printf("stack top is %d\n", stack.top->data);
    }

    // 遍历
    if (stack.top == NULL)
    {
        printf("stack is empty!\n");
    }
    else
    {
        node *p = stack.top; // 定义一个便利的指针
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    }
}