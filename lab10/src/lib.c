#include "lib.h"

    int* extract_diog_and_sortit(int input[], int length)
    {
        unsigned long length22 = (unsigned int) length;
        int* result = malloc(length22 * sizeof(int));
        if(result==NULL){
            return NULL;
        }
        for(int i = 0; i < length; i++) {
            *(result+i) = *(input+(i*length)+i);
        }

        for (int i = 0; i < length; ++i)
        {
            for (int j = i + 1; j < length; ++j)
            {
                if (*(result+i) > *(result+j))
                {
                    int tmp = *(result+i);
                    *(result+i) = *(result+j);
                    *(result+j) = tmp;
                }
            }
        }
        return result;
    }
