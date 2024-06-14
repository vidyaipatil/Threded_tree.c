#include<stdio.h>
#include<stdlib.h>
//defining the structure for node
struct node{
	int data;
	struct node*left;
	struct node*right;
	int lbit;
	int rbit;
};

//creating the tree

struct node* create(){
	int x;
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
//	printf("%d ",sizeof(newnode));
	printf("Enter the data of the node if not enter 0\n");
	scanf("%d",&x);
	if(x==0){
		return 0;
	}
	newnode->data=x;
	printf("Enter the left child of %d\n",x);
	newnode->left=create();
	if(newnode->left!=0){
		newnode->lbit=1;
	}
	else{
		newnode->lbit=0;
	}
	
	printf("Enter the right child of %d\n",x);
	newnode->right=create();
	if(newnode->right!=0){
		newnode->rbit=1;
	}
	else{
		newnode->rbit=0;
	}
	return newnode;
}
//finding the node predecessor
struct node* in_pre(struct node*root){
//	printf("In start of pre\n");
	if(root->left==0){
//		printf("In end of pre\n");
		return 0;
	}
	root=root->left;
	while(root->right!=0){
		root=root->right;
	}
//	printf("In end of pre\n");
	return root;
	
}
//finding the successor
struct node* in_succ(struct node*root){
//	printf("In start of succ\n");
	if(root->right==0){
//		printf("In end of succ\n");

		return 0;
	}
	root=root->right;
	while(root->left!=0){
		root=root->left;
	}
//	printf("In end of succ\n");
	return root;
	
}
// Creating the threaded tree
void thread(struct node*root,struct node*head){
//	printf("In start of thread\n");
if(root->lbit==0 || root->rbit==0){
//	printf("In condition of thread\n");

	if(root->lbit==0){
	if(in_pre(root)==0){
			root->left=head;
		}
		else{
		root->left=in_pre(root);
	}
}
  if(root->rbit==0){
	if(in_succ(root)==0){
			root->right=head;
		}
	else{
		root->right=in_succ(root);
	}
	
	}
	
	return ;
	
}
	else{
		thread(root->left,head);
		thread(root->right,head);
	}
}
// finding the preorder traversal of normal tree
void preorder(struct node*root){
	if(root==0){
		return ;
	}
	printf("%d  ",root->data);
	preorder(root->left);
	preorder(root->right);
	
}
//finding the inorder traversal of normal treee
void inorder(struct node*root){
	if(root==0){
		return ;
	}
	inorder(root->left);
	printf("%d  ",root->data);
	inorder(root->right);
	
}
//fining the preorder traversal of threaded tree
void b_preorder(struct node*root){
	if(root->lbit==0 && root->rbit==0){
		printf("%d  ",root->data);
		return ;
	}
	if(root->lbit==1 && root->rbit==0){
		printf("%d  ",root->data);
		b_preorder(root->left);
		return ;
	}
	if(root->lbit==0 && root->rbit==1){
		printf("%d  ",root->data);
		b_preorder(root->right);
		return ;
	}
	printf("%d  ",root->data);
	b_preorder(root->left);
	b_preorder(root->right);
	
}
//finding the inorder traversal of threaded tree
void b_inorder(struct node*root){
	if(root->lbit==0 && root->rbit==0){
		printf("%d  ",root->data);
		return ;
	}
	if(root->lbit==1 && root->rbit==0){
	
		b_inorder(root->left);
			printf("%d  ",root->data);
		return ;
	}
	if(root->lbit==0 && root->rbit==1){
		
		b_inorder(root->right);
		printf("%d  ",root->data);
		return ;
	}
	
	b_inorder(root->left);
	printf("%d  ",root->data);
	b_inorder(root->right);
	
}
int main(){
	struct node*root=0;
	
	root=create();
	struct node*head=(struct node*)malloc(sizeof(struct node));
	head->left=root;
	head->right=head;
	head->lbit=1;
	head->rbit=1;
	printf("The preorder traversal of the tree : \n");
	preorder(root);
	printf("\n");
	printf("The inorder traversal of the tree : \n");
	inorder(root);
	printf("\n");
	thread(root,head);
	printf("The preorder traversal of the threded tree : \n");
    b_preorder(root);
    printf("\n");
    printf("The inorder traversal of the threded tree : \n");
    b_inorder(root);
	return 0;
	
	
}
