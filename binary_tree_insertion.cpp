#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node * left,*right,*parent;
	int height;
	int bf;
};

 struct node*root = NULL;
 struct node* z;
 struct node* p;
 struct node* q;
 struct node* x;
 struct node* y;
 
 
//bf_check(struct node* rut);
 
 
insertion(int val)
 {
     z=(node *)malloc(sizeof(node));
 	z->key=val;
 	z->left=z->right = NULL;
 	if(root==NULL)
 	{
 		root=z;
 		z->parent = NULL;
	}
	else
	{
	p=root;
	q=NULL;
	
	while(p!=NULL)
	{
		q=p;
		if(val<p->key)

			p=p->left;
			else
			p=p->right;
	}
	z->parent = q;
	if(val<q->key)
	q->left = z;
	else
	q->right = z;
	
   }
 }

int height(struct node* x)
{
	int hl,hr;
	if(x==NULL)
	return 0;
	else
	{
		
		hl=height(x->left);
		hr=height(x->right);
	}
		if(hl>hr)
			return (hl+1);
			else
			return (hr+1);
}
 
 inorder(struct node* rut)
 {
 	if(rut!=NULL)
 	{
 	//	printf("\nThe inoder is\n");
 	inorder(rut->left);
	printf("  %d      -      %d    -    \n",rut->key,height(rut));
	inorder(rut->right);	
	}
 }
 
 preorder(struct node* rut)
 {
 	if(rut!=NULL)
 	{
 	//	printf("\nThe preorder is\n");
    printf("  %d      -      %d\n",rut->key,height(rut));
	preorder(rut->left);
	preorder(rut->right);	
	}
 }
 
 postorder(struct node* rut)
 {
 	if(rut!=NULL)
 	{
 	//	printf("\nThe post order is \n");
 		postorder(rut->left);
 		postorder(rut->right);
 		printf("  %d      -      %d\n",rut->key,height(rut));
	 }
 }
 
struct node* search(struct node* rut,int val)
 {
 	if((rut->key == val)||(rut == NULL))
 	printf("%d",rut->key);
 	else if(val<rut->key)
 	search(rut->left,val);
 	else
 	search(rut->right,val);
  }
  
 
  
 struct node * sucessor(struct node *x)
  {
  	if(x->right != NULL)
  	{
  		p = x->right;
  		while(p->left != NULL)
  		p = p->left;
  		return p ;
	  }
	  else
	    p = x->parent;
	    while( x != p->left && p!= NULL)
	    {
	    	x=p;
	    	p=p->parent;
	    	
		}
		return p;
	  }
   
  
 struct node *deletion(struct node* rut ,int val)
  {
  	x=search(root,val);
  	if(x != NULL)
  	{
  	if(x->left == NULL && x->right == NULL)
	  {
	  	if(x == x->parent->left)
	  	x->parent->left = NULL;
 	  else
 	    x->parent->right = NULL;
 	  }
     else if(x->right != NULL && x->left == NULL)
	 {
	   if(x == x->parent->left)
	   x->parent->left = x->right;
	   else
	   x->parent->right = x->right;
	   x->right->parent = x->parent;
	   	if(x == root)
     	root = x->right;
     } 	    
     else if(x->right == NULL && x->left !=NULL)
     {
     	if(x == x->parent->left)
     	x->parent->left = x->left;
     	else
     	x->parent->right = x->left;
     	x->left->parent = x->parent;
     	if(x == root)
     	root = x->right;
     	else
     	{
     		y=sucessor(x);
     		x->key = y->key;
     		deletion(rut,y->key);
		 }
	 }
	}
  }

left_rotate(struct node *x)
{
	y = x->right;
	x->right = y->left;
	y->left->parent = x;
	y->left = x;
	y->parent = x->parent;
	if(x == root)
	root = y;
	else
	{
		if(x=x->parent->left)
		x->parent->left = y;
		else
		x->parent->right = y;
	}
	x->parent = y;
}



right_rotate(struct node*x)
{
	x= y->left;
	y->left = x->right;
	x->right->parent = y;
	x->right = y;
	x->parent = y->parent;
	if(y = root)
	root = x;
	else
	{
		if( y= y->parent ->left)
		y->parent->left = x;
		else
		y->parent->right = x;
	}
	y->parent = x;
}

bf(struct node* rut)
{
	 return height(rut->left) - height(rut->right);
}

/* bf_check(struct node* rut)
 {
 	if(rut!=NULL && (bf(rut) == 2 || bf(rut) == -2))
 	{
 	//	printf("\nThe preorder is\n");
    printf("  %d      -      %d\n",rut->key,height(rut));
	preorder(rut->left);
	preorder(rut->right);	
	}
 }*/

int main()
{
	
   int ch,val,choice;
   printf("IF YOU WANT TO INSERT DATA THEN PRESS '1' OR PRESS '2' TO LET COMPUTER TAKE IT DEFAULT INPUT\n");
   scanf("%d",&choice);
   if(choice == 1)
   {
   	
   while(1)
   {
   printf("\n\nenter the choice \n");
   printf("1--for the insertion\n2--for the inorder\n3--for the preorder\n4--postorder\n5--height\n6--deletion\n7--exit\n");
   scanf("%d",&ch);
   
   switch(ch)
   {
   	case 1:
   		{
   			printf("enter the value\n");
   			scanf("%d",&val);
   			insertion(val);
   			break;
		}
	case 2:
		{
		    printf("inorder      height\n");
			inorder(root);
			break;
		}
	case 3:
		{
			printf("preorder      height\n");
		    preorder(root);
			break;	
		}
	case 4:
		{
			printf("postorder      height\n");
			postorder(root);
			break;
		
	case 5:
		{
			int ht;
			ht = height(root);
			printf("the height of the tree is %d",ht);
		}
	case 6:
			deletion(root ,val);
			break;
	default:
	{
		printf("INVALID CHOICE\n");
	}
	
   }
   }
   }
   }
   else
   {
   	printf("the computer has put the dafault value '5-2-7-1-4-6-9-3-8'\n");
   	insertion(5);
   	insertion(2);
   	insertion(7);
   	insertion(1);
   	insertion(4);
   	insertion(6);
   	insertion(9);
   	insertion(3);
   	insertion(8);
   	
   	 while(1)
   {
   printf("\n\nenter the choice \n");
printf("1--for the insertion\n2--for the inorder\n3--for the preorder\n4--postorder\n5--height\n6--deletion\n7--exit\n");
   scanf("%d",&ch);
   
   switch(ch)
   {
   	case 1:
   		{
   			printf("enter the value\n");
   			scanf("%d",&val);
   			insertion(val);
   			break;
		}
	case 2:
		{
			printf("inorder      height\n");
			inorder(root);
			break;
		}
	case 3:
		{
			printf("preorder      height\n");
		    preorder(root);
			break;	
		}
	case 4:
		{
			printf("postorder     height\n");
			postorder(root);
			break;
		
	case 5:
	    {
			int ht;
			ht = height(root);
			printf("the height of the tree is %d",ht);
		}
	case 6:
			deletion(root,val);
			break;
	default:
	{
		printf("INVALID CHOICE\n");
	}
	
   }
   }
   }
}
}
   
 
 
      
   
