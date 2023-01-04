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

struct borrowbook
{
    char isbn[100];
};

struct student
{
    char name[100];
    char id[100];
    char mail[100];
    char semester[20];
    char phone[15];
    char username[20];
    char password[15];
    int booksBorrowed = 0;
    struct borrowbook borrowBookStruct[10];
};

struct cred
{
    char username[100];
    char password[100];
} creden;
struct book booklist[2000];
struct student studentlist[2000];

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
            booklist[trc].numCopy = atoi(singleBook);
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

char *validmail(char mail[])
{

    char *p;
    char *q;

    // Find first occurrence of s2 in s1
    p = strstr(mail, ".");
    q = strstr(mail, "@");
    if (p != NULL && q != NULL)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}

void addStudent()
{
    FILE *fptr = fopen("students.txt", "a");
    struct student newStudent;

    printf("Add Name: \n");
    fgets(newStudent.name, 100, stdin);

    printf("Add id: \n");
    fgets(newStudent.id, 100, stdin);

    while (true)
    {
        printf("Add mail: \n");
        fgets(newStudent.mail, sizeof newStudent.mail, stdin);
        char *p = validmail(newStudent.mail);
        if (p == NULL)
        {
            printf("Your email should include @ and .!!! kindly insert right address.");
        }
        else
        {
            break;
        }
    }

    printf("Add Semester: \n");
    fgets(newStudent.semester, sizeof newStudent.semester, stdin);

    printf("Add Phone number of a Student: \n");
    fgets(newStudent.phone, 15, stdin);

    fputs(newStudent.name, fptr);
    fputs(newStudent.id, fptr);
    fputs(newStudent.mail, fptr);
    fputs(newStudent.semester, fptr);
    fputs(newStudent.phone, fptr);
    fputs(newStudent.id, fptr);
    fputs("12345", fptr);
    fputs("\n", fptr);
    fputs("0", fptr);
    fputs("\n", fptr);
    fputs("", fptr);
    fputs("\n", fptr);

    fclose(fptr);
}

int loadStudent(struct student studentlist[])
{
    FILE *fptr = fopen("students.txt", "r");

    int index = 0;
    int trc = 0;
    char singleStudent[100];

    while (fgets(singleStudent, 100, fptr) != NULL)
    {
        if (index == 0)
        {
            strcpy(studentlist[trc].name, singleStudent);
            index++;
        }
        else if (index == 1)
        {
            strcpy(studentlist[trc].id, singleStudent);
            index++;
        }
        else if (index == 2)
        {
            strcpy(studentlist[trc].mail, singleStudent);
            index++;
        }
        else if (index == 3)
        {
            strcpy(studentlist[trc].semester, singleStudent);
            index++;
        }
        else if (index == 4)
        {
            strcpy(studentlist[trc].phone, singleStudent);
            index++;
        }
        else if (index == 5)
        {
            strcpy(studentlist[trc].username, singleStudent);
            index++;
        }
        else if (index == 6)
        {
            strcpy(studentlist[trc].password, singleStudent);
            index++;
        }
        else if (index == 7)
        {
            studentlist[trc].booksBorrowed = atoi(singleStudent);
            index++;
        }
        else if (index == 8)
        {
            if (studentlist[trc].booksBorrowed > 0)
            {
                int n = studentlist[trc].booksBorrowed;
                int count = 0, ind = 0;
                char isbn[100];
                for (int i = 0; singleStudent[i] != '\0'; i++)
                {
                    if (singleStudent[i] == ':')
                    {
                        strcpy(studentlist[trc].borrowBookStruct[ind].isbn, isbn);
                        ind++;
                        count = 0;
                    }
                    else
                    {
                        isbn[count] = singleStudent[i];
                        count++;
                    }
                }
            }

            index = 0;
            trc++;
        }
    }

    fclose(fptr);

    return trc;
}

void showStudent(struct student studentlist[], int len)
{

    for (int i = 0; i < len; i++)
    {
        fputs(studentlist[i].name, stdout);
        fputs(studentlist[i].id, stdout);
        fputs(studentlist[i].mail, stdout);
        fputs(studentlist[i].semester, stdout);
        fputs(studentlist[i].phone, stdout);
    }
}

