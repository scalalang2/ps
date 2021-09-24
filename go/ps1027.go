package main

import (
	"bufio"
	"fmt"
	"math"
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
	b := make([]int, n)
	for i := 0; i < n; i++ {
		scanf("%d", &arr[i])
	}

	ans := 0
	for i := 0; i < n; i++ {
		e := math.MaxFloat64 * -1
		for j := i + 1; j < n; j++ {
			d := float64(arr[j]-arr[i]) / float64(j-i)
			if d > e {
				e = d
				b[i] += 1
				b[j] += 1
			}
		}
	}

	for _, v := range b {
		if v > ans {
			ans = v
		}
	}

	fmt.Println(ans)
}
