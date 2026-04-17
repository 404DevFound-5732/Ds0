#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef int ElemType;
#define MAXSIZE 100
struct Stack
{
    ElemType data[MAXSIZE];
    int top;

    //初始化
    Stack()
    {
        top = -1;
    }
    //进栈
    bool push(ElemType e)
    {
        if (top == MAXSIZE -1)
        {
            cout << "满了" << endl;
            return false;
        }
        data[++top] = e;
        return true;
    }
    //出栈
    bool pop(ElemType &e)
    {
        if (top == -1)
        {
            cout << "空的" << endl;
            return false;
        }
        e = data[top--];
        return true;
    }
    bool getTop(ElemType &e) {
        if (top == -1) {
            cout << "栈空，没有栈顶元素。" << endl;
            return false;
        }
        e = data[top]; // 直接赋值，不改 top
        return true;
    }

    // 4. 输出栈内全部元素
    void display() {
        if (top == -1) {
            cout << "当前栈为空。" << endl;
            return;
        }
        cout << "当前栈内元素（从顶到底）: ";
        for (int i = top; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack s;
    int choose;
    ElemType value;
    bool t = true;
    while(t)
    {
        cout << "\n请选择操作: 1.入栈  2.出栈  3.看栈顶  4.打印全栈  5.退出" << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
            cout << "请选择入栈的数字：";
            cin >> value;
            s.push(value);
            break;
        case 2:
            if(s.pop(value))
            {
                cout << "出栈成功，弹出值是：" << value << endl;
            }
            break;
        case 3:
            if (s.getTop(value)) cout << "当前栈顶元素为: " << value << endl;
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "退出" << endl;
            t = false;
            break;
        default:
            break;
        }

    }

}
