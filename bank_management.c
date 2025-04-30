#include<stdio.h>
#include<stdlib.h>
#include<conio.h> //getch() function
#include<string.h>

int choice;
float tAmt;
int dontCreate = 0, updating = 0, found1=0, found2=0, enough = 1, found =0;

struct date{
    int day, month, year;
};

struct{
    int acc_no;
    char name[50];
    struct date dob;
    char city[50];
    char phone[10];
    float amt;
    char password[50];
}add, check, update, withdraw, deposit;

void close();
void mainMenu();
void createAcc();
void close();
void edit();
void transaction();
void info();
void viewAll();
void removeAcc();

int main(){
    mainMenu();
}

void mainMenu(){
    printf("Bank Management System\n\n");
    printf("[1] Create a new account\n[2] Update information of existing account\n[3] Make a Transaction\n[4] Account info\n[5] View customer's list\n[6] Remove account\n[7] Exit\n\n\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch(choice){
        case 1: 
        createAcc();
        break;

        case 2:
        edit();
        break;

        case 3:
        transaction();
        break;

        case 4:
        info();
        break;

        case 5:
        viewAll();
        break;

        case 6:
        removeAcc();
        break;

        case 7: 
        close(); 
        break;

        default: 
        printf("No such task!! Press any key to enter main menu....");
        getch(); 
        mainMenu();
    }
}

