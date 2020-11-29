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
/*tag 생성기 , tage = tag명 A = 속성 ,B = 속성정보 , C= textNode*/
const getNode = function getNodeHtmlTagObject(tag,A,B,C){
  const object = document.createElement(`${tag}`);
  for (let i = 0; i <= A.length - 1; i++) {
    object.setAttribute(`${A[i]}`,`${B[i]}`);
  }
  if(C != undefined){
    const textNode = document.createTextNode(`${C}`);
    object.appendChild(textNode);
  }
  return object;
}
const getTime = function getTime(time) {

	let result = time.split('.')[0];
	result = result.split('T');
	return `${result[0]} ${result[1]}`;
}
const renderItem = function renderTodolistItem(data){
	const divTodoItem = getNode('div',['class','id'],['todo_item',`${data.id}`]);
	const spanKoText = getNode('span',['class'],['ko_text'],data.ko_text);
	const icon = getNode('i',['class'],['fas fa-arrow-right']);
	const spanEnText = getNode('span',['class'],['en_text']);
	const spanTime = getNode('span',['class'],['todo_time'],getTime(data.time));

	spanEnText.appendChild(icon);
	const textNode = document.createTextNode(data.en_text);
  spanEnText.appendChild(textNode);

	divTodoItem.appendChild(spanKoText);
	divTodoItem.appendChild(spanEnText);
	divTodoItem.appendChild(spanTime);
	return divTodoItem;
};

const render = function renderTodolist(data){
	const todo_list = document.querySelector('.todo_list');
	console.log(data)
	todo_list.insertBefore(renderItem(data),todo_list.firstChild)
	// todo_list.appendChild(renderItem(data));

};

const fetchData = async function fetchData(data){
	try{
		const res = await fetch('http://127.0.0.1:8081/data',{
			method : 'POST',
			headers:{
				'Content-Type' : 'application/json'
			},
			body: JSON.stringify(data)
		});

		render(await res.json());

	}catch(err){
		alert(err);
	}
};



const renderall = async function renderAllTodolist(data){
	const todo_list = document.querySelector('.todo_list');
	for (let i = data.length-1 ; i >= 0; i--){
		todo_list.appendChild(renderItem(data[i]));
	}
}

const fetchAllData = async function fetchAllData(data){
	try{
		const res = await fetch('http://127.0.0.1:8081/data');

		renderall(await res.json());

	}catch(err){
		alert(err);
	}
}

const button = document.querySelector('#input_button')
	.addEventListener('click',()=>{
		const data = document.querySelector('#input_data');
		fetchData({text : data.value});
		data.value = '';
	});

window.addEventListener('DOMContentLoaded',fetchAllData)