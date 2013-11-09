//顺序栈类

#include <iostream.h>

template <class T>
class SeqStack                                   //顺序栈类
{
  private:
    T *element;                                  //动态数组存储栈的数据元素
    int size;                                    //栈的数组容量
    int top;                                     //栈顶元素下标

  public:
    SeqStack(int size=64);                       //构造指定（默认）容量的空栈
    ~SeqStack();                                 //析构函数 

    bool isEmpty();                              //判断是否空栈
    void push(T x);                              //入栈
    T pop();                                     //出栈
    T get();                                     //返回栈顶元素，未出栈
    friend ostream& operator<<(ostream& out, SeqStack<T> &stack);    //输出栈
};

template <class T>
SeqStack<T>::SeqStack(int size)                  //构造指定容量的空栈
{
    this->size = size<64 ? 64 : size;
    this->element = new T[this->size];
    this->top = -1;
}

template <class T>
SeqStack<T>::~SeqStack()                         //析构函数
{
    delete []element;
}

template <class T>
bool SeqStack<T>::isEmpty()                      //判断栈是否为空，若空返回true
{
    return top==-1;
}

template <class T>
void SeqStack<T>::push(T x)                      //入栈
{
    if (top==size-1)                             //若栈满，则扩充数组容量
    {
        T *temp = element;  
        element = new T[size*2];                 //重新申请一个容量更大的数组
        for (int i=0; i<size; i++)               //复制数组元素，O(n)
            element[i] = temp[i];
        size *=2;
    }
    top++;
    element[top] = x;
}

template <class T>
T SeqStack<T>::get()                             //返回栈顶元素，未出栈，若栈空则抛出异常
{
    if (!isEmpty())
        return element[top];
    throw "空栈，不能获得栈顶元素";
}

template <class T>
T SeqStack<T>::pop()                             //出栈，返回栈顶元素，若栈空则抛出异常
{
    if (!isEmpty())
    {
        T x = element[top];
        top--;
        return x;
    }
    throw "空栈，不能执行出栈操作";
}

template <class T>
ostream& operator<<(ostream& out, SeqStack<T> &stack) //输出栈
{
    out<<"SeqStack: (";
    if (!stack.isEmpty())
    {
        for (int i=0; i<stack.top; i++)
             out<<stack.element[i]<<", ";
        out<<stack.element[stack.top];
    }
    out<<")\n";
    return out;
}
