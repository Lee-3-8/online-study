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


do{
	console.log("먼저실행하고 조건 비교 ")
}while(false)

const func = function(){
	console.log("dfdf")
}

function Func(a , b , c){
	this.name = a;
	this.color = b;
	console.log("dfdf")
	const move = c;
}

const inst = new Func("아","ㄱㅊ","오류날껄 ")

console.log(inst.name , inst.color , a.move) // => 오류