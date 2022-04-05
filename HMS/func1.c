

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "structure.h"
#include "launch.h"
#include "emplyoee.h"
#include "doctor.h"
#include "patient.h"
#include "func1.h"


void display(int reg,char fname[],char lname[],int age,int contact,char date[],char doc[],char c[])
{
    system("clear");
    title();
    printf("\n\nAppointment submitted successfully");
    printf("\n\n Reg No.  | First Name  | Last Name  | Age | Contact No.  | Date of Appointment | Doctor");
    printf("\n\n %d      %s         %s          %d   %d         %s              %s",reg,fname,lname,age,contact,date,doc);
    printf("\n\nPress enter key to continue....");                              
    getchar();
    getchar();
    user1_emp(c);
}

void display0(int reg,char fname[],char lname[],int age,int contact,char date[],char doc[],char c[])
{
    system("clear");
    title();
    printf("\n\n Reg No.  | First Name  | Last Name  | Age | Contact No.  | Date of Appointment | Doctor");
    printf("\n\n %d      %s         %s          %d   %d         %s              %s",reg,fname,lname,age,contact,date,doc);
    printf("\n\nPress enter key to continue....");                              
    getchar();
    getchar();
    user1_emp(c);
}



