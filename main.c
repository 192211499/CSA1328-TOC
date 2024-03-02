#include <stdio.h>
#include <string.h>


int belongsToCFG(char *str, int start, int end) {
    
    if (start > end)
        return 1;

    
    if (str[start] == '0' && str[end] == '1') {
        
        int i;
        for (i = start + 1; i <= end; i++) {
            if (str[i] == '1')
                break;
        }
        
        if (i > end)
            return 0;
        else
            
            return belongsToCFG(str, start + 1, i - 1) && belongsToCFG(str, i + 1, end);
    } 
    
    else if (start == end && str[start] == ' ')
        return 1;
    else
        return 0; 
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);


    if (belongsToCFG(str, 0, len - 1))
        printf("The string belongs to the CFG language.\n");
    else
        printf("The string does not belong to the CFG language.\n");

    return 0;
}