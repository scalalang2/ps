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

var size int
var arr []int

func construct(n int) {
	size = 1
	for {
		size <<= 1
		if size > n {
			break
		}
	}

	size *= 2

	arr = make([]int, size)
}

func update(i int, val int) {
	i += (size / 2) - 1
	arr[i] = val

	for i > 1 {
		i /= 2
		arr[i] = arr[i*2] + arr[i*2+1]
	}
}

func sum(l int, r int, idx int, nodeL int, nodeR int) int {
	if r < nodeL || nodeR < l {
		return 0
	}
	if l <= nodeL && nodeR <= r {
		return arr[idx]
	}

	mid := (nodeL + nodeR) / 2
	return sum(l, r, idx*2, nodeL, mid) + sum(l, r, idx*2+1, mid+1, nodeR)
}

func main() {
	var n int
	var m int
	var k int
	scanf("%d %d %d\n", &n, &m, &k)
	construct(n)

	for i := 0; i < n; i++ {
		var num int
		scanf("%d\n", &num)
		update(i+1, num)
	}

	for i := 0; i < m+k; i++ {
		var q int
		var a int
		var b int
		scanf("%d %d %d\n", &q, &a, &b)
		if q == 1 {
			update(a, b)
		} else {
			ret := sum(a-1, b-1, 1, 0, size/2-1)
			fmt.Println(ret)
		}
	}
}
