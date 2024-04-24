#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateStr(char *str, int k) {
    char *newstr = (char *)malloc((k + 1) * sizeof(char));
    if (newstr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int len_str = strlen(str);
    int no_of_str = k / len_str;
    int no_of_wrd_lft = k % len_str;

    int i, j;
    for (i = 0; i < no_of_str; i++) {
        strcat(newstr, str);
    }
    for (j = 0; j < no_of_wrd_lft; j++) {
        newstr[i * len_str + j] = str[j];
    }
    newstr[i * len_str + j] = '\0';

    strcpy(str, newstr);
    free(newstr);
}

int freqA(char *str) {
    int cnt = 0;
    while (*str) {
        if (*str == 'a')
            cnt++;
        str++;
    }
    return cnt;
}

int main() {
    printf("sub-string problem\n");
    printf("enter the string: ");
    char str[1000];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // remove trailing newline

    printf("enter the length of string to be generated: ");
    int k;
    scanf("%d", &k);

    generateStr(str, k);
    printf("frequency of 'A' in the string is: %d\n", freqA(str));

    return 0;
}

