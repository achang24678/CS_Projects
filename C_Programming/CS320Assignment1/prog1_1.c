#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    char buff[256];
    char *ptr;
    int i;
    printf("Assignment #1-1, Sheng Yu Chang, allen4646463@gmail.com\n");
    fgets(buff,256,stdin);
    buff[strlen(buff)-1] = '\0';
    i =strlen(buff);
        if(i > 65){

            printf("ERROR! Input string too long.\n");
            exit(0);
        }
    ptr = strtok (buff," ");

    while( ptr != NULL){

        printf("=%s=\n",ptr);
        
        ptr = strtok (NULL, " ");
    }
    return 0; 
}
