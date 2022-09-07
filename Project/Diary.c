#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void add_rec();
void edit_rec();
void edit_pass();
void view_rec();
void del_rec();
int pass_word();

struct rec

{
    char plce[30]; //
    char nam[35];
    char note[5000];
    char tme[7];
    char duration[15];
};

int main()

{

    int ch;

    printf("\t*PERSONAL DIARY*\n");

    printf("\t****************");

    while (1)

    {

        printf("\n\n\t\tMENU:");

        printf("\n\n\tADD ANY RECORD\t\t[1]");

        printf("\n\tVIEW ANY RECORD\t\t[2]");

        printf("\n\tEDIT ANY RECORD\t\t[3]");

        printf("\n\tDELETE ANY RECORD\t[4]");

        printf("\n\tEDIT THE PASSWORD\t[5]");

        printf("\n\tEXIT FROM APP\t\t[6]");

        printf("\n\n\tENTER ANY OF YOUR CHOICE:");

        scanf("%d", &ch);

        switch (ch)

        {

        case 1:

            add_rec();

            break;

        case 2:

            view_rec();

            break;

        case 3:

            edit_rec();

            break;

        case 4:

            del_rec();

            break;

        case 5:

            edit_pass();

            break;

        case 6:

            printf("\n\n\t\tTHANK YOU, PLEASE USE LATER AGAIN ");

            getch();

            exit(0);

        default:

            printf("\nYOUR CHOICE IS WRONG, ENTER SOMETHING ELSE..");

            printf("\nPRESS ANY KEY FOR TRYING AGAIN");

            getch();

            break;
        }

        system("cls");
    }

    return 0;
}

void add_rec()

{

    system("cls");

    FILE *filePointer;

    char anyother = 'Y', tme[11];

    struct rec e;

    char fnam[20];
    int choice;

    printf("\t\t*MENU : ADD*");

    printf("\n\t\t************\n\n");

    printf("\n\n\tENTER THE DATE FOR YOUR RECORD:[dd-mm-yyyy]:");

    fflush(stdin);

    gets(fnam);

    filePointer = fopen(fnam, "ab+"); // Binary file open kore file er last ey likhar jonno. The fopen() function file banay na thakle

    if (filePointer == NULL)

    {

        filePointer = fopen(fnam, "wb+"); // lekha porar jonno binary file banay. File thakle delete kore dey jodi na logical hoy.

        if (filePointer == NULL)

        {

            printf("\nERROR IN THE SYSTEM...");

            printf("\nPRESS ANY KEY IN THE KEYBOARD TO EXIT");

            getch();

            return;
        }
    }

    while (anyother == 'Y' || anyother == 'y')

    {

        choice = 0;

        fflush(stdin);

        /*fflush() output clear kore console ey pathay dey. */

        printf("\n\tENTER THE TIME:[hh:mm]:");

        scanf("%s", tme);

        rewind(filePointer);

        while (fread(&e, sizeof(e), 1, filePointer) == 1)

        {

            if (strcmp(e.tme, tme) == 0) // The strcmp() compares kore duita strings ke char by char

            {

                printf("\n\tTHE RECORD ALREADY EXISTS.\n");

                choice = 1;
            }
        }

        if (choice == 0)

        {

            strcpy(e.tme, tme);

            printf("\tENTER THE NAME:");

            fflush(stdin);

            gets(e.nam);

            fflush(stdin);

            printf("\tENTER THE PLACE:");

            gets(e.plce);

            fflush(stdin);

            printf("\tENTER THE DURATION:");

            gets(e.duration);

            fflush(stdin);

            printf("\tWRITE YOUR NOTE:");

            gets(e.note);

            fwrite(&e, sizeof(e), 1, filePointer);

            printf("\nRECORD IS ADDED...\n");
        }

        printf("\n\tWANT TO ADD ANY RECORD AGAIN...(Y/N) ");

        fflush(stdin);

        anyother = getchar();
    }

    fclose(filePointer);

    printf("\n\n\tPRESS ANY KEY FROM THE KEYBOARD TO EXIT...");

    getch();
}

void view_rec()

