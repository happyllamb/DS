#include <stdio.h>
#include <stdbool.h>
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

//有效字符串需满足：

//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。


//示例 1：

//输出：true
//示例 2：

//输入：s = "()[]{}"
//输出：true
//示例 3：

//输入：s = "(]"
//输出：false
//示例 4：

//输入：s = "([)]"
//输出：false

typedef char SLDatatype;
typedef struct stack
{
    SLDatatype* _data;
    int _size;
    int _capacity;
}stack;

//栈初始化
void stackInit(stack* st)
{
    st->_data = NULL;
    st->_capacity = st->_size = 0;
}

//栈的增容
void checkCapacity(stack* st)
{
    if (st->_capacity == st->_size) {
        int newCapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
        st->_data = (SLDatatype*)realloc(st->_data, sizeof(int) * newCapacity);
        st->_capacity = newCapacity;
    }
}

//入栈：尾插
void stackPush(stack* st, SLDatatype val)
{
    if (st == NULL)
        return;
    checkCapacity(st);
    st->_data[st->_size++] = val;
}

//出栈：尾删
void stackPop(stack* st)
{
    if (st == 0)
        return;
    if (st->_size > 0)
        st->_size--;
}

//显示栈顶的数据
SLDatatype stackTop(stack* st)
{
    return st->_data[st->_size - 1];
}


//获取栈有效元素的个数
int stackSize(stack* st)
{
    return st->_size;
}

//检查栈是否为空
int stackEmpty(stack* st)
{
    if (st == NULL || st->_size == 0)
        return 1;
    else
        return 0;

}

//销毁栈
void stackDestry(stack* st)
{
    if (st)
    {
        if (st->_data)
        {
            free(st->_data);
            st->_data = NULL;
        }
    }
}



bool isValid(char* s) {
    stack st;
    stackInit(&st);
    //左右括号的映射
    static char map[][2] = { {'(',')'},{'[',']'},{'{','}'} };
    //遍历字符串，左括号入栈，有括号匹配
    while (*s) {
        int i = 0;
        for (i = 0; i < 3; i++) {
            if (*s == map[i][0]) {
                //左括号入栈
                stackPush(&st, *s);
                ++s;
                break;
            }
        }
        //循环走完，说明不是一个左括号
        if (i == 3) {
            //让当前的右括号匹配栈顶元素
            if (stackEmpty(&st))
            {
                return false;
            }
            char topChar = stackTop(&st);
            //找出对应的右括号在map的位置
            for (int j = 0; j < 3; j++) {
                if (*s == map[j][1]) {
                    if (topChar == map[j][0]) {
                        //左右匹配，出栈
                        stackPop(&st);
                        ++s;
                        break;
                    }
                    else
                        return false;
                }

            }
        }
    }

    if (stackEmpty(&st))
        return true;
    return false;
}


//使用队列实现栈的下列操作：

//push(x) --元素 x 入栈
//pop() --移除栈顶元素
//top() --获取栈顶元素
//empty() --返回栈是否为空
//注意 :

//你只能使用队列的基本操作-- 也就是 push to back, peek / pop from front, size, 和 is empty 这些操作是合法的。
//你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
//你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。




typedef int QDataType;

//定义节点
typedef struct QNode
{
    struct QNode* _next;
    QDataType _data;
}QNode;

//定义队列
typedef struct Queue
{
    QNode* _front;
    QNode* _rear;
}Queue;


//初始化队列
void queueInit(Queue* q)
{
    //创建空队列
    q->_front = NULL;
    q->_rear = NULL;
}

//创建节点
QNode* creatNode(QDataType val)
{
    QNode* node = (QNode*)malloc(sizeof(QNode));
    node->_data = val;
    node->_next = NULL;
    return node;
}

//入队列：尾插
void queuePush(Queue* q, QDataType val)
{
    QNode* node = creatNode(val);
    if (q->_front == NULL)
        q->_front = q->_rear = node;
    else {
        q->_rear->_next = node;
        q->_rear = node;
    }
}

//出队列：头删
void queuePop(Queue* q)
{
    if (q->_front == NULL)
        return;
    QNode* next = q->_front->_next;
    free(q->_front);
    q->_front = next;
    //检查删除后是否为空队列
    if (q->_front == NULL)
        q->_rear = NULL;//如果不将rear指向NULL，rear还会指向已经free的内存，形成野指针
}

//获取队头元素
int  queueFront(Queue* q)
{
    return q->_front->_data;
}

//获取队尾元素
int  queueBack(Queue* q)
{
    return q->_rear->_data;
}

//获取队列有效元素的个数
int queueSize(Queue* q)
{
    int num = 0;
    QNode* cur = q->_front;
    while (cur)
    {
        num++;
        cur = cur->_next;
    }
    return num;
}

