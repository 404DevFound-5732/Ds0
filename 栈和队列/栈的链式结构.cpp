#include <iostream>
using namespace std;

typedef int ElemType;

// 栈结点结构
struct Stack
{
    ElemType data;
    Stack* next;
};

// 初始化栈
Stack* initStack()
{
    Stack* s = new Stack;
    s->data = 0;
    s->next = nullptr;
    return s;
}

// 判断栈空
bool isEmpty(Stack* s)
{
    return s->next == nullptr;
}

// 进栈
bool push(Stack* s, ElemType e)
{
    Stack* p = new Stack;
    p->data = e;
    p->next = s->next;
    s->next = p;
    return true;
}

// 出栈
bool pop(Stack* s, ElemType& e)
{
    if (isEmpty(s))
    {
        cout << "栈为空，无法出栈！" << endl;
        return false;
    }
    e = s->next->data;
    Stack* q = s->next;
    s->next = q->next;
    delete q;
    return true;
}

// 获取栈顶
bool getTop(Stack* s, ElemType& e)
{
    if (isEmpty(s))
    {
        cout << "栈为空！" << endl;
        return false;
    }
    e = s->next->data;
    return true;
}

// 菜单
void showMenu()
{
    cout << "\n====== 栈交互操作 ======" << endl;
    cout << "1. 进栈" << endl;
    cout << "2. 出栈" << endl;
    cout << "3. 查看栈顶元素" << endl;
    cout << "0. 退出程序" << endl;
    cout << "请输入操作编号：";
}

int main()
{
    Stack* s = initStack();
    int choice;
    ElemType e;

    while (true)
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "请输入要压入的数字：";
            cin >> e;
            push(s, e);
            cout << "进栈成功！" << endl;
            break;

        case 2:
            if (pop(s, e))
                cout << "出栈成功，弹出元素：" << e << endl;
            break;

        case 3:
            if (getTop(s, e))
                cout << "栈顶元素是：" << e << endl;
            break;

        case 0:
            cout << "程序已退出！" << endl;
            return 0;

        default:
            cout << "输入错误，请重新选择！" << endl;
        }
    }
    return 0;
}