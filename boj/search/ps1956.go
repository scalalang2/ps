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

var V int
var E int

var graph [][]int
var dist [][]int

func main() {
	scanf("%d %d\n", &V, &E)

	graph = make([][]int, V+1)
	dist = make([][]int, V+1)
	for i := 0; i <= V; i++ {
		graph[i] = make([]int, V+1)
		dist[i] = make([]int, V+1)
	}

	for i := 0; i <= V; i++ {
		for j := 0; j <= V; j++ {
			dist[i][j] = 1<<31 - 1
		}
	}

	for i := 0; i < E; i++ {
		var a int
		var b int
		var c int
		scanf("%d %d %d\n", &a, &b, &c)
		dist[a][b] = c
	}

	for k := 1; k <= V; k++ {
		for i := 1; i <= V; i++ {
			for j := 1; j <= V; j++ {
				if dist[i][j] > dist[i][k]+dist[k][j] {
					dist[i][j] = dist[i][k] + dist[k][j]
				}
			}
		}
	}

	ret := 1<<31 - 1
	for k := 1; k <= V; k++ {
		if dist[k][k] < ret {
			ret = dist[k][k]
		}
	}

	if ret == 1<<31-1 {
		fmt.Println(-1)
	} else {
		fmt.Println(ret)
	}
}