//判断队列是否为空队列，如果为空返回非零，如果不为空返回零
int queueEmpty(Queue* q)
{
    if (q->_front == NULL)
        return 1;
    return 0;
}

//销毁队列
void queueDestry(Queue* q)
{
    QNode* cur = q->_front;
    while (cur)
    {
        QNode* next = cur->_next;
        free(cur);
        cur = next;
    }
    q->_front = NULL;
    q->_rear = NULL;
}

typedef struct {
    Queue q;

} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
    queueInit(&ms->q);
    return ms;

}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    queuePush(&obj->q, x);

}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int ret;
    int size = queueSize(&obj->q);
    while (size > 1)
    {
        int front = queueFront(&obj->q);
        queuePop(&obj->q);
        queuePush(&obj->q, front);
        size--;

    }
    ret = queueFront(&obj->q);
    queuePop(&obj->q);
    return ret;

}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return queueBack(&obj->q);

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return queueEmpty(&obj->q);

}

void myStackFree(MyStack* obj) {
    queueDestry(&obj->q);
    free(obj);

}






//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）

typedef int SLDatatype;
typedef struct stack
{
    SLDatatype* _data;
    int _size;
    int _capacity;
}stack;

//栈初始化
void stackInit(stack* st)
{
    if (st == NULL)
        return;
    st->_data = NULL;
    st->_capacity = st->_size = 0;
}

//栈的增容
void checkCapacity(stack* st)
{
    if (st->_capacity == st->_size) {
        int newCapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
        st->_data = (int*)realloc(st->_data, sizeof(int) * newCapacity);
        st->_capacity = newCapacity;
    }
}

//入栈：尾插
void stackPush(stack* st, SLDatatype val)
{
    if (st == NULL)
        return;
    checkCapacity(st);
    st->_data[st->_size++] = val;
}

//出栈：尾删
void stackPop(stack* st)
{
    if (st == NULL)
        return;
    if (st->_size > 0)
        st->_size--;
}

//显示栈顶的数据
SLDatatype stackTop(stack* st)
{
    if (st->_data == NULL)
        return;
    return st->_data[st->_size - 1];
}


//获取栈有效元素的个数
int stackSize(stack* st)
{
    return st->_size;
}

//检查栈是否为空
int  stackEmpty(stack* st)
{
    if (st == NULL || st->_size == 0)
        return 1;
    else
        return 0;

}

//销毁栈
void stackDestry(stack* st)
{
    if (st)
    {
        if (st->_data)
        {
            free(st->_data);
            st->_data = NULL;
        }
    }
}



typedef struct {
    stack pushST;
    stack popST;

} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
    stackInit(&mq->pushST);
    stackInit(&mq->popST);
    return mq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    return stackPush(&obj->pushST, x);

}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int ret;
    if (stackEmpty(&obj->popST))
    {
        while (stackEmpty(&obj->pushST) != 1)
        {
            int top = stackTop(&obj->pushST);
            stackPop(&obj->pushST);
            stackPush(&obj->popST, top);
        }
    }
    ret = stackTop(&obj->popST);
    stackPop(&obj->popST);
    return ret;

}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {

    if (stackEmpty(&obj->popST))
    {
        while (stackEmpty(&obj->pushST) != 1)
        {
            int top = stackTop(&obj->pushST);
            stackPop(&obj->pushST);
            stackPush(&obj->popST, top);
        }
    }
    return stackTop(&obj->popST);

}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(&obj->pushST) && stackEmpty(&obj->popST);

}

void myQueueFree(MyQueue* obj) {
    stackDestry(&obj->pushST);
    stackDestry(&obj->popST);
    free(obj);

}



//循环队列


typedef struct {
    int* _data;
    //第一个元素的位置，队头元素；
    int _front;
    //最后一个元素的下一个位置
    int _rear;
    int _k;

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    mq->_data = (int*)malloc(sizeof(int) * (k + 1));
    mq->_front = mq->_rear = 0;
    mq->_k = k;
    return mq;

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->_front == obj->_rear)
        return true;
    return false;

}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if ((obj->_rear + 1) % (obj->_k + 1) == obj->_front)
        return true;
    else
        return false;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    //判断队列是否满
    if (myCircularQueueIsFull(obj))
        return false;
    obj->_data[obj->_rear++] = value;
    //判断队尾是否越界
    if (obj->_rear > obj->_k)
    {
        obj->_rear = 0;
    }
    return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    //判断队列是否为空
    if (myCircularQueueIsEmpty(obj))
        return false;
    //出队
    obj->_front++;
    //判断队头是否越界
    if (obj->_front > obj->_k)
        obj->_front = 0;
    return true;

}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->_data[obj->_front];

}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    if (obj->_rear != 0)
        return obj->_data[obj->_rear - 1];
    return obj->_data[obj->_k];

}



void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->_data);
    free(obj);

}
