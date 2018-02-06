#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char*argv[]){


    int countok(char *input);
    int loopchar(char *pi);
    char buff[256];
    char bf[256];
    char bfcp[256];
    char *p;
   
    int intvalid = 0;
    int i = 0;
    int t;
    int k;
    int a;
    int b;
    int tmp;
    int tmpvalid = 0;
    int len = 0;
    int inputok = 0;

    cout << "Assignment #2-1, Sheng Yu Chang, allen4646463@gmail.com\n";
    
    
    

    if(argc != 2){

        cout << "ERROR! Program 6 accepts 1 command line argument.\n";
        exit(0);

    }
    int argval = atoi(argv[1]);

    if(argval < 0){

        cout << "ERROR! Program 6 accepts 1 command line argument.\n";
        exit(0);

    }
        
       *argv++;
        
        

    if(loopchar(*argv) == 1){

        cout << "ERROR! Expected integer argument.\n";
            
    }

       

    else{
  
        for(k = 0; k < argval; k++){
            
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
                if(len > 2){
                    cout << "ERROR! Incorrect number of tokens found.\n";
                    continue;
                }

                if(i > 65){
                    cout << "ERROR! Input string too long.\n";
                    continue;
                }
        
                for(p = strtok(bf," "); p != NULL; p = strtok(NULL, " ")){

                    if(len < 2 && strcasecmp(p, "quit") == 0){
                        
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
                        a++;
              
                    }

                    else{
                        tmp = 0; // if it is string tmp = 0
                        b++;
             
                    }
                }

        if(a == 2){
            cout << "ERROR! Expected STR INT.\n";
            
            continue;
        }
        if(a == 1 && b == 0){
            cout << "ERROR! Expected STR.\n";
            
            continue;
        }
        if(tmpvalid == 1){  //if integer first string second
            
            cout << "ERROR! Expected STR INT.\n";
            
            continue;
        }
        if(b == 2){
            cout << "ERROR! Expected STR INT.\n";
            
            continue;
        }

        else{
            
            for(p = strtok(bfcp," "); p != NULL; p = strtok(NULL, " ")){

                if(len < 2 && strcasecmp(p, "quit") == 0){
                     
                     exit(0);
                }
                
                intvalid = 0;
             
                for(t = 0; p[t] != '\0'; t++){

                    if(!isdigit(p[t])){

                        intvalid = 1;
                    
                    }             
                }

                if(intvalid != 1){

                    cout << "INT ";
                    
                }

                else{

                    cout << "STR ";
  
                }

            }

                  
        }

        cout << "\n";

      }

    return 0;

  } 

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

int loopchar (char *pi){
    int x = 0;
    int length = strlen(pi);
    int val = 0;
    for(x = 0; x < length; x++){
        if(!isdigit(pi[x])){
            val = 1;
        }
     
     }
    return val;
 }



