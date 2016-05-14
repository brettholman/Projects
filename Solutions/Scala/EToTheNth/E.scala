import java.text.DecimalFormat

object E {
  private var formatter = new DecimalFormat("#.###")

  private def isAllDigits(x: String) = x forall Character.isDigit

  def main(args: Array[String]): Unit = {
    if(args.length != 1) {
      println("There must be exactly one argument passed to this program")
      return
    }

    if(args(0)(0) != '-') {
      if(!isAllDigits(args(0))) {
        println("You can not pass a non numeric value into this program.")
        println(args(0) + " Is not a valid input. ")
        return
      }
    }

    var limit = 0

    try {
      limit = args(0).toInt
    } catch {
      case e : Exception => {
        return
      }
    }

    if(limit < 0) {
      println("This program does not support negative numbers")
      return
    }

    if(limit > 15) {
      println("The program limits to 15 numbers after the decimal place.")
      return
    }

    formatter.setMaximumFractionDigits(limit)
    formatter.setMinimumFractionDigits(limit)

    println("The output is: \n" + formatter.format(Math.exp(1)))
  }
}
