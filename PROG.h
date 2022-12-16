#ifndef bank_H
#define bank_H

typedef struct customer
{
    char name[50];
    double cash ;      // problems
    char type[7] ;    //regular or Irregular
    int id ;
    char street[70];
	char city[20];
	char phone[13];   //+20**********
//    float payment;
}customer_t;



typedef struct items{
    char item[20];
    float price;
    int quantity;
};


typedef struct orders{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

typedef struct item
{
	int product_no;
	char product_name[10];
	int quantity;
	int price;
}item;


void BillFooter(float total);
void BillBody(char item[30],int quantity, float price);
void BillHeader(int id_chk , char date[30]);
void delete_customer_data(int id );
void  print_customer_data(int id);
void  edit_customer(int id );
void create_new_customer(void);



void create(void);
void create_new_customer(void);
void edit_customer(int id ) ;
void print_customer_data(int id) ;
void Quantity(void);
void delete_customer_data(int id );

/*******************************************/
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long  u64;
/*******************************************/
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;
typedef signed long    s64;
/*******************************************/
typedef float          f32;
typedef double         f64;
typedef long double    f128;
/*******************************************/


#endif

