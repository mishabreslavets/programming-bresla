#pragma once
#include<glib.h>
#include<math.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdint.h>
typedef struct Human
{
    char* full_name;
    char* email;
}human;
typedef enum Shift 
{
    STANDART ,
    LATE ,
    SECOND_SHIFT
}shift;
 typedef struct University
{
    bool is_free;
    char* name;
    size_t number;
    human owner;
    shift time;
}university;
void save_data(void* data,size_t bytes,FILE* f);
void* load_data(size_t bytes,FILE* f);
void un_prints(university* arr,int len);
university un_max_count(university* arr,int len);
#define un_comp(field) \
int un_comp_##field(const void *a,const void *b){return ((university*)a)-> field - ((university*)b)-> field; }
#define un_soft(arr,len,field) \
qsort(arr,len,sizeof(university),un_comp_##field)

