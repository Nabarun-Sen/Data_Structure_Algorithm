#include<stdio.h>
#include<string.h>
void main()
{
    char a;

    printf("Enter to check: ");
    scanf("%c", &a);

    if(a>='A' && a<='Z')
        printf("Alphanumeric");
    else if(a>='a' && a<='z')
        printf("Alphanumeric");
    else if(a>='0' && a<='9')
        printf("Alphanumeric");
    else
        printf("Special Character");
}