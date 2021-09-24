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

var tree map[string]string
var friends map[string]int

func initialize() {
	tree = make(map[string]string)
	friends = make(map[string]int)
}

func find(node string) string {
	if node == tree[node] {
		return node
	} else {
		parent := find(tree[node])
		tree[node] = parent
		return parent
	}
}

func union(a, b string) {
	p1 := find(a)
	p2 := find(b)

	if p1 != p2 {
		tree[p2] = p1
		friends[p1] += friends[p2]
	}
}

func main() {
	var t int
	scanf("%d\n", &t)

	for t > 0 {
		var n int
		scanf("%d\n", &n)

		initialize()

		for i := 0; i < n; i++ {
			var a string
			var b string

			scanf("%s %s\n", &a, &b)
			if _, ok := tree[a]; !ok {
				tree[a] = a
			}

			if _, ok := tree[b]; !ok {
				tree[b] = b
			}

			if friends[a] == 0 {
				friends[a] = 1
			}

			if friends[b] == 0 {
				friends[b] = 1
			}

			union(a, b)
			fmt.Println(friends[find(b)])
		}

		t -= 1
	}
}
