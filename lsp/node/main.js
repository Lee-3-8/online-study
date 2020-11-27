
const http  = require("http");
http.createServer(function(request,response){
	/*
	HTTP 헤더 전송
	HTTP status : 200 : ok
	content type: text/plain
	*/
	response.writeHead(200,{'Content-Type' : 'text/plain'});

	/*
		Response Body 를 "Heloo World"으로 설정

	*/

	response.end("Hello.World\n");
}).listen(8081);

console.log("server running at http://127.0.0.1:8081");