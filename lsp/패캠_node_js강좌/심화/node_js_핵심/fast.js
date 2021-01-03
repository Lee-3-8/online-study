// 'use strict' //엄격모드 : 컴파일시 좀더 엄격한 문법적용

// const obj = {
// 	title : 'node js 올인원 패키지'
// }



// function isEmptyobj (){
// 	if(obj.title){
// 		return true
// 	}else {
// 		return else;
// 	}	
// }

// isEmptyobj()




// ///최신문법으로

// const isEmptyobj1 = () => obj.title ? true : false;
// isEmptyobj1()


// // module.exports 
// function edit(){}
// function write(){}

// module.exports = {edit , write}

// //////////////EVERY 문법 /////////////////
// const arr  =[2,3,4]
// const isBiggerthanOne = arr.every(key => key > 1)
// //array에서 모든조건이 만족할때 실행 위 경우에는 2에서 바로 끝
// //프론트에서도 많이사용됨 

// console.log(isBiggerthanOne)


// /////////////find , include//////////

// const arr = ['node.js' , '올인원']

// const ret = arr.find(key => key == '올인원')//반환 : 올인원 
// const res = arr.includes('node.js');//반환 : true
// console.log(res);
// // 찾아서 실제로 사용할 데이터면 find , 있는지 유무 판단은 includes
// // 두가지를 구분지어 사용해야 데이터 누수를 방지할 수 있다.


// //////for each////

// //내부적으로 비동기적으로 실행되지않기때문에 주의해야함

// const arr = [1,2,3]
// const newArr = []
// // arr.forEach(item => console.log(item))
// arr.forEach(item =>{
// 	newArr.push(item)
// })
// //위코드는 스프레드 연산자로 클론하는게 가장 좋다


// //////map filter////////

// // const a = [1,2,3]
// // const b = a.map(x => x+1)
// // console.log(b)//2 3 4 

// const a = [1,2,3]
// const b = a.filter(x => x>1)
// console.log(b)//2,3 
// //주어진 조건을 만족하는 새로운 배열을 만든다.


// //////object.assign , spread ////
// const obj = {
// 	title: 'node js 올인원 패키지'
// }

// const newObj = {
// 	name : '패스트캠퍼스'
// }

// const ret = Object.assign({},obj,newObj);
// console.log(ret);
// //한개의 개체로 합쳐진다. 하지만 스프레드를 쓰자

// const ret = {
// 	...obj,
// 	...newObj
// }
// console.log(ret)
// //위코드와 같은 결과이다.

// const arr = [1,2,3]
// const newArr = [4,5,6]

// const ret = [
// 	...arr,
// 	...newArr
// ]

// console.log(ret)

// //배열에서도 사용가능하다.


// ///////set//////////
// //중복되는 자료를 없애는 set
// const test = new Set()//set 자료구조로 생성

// test.add(1)
// test.add(1)
// test.add(2)
// test.add(2)
// test.add(3)

// for(const item of test){
// 	console.log(item)
// }

// const ret = test.has(0)
// console.log(ret) // false
// //해당하는 자료구조에 데이터가 존재하는지 true or false 


// ////some////
// every는 다르게 최소 한가지이상만 만족하면 된다.

// const arr = [1, 2, 0 , -1 , -2]

// const res = arr.some(key => key < 0); //true
// console.log(res)


// /////template string///

// const detail = 'detail';
// let str = `node.js`
// str += `올인원 패키지 ${detail}`

// const int = 1
// str += `${str}의 값은 ${int}`;

// console.log`입력`


// ////string ///
// //js는 특정한 데이터 타입을 선언하지 않아도됨, typescript는 제외
// //그래서 타입말고 데이터가 변하는지 아닌지만 따지면됨

// let string = 'node.js 올인원 패키지'

// let isStartWith = string.startsWith('n');
// let isIncludes = string.includes('올인원');
// let isEndWith = string.endsWith('지');

// const checkIfContain = () =>{ 
// 	console.log(isEndWith);
// 	console.log('asdf');
// 	if (isStartWith && isIncludes && isEndWith){
// 		return true;
// 	}
// }

// checkIfContain()

// //Tyep Checking//
// const strig = 'node.js';
// const array = [];
// const obj = {};
// const num = 1;

// console.log(typeof strig);
// console.log(typeof array); //array도 더 상위객체인 object로 된다.
// console.log(typeof obj);
// console.log(typeof num);


// //Hoisting//

// //js 가 메모리에 함수를 미리저장하는 것을 말함

// function say(word) {
// 	console.log(word);

// }
// say('hi'); // hi

// ////////////////////////////
// say('hi'); // hi 똑같이 실행된다.
// function say(word) {
// 	console.log(word);

// }


// // IIFE //

// //내부 선언된 함수는 전역스코프를 오염시키지 않도록하고 , 외부에서도 함수내부로 침투할 수 없도록 한다.
// // 즉시실행함수를 생성하는 괄호를 해석해서 바로 실행함
// (function () {
// 	var lang = 'js';
// })();

// console.log(lang); //애러발생  외부로부터의 접근 이 불가능하다.

// let result = (function () {
// 	var lang = 'js';
// 	return lang;
// })();
// console.log(result); //실행결과만 나옴 

// // setInterval //

// setInterval(()=>{
// 	console.log('hi');
// },1000);//계속 반복해서 실행됨 1초마다 


// // Error Handling //

// try{
// 	a
// }catch(e){
// 	console.log('Err' + e);
// }

