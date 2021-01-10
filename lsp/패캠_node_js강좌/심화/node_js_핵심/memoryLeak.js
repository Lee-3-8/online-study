'use strict'

function study (value1, value2) {
  this.value1 = value1
  this.value2 = value2

  this.func1 = () => {
    console.log()
  }

  //this.prototype.func1
}

const problem = new study(undefined, undefined)
console.log(problem.func1())
/* 함수는 최상위 객체로 취급됨
내부에 있는 클로저함수를 계속가지게 되면 클로저안에 클로저를 또 선언한다?

*/