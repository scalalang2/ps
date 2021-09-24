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
	var m int

	scanf("%d\n", &n)
	scanf("%d\n", &m)

	dist := make([][]int, n+1)
	for i := 1; i <= n; i++ {
		dist[i] = make([]int, n+1)
		for j := 1; j <= n; j++ {
			dist[i][j] = 1<<31 - 1
		}
		dist[i][i] = 0
	}

	for i := 1; i <= m; i++ {
		var u int
		var v int
		scanf("%d %d\n", &u, &v)
		dist[u][v] = 1
	}

	for k := 1; k <= n; k++ {
		for i := 1; i <= n; i++ {
			for j := 1; j <= n; j++ {
				if dist[i][k]+dist[k][j] == 2 {
					dist[i][j] = 1
				}
			}
		}
	}

	for i := 1; i <= n; i++ {
		ans := 0
		for j := 1; j <= n; j++ {
			if dist[i][j] != 1<<31-1 {
				ans += dist[i][j]
			}

			if dist[j][i] != 1<<31-1 {
				ans += dist[j][i]
			}
		}
		fmt.Println(n - ans - 1)
	}
}
