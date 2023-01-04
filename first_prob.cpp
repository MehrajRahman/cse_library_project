// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <conio.h>

// struct database
// {
//     int ID;
//     char name[20];
//     char manufacturer[20];
//     int day, month, year;
// } car[];

// struct start
// {
//     char username[20];
//     char password[20];
// } sign_in;

// void head_message(char message[]);
// int menu(int choice);
// void vehicle_data(int count);
// void search_vehicle(int count);
// void view_vehicle(int count);
// int delete_vehicle(int count);
// void update_password();
// void Welcome_message();
// int ID_validation(char *check, int count);
// int name_validation(char *check);
// int date_validation(int dd, int mm, int yyyy);
// int username_validation(char name_update[]);
// int password_validation(char pass_update[]);

// int main()
// {
//     system("color 09");

//     int success, choice, count = 0;
//     char name_input[20], pass_input[20];

//     char def_username[20] = "Team_2";
//     char def_password[20] = "Team_2";

//     strcpy(sign_in.username, def_username);
//     strcpy(sign_in.password, def_password);

//     head_message("CSE103 PROJECT");
//     Welcome_message();

//     printf("\n\n\n\n\n\t\t\t\t\t\t\t\t  Press <Enter> to continue...");
//     getchar();
//     do
//     {
//         head_message("LOGIN");
//         printf("\n\t\t\t\t\t\t   Enter username: ");
//         gets(name_input);

//         printf("\n\t\t\t\t\t\t   Enter password: ");
//         gets(pass_input);

//         if (strcmp(sign_in.username, name_input) == 0 && strcmp(sign_in.password, pass_input) == 0)
//         {
//             do
//             {
//                 choice = menu(choice);

//                 switch (choice)
//                 {
//                 case 1:
//                     count++;
//                     vehicle_data(count);
//                     getchar();
//                     break;

//                 case 2:
//                     search_vehicle(count);
//                     break;

//                 case 3:
//                     view_vehicle(count);
//                     break;

//                 case 4:
//                     count = delete_vehicle(count);
//                     getchar();
//                     break;

//                 case 5:
//                     update_password();

//                     getchar();
//                     break;

//                 case 6:
//                     head_message("THE END");

//                     printf("\n\t\t\t\t\t\t  THANK YOU FOR EVERYTHING MANZUR SIR AND MUKTO BHAIYAAA!!!\n\n\n\n\n\n\n\n\n");
//                     break;

//                 default:
//                     printf("\n\t\t\t\t\t   <!> Invalid Input! Please choose correctly...");
//                     getchar();
//                     break;
//                 }
//                 if (choice == 5)
//                 {
//                     break;
//                 }
//             } while (choice != 6);
//         }
//         else
//         {
//             printf("\n\n\t\t\t\t\t\t<!> Login failed! Please enter correct Username and Password...");
//             getchar();
//             success = 0;
//         }
//         if (choice == 6)
//         {
//             success = 1;
//         }
//         else
//             success = 0;
//     } while (success != 1);

//     return 0;
// }

// void head_message(char message[])
// {
//     int i, j, k, l;
//     l = strlen(message);
//     system("cls");

//     for (i = 1; i <= 9; i++)
//     {
//         printf("\t\t\t\t\t   ");
//         for (j = 1; j <= 24; j++)
//         {
//             if (i == 5)
//             {
//                 printf("<*><*><*><*>           Vehicle Management System            <*><*><*><*>");
//                 break;
//             }
//             else if (i <= 3 || i >= 7 || j <= 4 || j >= 21)
//             {
//                 printf("<*>");
//             }
//             else
//             {
//                 printf("   ");
//             }
//         }
//         printf("\n");
//     }
//     printf("\n\n");

//     for (i = 1; i <= 5; i++)
//     {
//         printf("\t\t\t\t\t   ");
//         for (j = 1; j <= 24; j++)
//         {
//             if (i == 1 || i == 5)
//             {
//                 printf("<*>");
//             }
//             else if (i == 3)
//             {
//                 for (k = 1; k <= 36 - l / 2; k++)
//                 {
//                     printf(" ");
//                 }
//                 printf(message);
//                 break;
//             }
//         }
//         printf("\n");
//     }
//     printf("\n\n");
// }
// void Welcome_message()
// {
//     int j;

