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

void addBook()
{

    FILE *out = fopen("Book.txt", "ab");
    system("cls");
    printf("\n========================\n");
    printf("Add Book to The Library");
    printf("\n========================\n\n");

    struct Book b1;

    // add book id
    printf("Enter the Book id: ");
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
    scanf("%lf", &b1.price);

    fwrite(&b1, sizeof(struct Book), 1, out);

    fclose(out);
}

void readBooks()
{
    FILE *in = fopen("Book.txt", "rb");

    struct Book b;

    int count = 0;

    while (fread(&b, sizeof(struct Book), 1, in))
    {
        printf("Book name:  %s\n", b.name);
        count++;
    }

    printf("The total number of books is %d", count);

    fclose(in);
}

int main()
{

    // display menu

    int selected;
    int flag = 0;
    while (flag == 0)
    {
        // system("cls");
        printf("\n=======================\n");
        printf("Welcome to BVDU Library\n");
        printf("=======================\n\n");
        printf("1.Add a book\n");
        printf("2.List of Books\n");
        printf("3.Search Book\n");
        printf("4.Total number of books\n");
        printf("0.Exit\n");
        printf("Selected : ");
        scanf("%d", &selected);

        switch (selected)
        {
        case 1:;
            addBook();
            break;
        case 2:;
            system("cls");
            readBooks();
            break;
        case 3:
            printf("Search a book");
            break;
        case 4:
            printf("The Total number of books is: ");
            break;
        case 0:
            exit(1);
            flag = 1;
            break;

        default:
            break;
        }
    }

    return 0;
}