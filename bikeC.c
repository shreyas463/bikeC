// Binary Search Tree operations in C
//NAME-SHREYAS CHAUDHARY
//USN-1NH19CS743

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
  struct node *left, *right;
  int year; //key
  int cost;
  int quantity_sold;
  int quantity_left;
  char type[20];
  char model[20];
};

struct bike_details
{
  int year; 
  int cost;
  int quantity_sold;
  int quantity_left;
  char type[20];
  char model[20];
};
  
void oldestBIKE(struct node *root)
{     
  while(root->left!=NULL)
  root=root->left;
  printf(" the oldest bike model in the store is %s\n", root->model);
 }

void latestBIKE(struct node *root)
{
   while(root->right!=NULL)
   root=root->right;
   printf(" the latest bike model in the store is %s\n",root->model );
 }

    
struct node* delete(struct node *root, int key)
    {
      
      struct node *curr, *temp, *prev, *p, *q;
      prev=NULL;
      curr=root;
      while((curr!=NULL)&&(curr->year!=key))
      {
        prev=curr;
        if(key<curr->year)
          curr=curr->left;
        else
          curr=curr->right;
      }
      if(curr==NULL)
      {
        printf("BIKE NOT FOUND..\n");
        return root;
      }
      
      // if node has one subtree or no subtrees
      if((curr->left==NULL)||(curr->right==NULL))
      {
        if(curr->left==NULL)
          q=curr->right;
        else
          q=curr->left;
        
        //deleting root with one subtree
        if(prev==NULL)
        {
          free(curr);
          return q;
        }
        if(curr==prev->left)
          prev->left =q;
        else
          prev->right=q;
        free(curr);
      }
      else
      {
        //two subtrees present
        p=NULL; //parent of inorder successor
           temp=curr->right;
        while(temp->left!=NULL)
        {
          p=temp;
          temp=temp->left;
        }
        curr->year=temp->year;
        if(p!=NULL)
          p->left=temp->right;
        else
          curr->right=temp->right;
        free(temp);
      }
      return(root);
    }



struct node *newNode(int item, int cost, int quantity_sold, int quantity_left, char *type, char *model) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->year = item;
  temp->cost = cost;
  temp->quantity_sold = quantity_sold;
  temp->quantity_left = quantity_left;
  strncpy(temp->type, type, 20);
  strncpy(temp->model, model, 20);
  temp->left = temp->right = NULL;
  return temp;
}

void print_struct(struct node *record)
{
            printf("***** \n");
            printf(" ---------- Year is: %d \n", record->year);
            printf(" ---------- Cost is: %d \n", record->cost);
            printf(" ---------- Quantity_left is: %d \n", record->quantity_left);
            printf(" ---------- Quantity_sold is: %d \n", record->quantity_sold);
            printf(" ---------- Type is: %s \n", record->type);
            printf(" ---------- Model is: %s \n", record->model);
            printf("***** \n");
            printf("\n");
}


void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    print_struct(root);
    inorder(root->right);
  }
}


struct node *insert(struct node *node, int year, int cost, int quantity_sold, int quantity_left, char *type, char *model) {
  if (node == NULL) return newNode(year, cost, quantity_sold, quantity_left, type, model);
  if (year < node->year)
    node->left = insert(node->left, year, cost, quantity_sold, quantity_left, type, model);
  else
    node->right = insert(node->right, year, cost, quantity_sold, quantity_left, type, model);

  return node;
}


int main() 
{

    struct node *root = NULL;
    int ch,item,n,mode,xy;

    struct bike_details bike;
    int user_view = 0;
 	  printf("***** WELCOME ADMIN ******\n");
		while(1)
		{
    printf("***** WELCOME TO HARLEY'S BIKE STORE ******\n");
    //printf("3.MAIN MENU\n");
    printf("1.Insert bikes \n");
    printf("2.display all bikes \n");
    printf("3.Delete a bike\n");
    printf("4.View the oldest model bike \n"); 
    printf("5.View the latest model bike \n");
    printf("6.exit admin view and switch to user view \n");
    printf("Please select an option :\n");
    // printf("\n4.View the most sold bike "); 
     // printf("\n3.View the least sold bike ");
    
    scanf("%d",&ch);
    switch (ch)
    {
  //case 3: printf("***** WELCOME TO HARLEY'S BIKE STORE ******\n");
         // printf("***** WELCOME BACK TO MAIN MENU ******\n");
    case 1: printf("Enter the bike details ---- \n");
            printf("Enter year of release: ");
            scanf("%d", &bike.year);
            printf("Enter cost: ");
            scanf("%d", &bike.cost);
            printf("Enter qt left: ");
            scanf("%d", &bike.quantity_left);
            printf("Enter qt sold: ");
            scanf("%d", &bike.quantity_sold);
            printf("Enter type: ");
            scanf("%s", bike.type);
            printf("Enter model: ");
            scanf("%s", bike.model);
            
            root=insert(root, bike.year, bike.cost, bike.quantity_left, bike.quantity_sold, bike.type, bike.model);
            break;
    
   case 2 : if(root==NULL)
            printf("****** NO BIKE ******\n");
            else
             {
              printf("Inorder Traversal (YEAR WISE DISPLAY OF BIKES) :\n");
              inorder(root);
             } 
            break;
   case 3 : printf("Enter the bike to be deleted:\n");
            scanf("%d",&item);
            root =delete(root, item);
            break;
   case 4 :  oldestBIKE(root);
            // printf("\nThe oldest model bike is = %d\n",n);
            break;
   case 5 :  latestBIKE(root);
            // printf("\nThe latest model bike is = %d\n",n);
            break;
   case 6 : user_view = 1;
            break;

   case 7 : exit(0);
            default: 
            printf(" Enter a valid Choice(1 to 9) : \n");

      }

if(user_view == 1)
{
    break;
}

    
}

printf("***** WELCOME TO USER VIEW **** \n");
    while(1)
    {
       printf("***** WELCOME TO HARLEY'S BIKE STORE ******\n");
         printf("1.display all bikes \n");
         printf("2.View the oldest model bike \n"); 
         printf("3.View the latest model bike \n");
         printf("4.exit \n");
         printf("Please select an option :\n");
         scanf("%d",&xy);
         switch (xy)
     {

       case 1 : if(root==NULL)
                printf("****** NO BIKE ******\n");
                else
                 {
                  printf("Inorder Traversal (YEAR WISE DISPLAY OF BIKES) :\n");
                  inorder(root);
                 } 
                break;

       case 2 :  oldestBIKE(root);
                // printf("\nThe oldest model bike is = %d\n",n);
                break;
       case 3 :  latestBIKE(root);
                // printf("\nThe latest model bike is = %d\n",n);
                break;
       case 4 : exit(0);  
    }
   
    }






}