//     printf("\t\t\t\t\t      ");
//     for (j = 1; j <= 22; j++)
//     {
//         printf("<*>");
//     }
//     printf("\n\n\t\t\t\t\t            ");
//     for (j = 1; j <= 18; j++)
//     {
//         printf("<*>");
//     }
//     printf("\n\t\t\t\t\t            <*><*>                  WELCOME                 <*><*>");
//     printf("\n\t\t\t\t\t            <*><*>                    TO                    <*><*>");
//     printf("\n\t\t\t\t\t            <*><*>                  VEHICLE                 <*><*>");
//     printf("\n\t\t\t\t\t            <*><*>                 MANAGEMENT               <*><*>");
//     printf("\n\t\t\t\t\t            <*><*>                  SYSTEM                  <*><*>");

//     printf("\n\t\t\t\t\t            ");
//     for (j = 1; j <= 18; j++)
//     {
//         printf("<*>");
//     }
//     printf("\n\n\t\t\t\t\t      ");
//     for (j = 1; j <= 22; j++)
//     {
//         printf("<*>");
//     }
// }

// int menu(int choice)
// {
//     head_message("MAIN MENU");
//     printf("\n\t\t\t\t\t   1. Add vehicle");
//     printf("\n\t\t\t\t\t   2. Search vehicles");
//     printf("\n\t\t\t\t\t   3. View vehicles");
//     printf("\n\t\t\t\t\t   4. Delete vehicles");
//     printf("\n\t\t\t\t\t   5. Update login info");
//     printf("\n\t\t\t\t\t   6. Exit");

//     printf("\n\n\t\t\t\t\t   Enter choice: ");
//     scanf("%d", &choice);
//     getchar();

//     return choice;
// }

// void vehicle_data(int count)
// {
//     int i = (count - 1), ID_test, date_test, name_test, m_name_test, cont_ID, cont_date, cont_name, cont_m_name;
//     char input[50];
//     head_message("ADD VEHICLE");

//     printf("\n\t\t\t\t\t   ========================================================================");
//     printf("\n\t\t\t\t\t\t\t      <i>  Enter Vehicle Details Below:");
//     printf("\n\t\t\t\t\t   ========================================================================");
//     do
//     {
//         printf("\n\n\t\t\t\t\t   Vehicle ID                            : ");
//         gets(input);
//         ID_test = ID_validation(input, count);
//         if (ID_test == 0)
//         {
//             printf("\n\t\t\t\t\t   <!> Vehicle ID can not contain characters, negative numbers or duplicates! Please try again...");
//             getchar();
//             cont_ID = 0;
//         }
//         else
//         {
//             car[i].ID = atoi(input);
//             cont_ID = 1;
//         }
//     } while (cont_ID == 0);

//     do
//     {
//         printf("\n\t\t\t\t\t   Vehicle Name                          : ");
//         gets(car[i].name);
//         name_test = name_validation(car[i].name);
//         if (name_test == 0)
//         {
//             printf("\n\t\t\t\t\t   <!> Vehicle's name can not start with space, cannot contain symbols\n\t\t\t\t\t       or only spaces! Please try again...");
//             getchar();
//             cont_name = 0;
//         }
//         else
//         {
//             cont_name = 1;
//         }
//     } while (cont_name == 0);

//     do
//     {
//         printf("\n\t\t\t\t\t   Vehicle Manufacturer Name             : ");
//         gets(car[i].manufacturer);
//         m_name_test = name_validation(car[i].manufacturer);
//         if (m_name_test == 0)
//         {
//             printf("\n\t\t\t\t\t   <!> Vehicle's Manufacturer name can not start with space,\n\t\t\t\t\t       cannot contain symbols or only spaces! Please try again...");
//             getchar();
//             cont_m_name = 0;
//         }
//         else
//         {
//             cont_m_name = 1;
//         }
//     } while (cont_m_name == 0);

//     do
//     {
//         printf("\n\t\t\t\t\t   Vehicle Manufacture Date (DD/MM/YYYY) : ");
//         scanf("%d/%d/%d", &car[i].day, &car[i].month, &car[i].year);
//         date_test = date_validation(car[i].day, car[i].month, car[i].year);
//         if (date_test == 0)
//         {
//             printf("\n\t\t\t\t\t   <!> Invalid date input! Please try again...");
//             getchar();
//             cont_date = 0;
//         }
//         else
//         {
//             cont_date = 1;
//         }
//     } while (cont_date == 0);

