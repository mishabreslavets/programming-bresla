#include "lib.h"
#include <stdlib.h>
/**
 * @author Бресла
 * @version 1.0
 */
un_comp(number);
int main(int argc, char *argv[])
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
  g_rand_free(rand);
}