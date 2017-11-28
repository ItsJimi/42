package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Wrong arguments")
		os.Exit(1)
	}
	arg := strings.Replace(os.Args[1], " ", "", -1)
	fmt.Println(arg)

	equ := strings.Split(arg, "=")
	if len(equ) != 2 {
		fmt.Println("Wrong arguments")
		os.Exit(1)
	}
}
