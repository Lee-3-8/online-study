'use strict'

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

