#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node* next;
};
struct node* head = NULL;
int n;
int check = 0;
int main()
{
    scanf("%d",&n);
	int len = n;
    char opt1[10]="addlast",opt2[10]="addfirst",opt3[10]="addafter",opt4[10]="addbefore",opt5[10]="remove",opt6[10]="reverse";
    while(len>0)
    {
    	struct node* curr  = (struct node*)malloc(sizeof(struct node));
    	struct node* temp = head;
		int temp1;
	    scanf("%d",&temp1);
		if(check==0)
		{
			curr->val = temp1;
			curr->next = head;
			head = curr;
			check = 1;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			curr->val = temp1;
			curr->next = NULL;
			temp->next= curr;
		}
		len-=1;
	}
	char var[10];
	do
	{
		fflush(stdin);
		scanf("%s",var);
		if(strcmp(var,opt1)==0)
		{
			int temp1;
	    	scanf("%d",&temp1);
			int check = 1;
			struct node* f = head;
			while(f!=NULL)
			{
				if (f->val==temp1)
				{
					check = 0;
				}
				f= f->next;
			}
			if(check==1)
			{
				struct node* temp = head;
				struct node* curr  = (struct node*)malloc(sizeof(struct node));
				while(temp->next!=NULL)
				{
					temp = temp->next;
				}

				curr->val = temp1;
				curr->next = NULL;
				temp->next = curr;
			}
			

		}
		else if(strcmp(var,opt2)==0)
		{
			int temp1;
			int check = 1;
			scanf("%d",&temp1);
			struct node* f = head;
			while(f!=NULL)
			{
				if (f->val==temp1)
				{
					check = 0;
				}
				f= f->next;
			}
			if(check==1)
			{
				struct node* curr  = (struct node*)malloc(sizeof(struct node));
				
				struct node* temp = head;
				
				curr->val = temp1;
				curr->next = temp;
				head = curr;
			}
		}
		else if(strcmp(var,opt3)==0)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			struct node* temp = head;
			int check1=1,check2= 1;
			struct node* f1 = head,*f2 = head;
			while(f1!=NULL)
			{
				if (f1->val==u)
				{
					check1 = 0;
				}
				f1= f1->next;
			}
			while(f2!=NULL)
			{
				if (f2->val==v)
				{
					check2 = 0;
				}
				f2= f2->next;
			}
			if(check1==1 && check2==0)
			{
				while(temp!=NULL)
				{
					if (temp->val==v)
					{
						struct node* curr  = (struct node*)malloc(sizeof(struct node));
						curr->val = u;
						if(temp->next==NULL)
						{
							curr->next = NULL;
							temp->next = curr;
						}
						else
						{
							struct node* curr2  = temp->next;
							temp->next = curr;
							curr->next = curr2;
						}
					}
					temp = temp->next;
				}
			}
			

		}
		else if(strcmp(var,opt4)==0)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			struct node* temp = head;
			int check1=1,check2= 1;
			struct node* f1 = head,*f2 = head;
			while(f1!=NULL)
			{
				if (f1->val==u)
				{
					check1 = 0;
				}
				f1= f1->next;
			}
			while(f2!=NULL)
			{
				if (f2->val==v)
				{
					check2 = 0;
				}
				f2= f2->next;
			}
			if(check1==1 && check2==0)
			{
			
				if(temp->val==v)
				{
					
						struct node* curr  = (struct node*)malloc(sizeof(struct node));
						curr->val = u;
						curr->next = head;
						head =  curr;

					
				}
				
				while(temp->next!=NULL )
				{
						struct node* curr  = (struct node*)malloc(sizeof(struct node));
						if (temp->next->val==v)
						{
							curr->val = u;
							struct node* curr2 = temp->next;
							temp->next = curr;
							curr->next = curr2;
							temp = temp->next->next;

						}
						else
						{
							temp = temp->next;
						}
						

				}
				
	
				
			}
			
		}
		else if (strcmp(var,opt5)==0)
		{
			int k;
			scanf("%d",&k);
			struct node* temp = head;
			if(temp->val==k)
			{
				head = temp->next;
			}
			
				while ( temp!=NULL && temp->next!=NULL)
				{
					if(temp->next->val ==k)
					{
						struct node* g = temp->next->next;
						temp->next = g;
					}
					temp = temp->next;

				}
				
			
		}
		else if(strcmp(var,opt6)==0)
		{
			int i=0,len = 0;
			struct node *temp = head;
			while(temp!=NULL)
			{
				len+=1;
				temp = temp->next;
			}
			len-=1;
			while(i<len)
			{
				struct node* temp1 = head,*temp3 = head;
				int x=0,y =0;
				while(x<i)
				{
					x+=1;
					temp1 = temp1->next;
				}
				while(y<len)
				{
					y+=1;
					temp3 = temp3->next;
				}
				int b = temp1->val;
				temp1->val = temp3->val;
				temp3->val = b;
				i+=1;
				len-=1;
			}

			
		}
	}
	while(strcmp(var,"#")!=0);
	struct node* temp = head;
    while(temp!=NULL)
	{
		printf("%d ",temp->val);
		temp = temp->next;
	}
}