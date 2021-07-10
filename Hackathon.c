#include<stdio.h>
#include<string.h>
void display();
void working();
void signin();
void signup();
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

        default:                      //If a wrong option is chooosen then it will be redirected to the same page
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
    char fname[20];
    char lname[20];
    int mob[11];
    char pass[50];
    char cpass[50];
    int checkpoint;
    printf("Enter Your First Name    : ");
    scanf("%s",&fname);
    printf("Enter Your Last Name     : ");
    scanf("%s",&lname);
    printf("Enter Your Mobile Number : ");
    fflush(stdin);
    scanf("%s",&mob);
    printf("Set Password             : ");
    fflush(stdin);
    scanf("%s",&pass);
    printf("Confirm Password         : ");
    fflush(stdin);
    scanf("%s",&cpass);
    checkpoint=strcmp(cpass,pass);          //comparison of password
    if(checkpoint==0)                       //condition of strcmp function i.e. if it return 0 then the strings(password) are same
    signin();
    else
    {
        printf("!!Password Doesn't Match!!\n");
        printf("Please signup again\n\n");
        signup();
    }
}   //10 july
