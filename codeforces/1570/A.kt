private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val t = readInt()
    for (tt in 1..t) {
        val (a, b) = readInts()
        println(a + b)
    }
}