void createAcc(){
    FILE *rec;
    rec = fopen("record.txt", "a+");
    system("cls");
    printf("Enter account number : ");
    scanf("%d", &check.acc_no);
    while(fscanf(rec, "%d %s %d/%d/%d %s %s %f %s\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, add.city, add.phone, &add.amt, add.password) != EOF){
        if(check.acc_no == add.acc_no){
            printf("This account already exists!!");
            fclose(rec);
            dontCreate = 1;
        }
    }
    if(dontCreate == 1){
        printf("\nPress any key to go to main menu.......");
        getch();
        mainMenu();
        dontCreate = 0;
    }else{
        add.acc_no = check.acc_no;
        printf("\nEnter your name : ");
        scanf("%s", add.name);
        printf("\nEnter your date of birth(dd/mm/yyyy) : ");
        scanf("%d/%d/%d", &add.dob.day, &add.dob.month, &add.dob.year);
        printf("\nEnter your city : ");
        scanf("%s", add.city);
        printf("\nEnter your phone number : ");
        scanf("%s", add.phone);
        printf("\nEnter the amount you want to deposit : ");
        scanf("%f", &add.amt);
        system("cls");
        printf("Create your password : ");
        scanf("%s", add.password);
    
        fprintf(rec, "%d %s %d/%d/%d %s %s %f %s\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.city, add.phone, add.amt, add.password);

        fclose(rec);

        printf("Account successfully created!!......");
        getch();
        system("cls");
        mainMenu();
    }
}

void close(){
    system("cls");
    printf("Thanks you for using this tool......");
    getch();
}

void edit(){
    system("cls");
    printf("Please enter your account number : ");
    scanf("%d", &update.acc_no);
    FILE *old, *new;
    old = fopen("record.txt", "r");
    new = fopen("temp.txt", "w");

    while(fscanf(old, "%d %s %d/%d/%d %s %s %f %s\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, add.city, add.phone, &add.amt, add.password) != EOF){
        if(add.acc_no==update.acc_no){
            updating = 1;
            printf("What do you want to update?\n1. Name\n2. Date of birth\n3. City\n4. Phone number\n5. Password\n\nEnter your choice : ");
            scanf("%d", &choice);
            system("cls");
            switch(choice){
                case 1:
                printf("Enter your current password : ");
                scanf("%s", check.password);
                if(strcmp(check.password, add.password)==0){
                    system("cls");
                    printf("Enter new name : ");
                    scanf("%s", update.name);
                    fprintf(new, "%d %s %d/%d/%d %s %s %f %s\n", add.acc_no, update.name, add.dob.day, add.dob.month, add.dob.year, add.city, add.phone, add.amt, add.password);
                }
                break;

                case 2:
                printf("Enter your current password : ");
                scanf("%s", check.password);
                if(strcmp(check.password, add.password)==0){
                    system("cls");
                    printf("Enter new date of birth(dd/mm/yyyy) : ");
                    scanf("%d/%d/%d", &update.dob.day, &update.dob.month, &update.dob.year);
                    fprintf(new, "%d %s %d/%d/%d %s %s %f %s\n", add.acc_no, add.name, update.dob.day, update.dob.month, update.dob.year, add.city, add.phone, add.amt, add.password);
                }
                break;

                case 3:
                printf("Enter your current password : ");
                scanf("%s", check.password);
                if(strcmp(check.password, add.password)==0){
                    system("cls");
                    printf("Enter new city name : ");
                    scanf("%s", update.city);
                    fprintf(new, "%d %s %d/%d/%d %s %s %f %s\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, update.city, add.phone, add.amt, add.password);
                }
                break;

                case 4:
                printf("Enter your current password : ");
                scanf("%s", check.password);
                if(strcmp(check.password, add.password)==0){
                    system("cls");
                    printf("Enter new phone number : ");
                    scanf("%s", update.phone);
                    fprintf(new, "%d %s %d/%d/%d %s %s %f %s\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.city, update.phone, add.amt, add.password);
                }
                break;

                case 5:
                printf("Enter your current password : ");
                scanf("%s", check.password);
                if(strcmp(check.password, add.password)==0){
                    system("cls");
                    printf("Enter new password : ");
                    scanf("%s", update.password);
                    fprintf(new, "%d %s %d/%d/%d %s %s %f %s\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.city, add.phone, add.amt, update.password);
                }
                break;

                default:
                printf("No such choice!!");
                updating = 0;
            }
        }
        else{
            fprintf(new, "%d %s %d/%d/%d %s %s %f %s\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.city, add.phone, add.amt, add.password);
        }
    }
    if(updating != 1){
        printf("\nNo such record...");
    }
    if(updating == 1){
        printf("\nYour contact is successfully updated!!");
        updating = 0;
    }
    printf("\nPress any key to go to main menu.....");
    getch();
    system("cls");

    fclose(old);
    fclose(new);
    remove("record.txt");
    rename("temp.txt", "record.txt");
    mainMenu();
}

void transaction(){
    system("cls");
    FILE *rec, *new;
    rec = fopen("record.txt", "r");
    new = fopen("temp.txt", "w");
    printf("Enter your account number : ");
    scanf("%d", &withdraw.acc_no);
    while(fscanf(rec, "%d %s %d/%d/%d %s %s %f %s\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, add.city, add.phone, &add.amt, add.password) != EOF){
        if(withdraw.acc_no == add.acc_no){
            found1=1;
            withdraw.acc_no = add.acc_no; strcpy(withdraw.name, add.name); withdraw.dob.day = add.dob.day; withdraw.dob.month = add.dob.month; withdraw.dob.year = add.dob.year; strcpy(withdraw.city, add.city); strcpy(withdraw.phone, add.phone); withdraw.amt = add.amt; strcpy(withdraw.password, add.password);
            system("cls");
            printf("Enter your password : ");
            scanf("%s", check.password);
            system("cls");
            if(strcmp(withdraw.password, check.password)==0){
                printf("\nEnter the amount you want to send : ");
                scanf("%f", &tAmt);
                if(tAmt > withdraw.amt){
                    system("cls");
                    printf("Not enough money in your account......");
                    enough = 0;
                }
            }else{
                printf("Wrong Password......");
            }
        }
    }
    if(enough!=0){
        printf("\nEnter the account number of the customer you want to send money to : ");
        scanf("%d", &deposit.acc_no);
        printf("\n\n%d %s %d/%d/%d %s %s %f %s\n\n", deposit.acc_no, deposit.name, deposit.dob.day, deposit.dob.month, deposit.dob.year, deposit.city, deposit.phone, deposit.amt, deposit.password);
        while(fscanf(rec, "%d %s %d/%d/%d %s %s %f %s\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, add.city, add.phone, &add.amt, add.password) != EOF){
            if(add.acc_no==deposit.acc_no){
                found2=1;
                deposit.acc_no = add.acc_no; strcpy(deposit.name, add.name); deposit.dob.day = add.dob.day; deposit.dob.month = add.dob.month; deposit.dob.year = add.dob.year; strcpy(deposit.city, add.city); strcpy(deposit.phone, add.phone); deposit.amt = add.amt; strcpy(deposit.password, add.password);
                printf("\n\n%d %s %d/%d/%d %s %s %f %s\n\n", deposit.acc_no, deposit.name, deposit.dob.day, deposit.dob.month, deposit.dob.year, deposit.city, deposit.phone, deposit.amt, deposit.password);
            }
        }
    }
       
    if(found1 == 0){
        printf("No such record......");
        found2=0;
        if(found2 == 0){
            printf("No such record......");
            found1=0;
        }
    }else if(enough == 1){
        withdraw.amt = withdraw.amt - tAmt;
        deposit.amt = deposit.amt + tAmt;
        enough=0;
        printf("Your payment was successful!....");
    }
    
    printf("%d %s %d/%d/%d %s %s %f %s\n", withdraw.acc_no, withdraw.name, withdraw.dob.day, withdraw.dob.month, withdraw.dob.year, withdraw.city, withdraw.phone, withdraw.amt, withdraw.password);
    printf("%d %s %d/%d/%d %s %s %f %s\n", deposit.acc_no, deposit.name, deposit.dob.day, deposit.dob.month, deposit.dob.year, deposit.city, deposit.phone, deposit.amt, deposit.password);

    while(fscanf(rec, "%d %s %d/%d/%d %s %s %f %s\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, add.city, add.phone, &add.amt, add.password) != EOF){
        if(add.acc_no == withdraw.acc_no){
            fprintf(new, "%d %s %d/%d/%d %s %s %f %s\n", withdraw.acc_no, withdraw.name, withdraw.dob.day, withdraw.dob.month, withdraw.dob.year, withdraw.city, withdraw.phone, withdraw.amt, withdraw.password);
        }else if(add.acc_no == deposit.acc_no){
            fprintf(new, "%d %s %d/%d/%d %s %s %f %s\n", deposit.acc_no, deposit.name, deposit.dob.day, deposit.dob.month, deposit.dob.year, deposit.city, deposit.phone, deposit.amt, deposit.password);
        }else{
            fprintf(new, "%d %s %d/%d/%d %s %s %f %s\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.city, add.phone, add.amt, add.password);
        }
    }

    fclose(rec);
    fclose(new);
    remove("record.txt");
    rename("temp.txt", "record.txt");
    getch();
    system("cls");
    mainMenu();
}

void info(){
    FILE *rec;
    rec = fopen("record.txt", "r");
    system("cls");
    printf("Enter your account number : ");
    scanf("%d", &check.acc_no);
    system("cls");
    while(fscanf(rec, "%d %s %d/%d/%d %s %s %f %s\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, add.city, add.phone, &add.amt, add.password) != EOF){
        if(check.acc_no == add.acc_no){
            found = 1;
            printf("Account number : %d\n", add.acc_no);
            printf("Name : %s\n", add.name);
            printf("Date of birth : %d/%d/%d\n", add.dob.day, add.dob.month, add.dob.year);
            printf("City : %s\n", add.city);
            printf("Phone : %s\n", add.phone);
            printf("Balance : %f\n", add.amt);
        }
    }
    if(found == 0){
        printf("\nNo such record.........\n");
    }
    fclose(rec);
    printf("\nPress any key to go to main menu........");
    found = 0;    
    getch();
    system("cls");
    mainMenu();
}

void viewAll(){
    FILE *rec;
    rec = fopen("record.txt", "r");
    system("cls");
    while(fscanf(rec, "%d %s %d/%d/%d %s %s %f %s\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, add.city, add.phone, &add.amt, add.password) != EOF){
        printf("%d %s %d/%d/%d %s %s %f %s\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.city, add.phone, add.amt, add.password);
    }
    fclose(rec);
    printf("\nPress any key to go to main menu......");
    getch();
    mainMenu();
}

void removeAcc(){
    FILE *rec, *new;
    rec = fopen("record.txt", "r");
    new = fopen("temp.txt", "w");
    system("cls");
    printf("Enter account number : ");
    scanf("%d", &check.acc_no);
    while(fscanf(rec, "%d %s %d/%d/%d %s %s %f %s\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, add.city, add.phone, &add.amt, add.password) != EOF){
        if(check.acc_no == add.acc_no){
            found = 1;
        }
        if(check.acc_no != add.acc_no){
            fprintf(new, "%d %s %d/%d/%d %s %s %f %s\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.city, add.phone, add.amt, add.password);
        }
    }
    system("cls");
    if(found == 0){
        printf("No such record......");
    }else{
        printf("Account removed......");
    }
    printf("\nPress any key to go to main menu.....");
    found = 0;
    fclose(rec);
    fclose(new);
    remove("record.txt");
    rename("temp.txt", "record.txt");
    getch();
    mainMenu();
}
