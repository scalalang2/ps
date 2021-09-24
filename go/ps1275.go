// 5 2
// 1 2 3 4 5
// 2 3 3 1
// 3 5 4 1

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

var arr []int64
var size int

func create(n int) {
	size = 1
	for size < n {
		size <<= 1
	}
	size *= 2
	arr = make([]int64, size)
}

func update(i int, val int) {
	i += (size / 2)
	arr[i] = int64(val)
	for i > 1 {
		i /= 2
		arr[i] = arr[i*2] + arr[i*2+1]
	}
}

func sum(L int, R int, nodeNum int, arrL int, arrR int) int64 {
	if arrR < L || R < arrL {
		return 0
	}
	if L <= arrL && arrR <= R {
		return arr[nodeNum]
	}
	mid := (arrL + arrR) / 2
	return sum(L, R, nodeNum*2, arrL, mid) + sum(L, R, nodeNum*2+1, mid+1, arrR)
}

func main() {
	var n int
	var q int
	scanf("%d %d\n", &n, &q)
	create(n)

	for i := 0; i < n; i++ {
		var num int
		if i == n-1 {
			scanf("%d\n", &num)
		} else {
			scanf("%d", &num)
		}
		update(i, num)
	}

	for i := 0; i < q; i++ {
		var x int
		var y int
		var a int
		var b int
		scanf("%d %d %d %d\n", &x, &y, &a, &b)
		if x <= y {
			fmt.Println(sum(x-1, y-1, 1, 0, size/2-1))
		} else {
			fmt.Println(sum(y-1, x-1, 1, 0, size/2-1))
		}
		update(a-1, b)
	}
}