{

    FILE *fpt_e;

    system("cls");

    struct rec user;

    char tme[10], choice, fnam[20];

    int ch;

    printf("\t\t*MENU : VIEW*");

    printf("\n\t\t**************\n\n");

    choice = pass_word();

    if (choice != 0)

    {

        return;
    }

    do

    {

        printf("\n\tENTER DATE FOR VIEWING RECORD:[dd-mm-yyyy]:");

        fflush(stdin);

        gets(fnam);

        fpt_e = fopen(fnam, "rb"); // file thaka lage, binary file open kore

        if (fpt_e == NULL)

        {

            puts("\nNO RECORD FOUND...\n");

            printf("PRESS ANY KEY FROM THE KEYBOARD AND EXIT...");

            getch();

            return;
        }

        system("cls");

        printf("\n\tHOW YOU WANT TO VIEW A RECORD:\n");

        printf("\n\t1.ALL RECORD OF A DAY.");

        printf("\n\t2.FIX TIME.");

        printf("\n\t\tENTER ANY CHOICE:");

        scanf("%d", &ch);

        switch (ch)

        {

        case 1:

            printf("\nALL RECORD FOR %s IS:", fnam);

            while (fread(&user, sizeof(user), 1, fpt_e) == 1)

            {

                printf("\n");

                printf("\nTIME: %s", user.tme);

                printf("\nMEETING WITH: %s", user.nam);

                printf("\nMEETING AT: %s", user.plce);

                printf("\nDURATION: %s", user.duration);

                printf("\nNOTE: %s", user.note);

                printf("\n");
            }

            break;

        case 2:

            fflush(stdin);

            printf("\nENTER TIME:[hh:mm]:");

            gets(tme);

            while (fread(&user, sizeof(user), 1, fpt_e) == 1)

            {

                if (strcmp(user.tme, tme) == 0)

                {

                    printf("\nYOUR RECORD IS:");

                    printf("\nTIME: %s", user.tme);

                    printf("\nMEETING WITH: %s", user.nam);

                    printf("\nMEETING AT: %s", user.plce);

                    printf("\nDUARATION: %s", user.duration);

                    printf("\nNOTE: %s", user.note);
                }
            }

            break;

        default:
            printf("\nWRONG INPUT...\n");

            break;
        }

        printf("\n\nWANT TO CHECK MORE?...(Y/N):");

        fflush(stdin);

        scanf("%c", &choice);

    }
    while (choice == 'Y' || choice == 'y');

    fclose(fpt_e);

    return;
}

void edit_rec()

{

    system("cls");

    FILE *fpt_e;

    struct rec user;

    char tme[10], choice, fnam[20];

    int num, count = 0;

    printf("\t\t* MENU :  EDIT *");

    printf("\n\t\t*************\n\n");

    choice = pass_word();

    if (choice != 0)

    {

        return;
    }

    do

    {

        printf("\n\tENTER DATE FOR A RECORD:[dd-mm-yyyy]:");

        fflush(stdin);

        gets(fnam);

        printf("\n\tENTER THE TIME:[hh:mm]:");

        gets(tme);

        fpt_e = fopen(fnam, "rb+");

        if (fpt_e == NULL)

        {

            printf("\nRECORD NOT FOUND:");

            printf("\nPRESS ANY KEY FROM KEYBOARD TO GO BACK");

            getch();

            return;
        }

        while (fread(&user, sizeof(user), 1, fpt_e) == 1)

        {

            if (strcmp(user.tme, tme) == 0)

            {

                printf("\nOLD RECORD:");

                printf("\nTIME: %s", user.tme);

                printf("\nMEETING WITH: %s", user.nam);

                printf("\nMEETING AT: %s", user.plce);

                printf("\nDURATION: %s", user.duration);

                printf("\nNOTE: %s", user.note);

                printf("\n\n\t\tWHAT YOU WANT TO EDIT..");

                printf("\n1.Time.");

                printf("\n2.MEETING PERSON.");

                printf("\n3.MEETING PLACE.");

                printf("\n4.DURATION.");

                printf("\n5.NOTE.");

                printf("\n6.WHOLE RECORD.");

                printf("\n7.GO BACK TO MAIN MENU.");

                do

                {

                    printf("\n\tENTER A CHOICE:");

                    fflush(stdin);

                    scanf("%d", &num);

                    fflush(stdin);

                    switch (num)

                    {

                    case 1:
                        printf("\nENTER NEW DATA:");

                        printf("\nTHE NEW TIME:[hh:mm]:");

                        gets(user.tme);

                        break;

                    case 2:
                        printf("\nENTER NEW DATA:");

                        printf("\nNEW PERSON:");

                        gets(user.nam);

                        break;

                    case 3:
                        printf("\nENTER NEW DATA:");

                        printf("\nNEW PLACE:");

                        gets(user.plce);

                        break;

                    case 4:
                        printf("\nENTER NEW DATA:");

                        printf("\nDURATION:");

                        gets(user.duration);

                        break;

                    case 5:
                        printf("ENTER NEW DATA:");

                        printf("\nNOTE:");

                        gets(user.note);

                        break;

                    case 6:
                        printf("\nENTER NEW DATA:");

                        printf("\nNEW TIME:[hh:mm]:");

                        gets(user.tme);

                        printf("\nNEW PERSON:");

                        gets(user.nam);

                        printf("\nNEW PLACE:");

                        gets(user.plce);

                        printf("\nDURATION:");

                        gets(user.duration);

                        printf("\nNOTE:");

                        gets(user.note);

                        break;

                    case 7:
                        printf("\nPRESS KEY AND GO BACK...\n");

                        getch();

                        return;

                        break;

                    default:
                        printf("\nWRONG INPUT...TRY AGAIN\n");

                        break;
                    }

                }
                while (num < 1 || num > 8);

                fseek(fpt_e, sizeof(user), SEEK_CUR); // SEEK_CUR file pointer re jei location deya thake oikhane pathay dey

                fwrite(&user, sizeof(user), 1, fpt_e);

                fseek(fpt_e, sizeof(user), SEEK_CUR);

                fread(&user, sizeof(user), 1, fpt_e);

                choice = 5;

                break;
            }
        }

        if (choice == 5)

        {

            system("cls");

            printf("\n\t\tEDIT DONE...\n");

            printf("--------------------\n");

            printf("NEW RECORD:\n");

            printf("--------------------\n");

            printf("\nTIME: %s", user.tme);

            printf("\nMEETING WITH: %s", user.nam);

            printf("\nMEETING AT: %s", user.plce);

            printf("\nDURATION: %s", user.duration);

            printf("\nNOTE: %s", user.note);

            fclose(fpt_e);

            printf("\n\n\tEDIT OTHER RECORD?(Y/N)");

            scanf("%c", &choice);

            count++;
        }

        else

        {

            printf("\nNO RECORD FOUND::\n");

            printf("\nTRY AGAIN??...(Y/N)");

            scanf("%c", &choice);
        }

    }
    while (choice == 'Y' || choice == 'y');

    fclose(fpt_e);

    if (count == 1)

        printf("\n%d DONE EDITING...\n", count);

    else if (count > 1)

        printf("\n%d DONE EDITING..\n", count);

    else

        printf("\nNO EDIT...\n");

    printf("\tPRESS ENTER AND EXIT.");

    getch();
}

