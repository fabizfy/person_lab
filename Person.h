typedef struct _person {
        char *theName;
        struct _person *theF;
        struct _person *theM;
        struct _person *spouse;
} Person;

void deletePerson(Person *p);

void marryPerson(Person *p1, Person *p2);

void divorcePerson(Person *p);

