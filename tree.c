#include<stdio.h>
int arr[1000] ;
int i=0;
typedef struct Node
{
    int val;
    Node* children  = (Node*)malloc(sizeof(struct Node));    

}Node;
Node * root;
void makeroot()
{
    int val;
    scanf("%d",&val);
    root->val = val;
    root->children = NULL;
}
Node* find(Node* prev ,int v)
{
    if(prev==NULL) return NULL;
    if(prev->val==v) return prev;
    Node* p = prev->leftmostchild;
    while(p!=NULL)
    {
        Node* q = find(p,v);
        if(q!=NULL) return q;
        p = p->rightsibling;
    }
}
void insert()
{
    int u,v;
    scanf("%d %d",&u,&v);
    Node* temp = root;
    Node* add = find(temp,v);
    if(add->leftmostchild==NULL)
    {
        Node* x = (Node*)malloc(sizeof(Node));
        x->val = u;
        x->leftmostchild = NULL;
        x->rightsibling  =NULL;
        add->leftmostchild =x;
    }
    else
    {
        while(add->rightsibling!=NULL)
        {
            add = add->rightsibling;
        }
        Node* x = (Node*)malloc(sizeof(Node));
        x->val = u;
        x->leftmostchild = NULL;
        x->rightsibling  =NULL;
        add->rightsibling = x;
    }
}
void preorder(Node *p)
{
    int i=0;
    if(p==NULL) return;
    Node *x = p->leftmostchild;
    while(x!=NULL)
    {
        x = x->leftmostchild;
    }
    arr[i] = x->val;
    i++;
}
int main()
{
    char st1 = "MakeRoot",st2 = "Insert",st3 = "PreOrder",st4 = "InOrder",st5 = "PostOrder";
    char choice[10];
    do
    {
        fflush(stdin);
        scanf("%s",choice);
        if (strcmp(choice,"*")==0)
        {
            break;
        }
        if (strcmp(choice,st1)==0)
        {
            makeroot();
        }
        else if (strcmp(choice,st2)==0)
        {
            insert();
        }
        else if (strcmp(choice,st3)==0)
        {
            preorder();
        }
        else if (strcmp(choice,st4)==0)
        {
            inorder();
        }
        else if (strcmp(choice,st5)==0)
        {
            postorder();
        }
    }
    while(strcmp(choice,"*")!=0);
    
}