#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char*argv[])
{
    int countok(char *input);
    char buff[256];
    char bf[256];
    char *p;
    int i;
    int t;
    int intvalid = 0;
    int inputvalid = 0;
    
    printf("Assignment #1-3, Sheng Yu Chang, allen4646463@gmail.com\n");

    while(inputvalid != 1){
        
        printf("> ");

        fgets(buff,256,stdin);
        buff[strlen(buff)-1] = '\0';
        i =strlen(buff);
        strcpy(bf, buff);

        if(countok(buff) > 2 || countok(buff) == 0){

            printf("ERROR! Incorrect number of tokens found.\n");
            continue;
        }

        if(i > 65){

            printf("ERROR! Input string too long.\n");
            continue;
        }

        else{

            for(p = strtok(bf," "); p != NULL; p = strtok(NULL, " ")){

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

            inputvalid = 1;        
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


