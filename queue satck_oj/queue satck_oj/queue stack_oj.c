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

