// 백준 7453 - 합이 0인 네 정수

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
	ans := 0
	scanf("%d\n", &n)

	a := make([]int, n)
	b := make([]int, n)
	c := make([]int, n)
	d := make([]int, n)

	_map := make(map[int]int)

	for i := 0; i < n; i++ {
		scanf("%d %d %d %d\n", &a[i], &b[i], &c[i], &d[i])
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			_map[c[i]+d[j]] = _map[c[i]+d[j]] + 1
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			target := (a[i] + b[j]) * -1
			ans += _map[target]
		}
	}

	fmt.Println(ans)

}
