fun main() = with(System.`in`.bufferedReader()) {
    val nm = readLine().split(" ").map{it.toInt()}.toMutableList()
    val n = nm[0]
    val m = nm[1]

    var G = Array(n) { Array(m) { 0 } }
    var visited = Array(n) { Array(m) { false } }

    for(i in 0 until n) {
        var j = 0
        readLine().chars().forEach({
            G[i][j] = it.toInt() - '0'.code
            j++
        })
    }

    var dx = arrayOf(0, 0, 1, -1)
    var dy = arrayOf(1, -1, 0, 0)

    val queue = ArrayDeque<Pair<Int, Int>>();
    for(i in 0 until m) {
        if(G[0][i] == 0) {
            queue.addLast(Pair(0, i))
            visited[0][i] = true
        }
    }

    while(queue.isNotEmpty()) {
        val (y, x) = queue.removeFirst()

        for(i in 0 until 4) {
            val nx = x + dx[i]
            val ny = y + dy[i]
            if(nx < 0 || nx >= m || ny <0 || ny >= n) continue
            if(visited[ny][nx]) continue
            if(G[ny][nx] == 1) continue

            visited[ny][nx] = true
            queue.addLast(Pair(ny,nx))
        }
    }

    for(i in 0 until m) {
        if(visited[n-1][i]) {
            println("YES")
            return
        }
    }

    println("NO")
}