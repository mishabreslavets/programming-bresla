#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#ifdef T
#ifdef T_NAME
typedef struct
{
    T* data;
    uint32_t len;
    uint32_t cap;
}T_NAME(array);
void T_NAME(array_init)(T_NAME(array) *arr)
{
    arr->cap = 0;
    arr->data = 0;
    arr->len = 0;
}
void T_NAME(array_append)(T_NAME(array)* arr,T data)
{
    if(arr->cap < arr->len + 1)
    {
        T* buffer = malloc(sizeof(T)*((arr->cap + 1)*1.5f));
        if(arr->data != 0)
        {
        	memcpy(buffer,arr->data,arr->len*sizeof(T));
        	free(arr->data);
        }
        arr->data = buffer;
        arr->cap = (arr->cap + 1)*1.5f;
    }
        *(arr->data + arr->len++) = data;
}
void T_NAME(array_remove_index)(T_NAME(array)* arr,uint32_t index)
{
    T* end = arr->data + --arr->len;
    for(T* i = arr->data + index;i != end;++i)
    {
        *i = *(i+1);
    }
}
void T_NAME(array_for_each)(T_NAME(array)* arr,void(*func)(T*))
{
    for (T* i = arr->data;i != arr->data + arr->len;++i)
    {
        (*func)(i);
    }
}
void T_NAME(array_sort)(T_NAME(array)* arr,int (*comp)(const void *, const void *))
{
    qsort(arr->data,arr->len,sizeof(T),comp);
}
void T_NAME(array_free)(T_NAME(array)* arr)
{
    free(arr->data);
}
#endif
#endif



