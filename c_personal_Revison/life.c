#include <stdio.h>

struct Life {
    int knowledge;
    int length;
};

int main() {
    struct Life life = { .length = 100 };
    life.knowledge = 100;
    int age = 0;
    
    while (age++ < life.length) {
        life.knowledge++;
        printf("get more knowledge \n");
    }

    return 0;
}
