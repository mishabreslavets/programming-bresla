#include"lib.h"
/**
 * @brief save data in file
 * 
 * @param data data
 * @param bytes size of data in bytes
 * @param f file descriptor
 */
void save_data(void* data,size_t bytes,FILE* f)
{
    fwrite(data,bytes,1,f);
}
void* load_data(size_t bytes,FILE* f)
{
    void* b = malloc(bytes);
    fread(b,bytes,1,f);
    return b;
}
static inline void un_print(university un)
{
    g_print("free = %d\nname = %s\nnumber = %zu\nowner full name = %s\nowner mail = %s\n",un.is_free,un.name,un.number,un.owner.full_name,un.owner.email);
}
void un_prints(university* arr,int len)
{
    for (university* i = arr; i != arr+len+1; ++i)
    {
        un_print(*i);
    }
}
university un_max_count(university* arr,int len)
{
    university b;
    b.number = 0;
    for(university* i = arr;i!= arr+len;++i)
    {
        if(i->number > b.number)
            b = *i;           
    }
    return b;
}






