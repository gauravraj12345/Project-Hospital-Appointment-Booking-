#ifndef STRUCTURE_H
#define STRUCTURE_H

struct data_emp                          
{
    char name[30];
    int id;
    char pass[20];
};

struct data_doc                          
{
    char name[30];
    int id;
    int pre;
    char pass[20];
    char spec[20];
   
};

struct data_pt
{
    char fname[30];
    char lname[30];
    char symptoms[30];
    int age;
    int phone;
    char gender;
    char doc[30];
    char date[10];
    int reg;
};

typedef struct data_emp data_emp;
typedef struct data_pt data_pt;
typedef struct data_doc data_doc; 


#endif
