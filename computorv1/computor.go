package main

import (
	"fmt"
	"os"
	"regexp"
	"strconv"
	"strings"
)

func parseNbr(tab [][]string, x int) float64 {
	if len(tab) < x+1 {
		return 0
	}

	nbr, _ := strconv.ParseFloat(tab[x][1], 64)
	return nbr
}

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Wrong arguments")
		os.Exit(1)
	}

	arg := strings.Replace(os.Args[1], " ", "", -1)
	match, _ := regexp.MatchString(`(\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^1[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^2|\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^1|\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0)\=(\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^1[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^2|\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^1|\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0)`, arg)
	if (strings.Index(arg, "X^1") == -1 && strings.Index(arg, "X^2") == -1) || match == false {
		fmt.Println("Wrong arguments")
		os.Exit(1)
	}

	equ := strings.Split(arg, "=")
	re1, _ := regexp.Compile(`(\-?[0-9]+|\-?[0-9]+\.[0-9]+)\*X\^[0-2]`)
	leftSide := re1.FindAllStringSubmatch(equ[0], -1)
	rightSide := re1.FindAllStringSubmatch(equ[1], -1)

	var p []float64
	for i := 0; i < len(leftSide); i++ {
		p = append(p, parseNbr(leftSide, i)-parseNbr(rightSide, i))
	}

	fmt.Println(p)

	// fmt.Printf("Reduced form: %s * X^0 + %s * X^1 + %s * X^2 = 0", strconv.FormatFloat(p0, 'f', -1, 64), strconv.FormatFloat(p1, 'f', -1, 64), strconv.FormatFloat(p2, 'f', -1, 64))

	// result := p1*p1 - 4*p2*p0
	// fmt.Println(result)
	// solve1 := (-p1 - math.Sqrt(result)) / (2 * p2)
	// solve2 := (-p1 + math.Sqrt(result)) / (2 * p2)
	// fmt.Println(solve1)
	// fmt.Println(solve2)
}

/*

b * b - 4 * a * c

*/
