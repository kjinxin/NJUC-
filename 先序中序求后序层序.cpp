#include<stdio.h>

#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node * Lchild;
    struct Node * Rchild;
}BiTNode,*BiTree;//�������ڵ㣬��������

typedef struct QueueNode{
    BiTree data;
    struct QueueNode *next;
}LinkQueueNode;//�����е�ÿ���ڵ�
typedef struct
{
    LinkQueueNode *front;
    LinkQueueNode *rear;
}LinkQueue;//����

//���еĳ�ʼ��
void InitQueue(LinkQueue *Q)
{
    Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(Q->front != NULL)
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
    }
    //else printf("����ռ�ʧ��!n");
}

//���
void EnterQueue(LinkQueue *Q,BiTree x)
{
    LinkQueueNode *NewNode;
    NewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(NewNode != NULL)
    {
        NewNode->data = x;
        NewNode->next = NULL;
        Q->rear->next = NewNode;
        Q->rear = NewNode;
    }

}
// �����п�
int QueueIsEmpty(LinkQueue *Q)
{
    if(Q->front == Q->rear)
    return 1;
    else return 0;
}
//����
void DeleteQueue(LinkQueue *Q,BiTree *x)
{
    LinkQueueNode *p;
    if(Q->front == Q->rear)
    return;
    p = Q->front->next;
    Q->front->next = p->next;
    if(Q->rear == p)
    Q->rear = Q->front;
    *x = p->data;
    free(p);
}

/*
* ������չ�����������
* ������������
*/
void CreateBiTree(BiTree *bt)
{
    char ch;
    ch = getchar();
    if(ch == '.') *bt = NULL;
    else
    {
        *bt = (BiTree)malloc (sizeof(BiTNode));
        (*bt)->data = ch;
        CreateBiTree(&((*bt)->Lchild));
        CreateBiTree(&((*bt)->Rchild));
    }
}
//����ݹ����������
void PreOrder(BiTree root)
{
    if(root != NULL){
printf("%c ",root->data);

PreOrder(root->Lchild);

PreOrder(root->Rchild);

}

}

/*

* ����ݹ����������

*

* */

void PostOrder(BiTree root)

{

if(root != NULL){

PostOrder(root -> Lchild);

PostOrder(root -> Rchild);

printf("%c ",root->data);

}

}

/*

* ����ݹ����������

*

* */

void InOrder(BiTree root)

{

if(root != NULL){

InOrder(root->Lchild);

printf("%c ",root->data);

InOrder(root->Rchild);

}

}

//�������
void LayerOrder(BiTree root)

{
BiTree *x;
x = (BiTree *)malloc(sizeof(BiTree));

if(x == NULL){

printf("�ڴ����ʧ��!n");

}

LinkQueue *Q;

Q = (LinkQueue *)malloc(sizeof(LinkQueue));

InitQueue(Q);

EnterQueue(Q,root);

while(!QueueIsEmpty(Q)){

DeleteQueue(Q,x);

printf("%c ",(*x)->data);

if((*x)->Lchild)EnterQueue(Q,(*x)->Lchild);

if((*x)->Rchild)EnterQueue(Q,(*x)->Rchild);

}

}

int main(int argc , char **argv)

{

BiTree root;

CreateBiTree(&root);

printf("����ݹ����:n");

PreOrder(root);

printf("n");

printf("����ݹ����:n");

InOrder(root);

printf("n");

printf("����ݹ����:n");

PostOrder(root);

printf("n");

printf("�������:n");

LayerOrder(root);

printf("n");

}
