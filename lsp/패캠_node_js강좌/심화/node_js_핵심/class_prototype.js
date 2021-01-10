'use strict'

// 프로토타입을 사용한 코드

function fullstack (backend, frontend) {
  this.backend = backend
  this.frontend = frontend

  //내부 클로저 함수 사용
  fullstack.prototype.getBackend = () => this.backend
  fullstack.prototype.setBackend = () => this.backend = backend
  //get 과 set이 있음 set으로써 데이터를 설정해주고 사용

  fullstack.prototype.getFrontend = () => this.frontend
  fullstack.prototype.setFrontend = () => this.frontend = frontend

}

const Fullstack = new fullstack('js','js')
console.log(Fullstack.getBackend(), Fullstack.getFrontend()) // js , js 출력

//클래스를 사용한 코드

class Fullstack {
  constructor(backend , frontend) {
    //constructor에서는 await 키워드는 사용 불가능함
    //클래스 내부에는 비동기 코드가 안되는가? -> no!! static factory method 패턴을 사용
      this.backend = backend
      this.frontend = frontend
  }

  getBackend () {
    return this.backend
  }

  getFrontend () {
    return this.frontend
  }

  setBackend (backend) {
    this.backend = backend
  }

  setFrontend (frontend) {
    this.frontend = frontend
  } 
  
}

const fullstack = new Fullstack('js' , 'js')

// js class를 사용하는것이 실제로 객체지향형 프로그래밍에 더 가깝다.