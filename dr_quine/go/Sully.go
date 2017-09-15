package main

import (
	"fmt"
	"io/ioutil"
	"os/exec"
	"strconv"
	"runtime"
	"strings"
)

func main() {
	i := 5
	if i < 0 {
		return
	}
	_, file, _, _ := runtime.Caller(0); path := strings.Split(file, "/")
	if path[len(path) - 1] == "Sully_0.go" {
		return
	}
	if path[len(path) - 1] != "Sully.go" {
		i--
	}
	a := "package main%[1]c%[1]cimport (%[1]c%[2]c%[4]cfmt%[4]c%[1]c%[2]c%[4]cio/ioutil%[4]c%[1]c%[2]c%[4]cos/exec%[4]c%[1]c%[2]c%[4]cstrconv%[4]c%[1]c%[2]c%[4]cruntime%[4]c%[1]c%[2]c%[4]cstrings%[4]c%[1]c)%[1]c%[1]cfunc main() {%[1]c%[2]ci := %[5]d%[1]c%[2]cif i < 0 {%[1]c%[2]c%[2]creturn%[1]c%[2]c}%[1]c%[2]c_, file, _, _ := runtime.Caller(0); path := strings.Split(file, %[4]c/%[4]c)%[1]c%[2]cif path[len(path) - 1] == %[4]cSully_0.go%[4]c {%[1]c%[2]c%[2]creturn%[1]c%[2]c}%[1]c%[2]cif path[len(path) - 1] != %[4]cSully.go%[4]c {%[1]c%[2]c%[2]ci--%[1]c%[2]c}%[1]c%[2]ca := %[4]c%[3]s%[4]c%[1]c%[2]cioutil.WriteFile(%[4]cSully_%[4]c+strconv.Itoa(i)+%[4]c.go%[4]c, []byte(fmt.Sprintf(a, 10, 9, a, 34, i)), 0644)%[1]c%[2]cexec.Command(%[4]cgo%[4]c, %[4]cbuild%[4]c, %[4]cSully_%[4]c+strconv.Itoa(i)+%[4]c.go%[4]c).Run()%[1]c%[2]cexec.Command(%[4]c./Sully_%[4]c + strconv.Itoa(i)).Run()%[1]c}%[1]c"
	ioutil.WriteFile("Sully_"+strconv.Itoa(i)+".go", []byte(fmt.Sprintf(a, 10, 9, a, 34, i)), 0644)
	exec.Command("go", "build", "Sully_"+strconv.Itoa(i)+".go").Run()
	exec.Command("./Sully_" + strconv.Itoa(i)).Run()
}