int pass_word()

{

    char passw[25] = {0}, check[25] = {0}, ch;

    FILE *fppt;

    int i = 0, j;

    printf("::FOR SECURITY:FOUR TRIALS AVAILABLE::");

    for (j = 0; j < 4; j++)

    {

        i = 0;

        printf("\n\n\tENTER PASSWORD:");

        passw[0] = getch();

        while (passw[i] != '\r')

        {

            if (passw[i] == '\b')

            {

                i--;

                printf("\b");

                printf(" ");

                printf("\b");

                passw[i] = getch();
            }

            else

            {

                printf("*");

                i++;

                passw[i] = getch();
            }
        }

        passw[i] = '\0';

        fppt = fopen("SE", "r");

        if (fppt == NULL)

        {

            printf("\nERROR...\n");

            getch();

            return 1;
        }

        else

            i = 0;

        while (1)

        {

            ch = fgetc(fppt);

            if (ch == EOF)

            {

                check[i] = '\0';

                break;
            }

            check[i] = ch - 5;

            i++;
        }

        if (strcmp(passw, check) == 0)

        {

            printf("\n\n\tACCESS DONE...\n");

            return 0;
        }

        else

        {

            printf("\n\n\tENTERED WRONG PASSWORD..\n\n\tACCESS CANCELED...\n");
        }
    }

    printf("\n\n\t::ENTERED WRONG PASSWORD::NO ACCESS::\n\n\tPRESS A KEY FOR GOING BACK...");

    getch();

    return 1;
}

void edit_pass()

