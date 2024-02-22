#include <stdio.h>
#include <stdlib.h>

#define Table_size 13
#define Prime 7

int double_hashing(int key, int i)
{
    int hash1, hash2, hash;
    hash1 = key % Table_size;
    hash2 = Prime - (key % Prime);
    hash = (hash1 + i * hash2) % 13;
    return hash;
}

int main()
{
    char *input = (char*)malloc(sizeof(char)*2);      //動態宣告一維陣列(input)
    char **bucket;
    bucket = (char**)malloc(sizeof(char*) * Table_size);    //動態宣告二維陣列(bucket)
    for (int  i = 0; i < Table_size; i++)
        bucket[i] = (char*)malloc(sizeof(char));
    int key, hash;
    while (scanf("%s ", input) != EOF) {
        key = atoi(input);
        for (int i = 0; ; i++) {
            hash = double_hashing(key, i);
            if (bucket[hash][0] == '\0') {
                sprintf(bucket[hash], "%d", key);   //int to char
                break;
            }
        }
    }
    for (int i = 0; i < Table_size; i++) {
        if (i == 0)
            printf("%d->%s", i, bucket[i]);
        else
            printf("\r\n%d->%s", i, bucket[i]);
    }
    for (int i = 0; i < Table_size; i++)
        free(bucket[i]);
    free(bucket);
    free(input);
    return 0;
}