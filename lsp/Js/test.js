// const a = ["hello" , 20, "nodejs" , "2222"]

// console.log(a[0] , a[3])

// a[4] = 55

// console.log(a[4])

// console.log(a.length)
// console.log(a.indexOf("hello"))

// const b = new Array("2222","nodejs") // 비추천
// const c = []

// for(var i = 0 ; i<5; i++){
// 	console.log(i)
// }


// do{
// 	console.log("먼저실행하고 조건 비교 ")
// }while(false)

// const func = function(){
// 	console.log("dfdf")
// }

// function Func(a , b , c){
// 	this.name = a;
// 	this.color = b;
// 	console.log("dfdf");
// }

// Func.prototype.move = function(){
// 	console.log(this.name + "차이고" + this.color + "색입니다");
// }

// const inst1 = new Func("현대","빨간");
// const inst2 = new Func("기아","파란");

// // console.log(inst1.name , inst1.color)

// inst1.move();
// inst2.move();

///////////원래있는 객체에 나만의 속성 추가가능 /////
// const a = [1,2,3,4,5,6];
// Array.prototype.print = function(){
// 	for(var i = 0; i<this.length ; i++)
// 		console.log(i)
// }

// a.print();

//리터럴 객체 , 그리고 맴버
// const a = {
// 	'a' = 110,
// 	'b' = 'hello',
// 	'c' = function(){
// 		console.log('gggg')
// 	}
// }

// // 동일하다  const a = new Object()

// Object.prototype.sum = function(){
// 	console.log(this.a + 20);
// }
// a.sum()


// switch('yello'){
// 	case "blue" :
// 		console	.log('퍼런색');
// 		//....
// }

// function test(num,callback){
// 	callback();
// 	console.log(num);
// }

// test(1,function(){
// 	console.log('콜백함수가 실행됩니다.')
// })

// function ex_closer(){
// 	const num = 0;
// 	return function(){
// 		num++;
// 		console.log(num);
// 	}
// }
// //리턴을 익명함수로 했기 때문에 함수안에서 저장된 변수를 추가 , 수정가능함
// const test = ex_closer();
// test(); // 1
// test(); // 2


// document.addEventListener

