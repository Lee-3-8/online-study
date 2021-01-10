'use strict'

class CacheManager {
  constructor() {
    if(!CacheManager.instance) {
      // 인스턴스가 존재하지 않는경우 
        this._cache = [] //내부 접근만 하므로 _붙임
        CacheManager.instance = this
    }

    return CacheManager.instance
  }
}

const instance = new CacheManager()
Object.freeze(instance) 
// const로 선언한 객체의 내부값은 변경가능하다 근데 freeze함수를 사용하면 내부값도 불변이됨