'use strict'
// Class
class CacheManager {
  //typescript에선 private , public 도 지원가능 
  constructor(){//constructor는 비동기문법 불가능 
    this.config = [];
  }

  addConfig(obj = {}){
    this.config.push(obj);
  }

  getConfig(){
    return this.config;
  }

}

const cacheManager = new CacheManager();
