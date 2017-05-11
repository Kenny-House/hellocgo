#ifndef _C_LIBLIB_H
#define _C_LIBLIB_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* CGO_Person;

    void MakePerson(void);
    void MakePersonWithName(char* s);

    CGO_Person MakePersonAndReturn(char* s);
    void PersonSpeakAndDelete(CGO_Person p);

    //void f5(void (*f)(int));

#ifdef __cplusplus
}
#endif

#endif //_C_LIBLIB_H