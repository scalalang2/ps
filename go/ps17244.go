// 백준 17244 - 아 맞다 우산

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

var WALLS int
var START int
var OBJECT int
var ROAD int
var END int

var state map[string]bool

type Pos struct {
	X         int
	Y         int
	CurrState int
	Walk      int
	NOfObj    int
}

// 상태 정보를 문자열로 가진다.
// x2y201101, 장애물이 최대 5개이기 때문에 5개를 다 먹는다면 11111 값으로 들어와야함
func make_state(x, y, curr_state int) string {
	return "x" + strconv.Itoa(x) + "_" + "y" + strconv.Itoa(y) + "_" + strconv.Itoa(curr_state)
}

func main() {
	WALLS = -3
	START = -1
	OBJECT = 0
	ROAD = -2
	END = -4

	var n int
	var m int
	scanf("%d %d\n", &n, &m)

	state = make(map[string]bool)
	arr := make([][]int, m)
	for i := 0; i < m; i++ {
		arr[i] = make([]int, n)
	}

	var sx int
	var sy int

	// 맵을 자료구조로 만드는 과정
	obj := 0
	for i := 0; i < m; i++ {
		var text string
		scanf("%s\n", &text)
		for j, rune := range text {
			if rune == '#' {
				arr[i][j] = WALLS
			} else if rune == 'X' {
				arr[i][j] = 1 << obj
				obj += 1
			} else if rune == '.' {
				arr[i][j] = ROAD
			} else if rune == 'S' {
				arr[i][j] = START
				sx = j
				sy = i
			} else if rune == 'E' {
				arr[i][j] = END
			}
		}
	}

	ans := 0

	dy := []int{0, 0, 1, -1}
	dx := []int{-1, 1, 0, 0}

	queue := make([]Pos, 0)
	queue = append(queue, Pos{sx, sy, 0, 0, 0})
	state[make_state(sx, sy, 0)] = true

	chk_state := 0
	for i := 0; i < obj; i++ {
		chk_state = chk_state | (1 << i)
	}

	// BFS 수행
	for len(queue) > 0 {
		p := queue[0]
		queue = queue[1:]

		// 11111 값으로 다 먹었다면
		if p.CurrState == chk_state && arr[p.Y][p.X] == END {
			ans = p.Walk
			break
		}

		for i := 0; i < 4; i++ {
			nx := p.X + dx[i]
			ny := p.Y + dy[i]

			if nx < 0 || nx >= n || ny < 0 || ny >= m {
				continue
			}

			if arr[ny][nx] == WALLS {
				continue
			}

			new_state := p.CurrState
			new_obj := p.NOfObj
			walk := p.Walk + 1
			if arr[ny][nx] >= 0 {
				new_obj += 1
				new_state = new_state | arr[ny][nx]
			}

			state_mask := make_state(nx, ny, new_state)
			if state[state_mask] {
				continue
			}

			state[state_mask] = true
			queue = append(queue, Pos{nx, ny, new_state, walk, new_obj})
		}
	}

	fmt.Println(ans)
}
