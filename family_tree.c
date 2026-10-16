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
   printf("Enter age for %s: ", role) ;
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
void link_parents(Person *child, Person *father, Person *mother) {
    child->father = father;
    child->mother = mother;
}
void print_family_relationships(const Person *me) {
    printf("\n=== FAMILY TREE RELATIONSHIPS ===\n");
    printf("1. YOURSELF:\n");
    printf("- Name: %s | Age: %d\n", me->name, me->age);
    printf("2. PARENTS:\n");
    printf("- Father: %s | Age: %d\n", me->father->name, me->father->age);
    printf("- Mother: %s | Age: %d\n", me->mother->name, me->mother->age);
    printf("3. PATERNAL GRANDPARENTS (via Father's Pointers):\n");
    printf("- Grandfather: %s | Age: %d\n", me->father->father->name, me->father->father->age);
    printf("- Grandmother: %s | Age: %d\n", me->father->mother->name, me->father->mother->age);
    printf("4. MATERNAL GRANDPARENTS (via Mother's Pointers):\n");
    printf("- Grandfather: %s | Age: %d\n", me->mother->father->name, me->mother->father->age);
    printf("- Grandmother: %s | Age: %d\n", me->mother->mother->name, me->mother->mother->age);
}
int main(void) {
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
 link_parents(people[4], people[0], people[1]);   
 link_parents(people[5], people[2], people[3]);
 link_parents(people[6], people[4], people[5]);
 print_family_relationships(people[6]);


for (int i = 0; i < 7; i++) {
    free(people[i]);
}

return 0;
}


