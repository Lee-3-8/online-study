
async function login(data){
	const url = '/auth';
	const response = await fetch(url,{
		method: 'POST',
		headers: {
			'Accept' : 'application/json',
			'Content-Type': 'application/json',
		},
		body: JSON.stringify(data)
	});
	if (response.ok) {
		let json = await response.json();
		console.log(json);
		sessionStorage.setItem('access_token',json.access_token);
	}
	else{
		console.log(response);
	}
}

document.querySelector('.btn-primary').addEventListener('click',function(){

 const data = {
		username : document.querySelector('#userid').value,
		password : document.querySelector('#password').value,
	};
	console.log(data);
	login(data);
 // windows.location('/');
});
