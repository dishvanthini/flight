#include<stdio.h>
void phase1();
struct flight{
    int ch;
    char name[50];
    int pn;
    char des[100];
    char phno[11];
};
struct flight f;
void phase1()
{
    printf("FROM:\t\t");
    printf("TO:\n");
    printf("DEPARTURE:\n");
    printf("TRAVELLERS & CLASS:\n");
    printf("SEARCHING........!\n");
}
int main(){
    phase1();
return 0;
}