{

    system("cls");

    printf("\n");

    char passw[25] = {0}, cnfrm[25] = {0}, ch;

    int choice, i, check;

    FILE *filePointer;

    filePointer = fopen("SE", "rb");

    if (filePointer == NULL)

    {

        filePointer = fopen("SE", "wb");

        if (filePointer == NULL)

        {

            printf("SYSTEM ERROR...");

            getch();

            return;
        }

        fclose(filePointer);

        printf("\nRESTORED...\nPASSWORD IS 'ENTER'\n PRESS ENTER AND CHANGE PASSWORD\n\n");

        getch();
    }

    fclose(filePointer);

    check = pass_word();

    if (check == 1)

    {

        return;
    }

    do

    {

        if (check == 0)

        {

            i = 0;

            choice = 0;

            printf("\n\n\tENTER A NEW PASSWORD:");

            fflush(stdin);

            passw[0] = getch();

            while (passw[i] != '\r') // CR (Carriage Return)

            {

                if (passw[i] == '\b') // backspace

                {

                    i--;

                    printf("\b");

                    printf(" ");

                    printf("\b");

                    passw[i] = getch();
                }

                else

                {

                    printf("*");

                    i++;

                    passw[i] = getch();
                }
            }

            passw[i] = '\0';

            i = 0;

            printf("\n\tPASSWORD CONFIRM?:");

            cnfrm[0] = getch();

            while (cnfrm[i] != '\r')

            {

                if (cnfrm[i] == '\b')

                {

                    i--;

                    printf("\b");

                    printf(" ");

                    printf("\b");

                    cnfrm[i] = getch();
                }

                else

                {

                    printf("*");

                    i++;

                    cnfrm[i] = getch();
                }
            }

            cnfrm[i] = '\0';

            if (strcmp(passw, cnfrm) == 0)

            {

                filePointer = fopen("SE", "wb");

                if (filePointer == NULL)

                {

                    printf("\n\t\tSYSTEM ERROR");

                    getch();

                    return;
                }

                i = 0;

                while (passw[i] != '\0')

                {

                    ch = passw[i];

                    putc(ch + 5, filePointer);

                    i++;
                }

                putc(EOF, filePointer);

                fclose(filePointer);
            }

            else

            {

                printf("\n\tNEW PASSWORD DID NOT MATCH.");

                choice = 1;
            }
        }

    }
    while (choice == 1);

    printf("\n\n\tPASSWORD HAS BEEN CHANGED...\n\n\tPRESS ANY KEY AND GO BACK....");

    getch();
}

void del_rec()

{

    system("cls");

    FILE *filePointer, *fptr;

    struct rec file;

    char fnam[20], anyother = 'Y', tme[11];
    ;

    int choice, check;

    printf("\t\t* MENU : DELETE *");

    printf("\n\t\t*****************\n\n");

    check = pass_word();

    if (check == 1)

    {

        return;
    }

    while (anyother == 'Y')

    {

        printf("\n\n\tWANT TO DELETE.");

        printf("\n\n\t#DELETE ALL RECORD\t\t\t[1]");

        printf("\n\t#DELETE A SPECIFIC RECORD BY TIME\t[2]");

        do

        {

            printf("\n\t\tENTER A CHOICE:");

            scanf("%d", &choice);

            switch (choice)

            {

            case 1:

                printf("\n\tENTER A DATE FOR DELETE:[dd-mm-yyyy]:");

                fflush(stdin);

                gets(fnam);

                filePointer = fopen(fnam, "wb");

                if (filePointer == NULL)

                {

                    printf("\nNO FILE FOUND");

                    printf("\nPRESS A KEY AND TO GO BACK.");

                    getch();

                    return;
                }

                fclose(filePointer);

                remove(fnam);

                printf("\nDELETED SUCCESSFULLY...");

                break;

            case 2:

                printf("\n\tENTER A DATE OF RECORD:[dd-mm-yyyy]:");

                fflush(stdin);

                gets(fnam);

                filePointer = fopen(fnam, "rb");

                if (filePointer == NULL)

                {

                    printf("\nFILE NOT FOUND");

                    printf("\nPRESS A KEY AND GO BACK.");

                    getch();

                    return;
                }

                fptr = fopen("temp", "wb");

                if (fptr == NULL)

                {

                    printf("\nSYSTEM ERROR");

                    printf("\nPRESS ANY KEY TO GO BACK");

                    getch();

                    return;
                }

                printf("\n\tENTER TIME FOR DELETING:[hh:mm]:");

                fflush(stdin);

                gets(tme);

                while (fread(&file, sizeof(file), 1, filePointer) == 1)

                {

                    if (strcmp(file.tme, tme) != 0)

                        fwrite(&file, sizeof(file), 1, fptr);
                }

                fclose(filePointer);

                fclose(fptr);

                remove(fnam);

                rename("temp", fnam);

                printf("\nDELETED SUCCESSFULLY...");

                break;

            default:

                printf("\n\tWRONG CHOICE");

                break;
            }

        }
        while (choice < 1 || choice > 2);

        printf("\n\tWANT TO DELETE MORE?(Y/N):");

        fflush(stdin);

        scanf("%c", &anyother);
    }

    printf("\n\n\tPRESS A KEY AND EXIT...");

    getch();
}
