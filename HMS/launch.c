

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

void welcome_screen()
{                                                                             
    printf("\n\t\t\t=========================================================");
    printf("\n\t\t\t=\t\t\tWELCOME TO\t\t\t=");
    printf("\n\t\t\t=\t\tHELPING HAND HOSPITAL\t\t\t=");
    printf("\n\t\t\t=========================================================\n");
    printf("\n\nPress enter key to continue....");                              
    getchar();
    system("clear");
}
void title()
{                                                                             
    printf("\n\t\t\t=========================================================");
    printf("\n\t\t\t=\t\tHELPING HAND HOSPITAL\t\t\t=");
    printf("\n\t\t\t=========================================================\n");
                                                                                
}


void login()
{
    title();
    int input;
    printf("\n\n\n\t\t\t\tLOGIN PORTAL");
    printf("\n\n\t\t\t\tPress '1' to visit Emplyoee Page\n\t\t\t\tPress '2' to visit Doctor Page\n\t\t\t\tPress '3' to exit \n\n\n");
    printf("\n\n\t\t\tPress here to continue... ");
    scanf("%d",&input);
      if(input == 1)
        {    
            system("clear");
            log_page1();
        }

    else if(input == 2)
        {
            system("clear");
            log_page2();
        }
        
   else if(input == 3)
        {
            exit(EXIT_SUCCESS);
        }     
    
}


