#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;


Person* create_person(const char *name, int age) {
    Person *p = malloc(sizeof(Person));
    if (p == NULL) { return NULL; }
    strncpy(p->name, name, 49); 
    p->name[49] = '\0';
    p->age = age;
    p->father = NULL;
    p->mother = NULL;
    return p;
}
int main(void) {
    Person *test = create_person("Khushi", 20);
    printf("%s is %d\n", test->name, test->age);
    free(test);
    return 0;
}

   