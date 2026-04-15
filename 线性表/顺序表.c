#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int ElemType;

typedef struct 
{
    int *data;
    int length;
}Seqlist;

//初始化
Seqlist* initList()
{
    Seqlist* L = (Seqlist*)malloc(sizeof(Seqlist));
    L->data = (int*)malloc(sizeof(ElemType) * MAXSIZE);
    L->length = 0;
    return L;
}
//尾部添加元素
Seqlist* appendElem(Seqlist* L, ElemType e)
{
    if (L->length >= MAXSIZE)
    {
        printf("over");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;

}
//遍历
void listElem(Seqlist* L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ",L->data[i]);
    }
}
//插入
int insertElem(Seqlist *L, int pos, ElemType e)
{
    if (pos<=L->length)
    {
        for (int i = L->length; i>=pos - 1; i--)
        {
            L->data[i+1] = L->data[i];
        }
        L->data[pos-1] = e;
        L->length++;
    }
}
//删除数据
int deletElem(Seqlist* L, int pos,ElemType *e)
{
    if (L->length == 0)
    {
        printf("blank!");
        return 0;
    }
    if (pos < 1 || pos > L->length)
    {
        printf("not hefa");
        return 0;
    }
    *e = L->data[pos-1];
    for (int i = pos - 1; i < L->length; i++)
    {
        L->data[i] = L->data[i+1];
    }
    L->length--;
    return 1;
}
int findElem(Seqlist *L, ElemType e)
{
	if (L->length == 0)
	{
		printf("空列表\n");
		return 0;
	}

	for (int i = 0; i < L->length; i++)
	{
		if(L->data[i] == e)
		{
			return i + 1;
		}
	}

	return 0;
}
int main(int argc, char const *argv[])
{
    Seqlist* List;
    List = initList();
    appendElem(List,4);
    appendElem(List,5);
    appendElem(List,6);

    insertElem(List,2,9);
    insertElem(List,2,8);
    insertElem(List,2,6);
    insertElem(List,3,4);
    insertElem(List,4,7);
    listElem(List);
    ElemType dfault;
    deletElem(List,2,&dfault);
    printf("----%d-----",dfault);
    listElem(List);

}