//     printf("\n\n\n\t\t\t\t\t   <i> Vehicle data successfully added! Press any key to go to main menu...");
// }

// int ID_validation(char *check, int count)
// {
//     int i, duplicate, letter, flag, valid = atoi(check);
//     if (count > 1)
//     {
//         for (i = 0; i < count - 1; i++)
//         {
//             if (valid == car[i].ID)
//             {
//                 duplicate = 0;
//                 break;
//             }
//             else
//             {
//                 duplicate = 1;
//             }
//         }
//     }
//     else
//         duplicate = 1;
//     for (i = 0; i <= strlen(check) - 1; i++)
//     {
//         if ((check[i] >= '0' && check[i] <= '9') && (valid >= 0))
//         {
//             letter = 1;
//         }
//         else
//         {
//             letter = 0;
//             break;
//         }
//     }
//     if (letter == 1 && duplicate == 1)
//     {
//         flag = 1;
//     }
//     else
//         flag = 0;
//     return flag;
// }

// int date_validation(int dd, int mm, int yyyy)
// {
//     int check;
//     {
//         if (yyyy >= 1800 && yyyy <= 2023)
//         {
//             if (mm >= 1 && mm <= 12)
//             {
//                 if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
//                 {
//                     check = 1;
//                 }
//                 else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
//                 {
//                     check = 1;
//                 }
//                 else if ((dd >= 1 && dd <= 28) && (mm == 2))
//                 {
//                     check = 1;
//                 }
//                 else if ((dd == 29 && mm == 2) && ((yyyy % 400 == 0 || yyyy % 4 == 0) && (yyyy % 100 != 0)))
//                 {
//                     check = 1;
//                 }
//                 else
//                     check = 0;
//             }
//             else
//                 check = 0;
//         }
//         else
//             check = 0;
//     }

//     getchar();

//     return check;
// }

// int name_validation(char *check)
// {
//     int i, digit, letter, space, flag;
//     if (check[0] == ' ')
//     {
//         space = 0;
//     }
//     else
//         space = 1;

//     for (i = 0; i <= strlen(check) - 1; i++)
//     {
//         if ((check[i] >= 'a' && check[i] <= 'z') || (check[i] >= 'A' && check[i] <= 'Z') || check[i] == ' ')
//         {
//             letter = 1;
//         }
//         else
//         {
//             letter = 0;
//             break;
//         }
//     }

//     for (i = 0; i <= strlen(check) - 1; i++)
//     {
//         if (check[i] >= '0' && check[i] <= '9')
//         {
//             digit = 1;
//         }
//         else
//         {
//             digit = 0;
//             break;
//         }
//     }

//     if ((letter == 1 || digit == 1) && space == 1)
//     {
//         flag = 1;
//     }
//     else
//         flag = 0;

//     return flag;
// }

// void search_vehicle(int count)
// {
//     int i, search;
//     char input[50];
//     head_message("SEARCH VEHICLE");
//     if (count > 0)
//     {
//         printf("\n\t\t\t\t\t   Enter vehicle name: ");
//         gets(input);
//         for (i = 0; i < count; i++)
//         {
//             if (strcmp(car[i].name, input) == 0)
//             {
//                 printf("\n\t\t\t\t\t   ========================================================================");
//                 printf("\n\t\t\t\t\t\t\t\t     <i>  Found Vehicle!");
//                 printf("\n\t\t\t\t\t   ========================================================================");
//                 printf("\n\n\t\t\t\t\t   Vehicle ID                            : %d", car[i].ID);
//                 printf("\n\t\t\t\t\t   Vehicle Name                          : %s", car[i].name);
//                 printf("\n\t\t\t\t\t   Vehicle Manufacturer Name             : %s", car[i].manufacturer);
//                 printf("\n\t\t\t\t\t   Vehicle Manufacture Date (DD/MM/YYYY) : %d/%d/%d", car[i].day, car[i].month, car[i].year);
//                 search = 1;
//                 break;
//             }
//             else
//                 search = 0;
//         }
//         if (search == 0)
//         {
//             printf("\n\t\t\t\t\t   ========================================================================");
//             printf("\n\t\t\t\t\t\t\t   <!>  Vehicle name \"%s\" not registered...", input);
//             printf("\n\t\t\t\t\t   ========================================================================");
//         }

