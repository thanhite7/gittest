#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int arr[100][10000];
int i=0,j=1;
struct node
{
    int val;
    struct node* left;
    struct node* right;
};
struct node* root= NULL;
struct node* makenode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return makenode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        root->right = insert(root->right, value);
    }

    return root;
}

void preorder(struct node* root)
{
    if(root!=NULL){
        arr[i][j] = root->val;
        j++;
        
        preorder(root->left);
        preorder(root->right);

    }
    
}
void postorder(struct node* root)
{
    if(root!=NULL){
        
        postorder(root->left);
        postorder(root->right);
        arr[i][j] = root->val;
        j++;

    }
    
}
int main()
{
    char temp[15];
    do
    {
        fflush(stdin);
        scanf("%s",temp);
        if(strcmp(temp,"#")==0)
        {
            break;
        }
        else if(strcmp(temp,"insert")==0)
        {
            int data;
            scanf("%d",&data);
            root = insert(root,data);
        }
        else if(strcmp(temp,"preorder")==0)
        {
            j=1;
            preorder(root);
            arr[i][0] = j;
            i++;
        }
        else if(strcmp(temp,"postorder")==0)
        {
            j=1;
            postorder(root);
            arr[i][0] = j;
            i++;
        }
    } while (strcmp(temp,"#")!=0);
    for(int l=0;l<i;l++)
    {
        for(int n=1;n<arr[l][0];n++)
        {
            printf("%d ",arr[l][n]);
        }
        printf("\n");
    }
}