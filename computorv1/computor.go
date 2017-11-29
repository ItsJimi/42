package main

import (
	"fmt"
	"math"
	"os"
	"regexp"
	"strconv"
	"strings"
)

/*
 * Get max length between two float64 arrays
 */
func getMaxLength(a []float64, b []float64) int {
	var max int
	if len(a) > len(b) {
		max = len(a)
	} else {
		max = len(b)
	}
	return max
}

/*
 * Parse double string array to one float64 array with right value
 */
func parseTab(side [][]string) []float64 {
	power := 0
	for i := 0; i < len(side); i++ {
		value, _ := strconv.Atoi(side[i][2])
		if value > power {
			power = value
		}
	}
	var tab []float64
	for i := 0; i <= power; i++ {
		tab = append(tab, 0)
	}
	for i := 0; i < len(side); i++ {
		key, _ := strconv.Atoi(side[i][2])
		value, _ := strconv.ParseFloat(side[i][1], 64)
		tab[key] = value
	}
	return tab
}

/*
 * Parse float64 array to return 0 if value doesn't exist
 */
func parseNbr(tab []float64, x int) float64 {
	if len(tab) < x+1 {
		return 0
	}
	return tab[x]
}

/*
 * Print reduced form
 */
func printReduced(p []float64) {
	fmt.Printf("Reduced form: ")
	for i := 0; i < len(p); i++ {
		if p[i] == 0 {
			continue
		}
		var value string
		if strings.Index(strconv.FormatFloat(p[i], 'f', -1, 64), "-") == -1 && i != 0 {
			value = "+ " + strconv.FormatFloat(p[i], 'f', -1, 64)
		} else {
			value = strings.Replace(strconv.FormatFloat(p[i], 'f', -1, 64), "-", "- ", -1)
		}
		fmt.Printf("%s * X^%d ", value, i)
	}
	fmt.Printf("= 0\n")
}

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Wrong arguments")
		os.Exit(1)
	}

	arg := strings.Replace(os.Args[1], " ", "", -1)
	// match, _ := regexp.MatchString(``, arg)
	// if (strings.Index(arg, "X^1") == -1 && strings.Index(arg, "X^2") == -1) || match == false {
	// 	fmt.Println("Wrong arguments")
	// 	os.Exit(1)
	// }

	equ := strings.Split(arg, "=")
	re1, _ := regexp.Compile(`(\-?[0-9]+|\-?[0-9]+\.[0-9]+)\*X\^([0-9]+)`)
	leftSide := re1.FindAllStringSubmatch(equ[0], -1)
	rightSide := re1.FindAllStringSubmatch(equ[1], -1)

	left := parseTab(leftSide)
	right := parseTab(rightSide)
	// fmt.Println(left)
	// fmt.Println(right)

	var p []float64
	for i := 0; i < getMaxLength(left, right); i++ {
		p = append(p, parseNbr(left, i)-parseNbr(right, i))
	}

	fmt.Println(p)
	printReduced(p)
	fmt.Printf("Polynomial degree: %d\n", len(p)-1)
	if len(p) > 3 {
		fmt.Println("The polynomial degree is stricly greater than 2, I can't solve.")
		os.Exit(1)
	}
	if len(p) == 3 {
		delta := p[1]*p[1] - 4*p[2]*p[0]
		fmt.Printf("Delta: %f\n", delta)
		if delta < 0 {
			fmt.Println("Can't solve")
			os.Exit(1)
		} else if delta == 0 {
			result := -p[1] / 2 * p[2]
			fmt.Println("The solution is:")
			fmt.Println(result)
		} else {
			solve1 := (-p[1] - math.Sqrt(delta)) / (2 * p[2])
			solve2 := (-p[1] + math.Sqrt(delta)) / (2 * p[2])
			fmt.Println("The solution is:")
			fmt.Println(solve1)
			fmt.Println(solve2)
		}
	}
}

/*

1. a * X + b = c

x = (c - b) / a

2. a * X^2 + b * X + c = 0

Delta: b * b - 4 * a * c
Deltta < 0 -> Pas de solution
Delta = 0 -> -b / 2 * a
Delta > 0 -> (-b - sqrt(Delta)) / 2 * a || (-b + sqrt(Delta)) / 2 * a

*/