void searchStudent(struct student studentlist[], int len)
{
    char studentId[100];
    printf("Enter Student Id: ");
    fgets(studentId, sizeof studentId, stdin);
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        int val = strcmp(studentlist[i].id, studentId);
        if (val == 0)
        {
            printf("Student Matched!!\n");
            puts(studentlist[i].name);
            puts(studentlist[i].id);
            puts(studentlist[i].mail);
            puts(studentlist[i].semester);
            puts(studentlist[i].phone);
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("Student Does not matched!!");
    }
}

void bookfile(int len)
{
    FILE *fptr = fopen("books.txt", "w");

    for (int i = 0; i < len; i++)
    {
        fputs(booklist[i].title, fptr);
        fputs(booklist[i].author, fptr);
        fputs(booklist[i].isbn, fptr);
        fputs(booklist[i].edition, fptr);
        fprintf(fptr, "%d", booklist[i].numCopy);
        fprintf(fptr, "\n");
    }

    fclose(fptr);
}

void studentfile(int stdlen)
{
    FILE *fptr = fopen("students.txt", "w");

    printf("Stdlen is: %d", stdlen);
    for (int i = 0; i < stdlen; i++)
    {
        fputs(studentlist[i].name, fptr);
        fputs(studentlist[i].id, fptr);
        fputs(studentlist[i].mail, fptr);
        fputs(studentlist[i].semester, fptr);
        fputs(studentlist[i].phone, fptr);
        fputs(studentlist[i].username, fptr);
        fputs(studentlist[i].password, fptr);

        fprintf(fptr, "%d", studentlist[i].booksBorrowed);
        fputs("\n", fptr);
        char bookisbn[1000] = "";
        char sep[] = ":";
        if (studentlist[i].booksBorrowed > 0)
        {
            for (int j = 0; j < studentlist[i].booksBorrowed; j++)
            {
                char isbn[100];
                strcpy(isbn, studentlist[i].borrowBookStruct[j].isbn);
                isbn[strcspn(isbn, "\n")] = '\0';
                strcat(bookisbn, isbn);
                strcat(bookisbn, sep);
                puts(bookisbn);
            }
            fputs(bookisbn, fptr);
            fputs("\n", fptr);
        }
        else
        {
            fputs("", fptr);
            fputs("\n", fptr);
        }
    }

    fclose(fptr);
}

