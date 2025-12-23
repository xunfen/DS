#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10         //定义栈的最大容量

//初始化栈
typedef struct {
    int data[MAX_SIZE];      // 定义存储栈元素的数组
    int top;                 // 定义栈顶指针
} stack;

int main() {
    stack stack;            //声明我的栈
    stack.top = -1;         //初始化栈顶指针为-1表示栈空

    //入栈
    if (stack.top == MAX_SIZE - 1) {
        printf("栈已满,请先出栈\n");
    } else {
        stack.data[stack.top + 1] = 1;      //写入一个元素，若果想要批量写入则循环即可
        stack.top++;                        //栈顶指针加1
        printf("入栈成功\n");
    }

    //出栈(退栈)
    if (stack.top == -1) {
        printf("栈已空,请先入栈\n");
    } else {
        printf("出栈元素为%d\n", stack.data[stack.top]);
        stack.top--;
    }

    //取栈顶元素
    if (stack.top == -1) {
        printf("栈已空,请先入栈\n");
    } else {
        printf("栈顶元素为%d\n", stack.data[stack.top]);
        printf("栈中元素个数为%d\n", stack.top + 1);
        printf("栈中元素为:\n");
        for (int i = 0; i <= stack.top; i++) {
            printf("%d\n", stack.data[i]);
            printf("\n");
        }
    }
}
