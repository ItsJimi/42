package main

import (
	"fmt"
	"math"
	"os"
	"regexp"
	"strconv"
	"strings"
)

func parseNbr(tab [][]string, x int, y int) float64 {
	if len(tab) < x+1 {
		return 0
	}

	nbr, _ := strconv.ParseFloat(tab[x][y], 64)
	return nbr
}

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Wrong arguments")
		os.Exit(1)
	}
	arg := strings.Replace(os.Args[1], " ", "", -1)
	fmt.Println(arg)

	match, _ := regexp.MatchString(`(\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^1[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^2|\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^1|\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0)\=(\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^1[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^2|\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0[+-]([0-9]+|[0-9]+\.[0-9]+)\*X\^1|\-?([0-9]+|[0-9]+\.[0-9]+)\*X\^0)`, arg)
	if (strings.Index(arg, "X^1") == -1 && strings.Index(arg, "X^2") == -1) || match == false {
		fmt.Println("Wrong arguments")
		os.Exit(1)
	}

	equ := strings.Split(arg, "=")

	re1, _ := regexp.Compile(`(\-?[0-9]+|\-?[0-9]+\.[0-9]+)\*X\^[0-2]`)
	leftSide := re1.FindAllStringSubmatch(equ[0], -1)
	rightSide := re1.FindAllStringSubmatch(equ[1], -1)

	p0 := parseNbr(leftSide, 0, 1) - parseNbr(rightSide, 0, 1)
	p1 := parseNbr(leftSide, 1, 1) - parseNbr(rightSide, 1, 1)
	p2 := parseNbr(leftSide, 2, 1) - parseNbr(rightSide, 2, 1)

	// fmt.Println(p0)
	// fmt.Println(p1)
	// fmt.Println(p2)
	// fmt.Printf("%f * X^0 + %f * X^1 + %f * X^2 = 0", p0, p1, p2)

	result := p1*p1 - 4*p2*p0
	fmt.Println(result)
	solve1 := (-p1 - math.Sqrt(result)) / (2 * p2)
	solve2 := (-p1 + math.Sqrt(result)) / (2 * p2)
	fmt.Println(solve1)
	fmt.Println(solve2)
}

/*

b * b - 4 * a * c

*/
