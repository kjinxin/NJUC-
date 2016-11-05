/* �Թ�����ķǵݹ��㷨(ջʵ��)*/


#define MAXNUM        100/* ջ�����Ԫ�ظ��� */
#define N 11 /*��ͼ�ĵ�һά����*/
#include <stdio.h>
#include <stdlib.h>

typedef struct

{

int  x;/* ���±� */

int  y;/* ���±� */

int  d;/* �˶����� */

}DataType;

	struct  SeqStack	  		/* ˳��ջ���Ͷ��� */
	{	DataType  s[MAXNUM];
		int  t; 			/* ָʾջ��λ�� */
	};
	typedef  struct SeqStack  *PSeqStack;	/* ˳��ջ���͵�ָ������ */
	PSeqStack  pastack;					/* pastack��ָ��˳��ջ��һ��ָ����� */


PSeqStack  createEmptyStack_seq( void )
   {  PSeqStack pastack;
	  pastack = (PSeqStack)malloc(sizeof(struct SeqStack));
	  if (pastack==NULL)
			printf("Out of space!! \n");
	  else
			pastack->t=-1;
	  return  (pastack);
}


int  isEmptyStack_seq( PSeqStack pastack )
    {
	    return ( pastack->t == -1 );
}


void  push_seq( PSeqStack pastack, DataType x )
/* ��ջ��ѹ��һԪ��x */
{  if( pastack->t >= MAXNUM - 1  )
      printf( "Overflow! \n" );
  else
	{  pastack->t = pastack->t + 1;
	   pastack->s[pastack->t] = x;
	 }
}


void  pop_seq( PSeqStack pastack )
/* ɾ��ջ��Ԫ�� */
{  	if (pastack->t == -1 )
			printf( "Underflow!\n" );
    		else
			pastack->t = pastack->t - 1;
	}


DataType  top_seq( PSeqStack pastack )
/* ��pastack��ָ��ջ��Ϊ��ջʱ����ջ��Ԫ�ص�ֵ */
    {
        return (pastack->s[pastack->t]);
	 }



void pushtostack(PSeqStack st, int x, int y, int d)

{    DataType element;

      element.x = x;

element.y = y;

element.d = d;

push_seq(st,element);

}



void printpath(PSeqStack st)

{DataType element;
   printf("The revers path is:\n");     /* ��ӡ·���ϵ�ÿһ�� */

while(!isEmptyStack_seq(st))

{    element=top_seq(st);

pop_seq(st);

printf("the node is: %d %d \n",element.x,element.y);

}

}




void mazePath(int maze[][N],int direction[][2],int x1,int y1,int x2,int y2)

/* �Թ�maze[M][N]��������maze[x1][y1]������maze[x2][y2]��һ��·�� */

/* ���� 1<=x1,x2<=M-2 , 1<=y1,y2<=N-2 */

{    int i,j,k,g,h;

PSeqStack st;

DataType element;

st = createEmptyStack_seq( );

maze[x1][y1] = 2;                          /* ����ڿ�ʼ����,����� */                    

pushtostack(st, x1, y1, -1);              /* ��ڵ��ջ */

while (! isEmptyStack_seq(st))         /* �߲�ͨʱ,һ�������� */

{    element = top_seq(st);

pop_seq(st);

i = element.x; j = element.y; k = element.d + 1;

while (k<=3)                      /* ������̽ÿ������ */

{    g = i + direction[k][0];h = j + direction[k][1];

if (g==x2 && h==y2 && maze[g][h]==0)     /* �ߵ����ڵ� */

{    printpath(st);        /* ��ӡ·�� */

return;

}

if (maze[g][h]==0)            /* �ߵ�û�߹��ĵ� */

{    maze[g][h] = 2;            /* ����� */

pushtostack(st, i, j, k);   /* ��ջ */

i = g; j = h; k = -1;          /* ��һ��ת���ɵ�ǰ�� */

}

k = k + 1;

}

}

printf("The path has not been found.\n");              /* ջ����,δ�ҵ�·�� */

}

int main(){
int direction[][2]={0,1,1,0,0,-1,-1,0};
int maze[][N]={1,1,1,1,1,1,1,1,1,1,1,
1,0,1,0,0,1,1,1,0,0,1,
1,0,0,0,0,0,1,0,0,1,1,
1,0,1,1,1,0,0,0,1,1,1,
1,0,0,0,1,0,1,1,0,1,1,
1,1,0,0,1,0,1,1,0,0,1,
1,1,1,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1};
mazePath(maze,direction,1,1,6,9);
return 0;
}

		

