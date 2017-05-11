#include "lib.h"
#include "lib.hpp"
#include "_cgo_export.h"

#include <stdio.h>

Person::Person (string name) {
    this->name = name;
    this->goId = GoGetFunkyId();
}

void Person::Speak () {
    printf("Hi I'm %s. My id is %d\n", this->name.c_str(), this->goId);
}

void MakePerson(void) {
    Person* p = new Person("Fred");
    p->Speak();
    delete p;
}

void MakePersonWithName(char* n) {
    string name = string(n);
    Person* p = new Person(name);
    p->Speak();
    delete p;
}

CGO_Person MakePersonAndReturn(char* n) {
    string name = string(n);
    Person* p = new Person(name);
    return (CGO_Person)p;
}

void PersonSpeakAndDelete(CGO_Person cp) {
    Person* p = (Person*)cp;
    p->Speak();
    delete p;
}

//void f5(void (*f)(int)) {
//	int i;
//	for (i = 0; i < 3; i++) {
//		f(i);
//	}
//}