#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct book
{
    char title[100];
    char author[100];
    char isbn[20];
    char edition[20];
    int numCopy;
};

struct student
{
    char name[100];
    char id[100];
    char mail[100];
    char semester[20];
    char phone[15];
};

void greet()
{
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||||||||");
    printf(" %55s", "EWU LIBRARY MANAGEMENT SYSTEM");
    printf("%35s\n", "||||||||");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("___________________________________________________________________________________________________\n");
}

void addBooks()
{

    FILE *fptr = fopen("books.txt", "a");
    struct book newBook;

    printf("Add book Title: \n");
    fgets(newBook.title, 100, stdin);

    printf("Add book Author: \n");
    fgets(newBook.author, 100, stdin);

    printf("Add book ISBN: \n");
    fgets(newBook.isbn, sizeof newBook.isbn, stdin);

    printf("Add book edition: \n");
    fgets(newBook.edition, sizeof newBook.isbn, stdin);

    printf("Add book number of copy: \n");
    scanf("%d", &newBook.numCopy);

    fputs(newBook.title, fptr);
    fputs(newBook.author, fptr);
    fputs(newBook.isbn, fptr);
    fputs(newBook.edition, fptr);
    fprintf(fptr, "%d", newBook.numCopy);
    fprintf(fptr, "\n");
    fclose(fptr);
}

void showBooks(struct book booklist[], int len)
{
    for (int i = 0; i < len; i++)
    {
        puts(booklist[i].title);
        puts(booklist[i].author);
        puts(booklist[i].isbn);
        puts(booklist[i].edition);
        printf("%d", booklist[i].numCopy);
        printf("\n");
        printf("\n");
        printf("\n");
    }
}

int loadBooks(struct book booklist[])
{
    FILE *fptr = fopen("books.txt", "r");

    int index = 0;
    int trc = 0;
    char singleBook[100];
    while (fgets(singleBook, 100, fptr) != NULL)
    {
        if (index == 0)
        {
            strcpy(booklist[trc].title, singleBook);
            index++;
        }
        else if (index == 1)
        {
            strcpy(booklist[trc].author, singleBook);
            index++;
        }
        else if (index == 2)
        {
            strcpy(booklist[trc].isbn, singleBook);
            index++;
        }
        else if (index == 3)
        {
            strcpy(booklist[trc].edition, singleBook);
            index++;
        }
        else if (index == 4)
        {
            int n = 0;
            int s = 0;
            for (s = 0; singleBook[s] != '\0'; s++)
            {
            }
            int t = 0;
            for (int i = s - 2; i >= 0; i--)
            {
                n += pow(10, t) * (singleBook[i] - '0');
                t++;
            }

            booklist[trc].numCopy = n;
            index = 0;
            trc++;
        }
    }

    fclose(fptr);

    return trc;
}

void searchBooks(struct book booklist[], int len)
{
    int searchIndex = 0;
    char booksearch[100];
    printf("Enter the name of your book: ");
    fgets(booksearch, sizeof booksearch, stdin);
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        flag = 0;
        for (int j = 0; booklist[i].isbn[j] != '\0' || booksearch[j] != '\0'; j++)
        {
            if ((booklist[i].title[j]) != booksearch[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            searchIndex = i;
            break;
        }
    }

    puts(booklist[searchIndex].title);
    puts(booklist[searchIndex].author);
    puts(booklist[searchIndex].isbn);
    puts(booklist[searchIndex].edition);
    printf("%d", booklist[searchIndex].numCopy);
    printf("\n");
    printf("\n");
}

void addStudent()
{
    FILE *fptr = fopen("students.txt", "a");
    struct student newStudent;

    printf("Add Name: \n");
    fgets(newStudent.name, 100, stdin);

    printf("Add id: \n");
    fgets(newStudent.id, 100, stdin);

    printf("Add mail: \n");
    fgets(newStudent.mail, sizeof newStudent.mail, stdin);

    printf("Add Semester: \n");
    fgets(newStudent.semester, sizeof newStudent.semester, stdin);

    printf("Add Phone number of a Student: \n");
    fgets(newStudent.phone, sizeof newStudent.phone, stdin);

    fputs(newStudent.name, fptr);
    fputs(newStudent.id, fptr);
    fputs(newStudent.mail, fptr);
    fputs(newStudent.semester, fptr);
    fputs(newStudent.phone, fptr);
    fclose(fptr);
}

int main()
{
    int choice;
    struct book booklist[2000];
    int len = loadBooks(booklist);
    while (true)
    {
        greet();
        printf("Press 1 for add student. \nPress 2 for show all books. \nPress 3 for search Book. \nPress 4 for add student: \nPress 7 for exit:\n");

        scanf("%d", &choice);
        char buffer[5];
        fgets(buffer, 5, stdin);

        if (choice == 1)
        {
            addBooks();
        }
        else if (choice == 2)
        {
            showBooks(booklist, len);
        }
        else if (choice == 3)
        {
            searchBooks(booklist, len);
        }
        else if (choice == 4)
        {
            addStudent();
        }
        else if (choice == 7)
        {
            return 0;
        }
    }
}
