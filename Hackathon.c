#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct signupinfo
    {
    char fname[20];
    char lname[20];
    int mob[11];
    char pass[50];
    char cpass[50];
    };

void display();
void working();
void signin();
void signup();
void select();
void pay();
void checkbal();
void mobilerecharge();
void dthrecharge();
void addrecipent();
void settings();

int main()
{
    system("cls");                      //To clear the screen first time
    int n;
    printf("1.Sign In\n");
    printf("2.Sign Up\n");
    scanf("%d",&n);
    system("cls");                      //To clear the screen before loading the signin/signup pages
    switch (n)
    {
        case 1:
        signin();
        break;

        case 2:
        signup();
        break;

        default:                      //If a wrong option is choosen then it will be redirected to the same page
        main();
    }
    return 0;
}

void signin()
{
    int key;
    int count=0;
    do{                               //do while loop because it can create a similar effect as a swipeable menu
        system("cls");
        display(count);
        printf("\n\nEnter 77 to go to next page\nEnter 75 to go to previous page\nEnter 10 to select current page\nEnter 8 to go to Main Menu\n\n");
        fflush(stdin);
        scanf("%d",&key);
        if(key==77)   //right arrow key=77
        {
            if(count==5)    
            {
                count=-1;             //if user presses right arrow key on last page then he/she will be redirected to the first page
            }
            count++;
        }
        if(key==75)   //left arrow key=75
        {
            if(count==0)
            {
                count=6;               //if user presses left arrow key on first page then he/she will be redirected to the last page
            }
            count--;
        }
        if(key==8)  //Backspace key    for going back to main menu
        main();
    }while(key!=10);   //enter key=10   for selecting option
    select(count);
}

void display(int count)
{
    if(count==0)
    printf("Pay/Send Page\n");

        else if(count==1)
    printf("Check Account Balance Page\n");

        else if(count==2)
    printf("Mobile Recharge Page\n");

        else if(count==3)
    printf("DTH Recharge Page\n");

        else if(count==4)
    printf("Add Recipent Page\n");

        else if(count==5)
    printf("Settings Page\n");
}

void signup()
{
    //system("cls");
    //char fname[20];
    //char lname[20];
    //int mob[11];
    //char pass[50];
    //char cpass[50];
    int checkpoint,i=0;
    struct signupinfo customer[100];
    printf("Enter Your First Name    : ");
    scanf("%s",&customer[i].fname);
    printf("Enter Your Last Name     : ");
    scanf("%s",&customer[i].lname);
    printf("Enter Your Mobile Number : ");
    fflush(stdin);
    scanf("%s",&customer[i].mob);
    printf("Set Password             : ");
    fflush(stdin);
    scanf("%s",&customer[i].pass);
    printf("Confirm Password         : ");
    fflush(stdin);
    scanf("%s",&customer[i].cpass);
    checkpoint=strcmp(customer[i].cpass,customer[i].pass);          //comparison of password
    if(checkpoint==0)                       //condition of strcmp function i.e. if it return 0 then the strings(password) are same
    signin();
    else
    {
        printf("!!Password Doesn't Match!!\n");
        printf("Please signup again\n\n");
        signup();
    }
}

void select(int count)
{
        if(count==0)
        pay();
    
        else if(count==1)
        checkbal();

        else if(count==2)
        mobilerecharge();

        else if(count==3)
        dthrecharge();

        else if(count==4)
        addrecipent();

        else if(count==5)
        settings();    
}

void pay()
{
    system("cls");
    printf("You are in pay page\n");
    
}

void checkbal()
{
    system("cls");
    printf("You are in check balance page\n");
}

void mobilerecharge()
{
    system("cls");
    printf("You are in mobile recharge page\n");
}

void dthrecharge()
{
    system("cls");
    printf("You are in dth recharge page\n");
}

void addrecipent()
{
    system("cls");
    printf("You are in add recipent page\n");
}

void settings()
{
    system("cls");
    printf("You are in settings page\n");
}
