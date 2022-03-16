#include <stdio.h>

int main(char **argv){
    int value = 10;
    void* pointer_value = (void*)value;
    int result = (int)pointer_value;
    printf("%d\n",result);
    return 0;
}
