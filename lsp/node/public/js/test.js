/*
함수1)
입력값을 받아온다
변수에 저장한다.
fetch로 보낸다
보내고 값을 받는다.
rendering 한다
*랜더링하는 함수 하나 만들기

함수2)
버튼이벤트 리스너

함수3)
페이지가 로드되면 전체 투두리스트를 랜더링
*/

const render = function renderTodolist(res){
	const data = res.then(result=>return result);
};

const fetchData = async function fetchData(data){
	console.log(data)
	const res = await fetch('http://127.0.0.1:8081/data',{
		method : 'POST',
		headers:{
			'Content-Type' : 'application/json'
		},
		body: JSON.stringify(data)
	});
	render(res.json());
};


const button = document.querySelector('#input_button')
	.addEventListener('click',()=>{
		const data = document.querySelector('#input_data');
		fetchData({text : data.value})
	});
