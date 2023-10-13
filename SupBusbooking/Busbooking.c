#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Bus
{
   char name[20];
   char gender[10];
   int age;
   struct Bus *next;
};
typedef struct Bus node;
node *start=NULL;
void login();
void create();
void route();
void getinfo();
void create();

void main()
{  printf("************Welcome to SupBus**************\n");
   login();
   
}   


      
void receipt(char date[20],int cc,int n,int seat[])
   {
      node* ptr=start;
      int cost,rs=0;
     printf("\n\n\n******Journey details****\n");
     printf("Date:%s\n",date);
     if(cc==1)
     printf("Route:%s","Bengaluru to Kumta\n");
     else
     printf("%s","Kumta to Bengaluru\n");
     printf("Number of passengers:%d\n",n);
     for(int i=0;i<n;i++)
     {
     printf("Seat for passenger%d:%d\n",i+1,seat[i]);
     if(seat[i]<=20)
     { rs+=800;
     printf("Cost=Rs 800/-\n");
     }
     else
     {
     printf("Cost=Rs 700/-\n");
     rs+=700;
     }
     }
     printf("Total cost:%d",rs);
     printf("\n\n\n*****PASSENGERS DETAILS*****\n");
     for(int i=1;i<=n;i++)
     {
      printf("\nName of the passenger %d:",i);
      puts(ptr->name);
      printf("\nGender of the passenger %d:",i);
      puts(ptr->gender);
      printf("\nAge of the passenger %d: %d\n",i,ptr->age);
      ptr=ptr->next;
     }

    
   }
   
void getinfo()
{ 
   
   int i,ag;
   char date[15],nme[20],gend[10];
   system("cls");
   printf("LOGIN SUCCESSFULL\n");
   printf("Enter the journey date :\n");
   fflush(stdin);
   scanf("%s",date);
   int seat[10],cc,n;
         char content[100];
          FILE *fptr; 
           fptr = fopen("seat.txt", "r");
            printf("Select the route\n 1.Bengaluru to Kumta 2.Kumta to Bengaluru:\n");
            scanf("%d",&cc);
            printf("Enter the number of passengers:\n");
            scanf("%d",&n);
            printf("***Select the seats***\n");
            while (fgets(content, 100, fptr))
            {
               printf("%s", content);
            }
            for(int i=0;i<n;i++)
            {
              printf("Select the seat for passenger %d\n",i+1);
              scanf("%d",&seat[i]);
              
            }
   
   for (i=1;i<=n;i++)
   { 
      system("cls");
     
      printf("Name of passenger %d:\n",i);
       fflush(stdin);
      scanf("%s",nme);
      printf("Gender of the passenger %d:\n",i);
       fflush(stdin);
      scanf("%s",gend);
      printf("Age of passenger %d:\n",i);
       fflush(stdin);
      scanf("%d",&ag);


      create(nme,gend,ag);
   }
   receipt(date,cc,n,seat);
}
void create(char nm[20],char gen[10],int g)
{
   node *new1=NULL,*ptr;
   new1=(node*)malloc(sizeof(node));
   strcpy(new1->name,nm);
   strcpy(new1->gender,gen);
    new1->age=g;
    new1->next=NULL;
   if(start==NULL)
   start=new1;
    else
    {
    ptr=start;
    while(ptr->next!=NULL)    
      ptr=ptr->next;
      ptr->next=new1;
    }
}





   void login()
   {
   char a[20], b[20];
   long c,d;
   int res,ch,resl;
   for (;;)
     {
      printf("1:Register 2:Login 3.Exit\n");
      scanf("%d", &ch);
      switch (ch)
       {
        case 1:
         printf("Enter the Mobile number:\n");
         scanf("%ld", &c);
         printf("Enter the password:\n");
         scanf("%s", a);
         printf("Registered successfully\n");
         break;
        case 2:
         printf("Enter the Mobile number:\n");
         scanf("%ld", &d);
         printf("Enter the password:\n");
         scanf("%s",b);
         res = strcmp(a,b);
         resl = c - d;
         if (res == 0 && resl == 0)
         {
         printf("Login successfull\n");
         getinfo();
         }
         else
         { 
            if(res!=0)
            printf("Wrong Mobile number\n");
            else
            printf("Wrorng Password\n");
         }
         break;

         default:
         exit(0);
        }
      }  
   }   
   
      

