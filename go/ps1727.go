package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

var n int
var m int
var mans []int
var womans []int
var d [][]int

func main() {
	var n int
	var m int
	scanf("%d %d\n", &n, &m)

	mans = make([]int, n+1)
	womans = make([]int, m+1)
	d = make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		d[i] = make([]int, m+1)
	}

	for i := 1; i <= n; i++ {
		if i == n {
			scanf("%d\n", &mans[i])
		} else {
			scanf("%d", &mans[i])
		}
	}

	for i := 1; i <= m; i++ {
		if i == m {
			scanf("%d\n", &womans[i])
		} else {
			scanf("%d", &womans[i])
		}
	}

	sort.Slice(mans, func(i, j int) bool {
		return mans[i] < mans[j]
	})

	sort.Slice(womans, func(i, j int) bool {
		return womans[i] < womans[j]
	})

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			d[i][j] = d[i-1][j-1] + int(math.Abs(float64(mans[i]-womans[j])))
			if i > j {
				d[i][j] = int(math.Min(float64(d[i][j]), float64(d[i-1][j])))
			}
			if i < j {
				d[i][j] = int(math.Min(float64(d[i][j]), float64(d[i][j-1])))
			}
		}
	}

	fmt.Println(d[n][m])
}