// //arrow function

// const add = (var1,var2) => console.log(var1+var2);
// //arrow function은 상위 객체의 this를 받아온다.

// // arrow function 연습문제

// const getDiscount = rate => price => rate * price
// //같은 코드
// var getDiscount1 = function getDiscount1(rate){
//   return function (price){
//     return rate*price;
//   };
// };

// const getTempercentoff = getDiscount(0.1);
// getTempercentoff(10000);
// getTempercentoff(123);
// getTempercentoff(123444);
// getTempercentoff(2000);

// getTempercentoff(price);

// //합성함수 개념 f(g())
// //내부적으로 클로저를 생성한다.
// getDiscount(10000, 0.1)

// // Class
// class CacheManager {
//   //typescript에선 private , public 도 지원가능 
//   constructor(){//constructor는 비동기문법 불가능 
//     this.config = []
//   }
// }

// const CacheManager = new CacheManager();

// Class Extends
// // Class 추가

// class Robot {
//   constructor(name){
//     this.name = name;
//   }

//   speack(){
//     console.log(`${this.name}`);
//   }
// }

// class Ai extends Robot {
//   constructor(name){
//     super(name);
//   }

//   walk(){
//     console.log(`walk : ${this.name}`);
//   }
// }

// // const robot = new Robot('hi');
// // robot.speack();

// const a =new Ai('hi');
// a.speack(); // 상속받은것도 사용가능하다.
// a.walk();


// //static method
// class test {
//   constructor(){ //static함수만 잇으면 생략해도됨 

//   }

//   fn () {

//   }
//   //일반적인 func와 달리 static은 클래스를 생성하지않고 클래스 내부에 접근가능하다.
//   //static 함수내부에서는 constructor에 있는 변수등등에 접근이 불가능하다.
//   static  call(){
//     console.log('static method');
//   }
// }

// test.call()

// // Destructuring 비구조화

// const obj = {
//   title: 'node.js',
//   value : '올인원 패키지'
// }

// const arr = [0,3,4];
// const {title , value} = obj; //최신문법 비구조화
// const [,a,b] = arr //앞자리는 순서상 비워놓은거 
// // //이전 문법 
// // const title = obj.title;
// // const value = obj.value;

// console.log(title , value);
// console.log(a,b);

// // Generator 개념적 접근 
// //화살표 함수는 사용 x 명시적으로 *를 붙여서 사용
// function* log () {
//   console.log(0, yield)
//   console.log(1, yield)
//   console.log(2, yield)
// }

// const gen = log();

// gen.next('zero');
// gen.next('first');
// gen.next('second');

// // 제네레이터 추가 
// const obj = {
//   *gen() {
//       let cnt = 0;
//       yield ++cnt;
//       yield ++cnt;
//       yield ++cnt;
//       return ++cnt;
//   }
// }

// const g = obj.gen();
// // console.log(g.next());
// // //next를 호출하면 가장가까운 yiled 문을 만날때까지 실행이지속
// // //출력 결과 : value와 done ,  value는 산출값 ,  done은 함수코드실행이 끝났는지 유무
// // console.log(g.next());
// // console.log(g.next());
// // console.log(g.next());
// // console.log(g.next()); //해당 코드는 value에서 undefined가 반환됨

// for (let value of g){
//   console.log(value);
// }// 제네레이터는 이터러블 객체이므로 for of도 사용가능 ,
// //단 done : 결과가 True일경우 무시되어 마지막값은 출력이안된다.

// //Timer
// //뒤에나오는 시간초는 최소지연시간이다.단위는 ms
// //최소 1초뒤에 실행 or 훨뒤에 실행될수도있음
// const a = setTimeout(()=>{
//   console.log('first');
// },0);

// const b = setImmediate(()=>{
//   console.log('second');
// },0); 
// //지연시간이 없이 실행되는거처럼 보인다.
// //setTimeout도 0으로 해서 돌려보면 first와 second가 나오는 순서가 그때그때 다르다

// const c = setInterval(()=> {
//   console.log('third');
// },1000) //1초마다 반복실행 


// clearTimeout(a);
// clearTimeout(b);
// clearTimeout(c);

// // Event Emitter

// const EventEmitter = require('events');

// class ChatManager extends EventEmitter {}

// const chatManager = new ChatManager()

// chatManager.on("join", () => {
//   console.log("new user joined");
// });

// chatManager.emit("join") //해당하는 이벤트가 실행했을때 

// //DNS

// const dns = require('dns');

// dns.lookup('naver.com',(err,address, family) => {
//   console.log(`address : ${address} , ${family}`);
//   //family에 4가오면 ipv4임 
// })

// dns.resolve4('archive.org' , (err,addresses) => {
//   if (err) throw err
//   const response = JSON.stringify(addresses)
//   console.log(response);

//   addresses.forEach(a => {
//     dns.reverse(a, (err,hostnames)=>{
//       if (err) throw err

//       console.log(`reverse for ${a} ${JSON.stringify(hostnames)}`)
//     });
//   })
// })

// File System

const fs = require('fs');
//콜백형식으로 되어있다. 프로미스형식으로 바꿀수있다.
fs.readFile('test.txt','utf-8', (err,data) => {
  if (err) {
    console.error(err);
    return 
  }

  console.log(data)
});//지정하지않아도 디폴트값으로 utf-8으로됨

const content = 'something to write'
fs.writeFile('fast.txt', content, err => {
  if (err) {
    console.error(err);
    return
  }
  console.log('success');
})