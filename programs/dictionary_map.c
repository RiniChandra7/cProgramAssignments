#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
	char *key;
	char *val;
	struct node *left;
	struct node *right;
	int height;
}nd;

int max (int a , int b)
{
	return ((a>b)?a:b);

}
int height_nd(nd *temp)
{
	if(temp == NULL)
	{
		return 0;
	}
	return temp->height;
}
nd *create(char *k , char *v)
{
	nd *temp = (nd *)malloc(sizeof(nd));
	temp->left = NULL;
	temp->right = NULL;
	temp->key = k;
	temp->val = v;
	temp->height = 1;
	return temp;
}
 nd * right_rotate(nd *y)
 {
 	
 	nd * x = y->left;
 	nd *T2 = x->right;
 	x->right = y;
 	y->left = T2;
 	y->height = max(height_nd(y->left),height_nd(y->right))+1;
 	x->height = max(height_nd(x->left),height_nd(x->right))+1;
 	
 	return x;
 }

 nd * left_rotate(nd *x)
 {
 	
 	nd *y = x->right;
 	nd *T2 = y->left;
 	y->left = x;
 	x->right = T2;
 	y->height = max(height_nd(y->left),height_nd(y->right))+1;
 	x->height = max(height_nd(x->left),height_nd(x->right))+1;
 	
 	return y;

 }
 int get_balance(nd *temp)
 {
 	if(temp==NULL)
 	{
 		return 0;
 	}
 	return (height_nd(temp->left)-height_nd(temp->right));
 }
 nd *insert(nd *r , char *k , char * v)
 {
 	
 	if(r==NULL)
 	{
 		return (create(k,v));
 	}
 	int ff = strcmp(k,r->key);
 	if(ff>0)
 	{
 	
 		r->right = insert(r->right,k,v);
 	}
 	else if(ff<0)
 	{
 		r->left = insert(r->left,k,v);
 	}
 	else
 		return r;

 	r->height = 1+max(height_nd(r->left),height_nd(r->right));
 	int bal = get_balance(r);

 	if(bal<-1 && strcmp(k,r->right->key)>0)
 		return left_rotate(r);
 	if(bal>1 && strcmp(k,r->left->key)<0)
 		return right_rotate(r);
 	if(bal<-1 && strcmp(k,r->right->key)<0)
 	{
 		r->right = right_rotate(r->right);
 		return left_rotate(r);
 	}
 	if(bal>1 && strcmp(k,r->left->key)>0)
 	{
 		r->left = left_rotate(r->left);
 		return right_rotate(r);
 	}
 	return r;
 }

 void preorder(nd *r)
 {
 	if(r!=NULL)
 	{
 		preorder(r->left);
 		printf("%s : %s\n",r->key,r->val);
 		preorder(r->right);
 	}
 	
 }
 nd *get_minimum(nd *t)
 {
 	if(t==NULL) return NULL;
 	while(t->left!=NULL)
 	{
 		t = t->left;
 	}
 	return t;
 }
 nd * delete(nd *r , char *k)
 {
 	if(r==NULL)
 	{
 		return r;
 	}
 	if(strcmp(r->key,k)>0)
 	{
 		r->left=delete(r->left,k);
 	}
 	else if(strcmp(r->key,k)<0)
 	{
 		r->right = delete(r->right,k);
 	}
 	else
 	{
 		if(r->left==NULL||r->right==NULL)
 		{
 			nd *temp = (r->left==NULL)?r->right:r->left;
 			if(temp==NULL)
 			{
 				temp = r;
 				r = NULL;
 			}
 			else
 			{
 				*r = *temp;
 			}	
 			free(temp);
 		}
 		else
 		{
 			nd *temp = get_minimum(r->right);
 			r->key = temp->key;
 			r->val = temp->val;
 			r->right = delete(r->right,temp->key);
 		}
 	}
 	if(r == NULL)
 	{
 		return NULL;
 	}
 	int bal = get_balance(r);

 	if(bal >1 && get_balance(r->left)>=0)
 		return right_rotate(r);
 	if(bal > 1 && get_balance(r->left)<0)
 	{
 		r->left = left_rotate(r->left);
 		return right_rotate(r);
 	}
 	if(bal<-1 && get_balance(r->right)>0)
 		return left_rotate(r);
 	if(bal <-1 && get_balance(r->right)>0 )
 	{
 		r->right = right_rotate(r->right);
 		return left_rotate(r);
 	}
 	return r;
 }
int main()
{
	nd *map=NULL;
	char key[100];
	char value[100];
	char c;
	/*do
	{
		scanf("%s",&key);
		scanf("%s",&value);
		getchar();
		map = insert(map,key,value);
		preorder(map);
		printf("Do you want to enter more? (Y/N)? : ");
		scanf("%c",&c);
	}while(c=='Y'||c=='y');*/
	map = insert(map,"a","apple");
	map = insert(map,"app","bapple");
	map = insert(map,"ab","capple");
	map = insert(map,"de","dapple");
	map = insert(map,"az","fapple");
	map = insert(map,"ai","eapple");
	preorder(map);
	delete(map,"ab");
	preorder(map);
	return 0;
}


