#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

COORD coord = {0, 0};
void gotoxy(int x, int y);
void Loading();
void welcome();
void login();
void mainmenu();
void Addbooks();
int checkid(int z);
void Viewbookslist();
void Deletebooks();
void Searchbooks();
void Issuebooks();
void Checkqty(int a);
void Searchissuedbooks();
void Deleteissuedbooks();
void Logout();
FILE *fp, *fs, *fi;
struct idate
{
    char s[100];
    int month;
    int mday;
};
struct Books
{
    char category[20];
    char name[20];
    int id;
    char author[30];
    int rackno;
    int quantity;
    char stname[20];
    struct idate issuedate;
    struct idate returndate;
};

struct Books b;
// Main
int main()
{
    Loading();
    welcome();
    login();

    return 0;
}
// Coordinate fucntion
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Loading function
void Loading()
{
    system("cls");
    gotoxy(30, 10);
    printf("\t\t\t\t\tLoading .");
    Sleep(500);
    system("cls");
    gotoxy(30, 10);
    printf("\t\t\t\t\tLoading . .");
    Sleep(500);
    system("cls");
    gotoxy(30, 10);
    printf("\t\t\t\t\tLoading . . .");
    Sleep(500);
}
// welcome function
void welcome()
{
    char wel[] = {"--------------LIBRARY MANAGEMENT SYSTEM--------------"};
    int l;
    l = strlen(wel);
    system("cls");
    gotoxy(45, 0);
    for (int i = 0; i < l; i++)
    {
        printf("%c", wel[i]);
        Sleep(100);
    }
}
// Login function
void login()
{
    char pass[20] = "a";
    gotoxy(45, 5);
    printf("Enter Password to login: ");
    scanf("%s", &pass);

    if (strcmp(pass, "library") == 0)
    {
        gotoxy(45, 7);
        printf("Login successful.\n");
        gotoxy(45, 9);
        printf("Press any key to continue.");
        getch();
        mainmenu();
    }
    else
    {
        gotoxy(45, 7);
        printf("Incorrect password.\n");
        gotoxy(45, 9);
        printf("Press any key to try again.");
        getch();
        system("cls");
        gotoxy(45, 0);
        printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
        login();
    }
}
//   Mainmenu
void mainmenu()
{
    int index;
    system("cls");
    gotoxy(45, 0);
    printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
    gotoxy(45, 3);
    printf("List of operations.");
    gotoxy(45, 5);
    printf("1> Add Books.");
    gotoxy(45, 7);
    printf("2> Delete Books.");
    gotoxy(45, 9);
    printf("3> Search Books.");
    gotoxy(45, 11);
    printf("4> Issue Books.");
    gotoxy(45, 13);
    printf("5> View books list.");
    gotoxy(45, 15);
    printf("6> Edit books record.");
    gotoxy(45, 17);
    printf("7> Logout.");
    gotoxy(45, 19);
    printf("Enter the index number to perform: ");
    scanf("%d", &index);

    switch (index)
    {
    case 1:
        Addbooks();
        break;

    case 2:
        Deletebooks();
        break;

    case 3:
        Searchbooks();
        break;

    case 4:
        Issuebooks();
        break;

    case 5:
        Viewbookslist();
        break;

        // case 6:
        //     Editbookslist();
        //     break;

        case 7:
            Logout();
            break;

    default:
        gotoxy(45, 21);
        printf("Wrong index entered.");
        gotoxy(45, 23);
        printf("Press any key to try again");
        getch();
        system("cls");
        mainmenu();
        break;
    }
}
// Addbooks
void Addbooks()
{
    fflush(stdin);
    system("cls");
    gotoxy(45, 0);
    printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
    gotoxy(45, 3);
    printf("List of operations->Add Books->Categories");
    char categories[][15] = {"Software", "Computer", "Maths", "Physics", "Chemistry", "C/C++", "Java", "Unknown"};
    int choice;
    int Id;
    char yn;
    gotoxy(45, 5);
    printf("1> Software");
    gotoxy(45, 7);
    printf("2> Computer");
    gotoxy(45, 9);
    printf("3> Maths");
    gotoxy(45, 11);
    printf("4> Physics");
    gotoxy(45, 13);
    printf("5> Chemistry.");
    gotoxy(45, 15);
    printf("6> C/C++");
    gotoxy(45, 17);
    printf("7> Java");
    gotoxy(45, 19);
    printf("8> Unknown");
    gotoxy(45, 21);
    printf("9> Back to Main Menu");
    gotoxy(45, 23);
    fflush(stdin);
    fflush(stdout);
    printf("Enter the index number to perform: ");
    scanf("%d", &choice);
    if (choice == 9)
    {
        mainmenu();
    }
    system("cls");
    gotoxy(45, 0);
    printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
    gotoxy(45, 3);
    printf("List of operations->Add Books:");
    gotoxy(45, 5);
    printf("Category : %s", categories[choice - 1]);
    gotoxy(45, 7);
    fflush(stdin);
    printf("Book id : ");
    scanf("%d", &Id);
    checkid(Id);
    fp = fopen("Library.txt", "ab");

    strcpy(b.category, categories[choice - 1]);
    gotoxy(45, 9);
    fflush(stdin);
    printf("Book name : ");
    scanf(" %[^\n]", &b.name);
    gotoxy(45, 11);
    fflush(stdin);
    printf("Author : ");
    scanf("%[^\n]", &b.author);
    gotoxy(45, 13);
    fflush(stdin);
    printf("Quantity : ");
    scanf("%d", &b.quantity);
    gotoxy(45, 15);
    fflush(stdin);
    printf("Rack no :");
    scanf("%d", &b.rackno);
    fflush(stdin);
    b.id = Id;
    fseek(fp, 0, SEEK_END);
    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
    gotoxy(45, 17);
    printf("The Record Is Sucessfully Saved");
    gotoxy(45, 19);
    printf("Do you want to save more?(Y / N):");
    yn = getch();
    if (yn == 'n' || yn == 'N')
        mainmenu();
    else
    {
        Addbooks();
    }
}
//    checkid
int checkid(int z)
{
    fp = fopen("Library.txt", "rb");
    rewind(fp);
    while (fread(&b, sizeof(b), 1, fp))
    {
        if (b.id == z)
        {
            gotoxy(45, 9);
            printf("The book with id : %d already exist.", z);
            gotoxy(45, 12);
            printf("Press any key to enter book record with different id.");
            getch();
            system("cls");
            Addbooks();
        }
    }
}
//    viewbooks list
void Viewbookslist()
{
    system("cls");
    gotoxy(48, 0);
    printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
    gotoxy(48, 3);
    printf("List of operations->View books list:");
    gotoxy(40, 7);
    printf(" CATEGORY      ID       BOOK NAME            AUTHOR            QTY   RackNo ");
    gotoxy(40, 8);
    printf("____________________________________________________________________________");
    int j = 10, i = 0;
    fp = fopen("Library.txt", "rb");
    while (fread(&b, sizeof(b), 1, fp) == 1)
    {
        gotoxy(41, j);
        printf("%s", b.category);
        gotoxy(55, j);
        printf("%d", b.id);
        gotoxy(62, j);
        printf("%s", b.name);
        gotoxy(85, j);
        printf("%s", b.author);
        gotoxy(105, j);
        printf("%d", b.quantity);
        gotoxy(113, j);
        printf("%d", b.rackno);
        j++;
        i = i + b.quantity;
    }
    fclose(fp);
    gotoxy(85, j + 1);
    printf("Total books = %d.", i);
    gotoxy(50, j + 3);
    printf("Press any key to Menu.");
    getch();
    mainmenu();
}
//  deletebooks
void Deletebooks()
{
    fclose(fp);
    system("cls");
    gotoxy(48, 0);
    printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
    gotoxy(48, 3);
    printf("List of operations->Delete Books:");
    char del = 'y';
    char dele;
    char bookfound = 'n';
    int x;
    while (del == 'y')
    {
        fflush(stdin);
        gotoxy(48, 5);
        printf("Enter the Book ID to  delete:");
        scanf("%d", &x);
        fp = fopen("Library.txt", "rb");
        rewind(fp);
        while (fread(&b, sizeof(b), 1, fp))
        {
            if (b.id == x)
            {
                system("cls");
                gotoxy(48, 0);
                printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
                gotoxy(48, 3);
                printf("List of operations->Delete Books:");
                gotoxy(48, 5);
                printf("The Book Record Is Available :");
                gotoxy(40, 8);
                printf(" CATEGORY      ID       BOOK NAME            AUTHOR            QTY   RackNo ");
                gotoxy(40, 9);
                printf("____________________________________________________________________________");
                gotoxy(41, 11);
                printf("%s", b.category);
                gotoxy(55, 11);
                printf("%d", b.id);
                gotoxy(62, 11);
                printf("%s", b.name);
                gotoxy(85, 11);
                printf("%s", b.author);
                gotoxy(105, 11);
                printf("%d", b.quantity);
                gotoxy(113, 11);
                printf("%d", b.rackno);
                bookfound = 'y';
            }
            if (bookfound == 'y')
            {
                gotoxy(48, 13);
                printf("Do you want to delete it ? (y/n)");
                scanf("%s", &dele);
                if (dele == 'y' || dele == 'Y')
                {
                    fs = fopen("temp.txt", "wb");
                    rewind(fp);

                    while (fread(&b, sizeof(b), 1, fp))
                    {
                        if (b.id != x)
                        {
                            fseek(fs, 0, SEEK_CUR);
                            fwrite(&b, sizeof(b), 1, fs);
                        }
                    }
                    fclose(fs);
                    fclose(fp);
                    remove("Library.txt");
                    rename("temp.txt", "Library.txt");
                    gotoxy(48, 15);
                    printf("The record is successfully deleted.");
                    gotoxy(48, 16);
                    printf("Delete more records? (Y/N)");
                    if (getch() == 'y')
                    {
                        Deletebooks();
                    }
                    else
                    {
                        gotoxy(48, 18);
                        printf("Press any key to return");
                        getch();
                        mainmenu();
                    }
                }

                else
                {
                    fclose(fp);
                    gotoxy(48, 15);
                    printf("Press any key to return");
                    getch();
                    mainmenu();
                }
            }
        }
        if (bookfound != 'y')
        {
            fclose(fp);
            gotoxy(48, 7);
            printf("No book record found.");
            gotoxy(48, 9);
            printf("Press any key to return to menu.");
            if (getch())
                mainmenu();
        }
    }
}
//  searchbooks
void Searchbooks()
{

    char sbname[30];
    char saname[30];
    int sid;
    char found = 'y';
    int count = 0;
    int choice;
    char yn;
    int j = 11;
    system("cls");
    gotoxy(48, 0);
    printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
    gotoxy(48, 3);
    printf("List of operations->Search Books:");
    gotoxy(48, 6);
    printf("1-> Search Book by name.");
    gotoxy(48, 8);
    printf("2-> Search Book by Id.");
    gotoxy(48, 10);
    printf("3-> Search Book by Author.");
    gotoxy(48, 12);
    printf("4-> Return to menu.");
    gotoxy(48, 14);
    printf("Enter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        fflush(stdin);
        gotoxy(48, 16);
        printf("Enter Book name:");
        scanf("%[^\n]", &sbname);
        fp = fopen("Library.txt", "rb");
        rewind(fp);
        system("cls");
        while (fread(&b, sizeof(b), 1, fp))
        {
            gotoxy(48, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(48, 3);
            printf("List of operations->Search Book by name: %s", sbname);
            gotoxy(48, 5);
            printf("The Book Record Is Available :");
            gotoxy(40, 8);
            printf(" CATEGORY      ID       BOOK NAME            AUTHOR            QTY   RackNo ");
            gotoxy(40, 9);
            printf("____________________________________________________________________________");
            if (strcmpi(b.name, sbname) == 0)
            {
                gotoxy(41, j);
                printf("%s", b.category);
                gotoxy(55, j);
                printf("%d", b.id);
                gotoxy(62, j);
                printf("%s", b.name);
                gotoxy(85, j);
                printf("%s", b.author);
                gotoxy(105, j);
                printf("%d", b.quantity);
                gotoxy(113, j);
                printf("%d", b.rackno);
                count++;
                j = j + 2;
            }
        }
        gotoxy(48, 6);
        printf("Total books found= %d", count);
        if (count == 0)
        {

            system("cls");
            gotoxy(48, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(48, 3);
            printf("List of operations->Search Book by name: %s", sbname);
            gotoxy(48, 5);
            printf("The Book Record Is not  Available.");
        }
        fclose(fp);
        gotoxy(48, j + 1);
        printf("Search more books? (y/n)");
        scanf("%s", &yn);
        if (yn == 'y' || yn == 'Y')
        {
            Searchbooks();
        }
        else
        {
            mainmenu();
        }

        break;

    case 2:
        fflush(stdin);
        gotoxy(48, 16);
        printf("Enter Book ID:");
        scanf("%d", &sid);
        fp = fopen("Library.txt", "rb");
        rewind(fp);
        system("cls");
        while (fread(&b, sizeof(b), 1, fp))
        {

            gotoxy(48, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(48, 3);
            printf("List of operations->Search Book by ID: %d", sid);
            gotoxy(48, 5);
            printf("Book Details:");
            gotoxy(40, 8);
            printf(" CATEGORY      ID       BOOK NAME            AUTHOR            QTY   RackNo ");
            gotoxy(40, 9);
            printf("____________________________________________________________________________");
            if (b.id == sid)
            {
                gotoxy(41, j);
                printf("%s", b.category);
                gotoxy(55, j);
                printf("%d", b.id);
                gotoxy(65, j);
                printf("%s", b.name);
                gotoxy(85, j);
                printf("%s", b.author);
                gotoxy(105, j);
                printf("%d", b.quantity);
                gotoxy(113, j);
                printf("%d", b.rackno);
                count++;
                j = j + 2;
            }
        }
        gotoxy(48, 6);
        printf("Total books found= %d", count);
        if (count == 0)
        {

            system("cls");
            gotoxy(48, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(48, 3);
            printf("List of operations->Search Book by ID: %d", sid);
            gotoxy(48, 5);
            printf("The Book Record Is not  Available.");
        }
        fclose(fp);
        gotoxy(48, j + 2);
        fflush(stdin);
        printf("Search more books? (y/n)");
        scanf("%s", &yn);
        if (yn == 'y' || yn == 'Y')
        {
            Searchbooks();
        }
        else
        {
            mainmenu();
        }

        break;
    case 3:
        fflush(stdin);
        gotoxy(48, 16);
        printf("Enter Author name:");
        scanf("%[^\n]", &saname);
        fp = fopen("Library.txt", "rb");
        rewind(fp);
        system("cls");
        while (fread(&b, sizeof(b), 1, fp))
        {
            gotoxy(48, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(48, 3);
            printf("List of operations->Search Book by Author: %s", saname);
            gotoxy(48, 5);
            printf("The Book Record Is Available :");
            gotoxy(40, 8);
            printf(" CATEGORY      ID       BOOK NAME            AUTHOR            QTY   RackNo ");
            gotoxy(40, 9);
            printf("____________________________________________________________________________");
            if (strcmpi(b.author, saname) == 0)
            {
                gotoxy(41, j);
                printf("%s", b.category);
                gotoxy(55, j);
                printf("%d", b.id);
                gotoxy(62, j);
                printf("%s", b.name);
                gotoxy(85, j);
                printf("%s", b.author);
                gotoxy(105, j);
                printf("%d", b.quantity);
                gotoxy(113, j);
                printf("%d", b.rackno);
                count++;
                j = j + 2;
            }
        }
        gotoxy(48, 6);
        printf("Total books found= %d", count);
        if (count == 0)
        {

            system("cls");
            gotoxy(48, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(48, 3);
            printf("List of operations->Search Book by author: %s", saname);
            gotoxy(48, 5);
            printf("The Book Record Is not  Available.");
        }
        fclose(fp);
        gotoxy(48, j + 1);
        printf("Search more books? (y/n)");
        scanf("%s", &yn);
        if (yn == 'y' || yn == 'Y')
        {
            Searchbooks();
        }
        else
        {
            mainmenu();
        }

        break;
    case 4:
        mainmenu();
        break;
    default:
        gotoxy(48, 13);
        printf("Wrong index entered.");
        gotoxy(48, 15);
        printf("Press any key to enter again.");
        getch();
        Searchbooks();
        break;
    }
}
// Issuebooks

void Issuebooks()
{
    char nem[30];
    int choice1;
    int iid;
    int count1 = 0;
    int k = 11;
    int x;
    char iyn;
    int a = 18;
    system("cls");
    gotoxy(48, 0);
    printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
    gotoxy(48, 3);
    printf("List of operations->Issue books:");
    gotoxy(48, 6);
    printf("1-> Issue new book.");
    gotoxy(48, 8);
    printf("2-> List Issued books");
    gotoxy(48, 10);
    printf("3-> Search Issued books.");
    gotoxy(48, 12);
    printf("4-> Delete Issued books.");
    gotoxy(48, 14);
    printf("5-> Return to menu.");
    gotoxy(48, 16);
    printf("Enter your choice:");
    scanf("%d", &choice1);
    switch (choice1)
    {
    case 1:

        system("cls");
        gotoxy(48, 0);
        printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
        gotoxy(48, 3);
        printf("List of operations->Issue books->Issue new book:");
        gotoxy(48, 5);
        fflush(stdin);
        printf("Enter Book id to issue:");
        scanf("%d", &iid);
        fp = fopen("Library.txt", "rb");
        rewind(fp);

        system("cls");
        while (fread(&b, sizeof(b), 1, fp))
        {
            gotoxy(48, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(48, 3);
            printf("List of operations->Issue Book by ID: %d", iid);
            gotoxy(48, 5);
            printf("Book Details:");
            gotoxy(40, 8);
            printf(" CATEGORY      ID       BOOK NAME            AUTHOR            QTY   RackNo ");
            gotoxy(40, 9);
            printf("____________________________________________________________________________");
            if (b.id == iid)
            {
                gotoxy(41, k);
                printf("%s", b.category);
                gotoxy(55, k);
                printf("%d", b.id);
                gotoxy(62, k);
                printf("%s", b.name);
                gotoxy(85, k);
                printf("%s", b.author);
                gotoxy(105, k);
                printf("%d", b.quantity);
                gotoxy(113, k);
                printf("%d", b.rackno);
                count1++;
                k = k + 2;
                strcpy(nem, b.stname);
            }
        }
        fclose(fp);
        Checkqty(iid);
        if (count1 == 0)
        {
            system("cls");
            gotoxy(48, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(48, 3);
            printf("List of operations->Issue Book by ID: %d", iid);
            gotoxy(48, 5);
            printf("The Book Record Is not  Available.");
            gotoxy(48, 7);
            printf("Press any key to return to menu.");
            if (getch())
            {
                Issuebooks();
            }
        }
        strcpy(nem, b.stname);
        gotoxy(48, 23);
        printf("Succesfully issued book of id:%d to %s .", iid, nem);
        gotoxy(48, 25);
        printf("Issue more books? (y/n)");
        scanf("%s", &iyn);
        if (iyn == 'y' || iyn == 'Y')
        {
            Issuebooks();
        }
        else
        {
            mainmenu();
        }
        break;
    case 2:

        system("cls");
        gotoxy(42, 0);
        printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
        gotoxy(42, 3);
        printf("List of operations->List Issued Books:");
        gotoxy(29 - a, 7);
        printf("    St.NAME         CATEGORY      ID  BOOK NAME          AUTHOR              ISSUE DATE         T.PERIOD    ");
        gotoxy(29 - a, 8);
        printf("____________________________________________________________________________________________________________");
        int j = 10, i = 0;
        fp = fopen("Issue.txt", "rb");
        while (fread(&b, sizeof(b), 1, fp) == 1)
        {
            fflush(stdin);
            gotoxy(30 - a, j);
            printf("%s", b.stname);
            gotoxy(48 - a, j);
            printf("%s", b.category);
            gotoxy(63 - a, j);
            printf("%d", b.id);
            gotoxy(68 - a, j);
            printf("%s", b.name);
            gotoxy(80 - a, j);
            printf("%s", b.author);
            gotoxy(103 - a, j);
            printf("%s", b.issuedate.s);
            // printf("\033[0;31m"); // Set the text to the color red
            // printf("\033[0m"); // Resets the text to default color
            gotoxy(125 - a, j);
            printf("%d months", b.returndate.month);
            gotoxy(137 - a, j);
            fflush(stdin);

            j++;
            i++;
        }
        fclose(fp);
        gotoxy(85, j + 1);
        printf("Total books issued. = %d.", i);
        gotoxy(50, j + 3);
        printf("Press any key to Menu.");
        getch();
        Issuebooks();
        break;
    case 3:
        Searchissuedbooks();
        break;
    case 4:
        Deleteissuedbooks();
        break;

    case 5:
        mainmenu();
        break;
    default:
        gotoxy(48, 18);
        printf("Wrong index entered.");
        gotoxy(48, 20);
        printf("Press any key to enter again.");
        getch();
        Issuebooks();
        break;
    }
}

void Checkqty(int a)
{
    int qty = 0;
    fi = fopen("Issue.txt", "rb");
    rewind(fi);
    while (fread(&b, sizeof(b), 1, fi))
    {
        if (b.id == a)
        {
            qty++;
        }
    }
    fclose(fi);
    fp = fopen("Library.txt", "rb");
    rewind(fp);
    while (fread(&b, sizeof(b), 1, fp))
    {
        if (b.id == a)
        {
            if (qty == b.quantity)
            {
                system("cls");
                gotoxy(48, 0);
                printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
                gotoxy(48, 3);
                printf("List of operations->Issue Book by ID: %d", a);
                gotoxy(48, 5);
                printf("All Books with id : %d are issued.", a);
                gotoxy(48, 7);
                printf("Press any key to return to menu.");
                fclose(fs);
                if (getch())
                {
                    Issuebooks();
                }
            }
            else
            {
                fflush(stdin);
                fi = fopen("Issue.txt", "ab");
                gotoxy(48, 15);
                printf("Enter student name:");
                scanf("%[^\n]", &b.stname);
                gotoxy(48, 17);
                printf("1->1 month.");
                gotoxy(48, 19);
                printf("6->6 month.");
                gotoxy(48, 21);
                printf("Enter Return Time Period:");
                scanf("%d", &b.returndate.month);
                time_t live;
                live = time(NULL);
                struct tm *cur_time = localtime(&live);
                strftime(b.issuedate.s, 100, "%a %b %d-%I:%M %p", cur_time);
                b.issuedate.month = cur_time->tm_mday;
                b.issuedate.mday = cur_time->tm_mon + 1;
                fseek(fi, sizeof(b), SEEK_END);
                fwrite(&b, sizeof(b), 1, fi);
                fclose(fi);
            }
        }
    }
    fclose(fs);
}

// search issued books
void Searchissuedbooks()
{
    fflush(stdin);
    char sbname[30];
    char saname[30];
    int sid;
    char found = 'y';
    int count = 0;
    int choice;
    char yn;
    int j = 12;
    int a = 18;
    system("cls");
    gotoxy(48, 0);
    printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
    gotoxy(48, 3);
    printf("List of operations->Search Issued Books:");
    gotoxy(48, 6);
    printf("1-> Search issued Book by Student name.");
    gotoxy(48, 8);
    printf("2-> Search issued Book by Id.");
    gotoxy(48, 10);
    printf("3-> Search issued Book by Author.");
    gotoxy(48, 12);
    printf("4-> Return to menu.");
    gotoxy(48, 14);
    printf("Enter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        fflush(stdin);
        gotoxy(48, 16);
        printf("Enter Student name:");
        scanf("%[^\n]", &sbname);
        fi = fopen("Issue.txt", "rb");
        rewind(fi);
        system("cls");
        while (fread(&b, sizeof(b), 1, fi))
        {

            gotoxy(42, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(42, 3);
            printf("List of operations->Search issued Book by Student name: %s", sbname);
            gotoxy(29 - a, 7);
            printf("    St.NAME         CATEGORY      ID  BOOK NAME          AUTHOR              ISSUE DATE         T.PERIOD    ");
            gotoxy(29 - a, 8);
            printf("____________________________________________________________________________________________________________");
            if (strcmpi(b.stname, sbname) == 0)
            {
                fflush(stdin);
                gotoxy(30 - a, j);
                printf("%s", b.stname);
                gotoxy(48 - a, j);
                printf("%s", b.category);
                gotoxy(63 - a, j);
                printf("%d", b.id);
                gotoxy(68 - a, j);
                printf("%s", b.name);
                gotoxy(80 - a, j);
                printf("%s", b.author);
                gotoxy(103 - a, j);
                printf("%s", b.issuedate.s);
                // printf("\033[0;31m"); // Set the text to the color red
                // printf("\033[0m"); // Resets the text to default color
                gotoxy(125 - a, j);
                printf("%d months", b.returndate.month);
                gotoxy(137 - a, j);

                count++;
                j = j + 2;
            }
        }
        gotoxy(48, 6);
        printf("Total books found= %d", count);
        if (count == 0)
        {

            system("cls");
            gotoxy(48, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(48, 3);
            printf("List of operations->Search issued Book by Student name: %s", sbname);
            gotoxy(48, 5);
            printf("The Book Record Is not  Available.");
        }
        fclose(fp);
        gotoxy(48, j + 1);
        printf("Search more books? (y/n)");
        scanf("%s", &yn);
        if (yn == 'y' || yn == 'Y')
        {
            Searchissuedbooks();
        }
        else
        {
            mainmenu();
        }

        break;

    case 2:
        fflush(stdin);
        gotoxy(48, 16);
        printf("Enter Book ID:");
        scanf("%d", &sid);
        fi = fopen("Issue.txt", "rb");
        rewind(fi);
        system("cls");
        while (fread(&b, sizeof(b), 1, fi))
        {

            gotoxy(42, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(42, 3);
            printf("List of operations->Search issued Book by ID: %d", sid);
            gotoxy(29 - a, 7);
            printf("    St.NAME         CATEGORY      ID  BOOK NAME          AUTHOR              ISSUE DATE         T.PERIOD    ");
            gotoxy(29 - a, 8);
            printf("____________________________________________________________________________________________________________");
            if (b.id == sid)
            {
                fflush(stdin);
                gotoxy(30 - a, j);
                printf("%s", b.stname);
                gotoxy(48 - a, j);
                printf("%s", b.category);
                gotoxy(63 - a, j);
                printf("%d", b.id);
                gotoxy(68 - a, j);
                printf("%s", b.name);
                gotoxy(80 - a, j);
                printf("%s", b.author);
                gotoxy(103 - a, j);
                printf("%s", b.issuedate.s);
                // printf("\033[0;31m"); // Set the text to the color red
                // printf("\033[0m"); // Resets the text to default color
                gotoxy(125 - a, j);
                printf("%d months", b.returndate.month);
                gotoxy(137 - a, j);
                fflush(stdin);

                count++;
                j = j + 2;
            }
        }
        gotoxy(48, 6);
        printf("Total books found= %d", count);
        if (count == 0)
        {

            system("cls");
            gotoxy(48, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(48, 3);
            printf("List of operations->Search issued Book by ID: %d", sid);
            gotoxy(48, 5);
            printf("The Book Record Is not  Available.");
        }
        fclose(fi);
        gotoxy(48, j + 2);
        fflush(stdin);
        printf("Search more books? (y/n)");
        scanf("%s", &yn);
        if (yn == 'y' || yn == 'Y')
        {
            Searchissuedbooks();
        }
        else
        {
            mainmenu();
        }

        break;
    case 3:
        fflush(stdin);
        gotoxy(48, 16);
        printf("Enter Author name:");
        scanf("%[^\n]", &saname);
        fi = fopen("Issue.txt", "rb");
        rewind(fi);
        system("cls");
        while (fread(&b, sizeof(b), 1, fi))
        {

            gotoxy(42, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(42, 3);
            printf("List of operations->Search issued Book by author: %s", saname);
            gotoxy(29 - a, 7);
            printf("    St.NAME         CATEGORY      ID  BOOK NAME          AUTHOR              ISSUE DATE         T.PERIOD    ");
            gotoxy(29 - a, 8);
            printf("____________________________________________________________________________________________________________");
            if (strcmpi(b.author, saname) == 0)
            {
                fflush(stdin);
                gotoxy(30 - a, j);
                printf("%s", b.stname);
                gotoxy(48 - a, j);
                printf("%s", b.category);
                gotoxy(63 - a, j);
                printf("%d", b.id);
                gotoxy(68 - a, j);
                printf("%s", b.name);
                gotoxy(80 - a, j);
                printf("%s", b.author);
                gotoxy(103 - a, j);
                printf("%s", b.issuedate.s);
                // printf("\033[0;31m"); // Set the text to the color red
                // printf("\033[0m"); // Resets the text to default color
                gotoxy(125 - a, j);
                printf("%d months", b.returndate.month);
                gotoxy(137 - a, j);
                fflush(stdin);

                count++;
                j = j + 2;
            }
        }
        gotoxy(48, 6);
        printf("Total books found= %d", count);
        if (count == 0)
        {

            system("cls");
            gotoxy(48, 0);
            printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
            gotoxy(48, 3);
            printf("List of operations->Search issued Book by author: %s", saname);
            gotoxy(48, 5);
            printf("The Book Record Is not  Available.");
        }
        fclose(fi);
        gotoxy(48, j + 1);
        printf("Search more books? (y/n)");
        scanf("%s", &yn);
        if (yn == 'y' || yn == 'Y')
        {
            Searchissuedbooks();
        }
        else
        {
            mainmenu();
        }

        break;
    case 4:
        mainmenu();
        break;
    default:
        gotoxy(48, 13);
        printf("Wrong index entered.");
        gotoxy(48, 15);
        printf("Press any key to enter again.");
        getch();
        Searchissuedbooks();
        break;
    }
}

// delete issued books records

void Deleteissuedbooks()
{
    char stdname[30];
    fclose(fi);
    fflush(stdin);
    int a = 18;
    int j = 12;
    system("cls");
    gotoxy(48, 0);
    printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
    gotoxy(48, 3);
    printf("List of operations->Delete issued Books:");
    char del = 'y';
    char dele;
    char bookfound = 'n';
    int x;
    while (del == 'y')
    {
        fflush(stdin);
        gotoxy(48, 5);
        printf("Enter student name: ");
        scanf("%[^\n]", &stdname);
        gotoxy(48, 7);
        printf("Enter the Book ID to  delete:");
        scanf("%d", &x);
        fi = fopen("Issue.txt", "rb");
        rewind(fi);
        while (fread(&b, sizeof(b), 1, fi))
        {
            if (b.id == x && strcmp(b.stname, stdname) == 0)
            {
                system("cls");
                gotoxy(42, 0);
                printf("--------------LIBRARY MANAGEMENT SYSTEM--------------");
                gotoxy(42, 3);
                printf("List of operations->Delete issued Book of id: %d,issued to %s.", x, stdname);
                gotoxy(29 - a, 7);
                printf("    St.NAME         CATEGORY      ID  BOOK NAME          AUTHOR              ISSUE DATE         T.PERIOD    ");
                gotoxy(29 - a, 8);
                printf("____________________________________________________________________________________________________________");
                fflush(stdin);
                gotoxy(30 - a, j);
                printf("%s", b.stname);
                gotoxy(48 - a, j);
                printf("%s", b.category);
                gotoxy(63 - a, j);
                printf("%d", b.id);
                gotoxy(68 - a, j);
                printf("%s", b.name);
                gotoxy(80 - a, j);
                printf("%s", b.author);
                gotoxy(103 - a, j);
                printf("%s", b.issuedate.s);
                // printf("\033[0;31m"); // Set the text to the color red
                // printf("\033[0m"); // Resets the text to default color
                gotoxy(125 - a, j);
                printf("%d months", b.returndate.month);
                gotoxy(137 - a, j);
                bookfound = 'y';
            }
            if (bookfound == 'y')
            {
                gotoxy(48, 13);
                printf("Do you want to delete it ? (y/n)");
                scanf("%s", &dele);
                if (dele == 'y' || dele == 'Y')
                {
                    fs = fopen("temp.txt", "wb");
                    rewind(fi);

                    while (fread(&b, sizeof(b), 1, fi))
                    {
                        if ((strcmp(stdname, b.stname) != 0) && (b.id != x))
                        {
                            fseek(fs, 0, SEEK_CUR);
                            fwrite(&b, sizeof(b), 1, fs);
                        }
                    }
                    fclose(fs);
                    fclose(fi);
                    remove("Issue.txt");
                    rename("temp.txt", "Issue.txt");
                    gotoxy(48, 15);
                    printf("The record is successfully deleted.");
                    gotoxy(48, 16);
                    printf("Delete more records? (Y/N)");
                    if (getch() == 'y')
                    {
                        Deleteissuedbooks();
                    }
                    else
                    {
                        gotoxy(48, 18);
                        printf("Press any key to return");
                        getch();
                        mainmenu();
                    }
                }

                else
                {
                    fclose(fi);
                    gotoxy(48, 15);
                    printf("Press any key to return");
                    getch();
                    mainmenu();
                }
            }
        }
        if (bookfound != 'y')
        {
            fclose(fi);
            gotoxy(48, 9);
            printf("No book record found.");
            gotoxy(48, 11);
            printf("Press any key to return to menu.");
            if (getch())
                mainmenu();
        }
    }
}

void Logout(){
     char wel[] = {"--------------LIBRARY MANAGEMENT SYSTEM--------------"};
    int l;
    l = strlen(wel);
    system("cls");
    gotoxy(45, 0);
    for (int i = 0; i < l; i++)
    {
        printf("%c", wel[i]);
        
    }
    login();
}