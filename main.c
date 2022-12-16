/* Customer Billing System Project is a simple console application designed to demonstrate the
practical use of C programming language and its features as well as to generate an application
that can be used in any departmental store, shop, café, etc. for billing to the customer.
You can use this application to keep the records such as name, address, mobile number, paid
amount, due amount, payment date, etc. of your regular customer. Moreover, if you have a
new customer, you can add and edit the account at any time.
The source code of the Customer Billing System Project in C has been written in C programming
language without the use of any graphics. The code is complete, totally error-free, and not that
long – just. It is to be compiled in Code::Blocks using the GCC compiler.
====================================================================
Author: Omar A. ElShafey  & Nermeen Salama
Virsion: 1.0.0
Date: 12-16-2022
Time: 8:35pm
====================================================================
we have 2 C files  : main.c , PROG.c

*/

//Libiraries
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include "PROG.h"


int counter ;
customer_t arr[5] ;


int main()
{
/****************************************************************************/
// customer_var.
   char choice_Cus ;
   int id_check ;
   int id_from ;
   int id_to ;
   double money_transfer ;

 /*************************************************************************/
//Prog & Orders & Items
   int choice,n;
   struct orders ord ;
   struct orders order;
   char saveBill = 'y' , contFlag = 'y' ;
   char name[50];
   FILE *fp;



    while( contFlag == 'y' )
        {
        loop1:
        system("cls");
        float total = 0;
        int invoiceFound = 0;

        printf("\t\t\t*==*==*==*==* ON FIRE Online Store *==*==*==*==*");
        printf("\n\n\n");
        printf("\t------------------------------------\n");
        printf("\tPlease select your prefered operation:\n");
        printf("\t-------------------------------------\n");
        printf("\t01. Generate Bill.\n");
        printf("\t02. Show all Bills.\n");
        printf("\t03. Search Bill.\n");
        printf("\t04. Customer accounts.\n");
        printf("\t05. Exit.\n");
        printf("\t========================================\n");
        printf("\tYour choice: ");

        scanf("%d",&choice);

        fgetc(stdin);   

        switch(choice){
        case 1:
        system("cls");

        printf("\t\t\t*==*==*==*==* ON FIRE Online Store *==*==*==*==*");
        printf("\n\n\n");

        printf("\nPlease enter the \"ID\" of the customer:\t");
        scanf("%i",&id_check);

        strcpy(ord.date,__DATE__);
        printf("\nPlease enter the number of items:\t");
        
        scanf("%d",&n);
        ord.numOfItems = n;

        for(int i=0;i<n;i++){
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d:\t",i+1);
            fgets(ord.itm[i].item,20,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            printf("Please enter the quantity:\t");
            scanf("%d",&ord.itm[i].quantity);
            printf("Please enter the unit price:\t");
            scanf("%f",&ord.itm[i].price);
            total += ord.itm[i].quantity * ord.itm[i].price;
        }


        BillHeader(id_check, ord.date);

        for(int i=0;i<ord.numOfItems;i++){
            BillBody(ord.itm[i].item,ord.itm[i].quantity,ord.itm[i].price);
        }
       BillFooter(total);

        printf("\nDo you want to save the invoice [y/n]:\t");
        scanf("%s",&saveBill);

        if(saveBill == 'y'){
            fp = fopen("Bill.dat","a+");
            fwrite(&ord,sizeof(struct orders),1,fp);
            if(fwrite != 0)
            printf("\nSuccessfully saved");
            else
            printf("\nError saving");
            fclose(fp);
        }
        break;

        case 2:
        system("clear");
        fp = fopen("Bill.dat","r");
        printf("\n  *****Your Previous Invoices*****\n");
        while(fread(&order,sizeof(struct orders),1,fp)){
            float tot = 0;
            BillHeader(id_to, ord.date);
            for(int i=0;i<order.numOfItems;i++){
                BillBody(order.itm[i].item,order.itm[i].quantity,order.itm[i].price);
                tot+=order.itm[i].quantity * order.itm[i].price;
            }
            BillFooter(tot);
        }
        fclose(fp);
        break;

        case 3:
        printf("Enter the name of the customer:\t");
        fgetc(stdin);
        fgets(name,50,stdin);
        name[strlen(name)-1] = 0;
        system("clear");
        fp = fopen("Bill.dat","r");
        printf("\t*****Invoice of %s*****",name);
        while(fread(&order,sizeof(struct orders),1,fp)){
            float tot = 0;
            if(!strcmp(order.customer,name)){
            BillHeader(id_to, ord.date);
            for(int i=0;i<order.numOfItems;i++){
                BillBody(order.itm[i].item,order.itm[i].quantity,order.itm[i].price);
                tot+=order.itm[i].quantity * order.itm[i].price;
            }
            BillFooter(tot);
            invoiceFound = 1;
            }

        }
        if(!invoiceFound){
            printf("Sorry the invoice for %s doesnot exists",name);
        }
        fclose(fp);
        break;


    case 4:
        system("cls");
        s32 i;
        s8 ch,password[10],q[10]="IEEE-KFB";
        printf("\tEnter Password:\t");
        for(i=0;i<8;i++)
        {
            ch = getch();
            password[i] = ch;
            ch = '*' ;
            printf("%c",ch);
        }
        password[i]='\0';    // To set the Null

        if(strcmp(password,q)) // Check the password
        {
            printf("\n\t");
            printf("Wrong Password Please Try Again");
            printf("\n\n");
            goto loop1;
        }
        else
        goto continue_;

        continue_:
        while(1)
            {
				system("cls");
                printf("\t\t\t*==*==*==*==* ON FIRE Online Store *==*==*==*==*");
                printf("\n\n");
                printf("\t---------------------------------------------\n");
                printf("\tplease select one of the following options :\n");
                printf("\t---------------------------------------------\n");
                printf("\
                       01. create a new customer. (press 1 to select this option)\n\
                       02. edit customer. (press 2 to select this option )\n\
                       03. delete customer. (press 3 to select this option)\n\
                       04. print customer data. (press 4 to select this option)\n\
                       05. Home Page. (press 5 to select this option)\n\
                       06. exit (press 6 to select this option)\n\
                   ___________________________________________________________________________\n\
                       \n\
                       =>  please enter your choice:");  //we need an option to Go to home page (Don't Forget)

                fflush(stdin);
                scanf("%c",&choice_Cus);
                printf("\n\n");
                switch(choice_Cus)
                {
                case '1' :
                    if(counter>=5)
                    {
                        printf("the maximum number of customers is 5 so you can't add anymore\n");
                        break ;
                    }
                    create_new_customer();
                    break ;

                case '2' :
                    printf("please enter the id of the customer who you need to change its data :");
                    scanf("%i",&id_check);
                    edit_customer(id_check) ;
                    break ;

                case '3' :
                    printf("please enter the id of the customer who you need to delete its data :");
                    scanf("%i",&id_check);
                    delete_customer_data(id_check);
                    break;

                case '4' :
                    printf("please enter the id of the customer who you need to print its data :");
                    scanf("%i",&id_check);
                    print_customer_data(id_check) ;
                    break;

                case '5':
                    goto loop1;
                break;

                case '6' :
                exit(0);
                default:
                printf("wrong choice\n\n");
                }

            }

    case 5:

    printf("\n\t\t Use Our Service Again :) \n\n");
    exit(0);
    break;

    default:
    printf("Sorry invalid option");
    break;
    }
    printf("\nDo you want to perform another operation?[y/n]:\t");
    scanf("%s",&contFlag);
    }
    printf("\n\t\t Bye Bye :)\n\n");
    printf("\n\n");

/*************************************************************************/


    return 0 ;
    }
