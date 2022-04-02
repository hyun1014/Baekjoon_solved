package com.study

import java.util.LinkedList

val br by lazy { System.`in`.bufferedReader() }

fun main(args: Array<String>) {
    val testCount = br.readLine().toInt()
    for (tcase in 0 until testCount) {
        val l = br.readLine().toInt()
        val start = br.readLine().split(" ").map { it.toInt() }
        val target = br.readLine().split(" ").map { it.toInt() }
        println(findDepth(start[0] to start[1], target[0] to target[1], l))
    }
}

fun findDepth(start: Pair<Int, Int>, target: Pair<Int, Int>, l: Int): Int {
    val moving = arrayOf(-2 to -1, -1 to -2, 1 to -2, 2 to -1, 2 to 1, 1 to 2, -1 to 2, -2 to 1)
    val visitedSet = mutableSetOf<Int>()
    val queue = LinkedList<Pair<Int, Int>>()
    var depth = 0
    var prev = 1
    var next = 0
    queue.add(start)
    visitedSet.add(start.first * 1000 + start.second)


    while (queue.isNotEmpty()) {
        val current = queue.poll()
        prev--
        if (current.equals(target)) {
            break
        }
        for ((dx, dy) in moving) {
            val nx = current.first + dx
            val ny = current.second + dy
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