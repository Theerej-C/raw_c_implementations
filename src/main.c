#include "basic_types.h"
#include "hash_map.h"
#include <stdio.h>
#include "file_operation.h"
int main(){
    char string[100];
    char key[100];
    printf("Key: ");
    scanf("%99s", key);  // reads a single word into key

    printf("Value: ");
    scanf("%99s", string); // reads a single word into string
    HashMap* h_map = initialize_hashmap();
    hash_map_set(h_map, key, string);
    hash_map_set(h_map, "Hello", "Hai");
    hash_map_set(h_map, "Hai", "Hello");
    char buff[100];
    hash_map_get(h_map, buff, (const char*) key);
    printf("%s",buff);
    char buff1[100];
    hash_map_get(h_map,buff1,(const char*)"Hello");
    printf("%s",buff1);
    file_write(h_map, "data.bin");
    destroy_hash_map(h_map);
    HashMap* h_map_2 = initialize_hashmap();
    file_read(h_map_2, "data.bin");
    for(int i = 0; i < h_map_2->size; i++){
        Node *curr = h_map_2->buckets[i];
        while(curr){
            printf("Key: %s, Value: %s\n",
                   curr->key.value,
                   curr->value.value);
            curr = curr->next;
        }
    }
    destroy_hash_map(h_map_2);
    return 0;
}
