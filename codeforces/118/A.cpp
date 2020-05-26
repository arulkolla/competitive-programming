#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int i;
    char arr[100];
    scanf("%s",&arr);
    for( i=0;arr[i]!='\0';i++){
        if(arr[i]=='a'||arr[i]=='A'||arr[i]=='o'||arr[i]=='O'||arr[i]=='y'||arr[i]=='Y'||arr[i]=='e'||arr[i]=='E'||arr[i]=='u'||arr[i]=='U'||arr[i]=='i'||arr[i]=='I'){}
 
 
        else
        printf(".%c",tolower(arr[i]));}
    return 0;
}