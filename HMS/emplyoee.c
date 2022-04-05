

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

void login_emp()
{   
    system("clear");
    title();
    int input;
    int uid,flag =0;
    char cpass[20];
    char cname[30];
    FILE *ptr;
    

    ptr = fopen("data.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }

    data_emp  d1;
    
    printf("\n\n\n\t\t\t\tENTER YOUR CREDENTIALS");
    printf("\n\n\n\t\t\t\tPlease Enter User Id ");
    scanf("%d",&uid);
    printf("\n\t\t\t\tPassword: ");
    scanf("%s",cpass);

    while(fread(&d1,sizeof(d1),1,ptr))
        {
        
        if(d1.id == uid)
		{
			if(strcmp(d1.pass,cpass)==0)
			{
				flag = 1;
				strcpy(cpass,d1.name);
				user1_emp(cpass); 
				break;
			}
		}
   
    
         }
         
           if(flag != 1){
		printf("\nCheck UID/Password\n");
		}
		
       fclose(ptr);
     
}

void registration_emp()
{
    system("clear");
    title();
    FILE *ptr;

    ptr = fopen("data.dat","ab");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }

    data_emp d1;
    printf("\n\n\n\t\t\t\tCREATING AN ACCOUNT");
    printf("\n\n\n\t\t\t\tEnter Name: ");
    scanf("%s",d1.name);
    fflush(stdin);   
    printf("\n\t\t\t\tEnter User Id: ");
    scanf("%d",&d1.id);
    printf("\n\t\t\t\tEnter Password: ");
    scanf("%s",d1.pass);


    fwrite(&d1,sizeof(d1),1,ptr);
    
    fclose(ptr);
    
    log_page1();
}


void log_page1()
{   
    system("clear");
    title();
    int input;
    printf("\n\n\n\t\t\t\tEMPLYOEE PORTAL");
    printf("\n\n\t\t\t\tPress '1' for New User\n\t\t\t\tPress '2' for Existing User\n\n");
    printf("\n\n\t\t\tPress here to continue... ");
    scanf("%d",&input);


    if(input == 1)
        {
            registration_emp();
        }

    else if(input == 2)
        {   
            
            login_emp();
        }
    else if(input == 3)
        {
            read_emp();
        } 
}

void read_emp()
{
   
    FILE *ptr;

    ptr = fopen("data.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }

    data_emp  d1;
    
    while(fread(&d1,sizeof(d1),1,ptr))
        {
    printf("Name : %s\n",d1.name);
    printf("Uid : %d\n",d1.id);
    printf("Password : %s\n\n",d1.pass);
    }   	
       
    fclose(ptr);   
         
}


void user1_emp(char c[])
{   
    system("clear");
    title();
    int input;
    printf("\n\n\n\t\t\t\tWELCOME: %s",c);
    printf("\n\n\t\t\t\tPress '1' to Add Patients Record\n\t\t\t\tPress '2' to List Patient Record\n\t\t\t\tPress '3' to Search Patient Record\n\t\t\t\tPress '4' to Edit Patient Record");
    printf("\n\t\t\t\tPress '5' to List Doctor Record\n\t\t\t\tPress '6' to exit");
    printf("\n\n\n\t\t\tPress here to continue... ");
    scanf("%d",&input);
      if(input == 1)
        {    
            add_rec(c);
        }

    else if(input == 2)
        {
            read_pt(c);
        }
     else if(input == 3)
        {
            search_rec(c);
        }
      else if(input == 4)
        {
            edit_rec(c);
        }
      else if(input == 5)
        {
           dis_doc(c);
        }
      else if(input == 6)
        {
           exit(EXIT_SUCCESS);
        }        
   
}

