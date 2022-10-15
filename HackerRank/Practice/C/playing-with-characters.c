#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch;
    scanf("%c", &ch);
    printf("%c\n", ch);
    
    int MAX_LEN = 100;
    char s[MAX_LEN];
    
    scanf("%s", s);
    printf("%s\n", s);
    
    scanf("\n");
    scanf("%[^\n]%*c", s);
    printf("%s\n", s);
    
    
    return 0;
}
