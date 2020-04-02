//to convert postfix to infix expression

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int size=20;
int top=-1;
int a[20];
void push(char x)
{	if(top==size-1)
		printf("Oveflow \n");
	else if(top==-1)
	{	top=0;
		a[top]=x;
	}
	else
	{	top++;
		a[top]=x;
	}
}

char pop()
{	char item;
	if(top==-1)
		printf("Underflow \n");
	else
	{	item=a[top];
		top--;
		return item;
	}
}

int priority(char ch)
{	if (ch=='(')
		return 0;
	else if(ch=='+' || ch=='-')
		return 1;
	else if(ch=='*' || ch== '/')
		return 2;
	else if(ch=='^')
		return 3;
}

void main()
{	char exp[20],p,ch;
	int opt,l,i;
	char ans;
	do
	{	printf("1.Postfix to Infix \n  2.Infix to ppstfix \n Enter your option \n");
		scanf(" %d",&opt);
		switch(opt)
		{	case 2:printf("Enter expression \n");
				scanf(" %s",exp);
				l=strlen(exp);
	for(i=0;i<l;i++)
	{	ch=exp[i];
		if(isalnum(ch))
			printf("%c",ch);
		else if(ch=='(')
			push(ch);
		else  if(ch==')')
			{	while((p=pop())!='(')
					printf("%c",p);
			}
		else
		{ while(priority(a[top])>=priority(ch))
			
			printf("%c",pop());
			push(ch);
		}
}

while(top!=-1)
printf("%c",pop());
break;
	default:printf("Wrong option \n");
	}
	printf("Dywtc ? \n");
	scanf("%c",&ans);
	}while(ans=='y'||ans=='Y');
}
