// 백준 1300 - k번째 수 찾기

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
	var k int
	scanf("%d\n", &n)
	scanf("%d\n", &k)

	s := 0
	e := k
	ret := 0

	for s <= e {
		cnt := 0
		mid := (s + e) / 2

		for i := 1; i <= n; i++ {
			if mid/i < n {
				cnt += mid / i
			} else {
				cnt += n
			}
		}

		if cnt < k {
			s = mid + 1
		} else {
			ret = mid
			e = mid - 1
		}
	}

	fmt.Println(ret)
}