//         printf("\n\n\n\n\t\t\t\t\t\t\t   <i>  Press any key to go to main menu...");
//         getchar();
//     }
//     else
//     {
//         printf("\n\t\t\t\t\t   ========================================================================");
//         printf("\n\t\t\t\t\t\t\t   <i>  No Vehicle has been registered yet...");
//         printf("\n\t\t\t\t\t   ========================================================================");
//         printf("\n\n\n\n\t\t\t\t\t\t\t   <i>  Press any key to go to main menu...");
//         getchar();
//     }
// }

// void view_vehicle(int count)
// {
//     int i;
//     head_message("VIEW VEHICLE");
//     if (count > 0)
//     {
//         printf("\n\t\t\t\t\t   ========================================================================");
//         printf("\n\t\t\t\t\t\t\t\t<i>  Total vehicle entered: %d", count);
//         printf("\n\t\t\t\t\t   ========================================================================\n\n");
//         for (i = 0; i < count; i++)
//         {
//             printf("\n\t\t\t\t\t   Vehicle count: %d", i + 1);
//             printf("\n\t\t\t\t\t   ------------------\n");
//             printf("\n\t\t\t\t\t   Vehicle ID                           : %d", car[i].ID);
//             printf("\n\t\t\t\t\t   Vehicle Name                         : %s", car[i].name);
//             printf("\n\t\t\t\t\t   Vehicle Manufacturer Name            : %s", car[i].manufacturer);
//             printf("\n\t\t\t\t\t   Vehicle Manufacture Date (DD/MM/YYYY): %d/%d/%d", car[i].day, car[i].month, car[i].year);
//             printf("\n\n\n");
//         }
//         printf("\n\n\n\n\t\t\t\t\t\t\t   <i>  Press any key to go to main menu...");
//         getchar();
//     }
//     else
//     {
//         printf("\n\t\t\t\t\t   ========================================================================");
//         printf("\n\t\t\t\t\t\t\t   <i>  No vehicle has been registered yet!");
//         printf("\n\t\t\t\t\t   ========================================================================");
//         printf("\n\n\n\n\t\t\t\t\t\t\t   <i>  Press any key to go to main menu...");
//         getchar();
//     }
// }

// int delete_vehicle(int count)
// {
//     int i, j, input, remove, to_delete;
//     head_message("DELETE VEHICLE");

//     if (count > 0)
//     {
//         printf("\n\t\t\t\t\t   Enter Vehicle ID NO. for delete: ");
//         scanf("%d", &input);
//         getchar();

//         for (i = 0; i < count; i++)
//         {
//             if (input == car[i].ID)
//             {
//                 to_delete = i;
//                 remove = 1;
//                 break;
//             }
//             else
//                 remove = 0;
//         }

//         if (remove == 1)
//         {
//             for (j = to_delete; j < count - 1; j++)
//             {
//                 car[j] = car[j + 1];
//             }
//             printf("\n\t\t\t\t\t   ========================================================================");
//             printf("\n\t\t\t\t\t\t      <!>  Vehicle successfully removed from database...");
//             printf("\n\t\t\t\t\t   ========================================================================");
//             printf("\n\n\n\n\t\t\t\t\t\t\t   <i>  Press any key to go to main menu...");
//             count--;
//         }
//         else
//         {
//             printf("\n\t\t\t\t\t   ========================================================================");
//             printf("\n\t\t\t\t\t\t\t   <!>  No such vehicle exists with ID: %d ", input);
//             printf("\n\t\t\t\t\t   ========================================================================");
//             printf("\n\n\n\n\t\t\t\t\t\t\t   <i>  Press any key to go to main menu...");
//         }
//     }
//     else
//         printf("\n\t\t\t\t\t   <!>  No vehicle registered yet...");
//     return count;
// }

// void update_password(int count)
// {
//     int success, correct_name, correct_pass;
//     char name_input[20], pass_input[20];
//     char name_update[20], pass_update[20];
//     head_message("UPDATE CREDENTIALS");

