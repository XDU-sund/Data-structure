#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
typedef char ElemType;
typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}sqStack;

void initStack(sqStack *s)
{
	/*�ڴ��п���һ�������ռ���Ϊջ�ռ䣬�׵�ַ��ֵ��s->base*/
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base)
	exit(0);      //����ռ�ʧ��
	s->top = s->base;    //�ʼ��ջ������ջ��
	s->stacksize = STACK_INIT_SIZE;    //�������ΪSTACK_INIT_SIZE 
}

void Push(sqStack *s, ElemType e) {
	if (s->top - s->base >= s->stacksize)
	{	//ջ����׷�ӿռ� 
		s->base = (ElemType *)realloc(s->base,(s->stacksize + STACKINCREMENT) * sizeof(ElemType));
		if (!s->base)
		exit(0);      //�洢����ʧ��
		s->top = s->base + s->stacksize;
		s->stacksize = s->stacksize + STACKINCREMENT;   //����ջ��������� 
	}
	*(s->top) = e;     //�������� 
	s->top++;
}

void Pop (sqStack *s, ElemType *e){
	if (s->top == s->base) 
	exit(0);
	*e = *--(s->top);     //�Ƚ�top��ַ��һ���ٽ��޸ĺ�ĵ�ַ�ϵ�ֵ��ֵ��e 
}

int StackLen (sqStack s){
	return (s.top - s.base);
}

void DestroyStack(sqStack *s){
	free (s->base);   //�ͷŵ��ڴ�ռ�
	s->base = s->top = NULL;   //ջ��ջ��ָ������ΪNULL
	s->stacksize = 0;      //����ջ���������Ϊ0 
}

int main(void)
{
	ElemType c;
	sqStack s;
	int len, i, sum = 0;
	printf("Please input a Binary digit\n");
	
	initStack(&s);      //����һ��ջ�������洢�������ַ���
	/*����0/1�ַ���ʾ�Ķ�����������#����*/
	scanf("%c",&c) ;
	while (c != '#')
	{
		Push(&s,c);
		scanf("%c",&c);
	}
	getchar();
	len = StackLen(s);    //�õ�ջ�е�Ԫ�ظ����������������ĳ���
	for (i = 0;i < len;i++) {
		Pop(&s,&c);
		sum = sum + (c - 48) * pow(2,i);  //ת��Ϊʮ���� 
	}
	printf("Decimal is %d\n",sum);
	DestroyStack(&s);    //�ͷ�ջ�ռ�
	return 0; 
}















