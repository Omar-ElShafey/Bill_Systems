
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PROG.h"

extern int counter ;
extern customer_t arr[5] ;

void create_new_customer(void)
{
    customer_t new_customer ;
    printf("please enter the name of the customer number %i:",counter+1);
    fflush(stdin);
    gets(new_customer.name);

    printf("please enter the id of the customer number %i:",counter+1);
    scanf("%i",&(new_customer.id));

    printf("please enter the street of the customer number %i:",counter+1);
    fflush(stdin);
    gets(new_customer.street);

    printf("please enter the City of the customer number %i:",counter+1);
    fflush(stdin);
    gets(new_customer.city);

    printf("please enter the Phone of the customer number %i:",counter+1);
    fflush(stdin);
    gets(new_customer.phone);


    printf("\n\n");
    arr[counter]=new_customer ;
    counter++ ;

}

void  edit_customer(int id )
{
    int i ;
    for(i=0;i<=counter;i++)
    {
      if(id==arr[i].id)
      {
    printf("please enter the new name :");
    fflush(stdin);
    gets(arr[i].name);


    printf("please enter the new id :");
    scanf("%i",&(arr[i].id));

    printf("please enter the new street :");
    fflush(stdin);
    gets(arr[i].street);

    printf("please enter the new city :");
    fflush(stdin);
    gets(arr[i].city );

    printf("please enter the new phone :");
    fflush(stdin);
    gets(arr[i].phone);


    printf("\n\n");
    break ;
      }
    }

}

  void  print_customer_data(int id)
    {

        for(int i=0; i<=counter ;i++)    //search times = no. of customers
        {

        if (id==arr[i].id)
        {

                printf("the name  : %s\n",arr[i].name);
              //printf("the type of the customer is : %s\n",arr[i].type);
                printf(" the ID is : %i\n",arr[i].id);
                printf(" St. : %s\n",arr[i].street);
                printf(" City: %s\n",arr[i].city);
                printf("Phone: %s\n",arr[i].phone);
                printf("\n\n");
            break ;
         }
         }
    }

void delete_customer_data(int id )
{
    int i ;
    int index ;
    for(i=0;i<=counter-1;i++)
        {
        if(arr[i].id==id)
        {
            index=i ;
    for(i=index;i<=counter-1;i++)
        {
        arr[i]=arr[i+1];

        }
        }
        }
        arr[counter].cash=-1; // -1 indicate this is empty place for new customer
        arr[counter].id=-1 ;  // -1 indicate this is empty place for new customer
        strcpy(arr[counter].name,"-1"); // -1 indicate this is empty place for new customer
        strcpy(arr[counter].type,"-1"); // -1 indicate this is empty place for new customer
        counter--;
}

//functions of biils  1          16-12
    void BillHeader(int id_chk , char date[30])
    {
        system("cls");

        printf("\t\t\t*==*==*==*==* ON FIRE Online Store *==*==*==*==*");
        printf("\n\n");
        printf("\n\t   -----------------");
        printf("\n Date:%s\n ",date);
        /**************************/
        print_customer_data(id_chk);  // another function
        /****************************/
        printf("Items\t\t");
        printf("Quantity\t\t");
        printf("Total\t\t");
        printf("\n---------------------------------------");
        printf("\n\n");

}
void BillBody(char item[30],int quantity, float price){
    printf("%s\t\t",item);
        printf("%d\t\t",quantity);
        printf("%.2f\t\t",quantity * price);
        printf("\n");
}



void BillFooter(float total)
{
    printf("\n");
    float dis = 0.05*total;
    float netTotal=total-dis;
    float cgst=0.14*netTotal,grandTotal=netTotal + cgst;//netTotal + cgst
    printf("---------------------------------------\n");
    printf("Sub Total\t\t\t%.2f",total);
    printf("\nDiscount 5%s\t\t\t%.2f","%",dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f",netTotal);
    printf("\nCGST 14%s\t\t\t%.2f","%",cgst);
    printf("\n---------------------------------------");
    printf("\nGrand Total\t\t\t%.2f",grandTotal);
    printf("\n---------------------------------------\n");
}


