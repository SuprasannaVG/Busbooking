#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct bus
{
    char seat[20];
};
typedef struct bus B;
int main()
{
    int i,elem;
    long int st;
    B brr[25];
    FILE *ptr;
    ptr=fopen("file1.txt","r+");
    for(i=0;i<20;i++)
    {
        strcpy(brr[i].seat,"Empty");
        fwrite(&brr[i].seat,sizeof(B),1,ptr);
        
    }
    
    fclose(ptr);


    FILE *ptr1;
    ptr1=fopen("reg.txt","r+");
    B arr[20];
    for(i=0;i<20;i++)
    {
        strcpy(arr[i].seat,"Empty");
        fwrite(&arr[i].seat,sizeof(B),1,ptr1);
        
    }
    fclose(ptr1);
    
    FILE *ptr2;
    B crr[25];
    ptr2=fopen("file1.txt","r+");
    for(i=0;i<20;i++)
    {
            fread(&crr[i].seat,sizeof(B),1,ptr2);
            printf("seat %d: %s\n",i+1,crr[i].seat);
            //i++;
    }
    fclose(ptr2);

    FILE *ptr3;
    B drr[25];
    ptr3=fopen("reg.txt","r+");
    for(i=0;i<20;i++)
    {
            fread(&drr[i].seat,sizeof(B),1,ptr3);
            printf("seat %d: %s\n",i+1,drr[i].seat);
            //i++;
    }
        
    
    fclose(ptr3);

}
