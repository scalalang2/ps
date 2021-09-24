package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc.Split(bufio.ScanWords)
	a, b, c := nextInt(), nextInt(), nextInt()

	// fmt.Println(a, b, c)

	num := float64(a) / float64(b)

	for c > 0 {
		num *= 10
		c -= 1
	}

	fmt.Println(int(num) % 10)
}

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

func nextString() string {
	sc.Scan()
	text := sc.Text()
	return text
}

func nextInt() int {
	sc.Scan()
	text := sc.Text()
	v, _ := strconv.Atoi(text)
	return v
}

func nextInt64() int64 {
	sc.Scan()
	text := sc.Text()
	v, _ := strconv.ParseInt(text, 10, 64)
	return v
}
