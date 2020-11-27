
const http  = require("http");
http.createServer(function(request,response){
	return request
		.on('error', (err) =>{ //요청에 애러가 있는경우
			console.error(err);
		})
		.on('data', (data) =>{//요청에 데이터가 있읐으면
			console.log(data);
		})
		.on('end', () =>{
			response.on('error', (err) =>{
				console.error(err);
			});
			response.statuscode = 200;
			response.setHeader('Content-Type','text/plain'); // header 설정
			response.write('hi\n');// body에 정보 탑재
			response.end('the end!'); //정보 탑재후 브라우저로 전송
		})
	// /*
	// HTTP 헤더 전송
	// HTTP status : 200 : ok
	// content type: text/plain
	// */
	// response.writeHead(200,{'Content-Type' : 'text/plain'});

	// /*
	// 	Response Body 를 "Heloo World"으로 설정

	// */

	// response.end("Hello.World\n");
}).listen(8081);

console.log("server running at http://127.0.0.1:8081");