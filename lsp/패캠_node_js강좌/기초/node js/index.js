const http = require('http');
const expres
//express없이 내부모듈로 서버 구성
http.createServer((request,response)=>{
	response.writeHead(200,{'Content-Type' : 'text/plain'});
	response.write('Hello Server');
	response.end();
}).listen(3000);