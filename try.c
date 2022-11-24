#include<stdio.h>

struct Book
{
    int id;
    char name[30];
    char author[30];
    int pages;
    double price;
};

int main(){
    FILE * in = fopen("Book.txt","rb");
            
            struct Book b;
            
            int count = 0;
            
            while(fread(&b,sizeof(struct Book),1,in)){
                printf("Book name:  %s\n",b.name);
                count++;
            }

            printf("The total number of books is %d",count);

            fclose(in);


            return 0;
}