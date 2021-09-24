package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func main() {
	var n int
	var m int
	scanf("%d %d\n", &n, &m)

	less := make([]int, 0)
	grt := make([]int, 0)

	for i := 0; i < n; i++ {
		var temp int
		scanf("%d", &temp)
		if temp < 0 {
			less = append(less, temp)
		} else {
			grt = append(grt, temp)
		}
	}

	// 좌측정렬
	sort.Slice(less, func(i, j int) bool {
		// compareSort 개념, 작은게 먼저 발견되어야 한다.
		return less[i] < less[j]
	})

	sort.Slice(grt, func(i, j int) bool {
		// compareSort 개념, 큰게 먼저 발견되어야 한다.
		return grt[i] > grt[j]
	})

	ans := 0
	temp := 0
	maxLess := 0
	if len(less) > 0 {
		maxLess = less[0] * -1
	}
	maxGrt := 0
	if len(grt) > 0 {
		maxGrt = grt[0]
	}

	for _, v := range less {
		if temp == 0 {
			ans += (v * -1) * 2
		}

		temp += 1
		temp %= m
	}

	temp = 0
	for _, v := range grt {
		if temp == 0 {
			ans += v * 2
		}

		temp += 1
		temp %= m
	}

	if maxLess > maxGrt {
		ans -= maxLess
	} else {
		ans -= maxGrt
	}

	fmt.Println(ans)
}
