
async function regist(data){
	const url = '/api/v1/users';
	const token = sessionStorage.getItem('access_token');
	const response = await fetch(url,{
		method: 'POST',
		headers: {
			'Accept' : 'application/json',
			'Content-Type': 'application/json',
			'Authorization': token
		},
		body: JSON.stringify(data)
	});
	if (response.ok) {
		console.log(response);
		return response;
	}
	else{
		console.log(response);
	}
}

document.querySelector('.btn-primary').addEventListener('click',function(){

 const data = {
		userid : document.querySelector('#userid').value,
		username : document.querySelector('#username').value,
		password : document.querySelector('#password').value,
		re_password : document.querySelector('#re_password').value,
	};
	console.log(data);
	regist(data);
 // windows.location('/');
});
