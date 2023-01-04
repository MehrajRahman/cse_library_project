
//|||||||||||||| Library Management System ||||||||||||||||||||
// Group Name: Milky_Way
// Members:
// 1. Anmun Sultana                ID: 2022-3-60-248
// 2. Md Moon Rahman Nayem         ID: 2022-3-60-315
// 3. Md. Jabed Iqbal Sami         ID: 2022-3-60-313
// 4. Mahamudur Rahman Mehraj      ID: 2022-3-60-209

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//////////////////////////////////////////////////////////////////////////

void printTitle(char a[]);
void stringToCaps(char a[]);

int play()
{
    int userHand, computerHand;
    char userHandString[10], computerHandString[10];

    int result;

    int keepAsking;
    char keepPlaying = 'Y';

    /*Start randomizer*/
    // srand(time(NULL));

    while (keepPlaying == 'Y' || keepPlaying == 'y')
    {
        /*Generate computer's hand*/
        computerHand = rand() % 3;

        switch (computerHand)
        {
        case 0:
            strcpy(computerHandString, "ROCK");
            break;
        case 1:
            strcpy(computerHandString, "PAPER");
            break;
        case 2:
            strcpy(computerHandString, "SCISSORS");
            break;
        default:
            break;
        }

        /*Game*/
        printTitle("ROCK, PAPER, SCISSORS BY Rahman Mehraj");

        do
        {
            printf("\nType Rock, paper or scissors.");
            printf("\nRock, paper or scissors?: ");

            scanf("%s", userHandString);
            stringToCaps(userHandString);

            keepAsking = 0;

            if (strcmp(userHandString, "ROCK") == 0)
                userHand = 0;
            else if (strcmp(userHandString, "PAPER") == 0)
                userHand = 1;
            else if (strcmp(userHandString, "SCISSORS") == 0)
                userHand = 2;
            else
                keepAsking = 1;
        } while (keepAsking == 1);

        printf("\n\nYour hand: %s", userHandString);
        printf("\nComputer's hand: %s\n\n", computerHandString);

        result = userHand - computerHand;
        if (result < 0)
            result += 3;

        switch (result)
        {
        case 0:
            printf("It's a draw, gg\n\n");
            break;
        case 1:
            printf("YOU WON YAY!\n\n");
            break;
        case 2:
            printf("Oh, you lost. GG EZ NOOB\n\n");
            break;
        default:
            break;
        }

        do
        {
            printf("Do you want to keep playing? [Y/N]: ");
            // fflush(stdin);
            scanf("%c", &keepPlaying);
        } while (keepPlaying != 'y' && keepPlaying != 'Y' && keepPlaying != 'n' && keepPlaying != 'N');
        system("@cls||clear");
    }

    printTitle("Thanks for playing! UwU");

    return 0;
}

void printTitle(char a[])
{
    int j = 0;
    printf("%c%c", 176, 177);
    while (a[j] != '\0')
    {
        printf("%c", a[j]);
        j++;
    }
    printf("%c%c\n", 177, 176);
}

void stringToCaps(char a[])
{
    for (int i = 0; i < strlen(a); i++)
        if (a[i] > 96 && a[i] < 123)
            a[i] -= 32;
}

//////////////////////////////////////////////////////////////////////////

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

void addBooks(struct book booklist[], int len)
{
    int flag = 0;
    int searchIndex = 0;

    FILE *fptr = fopen("books.txt", "a");
    FILE *fptr2 = fopen("books.txt", "r");
    FILE *fptr1 = fopen("book.txt", "w");
    struct book newBook;
    system("@cls||clear");
    printf("Add book Title: \n");
    fgets(newBook.title, 100, stdin);

    for (int i = 0; i < len; i++)
    {
        flag = 0;
        for (int j = 0; booklist[i].title[j] != '\0' || newBook.title[j] != '\0'; j++)
        {
            if ((booklist[i].title[j]) != newBook.title[j])
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

    if (flag == 0)
    {
        printf("This Book already Exist!!");
        printf("Add Number of copy which will be added: \n");
        scanf("%d", &newBook.numCopy);
        booklist[searchIndex].numCopy += newBook.numCopy;
        int line = (searchIndex + 1) * 5, currentLine = 0;
        int index = 0;
        char singleBook[100];
        while (!feof(fptr2))
        {

            if (!feof(fptr2))
            {
                fgets(singleBook, 100, fptr2);
                currentLine++;

                if (currentLine == line)
                {
                    fprintf(fptr1, "%d", booklist[searchIndex].numCopy);
                    fprintf(fptr1, "\n");
                }
                else
                {
                    fprintf(fptr1, "%s", singleBook);
                }
            }
        }

        fclose(fptr1);
        fclose(fptr2);
        currentLine = 0;
        FILE *fptr3 = fopen("book.txt", "r");
        FILE *fptr4 = fopen("books.txt", "w");

        while (!feof(fptr3))
        {

            if (!feof(fptr3))
            {
                fgets(singleBook, 100, fptr3);
                puts(singleBook);
                currentLine++;

                if (currentLine == line)
                {
                    fprintf(fptr4, "%d", booklist[searchIndex].numCopy);
                    fprintf(fptr4, "\n");
                }
                else
                {
                    fprintf(fptr4, "%s", singleBook);
                }
            }
        }
        fprintf(fptr4, "\n");

        fclose(fptr);

        fclose(fptr3);
        fclose(fptr4);
    }
    else
    {
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
        for (int j = 0; booklist[i].title[j] != '\0' || booksearch[j] != '\0'; j++)
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
        system("@cls||clear");
        greet();
        printf("Press 1 for add student. \nPress 2 for show all books. \nPress 3 for search Book. \nPress 4 for add student: \nPress 5 for play Games: \nPress 7 for exit:\n");

        scanf("%d", &choice);
        char buffer[5];
        fgets(buffer, 5, stdin);

        if (choice == 1)
        {
            addBooks(booklist, len);
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
        else if (choice == 5)
        {
            play();
        }
        else if (choice == 7)
        {
            return 0;
        }
    }
}
