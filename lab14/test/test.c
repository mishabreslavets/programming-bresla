#include<lib.h>
#include<glib.h>
#include<stdio.h>
/**
 * @file main.c
 * @brief Файл
 *
 * @author Bresla
 * @version 1.02
 */
un_comp(number);
void un_max_count_test()
{
  GRand* rand = g_rand_new(); 
  int max = 0;
  university un[25] ;
  for(char i = 0;i != 25;++i)
  {
    int b = g_random_int_range(0,INT32_MAX);
    un[i] = (university){0,"",b,{"",""},0};
    if(b > max) 
      max = b;
  }
  int max1 = un_max_count(un,25).number;
  g_assert_true(max == max1);
}
void save_load_test()
{
    university un = {true,"Mega Super",100,{"943","371"},STANDART};
    FILE* f = fopen("Megamega".bin","w");
    save_data(&un,sizeof(university),f);
    fclose(f);
    f = fopen("Your_mom.bin","r");
    university *un1 = (university*)load_data(sizeof(university),f);
    fclose(f);
    g_assert_true
    (
    un.is_free == un1->is_free &&
    un.name == un1->name &&
    un.number == un1->number &&
    un.time == un1->time &&
    un.owner.email == un1->owner.email &&
    un.owner.full_name == un1->owner.full_name
    );
    free(un1);
}
void sort_test()
{
  university un0[25];
  university un1[25];
	for (char i = 0; i != 25; ++i) 
  {
	un0[i] = (university){ 0, "", 24 - i, { "", "" }, 0 };
  un1[i] = (university){ 0, "", i, { "", "" }, 0 };
	}
  un_soft(un0,25,number);
  for (char i = 0; i != 25; ++i) 
  {
    g_assert_true(un0[i].number == un1[i].number);
	}
}
int main(int argv,char **argc)
{
  g_test_init(&argv,&argc,NULL);
  g_test_add_func("/main/test1",un_max_count_test);
  g_test_add_func("/main/test2",save_load_test);
  g_test_add_func("/main/test3",sort_test);
  return g_test_run();
}