package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func fact(n int) int64 {
	var ret int64
	ret = int64(n)
	for n > 1 {
		n -= 1
		ret *= int64(n)
		fmt.Println(ret)
	}
	return ret
}

func main() {
	var n int
	var m int
	scanf("%d %d\n", &n, &m)
	fmt.Println(fact(n))
	fmt.Println(fact(n - m))
	fmt.Println(fact(m))

	// ans := fact(n) / (fact(n-m) * fact(m))
	// fmt.Println(ans)
}
