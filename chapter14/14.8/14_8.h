void hash_dh_add(element item, element ht[])
{
    int i, hash_value, inc;
    hash_value = i = hash_function(item.key);
    inc = hash_function2(item.key);
    // printf("hash_address = %d\n", i);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "searching key is overlapped.\n");
            exit(1);
        }
        i = (i + inc) % TABLE_SIZE;
        if (i == hash_value) {
            fprintf(stderr, "table is full.\n");
            exit(1);
        }
    }
    ht[i] = item;
}