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

var arr [][]int
var dp [][]int
var left []int
var right []int

func main() {
	var n int
	var m int
	scanf("%d %d", &n, &m)

	left := make([]int, m+1)
	right := make([]int, m+1)

	arr := make([][]int, n+1)
	dp := make([][]int, n+1)
	for i := 0; i < n; i++ {
		arr[i] = make([]int, m+1)
		dp[i] = make([]int, m+1)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			var temp int
			scanf("%d", &temp)
			arr[i+1][j+1] = temp
		}
	}

	for i := 1; i < m+1; i++ {
		dp[1][i] = dp[1][i-1] + arr[1][i]
	}

	for i := 2; i < n+1; i++ {
		left[m] = dp[i-1][m] + arr[i][m]
		right[1] = dp[i-1][1] + arr[i][1]

	}

