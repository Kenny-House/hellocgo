package hcg

/*
#include <stdlib.h>       // for free()
#include "lib.h"
*/
import "C"
import (
	"unsafe"
	"fmt"
	"sync"
)

var funkyIdMu sync.Mutex
var funkyIds = 0
//export GoGetFunkyId
func GoGetFunkyId() int{
	funkyIdMu.Lock()
	defer func(){
		funkyIds++
		funkyIdMu.Unlock()
	}()
	return funkyIds
}

func Work(){
	fmt.Println("No params, C call from Go:")
	C.MakePerson()
	fmt.Println("")

	fmt.Println("Go string param, C call from Go and deferred free:")
	name := C.CString("Frederick")
	C.MakePersonWithName(name)
	C.free(unsafe.Pointer(name))
	fmt.Println("")

	fmt.Println("Returning pointer to created person from C")
	name3 := C.CString("Francisco")
	cPerson := C.MakePersonAndReturn(name3)
	C.PersonSpeakAndDelete(cPerson)
	C.free(unsafe.Pointer(name3))
}
