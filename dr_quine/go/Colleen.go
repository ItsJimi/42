package main
import "fmt"

/*
** Bacon
*/

func test() int { return 0 }

func main() {
	/*
	** Cheese
	*/
	var a = "package main%[1]cimport %[4]cfmt%[4]c%[1]c%[1]c/*%[1]c** Bacon%[1]c*/%[1]c%[1]cfunc test() int { return 0 }%[1]c%[1]cfunc main() {%[1]c%[2]c/*%[1]c%[2]c** Cheese%[1]c%[2]c*/%[1]c%[2]cvar a = %[4]c%[3]c%[4]c%[1]c%[2]ctest()%[1]c%[2]cfmt.Printf(a, 10, 9, a, 34)%[1]c}%[1]c%[1]c"
	test()
	fmt.Printf(a, 10, 9, a, 34)
}
