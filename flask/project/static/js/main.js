
async function resgist(data){
	const url = '/api/v1/users';
	const response = await fetch(url,{
		method : 'GET',
		headers : {
			'Accept' : 'application/json',
			'Content-Type': 'application/json',
		},
		body : JSon.stringfy(data)
	});
	if (response.ok) {
		console.log(response);
		return response;
	}
	else{
		console.log('no');
	}
}

document.querySelector('.btn-primary').addEventListener('click',function(){

 regist();
 window.location('/');
});
