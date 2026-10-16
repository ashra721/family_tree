#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

void read_person_info(const char *role, char *name_out, int *age_out) {
   printf("Enter name for %s: ", role);
   char buffer[100];
   fgets(buffer, sizeof(buffer), stdin);
   buffer[strcspn(buffer, "\n")] = '\0';
   strncpy(name_out, buffer, 49);
   name_out[49] = '\0';
   printf("Enter age for %s: ", role);
   fgets(buffer, sizeof(buffer), stdin);
   buffer[strcspn(buffer, "\n")] = '\0';
      *age_out = atoi(buffer);
}      

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
    char name[50];
     const char *roles[7] = {
    "Paternal Grandfather", "Paternal Grandmother",
    "Maternal Grandfather", "Maternal Grandmother",
    "Father", "Mother", "Yourself"
};
Person *people[7];
for (int i = 0; i < 7; i++) {
    char name[50];
    int age;

    read_person_info(roles[i], name, &age);
    people[i] = create_person(name, age);
}
    
printf("\n--- You entered ---\n");
for (int i = 0; i < 7; i++) {
    printf("%s: %s, age %d\n", roles[i], people[i]->name, people[i]->age);
}

for (int i = 0; i < 7; i++) {
    free(people[i]);
}

return 0;
}
