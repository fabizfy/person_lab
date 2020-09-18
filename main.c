/***************************************************
Name: Fabiane Yeung 
CS360 - lab 2 - create a program for the following:

Person.h

Struct Person{};
        newPerson(char *name, Person *F, Person *M);

void deletePerson(Person *p);
void marryPerson(Person *p1, Person *p2);
void divorcePerson(Person *p);

----------------------------------------------------*/

#include <stdio.h>
#include "Person.h"
#include <stdlib.h>

	Person * newPerson (char *Name, Person *F,Person *M) {
		Person *p;
		p = (Person *) malloc (sizeof (Person) );
		p->theName = Name;
		p->theF = F;
		p->theM = M;
		p->spouse = NULL;

		return p;
	};

void deletePerson (Person *p) {

	printf("%s is expected to be deleted.\n", p->theName);
	printf("The parents are %s and %s.\n", p->theF->theName, p->theM->theName);
	printf("%s was deleted.\n", p->theName);
	p->theName = NULL;
	free(p);
}

void marryPerson (Person *p1, Person *p2) {

	printf("%s is expected to marry.\n", p1->theName);
	printf("%s is expected to marry.\n", p2->theName);

	p1->spouse = p2;
	p2->spouse = p1;

	printf("%s is married to %s.\n", p1->theName, p2->theName);
	printf("%s is the spouse of %s.\n", p1->spouse->theName, p1->theName);

}

void divorcePerson (Person *p) {

	printf("%s is expected to get divorced.\n", p->theName);
	printf("%s will be divorced.\n", p->theName);
	p->spouse->spouse = NULL;
	p->spouse = NULL;
	printf("%s is divorced.\n", p->theName);

}


int main() {

	Person *Paul, *Mary, *Carl;

	Mary = newPerson ("Mary the Pirate", NULL, NULL);
	Carl = newPerson ("Carl the Pirate", NULL, NULL);
	Paul = newPerson ("Paul will be gone", Carl, Mary);

	deletePerson(Paul);
	marryPerson(Mary, Carl);
	divorcePerson(Mary);

}
