// 백준 1647 - 도시 분할 계획

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

var parent map[int]int
var ans int

type Edge struct {
	From int
	To   int
	Cost int
}

func find(node int) int {
	if parent[node] == node {
		return node
	} else {
		p := find(parent[node])
		parent[node] = p
		return p
	}
}

func union(a int, b int) bool {
	p1 := find(a)
	p2 := find(b)
	if p1 == p2 {
		return false
	}

	parent[p1] = p2
	return true
}

func main() {
	var n int
	var m int
	scanf("%d %d\n", &n, &m)

	parent = make(map[int]int)
	arr := make([]Edge, m)

	for i := 0; i < m; i++ {
		var from int
		var to int
		var cost int
		scanf("%d %d %d\n", &from, &to, &cost)

		arr[i] = Edge{from, to, cost}
		parent[from] = from
		parent[to] = to
	}

	sort.Slice(arr, func(i, j int) bool {
		return arr[i].Cost < arr[j].Cost
	})

	v := 0
	for i := 0; i < m; i++ {
		if union(arr[i].From, arr[i].To) {
			ans += arr[i].Cost
			v += 1
			if v == n-2 {
				break
			}
		}
	}

	fmt.Println(ans)
}
