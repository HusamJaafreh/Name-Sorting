#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char temp[20];
    char word[20];
    FILE *fp;

    fp = fopen("names.txt", "r");
    if (fp == NULL) {
        printf("Could not open names.txt\n");
        return 1;
    }
    int count;
    for(count=0; fscanf(fp, "%19s", word) != EOF; count++);

    char names[count][20];

    fclose(fp);
    fp = fopen("names.txt", "r");

    for(int i=0; fscanf(fp, "%19s", word) != EOF; i++){

        for(int j=0; word[j] != '\0'; j++)
            word[j] = toupper(word[j]);

        strcpy(names[i],  word);
    }
    fclose(fp);

    for(int i=0; i<sizeof(names)/sizeof(names[0]); i++){
        for(int j=i+1; j<sizeof(names)/sizeof(names[0]); j++){

            if(strcmp(names[j],names[i]) > 0){
                strcpy(temp, names[j]);
                strcpy(names[j], names[i]);
                strcpy(names[i], temp);
            }

        }
    }

    fp = fopen("Sorted_Names.txt", "w");
    if (fp == NULL) {
        printf("Could not create Sorted_Names.txt\n");
        return 1;
    }

    for(int i=0; i < sizeof(names)/sizeof(names[0]); i++)
        fprintf(fp, "%s\n", names[i]);

    fclose(fp);
    return 0;
}
