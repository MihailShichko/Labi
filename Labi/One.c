
#include "stdbool.h";
#include "stdio.h";

struct Child
{
    int a;
    union Aye 
    {
        double b;
        int c;
        char* anal;
    };
};

int main()
{
    struct Child child;
    union Aye aye;
    child.a = 129;
    printf("%d\n", child.a);
    child.b = 13.3;
    child.c = 3;
    printf("%f\n%d\n", child.b, child.c);
    printf("%f\n", child.b);
    child.anal = (char*)malloc(10);
    get(child.anal);
    printf("%s", child.anal);
}

