//˳��ջ��

#include <iostream.h>

template <class T>
class SeqStack                                   //˳��ջ��
{
  private:
    T *element;                                  //��̬����洢ջ������Ԫ��
    int size;                                    //ջ����������
    int top;                                     //ջ��Ԫ���±�

  public:
    SeqStack(int size=64);                       //����ָ����Ĭ�ϣ������Ŀ�ջ
    ~SeqStack();                                 //�������� 

    bool isEmpty();                              //�ж��Ƿ��ջ
    void push(T x);                              //��ջ
    T pop();                                     //��ջ
    T get();                                     //����ջ��Ԫ�أ�δ��ջ
    friend ostream& operator<<(ostream& out, SeqStack<T> &stack);    //���ջ
};

template <class T>
SeqStack<T>::SeqStack(int size)                  //����ָ�������Ŀ�ջ
{
    this->size = size<64 ? 64 : size;
    this->element = new T[this->size];
    this->top = -1;
}

template <class T>
SeqStack<T>::~SeqStack()                         //��������
{
    delete []element;
}

template <class T>
bool SeqStack<T>::isEmpty()                      //�ж�ջ�Ƿ�Ϊ�գ����շ���true
{
    return top==-1;
}

template <class T>
void SeqStack<T>::push(T x)                      //��ջ
{
    if (top==size-1)                             //��ջ������������������
    {
        T *temp = element;  
        element = new T[size*2];                 //��������һ���������������
        for (int i=0; i<size; i++)               //��������Ԫ�أ�O(n)
            element[i] = temp[i];
        size *=2;
    }
    top++;
    element[top] = x;
}

template <class T>
T SeqStack<T>::get()                             //����ջ��Ԫ�أ�δ��ջ����ջ�����׳��쳣
{
    if (!isEmpty())
        return element[top];
    throw "��ջ�����ܻ��ջ��Ԫ��";
}

template <class T>
T SeqStack<T>::pop()                             //��ջ������ջ��Ԫ�أ���ջ�����׳��쳣
{
    if (!isEmpty())
    {
        T x = element[top];
        top--;
        return x;
    }
    throw "��ջ������ִ�г�ջ����";
}

template <class T>
ostream& operator<<(ostream& out, SeqStack<T> &stack) //���ջ
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
