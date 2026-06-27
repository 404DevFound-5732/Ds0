#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild;
    struct ThreadNode *rchild;
    int ltag;
    int rtag;
}ThreadNode;
typedef ThreadNode* ThreadTree;

char str[] = "ABDH##I##EJ###CF##G##";
int idx = 0;

ThreadTree prev;
void createTree(ThreadTree *T)
{
    ElemType ch;
    ch = str[idx++];
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (ThreadTree)malloc(sizeof(ThreadTree));

        (*T)->data = ch;

        createTree(&(*T)->lchild);
        if((*T)->lchild != NULL)
        {
            (*T)->ltag = 0;
        }

        createTree(&(*T)->rchild);  
        if((*T)->rchild != NULL)
        {
            (*T)->rtag = 0;
        }

    }
}
//线索化
void threading(ThreadTree T)
{
    if(T != NULL)
    {
        threading(T->lchild);
        if(T->lchild == NULL)
        {
            T->ltag = 1;
            T->lchild = prev;
        }
        if(prev->rchild == NULL)
        {
            prev->rtag = 1;
            prev->rchild = T;
        }
        prev = T;
        threading(T->rchild);
    }
}

//开始线索化
void inOrderThreading(ThreadTree *head,ThreadTree T)
{
    *head = (ThreadTree)malloc(sizeof(ThreadNode));
    (*head)->ltag = 0;
    (*head)->rtag = 1;
    (*head)->rchild = (*head);

	if (T == NULL)
	{
		(*head)->lchild = *head;
	}
    else
    {
        (*head)->lchild = T;
        prev = (*head);

        threading(T);

        prev->rchild = *head;
        prev->rtag = 1;

		(*head)->rchild = prev;
    }
}

void inOrder(ThreadTree T)
{
    ThreadTree cur;
    cur = T->lchild;
    while (cur != T)
    {
        while(cur->ltag = 0)
        {
            cur = cur->lchild;
        }
        printf("%c ",cur->data);

        while (cur->rtag == 1 && cur->rchild != T)
        {
            /* code */cur = cur->rchild;
            printf("%c ",cur->data);
        }
        cur = cur->rchild;
        
    }
    
}
int main(int argc, char const *argv[])
{
	ThreadTree head;
	ThreadTree T;
	//创建
	createTree(&T);
	//线索化
	inOrderThreading(&head, T);
	//基于线索遍历
	inOrder(head);

	return 0;
}
