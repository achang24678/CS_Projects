#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    char buff[256];
    char *p;
    int intvalid = 0;
    int t = 0;
    int i;

    printf("Assignment #1-2, Sheng Yu Chang, allen4646463@gmail.com\n");
    printf("> ");
    fgets(buff,256,stdin);
    buff[strlen(buff)-1] = '\0';
    i =strlen(buff);

     if(i > 65){

            printf("ERROR! Input string too long.\n");
            exit(0);
        }

    

    for(p = strtok(buff," "); p != NULL; p = strtok(NULL, " ")){

                intvalid = 0;
             
                for(t = 0; p[t] != '\0'; t++){

                    if(!isdigit(p[t])){

                        intvalid = 1;
                    
                    }             
                }

                if(intvalid != 1){

                    printf("INT ");
                    
                }

                else{

                    printf("STR ");
  
                }
                        
            }

    printf("\n");
    return 0;
}
            