void borrowbook(struct student studentlist[], int stdlen, struct book booklist[], int len)
{
    printf("Enter The book Name you want to borrow .Book Name must be inside 100 characters. \n");
    char bookName[100];
    fgets(bookName, sizeof bookName, stdin);
    int searchIndex, flag = 0, userInput;

    for (int i = 0; i < len; i++)
    {
        if (!strcmp(booklist[i].title, bookName))
        {
            printf("Book Title: ");
            puts(booklist[i].title);
            printf("Book Author: ");
            puts(booklist[i].author);
            printf("Book ISBN: ");
            puts(booklist[i].isbn);
            printf("Book Edition: ");
            puts(booklist[i].edition);
            printf("Available Copy: ");
            printf("%d", booklist[i].numCopy);
            printf("\n");
            searchIndex = i;
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        if (booklist[searchIndex].numCopy > 1)
        {
            printf("Are you sure you want to borrow the book? Press 1 to to confirm or 0 to cancel.\n");
            scanf("%d", &userInput);

            for (int i = 0; i < stdlen; i++)
            {
                printf("%d", strcmp(creden.username, studentlist[i].username));
                if ((strcmp(creden.username, studentlist[i].username) == 0) && (strcmp(creden.password, studentlist[i].password) == 0))
                {
                    studentlist[i].booksBorrowed += 1;
                    booklist[searchIndex].numCopy -= 1;
                    strcpy(studentlist[i].borrowBookStruct[studentlist[i].booksBorrowed - 1].isbn, booklist[searchIndex].isbn);
                    bookfile(len);
                    studentfile(stdlen);
                    printf("Called: \n");
                }
            }

            // if(userInput == 1){
            //     printf("Enter your student id: ");
            //     char s
            // }
        }
        else
        {
            printf("Sorry! This book is not currently available for borrow. Kindly contact with us later.");
        }
    }
}

int adminPanel(int len, int stdlen)
{
    int choice;

    char username[20];
    char password[15];
    while (true)
    {

        printf("Enter the user name:");
        fgets(username, sizeof username, stdin);

        printf("Enter the password:");
        fgets(password, sizeof password, stdin);

        username[strcspn(username, "\n")] = '\0';
        password[strcspn(password, "\n")] = '\0';

        if ((strcmp(username, "admin") == 0) && (strcmp(password, "12345") == 0))
        {
            while (true)
            {
                greet();
                printf("Press 1 to See All Books. \n");
                printf("Press 2 to Search Books. \n");
                printf("Press 3 to See All Student. \n");
                printf("Press 4 to Search Student. \n");
                printf("Press 5 to Add Books. \n");
                printf("Press 6 to Add Student. \n");
                printf("Press 0 to Return to the main menu. \n");
                scanf("%d", &choice);
                char buffer[5];
                fgets(buffer, 5, stdin);

                if (choice == 1)
                {
                    showBooks(booklist, len);
                }
                else if (choice == 2)
                {
                    searchBooks(booklist, len);
                }
                else if (choice == 3)
                {
                    showStudent(studentlist, stdlen);
                }
                else if (choice == 4)
                {
                    searchStudent(studentlist, stdlen);
                }
                else if (choice == 5)
                {
                    addBooks(booklist, len);
                }
                else if (choice == 6)
                {
                    addStudent();
                }
                else if (choice == 0)
                {
                    return 0;
                }
            }
        }
        else
        {
            printf("You entered wrong creentials!");
            return 0;
        }
    }
}

int studentPanel(int len, int stdlen)
{
    int choice;

    char username[20];
    char password[15];
    while (true)
    {
        printf("Enter the user name:");
        fgets(username, sizeof username, stdin);
        printf("Enter the password:");
        fgets(password, sizeof password, stdin);

        int matched = 0;
        for (int i = 0; i < stdlen; i++)
        {
            if ((strcmp(username, studentlist[i].username) == 0) && (strcmp(password, studentlist[i].password) == 0))
            {
                matched = 1;
                strcpy(creden.username, studentlist[i].username);
                strcpy(creden.password, studentlist[i].password);
            }
        }
        if (matched == 1)
        {
            while (true)
            {
                greet();
                printf("Press 1 to See All Books. \n");
                printf("Press 2 to Search Books. \n");
                printf("Press 3 to See All Student. \n");
                printf("Press 4 to Search Student. \n");
                printf("Press 5 to Borrow Books. \n");
                printf("Press 2 to Search Books. \n");
                printf("Press 0 to Return to the main menu. \n");
                scanf("%d", &choice);
                char buffer[5];
                fgets(buffer, 5, stdin);

                if (choice == 1)
                {
                    showBooks(booklist, len);
                }
                else if (choice == 2)
                {
                    searchBooks(booklist, len);
                }
                else if (choice == 3)
                {
                    showStudent(studentlist, stdlen);
                }
                else if (choice == 4)
                {
                    searchStudent(studentlist, stdlen);
                }
                else if (choice == 5)
                {
                    borrowbook(studentlist, stdlen, booklist, len);
                }
                else if (choice == 6)
                {
                    play();
                }
                else if (choice == 0)
                {
                    return 0;
                }
            }
        }
        else
        {
            printf("You entered wrong creentials!");
            return 0;
        }
    }
}

int main()
{
    int choice;

    while (true)
    {
        greet();
        printf("Press 1 to enter in admin panel. \n");
        printf("Press 2 to enter in Student panel. \n");
        printf("Press 0 to Close the Application. \n");

        int len = loadBooks(booklist);
        int stdlen = loadStudent(studentlist);

        printf("Std len : %d \n", stdlen);
        char buffer[5];
        scanf("%d", &choice);
        fgets(buffer, 5, stdin);

        if (choice == 1)
        {
            adminPanel(len, stdlen);
        }
        else if (choice == 2)
        {
            studentPanel(len, stdlen);
        }
        else
        {
            break;
        }
    }
}