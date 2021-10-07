private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val t = readInt()
    for (tt in 1..t) {
        val s = readLn()
        var lseen = false; var rseen = false
        for (c in s) {
            if (c == '<') {lseen = true}
            if (c == '>') {rseen = true}
        }
        if (lseen && !rseen) {
            println("<")
        }
        if (!lseen && rseen) {
            println(">")
        }
        if (lseen && rseen) {
            println("?")
        }
        if (!lseen && !rseen) {
            println("=")
        }
    }

}