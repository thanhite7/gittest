#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int id;
	struct Node* leftMostChild;
	struct Node* rightSibling;
}Node;

Node* root;

Node* makeNode(int id){
	Node* p = (Node*)malloc(sizeof(Node));
	p->id = id; p->leftMostChild = NULL; p->rightSibling = NULL;
	return p;
}
Node* find(int id, Node* r){// apply pre-order traversal over the tree
	// return a node having id = the given id
	if(r == NULL) return NULL;
	if(r->id == id) return r;// visit the root r
	Node* p = r->leftMostChild;
	while(p != NULL){
		Node* q = find(id, p);
		if(q != NULL) return q;// found
		p = p->rightSibling;
	}
	return NULL;// not found the node having id = the given id
}
void insert(int u, int v){
	// create a node having id = u at the end of the children list of the node id = v
	Node* p = find(u,root);
	if(p != NULL) return;// the node having id u already exist, do not insert more
	Node* q = find(v,root);
	if(q == NULL) return; // the node having id = v does not exist, do not insert

	p = makeNode(u);
	if(q->leftMostChild == NULL){ q->leftMostChild = p; return; }
	// find the pointer to the last (right-most child) of the node q
	Node* last = q->leftMostChild;
	while(last->rightSibling != NULL) last = last->rightSibling;
	last->rightSibling = p;
}
void preOrder(Node* r){
	if(r == NULL) return;
	printf("%d ",r->id);
	// traverse the sub-tree in pre-order principle
	for(Node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
		preOrder(p);
	}
}
void  inOrder(Node* r){
	if(r == NULL) return;
	Node* p = r->leftMostChild;
	inOrder(p);// visit the left-mosy subtree T1
	printf("%d ",r->id);// visit the root
	if(p == NULL) return;
	p = p->rightSibling;// visit T2, T3, ... in inOrder principal
	while(p != NULL){
		inOrder(p);
		p = p->rightSibling;
	}
}
void postOrder(Node* r){
	if(r == NULL) return;
	for(Node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
		postOrder(p);// iteratively traverse T1, T2, ... in post-order principal
	}
	printf("%d ",r->id);// visit the root
}
int heightNode(Node* r){
	if(r == NULL) return 0;
	int maxH = 0;
	for(Node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
		int h = heightNode(p);
		if(h > maxH) maxH = h;
	}
	return maxH + 1;
}
int height(int v){
	Node* r = find(v,root);
	return heightNode(r);
}
int depthNode(int v, Node* r, int d){
	if(r == NULL) return -1;// v is not in the tree rooted at r
	if(r->id == v) return d;
	for(Node* p = r->leftMostChild; p != NULL; p = p->rightSibling){
		if(p->id == v) return d+1;
		int d1 = depthNode(v,p,d+1);
		if(d1 != -1) return d1;
	}
	return -1;// v  is not in the tree rooted at r
}
int depth(int v){
	int res = depthNode(v,root,1);
}
void run(){
	char cmd[50]; root = NULL;
	while(1){
		scanf("%s",cmd);
		//printf("read %s\n",cmd);
		if(strcmp(cmd,"*")==0) break;
		else if(strcmp(cmd,"MakeRoot")==0){
			int v; scanf("%d",&v);
			root = makeNode(v);
		}else if(strcmp(cmd,"Insert")==0){
			int u,v; scanf("%d %d",&u,&v);
			insert(u,v);
		}else if(strcmp(cmd,"PreOrder")==0){
			preOrder(root); printf("\n");
		}else if(strcmp(cmd,"InOrder")==0){
			inOrder(root); printf("\n");
		}else if(strcmp(cmd,"PostOrder")==0){
			postOrder(root); printf("\n");
		}else if(strcmp(cmd,"Height")==0){
			int v; scanf("%d",&v);
			printf("%d\n",height(v));
		}else if(strcmp(cmd,"Depth")==0){
			int v; scanf("%d",&v);
			printf("%d\n",depth(v));
		}
	}
}
int main(){
	//freopen("1.txt","r",stdin);
	run();
	return 0;
}
