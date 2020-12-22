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

const arr = ['node.js' , '올인원']

const ret = arr.find(key => key == '올인원')//반환 : 올인원 
const res = arr.includes('node.js');//반환 : true
console.log(res);
// 찾아서 실제로 사용할 데이터면 find , 있는지 유무 판단은 includes
// 두가지를 구분지어 사용해야 데이터 누수를 방지할 수 있다.