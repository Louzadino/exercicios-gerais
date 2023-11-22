#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main(){

    tData* data1 = CriaData();
    LeData(data1);

    tData* data2 = CriaData();
    LeData(data2);

    LiberaData(data1);
    LiberaData(data2);

    return 0;
}
