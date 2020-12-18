'user strict' //엄격모드 : 컴파일시 좀더 엄격한 문법적용

const obj = {
	title : 'node js 올인원 패키지'
}



function isEmptyobj (){
	if(obj.title){
		return true
	}else {
		return else;
	}	
}

isEmptyobj()




///최신문법으로

const isEmptyobj1 = () => obj.title ? true : false;
isEmptyobj1()