package main

import (
	"fmt"
	"os"
	"regexp"
	"strings"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Wrong arguments")
		os.Exit(1)
	}
	arg := strings.Replace(os.Args[1], " ", "", -1)
	// fmt.Println(arg)

	match, _ := regexp.MatchString(`(\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^1[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^2|\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^1|\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0)\=(\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^1[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^2|\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^1|\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0)`, arg)
	if (strings.Index(arg, "X^1") == -1 && strings.Index(arg, "X^2") == -1) || match == false {
		fmt.Println("Wrong arguments")
		os.Exit(1)
	}

	equ := strings.Split(arg, "=")
	fmt.Println(equ[0])

	re1, _ := regexp.Compile(`(\-?[0-9]+|\-?[0-9]+\.[0-9]+)\*X\^[0-2][+-](\-?[0-9]+|\-?[0-9]+\.[0-9]+)\*X\^[0-2][+-](\-?[0-9]+|\-?[0-9]+\.[0-9]+)\*X\^[0-2]`)
	result := re1.FindStringSubmatch(equ[0])

	for k, v := range result {
		fmt.Printf("%d. %s\n", k, v)
	}
}
