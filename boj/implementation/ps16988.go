package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

// 그룹핑 <키> = <빈 공간의 개수>
var groups map[int]int
var groupSize map[int]int

// 바둑판 테이블
var table [][]int
var visited [][]bool
var chk map[string]bool
var dx []int
var dy []int
var n int
var m int

func clearVisit() {
	visited = make([][]bool, n)
	for i := 0; i < n; i++ {
		visited[i] = make([]bool, m)
	}
}

func createGroups() {
	clearVisit()
	groups = make(map[int]int)
	groupSize = make(map[int]int)
	group := 1
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if visited[i][j] {
				continue
			}
			if table[i][j] == 2 {
				chk = make(map[string]bool)
				dfs(i, j, group)
				group += 1
			}
		}
	}
}

func dfs(i, j, g int) {
	emptyCell := 0
	for k := 0; k < 4; k++ {
		ny := i + dy[k]
		nx := j + dx[k]

		if ny < 0 || ny >= n || nx < 0 || nx >= m {
			continue
		}

		if table[ny][nx] == 2 && visited[ny][nx] {
			continue
		}
		visited[ny][nx] = true

		if table[ny][nx] == 2 {
			dfs(ny, nx, g)
			groupSize[g] = groupSize[g] + 1
		} else if table[ny][nx] == 0 {
			text := "y:" + strconv.Itoa(ny) + "x:" + strconv.Itoa(nx)
			if chk[text] {
				continue
			}
			chk[text] = true
			emptyCell += 1
		}
	}

	groups[g] = groups[g] + emptyCell
}

func main() {
	scanf("%d %d\n", &n, &m)
	table = make([][]int, n)
	dx = []int{0, 0, 1, -1}
	dy = []int{1, -1, 0, 0}

	for i := 0; i < n; i++ {
		table[i] = make([]int, m)
		for j := 0; j < m; j++ {
			if j == m-1 {
				scanf("%d\n", &table[i][j])
			} else {
				scanf("%d", &table[i][j])
			}
		}
	}

	createGroups()

	ret1 := 0
	ret2 := 0
	ret3 := 0
	for k, v := range groups {
		if v == 1 {
			if groupSize[k] >= ret2 {
				ret2 = groupSize[k]

				if ret2 >= ret1 {
					temp := ret1
					ret1 = ret2
					ret2 = temp
				}
			}
		} else if v == 2 {
			if groupSize[k] >= ret3 {
				ret3 = groupSize[k]
			}
		}
	}

	if ret1 + ret2 > ret3 {
		fmt.Println(ret1 + ret2)
	} else {
		fmt.Println(ret3)
	}
}
