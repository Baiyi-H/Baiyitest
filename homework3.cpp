#include<stdio.h>
#include<stdlib.h>
#define max 2014
typedef struct stack
{
	int data[max];
	int top;
}stack;
stack *createstack(void)//创建栈
{
	stack *s;
	s=(stack*)malloc(sizeof(stack));
	s->top=-1;
	return s;
}
int stackempty(stack *s)//判断栈空
{
	if(s)
	{
		if(s->top==-1)
			return 1;
		else 
			return 0;
	}
	return -1;
}
int stackfull(stack *s)//判断栈满
{
	if(s)
	{
		if(s->top==max-1)
			return 1;
		else
			return 0;
	}
	return -1;
}
void push(stack *s,int x)//入栈
{
	if(s)
	{
		if(stackfull(s)==0)
			s->data[++s->top]=x;
	}
}
int pop(stack *s)//出栈
{
	if(s)
		if(stackempty(s)==0)
			return s->data[s->top--];
}
void clearstack(stack *s)//清除栈
{
	if(s)
		s->top=-1;
}
void destroystack(stack *s)//销毁栈
{
	if(s)
	{
		s->top=-1;
		free(s);
		s=NULL;
	}
}
int func(char* p)//判断运算符的优先级
{
	if(*p=='*'||*p=='/')
		return 1;
	else if(*p=='+')
		return 0;
	else
		return 2;
}
int Func(stack *s1,stack *s2)//对数据进行运算
{
	char ch[1000]={0},w;
	char *p=ch,*q=ch;
	int a,b,c,flag=0,flag1=0;
	while((*q=getchar())!='\n')
	{
		q++;
	}
	while(1)
	{
		a=0;
		b=0;
		while(*p>='0'&&*p<='9')
		{
			a=*p-'0';
			b=b*10+a;
			p++;
		}
		if(flag==1)
		{
			c=pop(s1);
			w=pop(s2);
			if(w=='*')
				b=b*c;
			else
				b=c/b;
			flag=0;
		}
		if(*p=='=')//等号结束运算
			break;
		push(s1,b);
		push(s2,*p);
		if(func(p)==1)
		{
			flag=1;
		}
		p++;
	}
	if(stackempty(s2)==0)
	{
		w=pop(s2);
		if(w=='-')
			b=-b;
	}
	while(stackempty(s1)==0)
	{
		c=pop(s1);
		if(stackempty(s2)==0)
			w=pop(s2);
		else
		{
			b=b+c;
			break;
		}
		if(w=='-')
			b=b-c;
		else
			b=b+c;	  
	}
	return b;
}
int main()
{
	stack *s1=createstack();
	stack *s2=createstack();
	int x=Func(s1,s2);
	printf("计算结果为: %d",x); 
	printf("\n"); 
	return 0;
}
