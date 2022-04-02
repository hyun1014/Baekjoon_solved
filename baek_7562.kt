package com.study

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val testCount = br.readLine().toInt()
    for (tcase in 0 until testCount) {
        val l = br.readLine().toInt()
        val start = br.readLine().split(" ").map { it.toInt() }
        val target = br.readLine().split(" ").map { it.toInt() }
        println(findDepth(Pair(start[0], start[1]), Pair(target[0], target[1]), l))
    }
}

fun findDepth(start: Pair, target: Pair, l: Int): Int {
    val dx = arrayOf(-1, -2, -2, -1, 1, 2, 2, 1)
    val dy = arrayOf(-2, -1, 1, 2, 2, 1, -1, -2)
    val visitedSet = mutableSetOf<Int>()
    val queue = LinkedList<Pair>()
    var depth = 0
    var prev = 1
    var next = 0
    queue.add(start)
    visitedSet.add(start.x * 1000 + start.y)

    while (!queue.isEmpty()) {
        val current = queue.poll()
        prev--
        if (current.equals(target)) {
            break
        }
        for (i in 0 until 8) {
            val nx = current.x + dx[i]
            val ny = current.y + dy[i]
            if (nx in 0 until l && ny in 0 until l && !visitedSet.contains(nx * 1000 + ny)) {
                queue.add(Pair(nx, ny))
                visitedSet.add(nx * 1000 + ny)
                next++
            }
        }
        if (prev == 0) {
            depth++
            prev = next
            next = 0
        }
    }
    return depth
}

data class Pair(val x: Int, val y: Int)