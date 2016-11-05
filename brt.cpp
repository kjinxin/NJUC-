#include <cstdio>
#include <malloc.h>
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BTNode,BTree;
BTree* InsertBST(BTree *T,int key)
{
    BTree *f=T,*p=T;
    while(p)
    {
        //if(p->data==key) return T;
        f=p;  //��f���²���·���ϵ����һ�����ʵĽڵ�
        p=(key<p->data)? p->lchild:p->rchild;
    }
    p=(BTNode*)malloc(sizeof(BTNode));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(T==NULL)
    T=p;
    else
    if (key<f->data)
    f->lchild=p;
    else
    f->rchild=p;
    return T;
}
//�ݹ��������
void InOrderDisplay(BTree *T){
    if(T)
    {
        InOrderDisplay(T->lchild);
        printf("%d ",T->data);
        InOrderDisplay(T->rchild);
    }
}

int main(){
    int i,data,n;
    BTree *tree=NULL;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&data);
        tree=InsertBST(tree,data);
    }
    InOrderDisplay(tree);
    printf("\n");
    return 0;
}
