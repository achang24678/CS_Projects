#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int countok(char *input);
    char buff[256];
    char bf[256];
    char bfcp[256];
    char *p;
    char *w = "quit";
    int inputvalid = 0;
    int intvalid = 0;
    int i = 0;
    int t;
    int a;
    int b;
    int tmp;
    int tmpvalid = 0;
    int len = 0;
    
    
    printf("Assignment #1-5, Sheng Yu Chang, allen4646463@gmail.com\n");
    while(inputvalid != 1){

        a = 0;
        b = 0;
        tmp = 0;
        tmpvalid = 0;
        printf("> ");

        fgets(buff,256,stdin);
    
        buff[strlen(buff)-1] = '\0';
        i =strlen(buff);
        strcpy(bf, buff);
        
        strcpy(bfcp, buff);
        len = countok(buff);
        if(len > 2 || countok(buff) == 0){

            printf("ERROR! Incorrect number of tokens found.\n");
            continue;

        }

        if(i > 65){

            printf("ERROR! Input string too long.\n");
            continue;

        }
        
        for(p = strtok(bf," "); p != NULL; p = strtok(NULL, " ")){

         
            if(len < 2 && strcasecmp(p, w) == 0){

                inputvalid = 1;
                exit(0);
            }

            // integer first string second - tmp = 1, tmpvalid =1
             
            if(tmp == 1){

                tmpvalid = 1;

            }

            intvalid = 0;
             
            for(t = 0; p[t] != '\0'; t++){

                if(!isdigit(p[t])){

                    intvalid = 1;
                    
                }             
            }

            if(intvalid != 1){
                tmp = 1; //if it is integer tmp = 1
                a++;    //count integers
              
            }

            else{
                tmp = 0; // if it is string tmp = 0
                b++;    //count strings
             
            }
            
         }

        if(a == 2){     //if both integers
            printf("ERROR! Expected STR INT.\n");
            
            continue;
        }
        if(a == 1 && b == 0){   //if one integer only
            printf("ERROR! Expected STR.\n");
            
            continue;
        }
        if(tmpvalid == 1){  //if integer first string second
            printf("ERROR! Expected STR INT.\n");
            
            continue;
        }
        if(b == 2){     //if both string
            printf("ERROR! Expected STR INT.\n");
            
            continue;
        }

        else{
            
            for(p = strtok(bfcp," "); p != NULL; p = strtok(NULL, " ")){

                if(len < 2 && strcasecmp(p, w) == 0){

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

