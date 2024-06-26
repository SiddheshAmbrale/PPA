/*Accept character from user and display its ASCII value in decimal ,octal,hexadecimal format.

Input: A

Output: Decimal         65
        Octal           0101
        Hexadecimal     0X41

*/

#include<stdio.h>

void Display(char ch)
{
    printf("Decimal :       %d\n",ch);
    printf("Octal :         %o\n",ch);
    printf("Hexadecimal :   %x\n",ch);
}

int main()
{
    char cvalue='\0';

    printf("Enter the character\n");
    scanf("%c",&cvalue);

    Display(cvalue);

    return 0;
}