#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct Book
{
    int id;
    char name[30];
    char author[30];
    int pages;
    double price;
};

int menu()
{
     system("cls");
    int selected;
    char ch = 'x';
    printf("\n=======================\n");
    printf("Welcome to BVDU Library\n");
    printf("=======================\n\n");
    printf("1.Add a book\n");
    printf("2.List of Books\n");
    printf("3.Search Book\n");
    printf("4.Total number of books\n");
    printf("0.Exit\n");
    printf("Selected : ");
    scanf("%d%c", &selected, &ch);

    return selected;
}

void addBook()
{

    FILE *out = fopen("Book.txt", "ab");
    system("cls");
    printf("\n========================\n");
    printf("Add Book to The Library");
    printf("\n========================\n\n");

    struct Book b1;

    char ch = 'x';

    // add book id
    printf("Enter the 4 digit Book id: ");
    scanf("%d", &b1.id);

    // add book name
    printf("Enter the book name: ");
    scanf("%s", b1.name);

    // add author name
    printf("Enter the author name: ");
    scanf("%s", b1.author);

    // add number of pages
    printf("Enter the number of pages in the book: ");
    scanf("%d", &b1.pages);

    // add the price of the book
    printf("Enter the price of the book: ");
    scanf("%lf%c", &b1.price, &ch);

    fwrite(&b1, sizeof(struct Book), 1, out);

    fclose(out);
}

void readBooks()
{
    system("cls");
    FILE *in = fopen("Book.txt", "rb");

    struct Book b;

    int count = 0;
    printf("\n=================================\n");
    printf("\n       List of All the Books       \n");
    printf("\n==================================\n\n");

    while (fread(&b, sizeof(struct Book), 1, in))
    {
        printf("\n\n====================\n");
        printf("  %s  ", b.name);
        printf("\n=====================\n");
        printf("+ Book Id: %d\n", b.id);
        printf("+ Book Author: %s\n", b.author);
        printf("+ Book price: %0.2lf\n", b.price);
        printf("+ Total Pages: %d\n", b.pages);
        printf("\n=====================\n\n");
    }

    printf("The total number of books is %d", count);

    fclose(in);
}

void searchBooks()
{
    int choice;
    char ch = 'x';
    printf("\n============================\n");
    printf("\n  Search Books in Library  \n");
    printf("\n============================\n\n");
    printf("1.Search by Book Name\n");
    printf("2.Search by author\n");
    printf("Selected: ");
    scanf("%d%c", &choice, &ch);

    if (choice == 1)
    {
        char b_name[20];
        FILE *fp = fopen("Book.txt", "rb");

        printf("Please Enter the name of the book: ");
        scanf("%s", b_name);

        struct Book b1;

        while (fread(&b1, sizeof(struct Book), 1, fp))
        {
            if (strcmp(b_name, b1.name) == 0) // compare the name provided by the user and the author name
            {
                printf("\n\n====================\n");
                printf("  %s  ", b1.name);
                printf("\n=====================\n");
                printf("+ Book Id: %d\n", b1.id);
                printf("+ Book Author: %s\n", b1.author);
                printf("+ Book price: %0.2lf\n", b1.price);
                printf("+ Total Pages: %d\n", b1.pages);
                printf("\n=====================\n\n");
            }
        }

        fclose(fp);
    }
    else if(choice == 2){
        char a_name[20];

    }
}

int main()
{

    // display menu
    int flag = 0;

    while (flag == 0)
    {
        int selected = menu();

        if (selected == 1)
        {
            addBook();
            char ch = 'x';
            printf("\nDo you want to continue to the main menu.....[y,n]: ");
            scanf("%c", &ch);

            if (ch == 'y' || ch == 'Y')
            {
                continue;
            }
            else if (ch == 'n')
            {
                exit(1);
            }
        }
        else if (selected == 2)
        {
            readBooks();
            char ch = 'x';
            printf("\n\nDo you want to continue to the main menu.....[y,n]: ");
            scanf("%c", &ch);

            if (ch == 'y' || ch == 'Y')
            {
                continue;
            }
            else if (ch == 'n' || ch == 'N')
            {
                exit(1);
            }
        }
        else if (selected == 3)
        {

            searchBooks();
            char ch = 'x';
            printf("\n\nDo you want to continue to the main menu.....[y,n]: ");
            scanf(" %c", &ch);

            if (ch == 'y' || ch == 'Y')
            {
                continue;
            }
            else if (ch == 'n' || ch == 'N')
            {
                exit(1);
            }
        }
    }

    return 0;
}