//     do
//     {

//         head_message("UPDATE CREDENTIALS");

//         printf("\n\t\t\t\t\t   <i> Username must contain (4-16) characters.");

//         do
//         {
//             printf("\n\n\t\t\t\t\t   Enter new username: ");
//             gets(name_update);

//             correct_name = username_validation(name_update);
//         } while (correct_name != 1);

//         printf("\n\n\t\t\t\t\t   <i> Password requirements:\n");
//         printf("\n\t\t\t\t\t       1. A mixture of uppercase and lowercase letters.");
//         printf("\n\t\t\t\t\t       2. At least one digit.");
//         printf("\n\t\t\t\t\t       3. Cannot contain spaces.");
//         printf("\n\t\t\t\t\t       4. Must contain one of these special characters. [ @ # $ * & _ ]");

//         do
//         {
//             printf("\n\n\t\t\t\t\t   Enter new password: ");
//             gets(pass_update);

//             correct_pass = password_validation(pass_update);

//         } while (correct_pass == 0);

//     } while (correct_name != 1 && correct_pass != 1);
// }

// int username_validation(char name_update[])
// {
//     int correct;
//     if (strlen(name_update) >= 4 && strlen(name_update) <= 16)
//     {
//         strcpy(sign_in.username, name_update);
//         correct = 1;
//     }
//     else
//     {
//         printf("\n\t\t\t\t\t   <!>  Username conditions did not match! Please try again...");

//         correct = 0;
//     }
//     return correct;
// }

// int password_validation(char pass_update[])
// {
//     int option, i, passlen, u_case, l_case, digit, sp_char, space;

//     if (strlen(pass_update) >= 4 && strlen(pass_update) <= 16)
//     {
//         passlen = 1;
//     }
//     else
//         passlen = 0;

//     for (i = 0; i < strlen(pass_update); i++)
//     {
//         if (pass_update[i] >= 'a' && pass_update[i] <= 'z')
//         {
//             l_case = 1;
//             break;
//         }
//         else
//             l_case = 0;
//     }

//     for (i = 0; i < strlen(pass_update); i++)
//     {
//         if (pass_update[i] >= 'A' && pass_update[i] <= 'Z')
//         {
//             u_case = 1;
//             break;
//         }
//         else
//             u_case = 0;
//     }

//     for (i = 0; i < strlen(pass_update); i++)
//     {
//         if (pass_update[i] == '@' || pass_update[i] == '#' || pass_update[i] == '$' || pass_update[i] == '_' || pass_update[i] == '&' || pass_update[i] == '*')
//         {
//             sp_char = 1;
//             break;
//         }
//         else
//             sp_char = 0;
//     }

//     for (i = 0; i < strlen(pass_update); i++)
//     {
//         if (pass_update[i] >= '0' && pass_update[i] <= '9')
//         {
//             digit = 1;
//             break;
//         }
//         else
//             digit = 0;
//     }

//     for (i = 0; i < strlen(pass_update); i++)
//     {
//         if (pass_update[i] == ' ')
//         {
//             space = 0;
//             break;
//         }
//         else
//             space = 1;
//     }

//     if (passlen == 1 && u_case == 1 && l_case == 1 && digit == 1 && sp_char == 1 && space == 1)
//     {
//         strcpy(sign_in.password, pass_update);
//         printf("\n\n\t\t\t\t\t   ========================================================================");
//         printf("\n\t\t\t\t\t\t   <i>  Username and Password has been changed successfully!");
//         printf("\n\t\t\t\t\t   ========================================================================");
//         printf("\n\n\t\t\t\t\t\t\t\t       --> Login again");
//         option = 1;
//     }
//     else
//     {
//         printf("\n\t\t\t\t\t   <!>  Password conditions did not match! Please try again...");
//         getchar();
//         option = 0;
//     }

//     return option;
// }

#include <stdio.h>
#include <string.h>
int main()
{
    char a[20];
    printf("ENter word: \n");

    char s1[] = "Geeks@forGeeks";
    char s2[] = ".";
    char *p;

    // Find first occurrence of s2 in s1
    p = strstr(s1, ".");
    printf("%s\n", p);

    return 0;
}