#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

struct Book
{
    string id;
    string name;
    double price;
};

typedef struct Node
{
    Book data;
    Node *next;
}Node;

//初始化
Node* initList()
{
    Node* hd = new Node;
    hd->next = nullptr;
    return hd;
}
//取值

int GetElem(Node* hd,int pos, Book &e)
{
    if (pos<1)
    {
        return 0;
    }
    Node* p = hd->next;
    int con = 1;
    while(p != nullptr && con <pos)
    {
        p = p->next;
        con++;
    }
    if (p==nullptr) return 0;
    e = p->data;
    return 1;
}
//按价格查找，
int LocateElem(Node* hd, double price)
{
    Node* p = hd->next;
    int con = 1;
    while(p != nullptr)
    {
        if (p->data.price == price)
        {
            return con;
        }
        p = p->next;
        con++;
    }
    return 0;
}
//插入
int Listinsert(Node* hd, int i,Book e)
{
    if(i < 1) return 0;
    Node* p = hd;
    int con = 0;
    while(p != nullptr && con < i-1)
    {
        p = p->next;
        con++;
    }
    if (p == nullptr) return 0;
    Node* q = new Node;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}
//删除
int ListDelete(Node* hd, int i)
{
    if (i < 1) return 0;
    Node* p = hd;
    int con = 0;
    while(p != nullptr && con < i-1)
    {
        p = p->next;
        con++;
    }
    if (p == nullptr || p->next == nullptr) return 0;
    Node* q = p->next;
    p->next = q->next;
    delete q;
    return 1;
}
//输出
void printList(Node* hd)
{
    Node* p = hd->next;
    while(p != nullptr)
    {
        cout << left <<setw(15) << p->data.id
            << "\t" << left << setw(50) << p->data.name
            << "\t" << left << setw(5) << p->data.price << endl;
        p = p->next;
    }
}
int main()
{
    Node* L = nullptr;
    int i = 0,temp, a, c, choose;
    double price;
    Book e;
    string head1,head2,head3;
    cout << "1. 建立\n";
    cout << "2. 输入\n";
    cout << "3. 取值\n";
    cout << "4. 查找\n";
    cout << "5. 插入\n";
    cout << "6. 删除\n";
    cout << "7. 输出\n";
    cout << "0. 退出\n\n";
    choose = -1;
    while(choose != 0)
    {
        cout << "请选择：";
        cin >> choose;
        switch (choose)
        {
            case 1:
                L = initList();
                cout << "链表建立成功" << endl;
                break;
            case 2: {
                if(!L) { cout << "请先执行1初始化！" << endl; break; }
                fstream file("book.txt");
                if(!file) { cout << "未找到文件" << endl; break; }
                file >> head1 >> head2 >> head3;
                Node* tail = L;
                while(tail->next) tail = tail->next;
                while(file >> e.id >> e.name >> e.price) {
                    Node* q = new Node;
                    q->data = e;
                    q->next = nullptr;
                    tail->next = q;
                    tail = q;
                }
                cout << "数据导入成功！" << endl;
                file.close();
                break;
            }
            case 3:
            cout << "请输入一个位置用来取值：\n";
            cin >> i;
            temp = GetElem(L, i, e);
            if (temp != 0) {
                cout << "查找成功\n";
                cout << "第" << i << "本图书的信息是：\n";
                cout << left << setw(15) << e.id << "\t" << left << setw(50)
                     << e.name << "\t" << left << setw(5) << e.price << endl << endl;
            } else
                cout << "查找失败！位置超出范围\n\n";
            break;

        case 4:
            cout << "请输入所要查找价格:";
            cin >> price;
            temp = LocateElem(L, price);
            if (temp != 0) {
                cout << "查找成功\n";
                GetElem(L, temp, e);
                cout << "该价格对应的书名为：" << e.name << endl << endl;
            } else
                cout << "查找失败！没有这个价格对应的书籍\n\n";
            break;

        case 5:
            cout << "请输入插入的位置和书本信息，包括：编号 书名 价格（用空格隔开）:";
            cin >> a;
            cin >> e.id >> e.name >> e.price;
            if (Listinsert(L, a, e))
                cout << "插入成功.\n\n";
            else
                cout << "插入失败.\n\n";
            break;

        case 6:
            cout << "请输入所要删除的书籍的位置:";
            cin >> c;
            if (ListDelete(L, c))
                cout << "删除成功.\n\n";
            else
                cout << "删除失败.\n\n";
            break;

        case 7:
            cout << "当前图书系统信息（链表）读出:\n";
            printList(L);
            cout << endl;
            break;
        }
    }
}