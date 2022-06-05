#include<entity.h>
#include<glib.h>
#include<stdio.h>
#include"university_list.h"
/**
 * @file main.c
 * @brief Файл
 *
 * @author Bresla
 * @version 1.453
 */
un_comp(number);
void un_max_count_test()
{
  GRand* rand = g_rand_new(); 
  int max = 0;
  university_array arr;
  university_array_init(&arr);
  for(char i = 0;i != 25;++i)
  {
    int b = g_random_int_range(0,INT32_MAX);
    university_array_append(&arr,(university){0,"",b,{"",""},0});
    if(b > max) 
      max = b;
  }
  int max1 = un_max_count(arr.data,arr.len).number;
  g_assert_true(max == max1);
  university_array_free(&arr);
}
void save_load_test()
{
    university_array un ;
    university_array_init(&un);
    university_array_append(&un, (university) {true, "Not so mega", 100, {"123", "321"}, STANDART});
    FILE* f = fopen("UNmega.bin","w");
    save_data(un.data,sizeof(university)*un.len,f);
    fclose(f);
    f = fopen("UNmega.bin","r");
    university_array un1;
    un1.data = (university*)load_data(sizeof(university),f);;
    un1.len = 1;
    un1.cap = 1;
    fclose(f);
    g_assert_true
    (
    un.data->is_free == un1.data->is_free &&
    un.data->name == un1.data->name &&
    un.data->number == un1.data->number &&
    un.data->time == un1.data->time &&
    un.data->owner.email == un1.data->owner.email &&
    un.data->owner.full_name == un1.data->owner.full_name
    );
    university_array_free(&un);
    university_array_free(&un1);
}
void sort_test()
{
  university_array un0;
  university_array un1;
  university_array_init(&un1);
  university_array_init(&un0);
	for (char i = 0; i != 25; ++i) 
  {
	university_array_append(&un0,(university){ 0, "", 24 - i, { "", "" }, 0 });
  university_array_append(&un1,(university){ 0, "", i, { "", "" }, 0 });
	}
  university_array_sort(&un0,un_comp_number);
  for (char i = 0; i != 25; ++i) 
  {
    g_assert_true(un0.data[i].number == un1.data[i].number);
	}
  university_array_free(&un0);
  university_array_free(&un1);
}
int main(int argv,char **argc)
{
  g_test_init(&argv,&argc,NULL);
  g_test_add_func("/main/test1",un_max_count_test);
  g_test_add_func("/main/test2",save_load_test);
  g_test_add_func("/main/test3",sort_test);
  return g_test_run();
}