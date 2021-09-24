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

func main() {
	var n int
	scanf("%d\n", &n)
	arr := make([]int, n)

	for i := 0; i < n; i++ {
		var el int
		if i == n-1 {
			scanf("%d\n", &el)
		} else {
			scanf("%d", &el)
		}
		arr[i] = el
	}

	if n == 1 {
		fmt.Println("A")
	} else if n == 2 {
		if arr[0] == arr[1] {
			fmt.Println(arr[0])
		} else {
			fmt.Println("A")
		}
	} else {
		a := 0
		if arr[0] == arr[1] {
			a = 0
		} else {
			a = (arr[2] - arr[1]) / (arr[1] - arr[0])
		}

		b := arr[1] - a*arr[0]
		for i := 0; i < n-1; i++ {
			nxt := a*arr[i] + b
			if arr[i+1] != nxt {
				fmt.Println("B")
				os.Exit(0)
			}
		}

		fmt.Println(a*arr[n-1] + b)
	}
}
