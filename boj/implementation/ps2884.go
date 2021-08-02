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
	var hour int
	var minutes int
	scanf("%d %d", &hour, &minutes)

	if minutes >= 45 {
		fmt.Println(hour, minutes-45)
	} else {
		h := hour - 1
		if h < 0 {
			h = 23
		}
		fmt.Println(h, 60-(45-minutes))
	}
}
