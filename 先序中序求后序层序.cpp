#include<stdio.h>

#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node * Lchild;
    struct Node * Rchild;
}BiTNode,*BiTree;//二叉树节点，二叉链表

typedef struct QueueNode{
    BiTree data;
    struct QueueNode *next;
}LinkQueueNode;//队列中的每个节点
typedef struct
{
    LinkQueueNode *front;
    LinkQueueNode *rear;
}LinkQueue;//队列

//队列的初始化
void InitQueue(LinkQueue *Q)
{
    Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(Q->front != NULL)
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
    }
    //else printf("分配空间失败!n");
}

//入队
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
// 队列判空
int QueueIsEmpty(LinkQueue *Q)
{
    if(Q->front == Q->rear)
    return 1;
    else return 0;
}
//出队
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
* 利用扩展先序遍历序列
* 创建二叉链表
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
//先序递归遍历二叉树
void PreOrder(BiTree root)
{
    if(root != NULL){
printf("%c ",root->data);

PreOrder(root->Lchild);

PreOrder(root->Rchild);

}

}

/*

* 后序递归遍历二叉树

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

* 中序递归遍历二叉树

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

//层序遍历
void LayerOrder(BiTree root)

{
BiTree *x;
x = (BiTree *)malloc(sizeof(BiTree));

if(x == NULL){

printf("内存分配失败!n");

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

printf("先序递归遍历:n");

PreOrder(root);

printf("n");

printf("中序递归遍历:n");

InOrder(root);

printf("n");

printf("后序递归遍历:n");

PostOrder(root);

printf("n");

printf("层序遍历:n");

LayerOrder(root);

printf("n");

}
