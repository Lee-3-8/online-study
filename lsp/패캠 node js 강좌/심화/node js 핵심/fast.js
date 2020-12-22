'use strict' //엄격모드 : 컴파일시 좀더 엄격한 문법적용

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

////////////////EVERY 문법 /////////////////
// const arr  =[2,3,4]
// const isBiggerthanOne = arr.every(key => key > 1)
// //array에서 모든조건이 만족할때 실행 위 경우에는 2에서 바로 끝
// 프론트에서도 많이사용됨 

// console.log(isBiggerthanOne)


///////////////find , include//////////

// const arr = ['node.js' , '올인원']

// const ret = arr.find(key => key == '올인원')//반환 : 올인원 
// const res = arr.includes('node.js');//반환 : true
// console.log(res);
// // 찾아서 실제로 사용할 데이터면 find , 있는지 유무 판단은 includes
// // 두가지를 구분지어 사용해야 데이터 누수를 방지할 수 있다.


////////for each////

// //내부적으로 비동기적으로 실행되지않기때문에 주의해야함

// const arr = [1,2,3]
// const newArr = []
// // arr.forEach(item => console.log(item))
// arr.forEach(item =>{
// 	newArr.push(item)
// })
// //위코드는 스프레드 연산자로 클론하는게 가장 좋다


////////map filter////////

// const a = [1,2,3]
// const b = a.map(x => x+1)
// console.log(b)//2 3 4 

const a = [1,2,3]
const b = a.filter(x => x>1)
console.log(b)//2,3 
//주어진 조건을 만족하는 새로운 배열을 만든다.