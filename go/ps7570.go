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
	dp := make([]int, n+1)
	max := 0

	for i := 0; i < n; i++ {
		scanf("%d", &arr[i])
	}

	for i := 1; i < n+1; i++ {
		no := arr[i-1]
		dp[no] = dp[no-1] + 1
		if dp[no] > max {
			max = dp[no]
		}
	}

	fmt.Println(n - max)

	// fmt.Println(n - len(lis))
}
