package main

import "fmt"
import "io/ioutil"

/*
** Pita
 */

func main() {
	a := "package main%[1]c%[1]cimport %[4]cfmt%[4]c%[1]cimport %[4]cio/ioutil%[4]c%[1]c%[1]c/*%[1]c** Pita%[1]c */%[1]c%[1]cfunc main() {%[1]c%[2]ca := %[4]c%[3]s%[4]c%[1]c%[2]cioutil.WriteFile(%[4]cGrace_kid.go%[4]c, []byte(fmt.Sprintf(a, 10, 9, a, 34)), 0644)%[1]c}%[1]c"
	ioutil.WriteFile("Grace_kid.go", []byte(fmt.Sprintf(a, 10, 9, a, 34)), 0644)
}
