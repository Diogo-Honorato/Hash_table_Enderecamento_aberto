#include <stdio.h>
#include <stdlib.h>
#define TAM 21

typedef struct HashTable
{
    int item;
    int full;
}HashTable;

int StartHash(HashTable *hash)
{
 
    for (int i = 0; i < TAM; i++)
    {
        hash[i].item = -1;
    }
    hash->full = 0;

    return 1;
}

int FuctionHash(int key)
{
    return key % TAM;
}

int InsertHash(HashTable *hash, int key)
{
    

    if (hash->full == TAM)
    {
        printf("\n\nHash is full!\nKey not inserted: %d\n",key);
    }
    else
    {
        int index = FuctionHash(key);

        while (hash[index].item != -1 && hash[index].item != -2)
        {
            if (hash[index].item == key)
            {
                printf("\n\nExisting key will not be allocated: %d\n\n", key);
                break;
            }
            index = FuctionHash(index + 1);
        }

        if (hash[index].item != key)
        {
            hash[index].item = key;
            hash->full++;
        }
    }

    return 1;
}

int RemoveHash(HashTable *hash, int key)
{

    if(hash->full == 0)
    {
        printf("\n\nEmpty hash!\n\n");
        exit(0);
    }

    int index = FuctionHash(key);
    int count = 0;

    while (hash[index].item != -1 && hash[index].item != key)
    {
        if(count == TAM)
        {
            break;
        }
        count++;
        index = FuctionHash(index + 1);
    }

    if (hash[index].item == key)
    {
        hash[index].item = -2;
        printf("\n\nRemoved key: %d\nIndex: [%d]\n", key,index);
        hash->full--;
    }
    else
    {
        printf("\n\nKey is not in the hash table to remove: %d\n\n", key);
    }

    return key;
}

int SearchHash(HashTable *hash, int key)
{
    

    if(hash->full == 0)
    {
        printf("\n\nEmpty hash!\n\n");
        exit(0);
    }

    int index = FuctionHash(key);
    int count = 0;

    while (hash[index].item != -1 && hash[index].item != key)
    {
        if(count == TAM)
        {
            break;
        }
        count++;
        index = FuctionHash(index + 1);
    }

    if (hash[index].item == key)
    {
        printf("\n\nKey was found: %d\nIndex:[%d]\n", key, index);
    }
    else
    {
        printf("\n\nKey is not in the hash table: %d\n\n", key);
    }

    return key;
}

void PrintHash(HashTable *hash)
{
    printf("\nHash Table:\n");
    for (int i = 0; i < TAM; i++)
    {
        if (hash[i].item != -1 && hash[i].item != -2)
        {
            printf("[%d] - (%d)\n", i, hash[i].item);
        }
        else
        {
            printf("[%d] - ( )\n", i);
        }
    }
    
    if(hash->full == 0)
    {
        printf("\n\nEmpty hash!\n\n");
        exit(0);
    }
}

int main()
{
    HashTable hash[TAM];
    int list[] = {39,89,70,33,110,50,56,90,10,80};
    int size = sizeof(list) / sizeof(int);

    StartHash(hash);

    for (int i = 0; i < size; i++)
    {
       InsertHash(hash, list[i]);
    }

    PrintHash(hash);
    SearchHash(hash, 90);
    SearchHash(hash, 100);
    RemoveHash(hash, 900);
    RemoveHash(hash,39);
    PrintHash(hash);

}
