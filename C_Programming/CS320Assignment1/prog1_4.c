#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int countok(char *in);
    char buff[256];
    char bf[256];
    char *p;
    char *w = "quit";
    int inputvalid = 0;
    int i = 0;
    int t = 0;
    int intvalid;
    
    printf("Assignment #1-4, Sheng Yu Chang, allen4646463@gmail.com\n");
    while(inputvalid != 1){

        printf("> ");

        fgets(buff,256,stdin);
        buff[strlen(buff)-1] = '\0';
        i =strlen(buff);
        strcpy(bf, buff);
          if(i > 20){

            printf("ERROR! Input string too long.\n");
            continue;
        }
    
        if(countok(buff) > 2 || countok(buff) == 0){

            printf("ERROR! Incorrect number of tokens found.\n");
            continue;
        }

      

        else{

            for(p = strtok(bf," "); p != NULL; p = strtok(NULL, " ")){

                if(strcasecmp(p, w) == 0){

                     inputvalid = 1;
                     exit(0);
                }

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

            inputvalid = 0;        
        }

        printf("\n");
    }

    return 0;
}    

int countok(char *input){

    int count = 0;
    
    char *ptr;

    ptr = strtok(input," ");
    
    while(ptr!= NULL){
        
        count++;      
        ptr = strtok (NULL," ");

    }
    return count;
}

