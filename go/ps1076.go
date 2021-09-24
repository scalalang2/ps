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

func main() {
	plus := make(map[string]int)
	mul := make(map[string]int)
	arr := []string{"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"}

	i := 0
	j := 1
	for _, v := range arr {
		plus[v] = i
		mul[v] = j
		i += 1
		j *= 10
	}

	var a string
	var b string
	var c string
	scanf("%s\n", &a)
	scanf("%s\n", &b)
	scanf("%s\n", &c)

	num, _ := strconv.Atoi(strconv.Itoa(plus[a]) + strconv.Itoa(plus[b]))
	fmt.Println(num * mul[c])
}
