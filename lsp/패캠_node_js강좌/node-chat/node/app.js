const express = require('express');

const app = express();
const port = 3000;


app.get('/', ( _ ,res) => {
    res.sendFile(__dirname + '/index.html');
});

const server = app.listen( port, () => {
    console.log('Express listening on port', port);
});

const listen = require('socket.io');
const io = listen(server);

const color = [
    "yellow",
    "green",
    "red",
    "blue",
    "white",
    "black",
]

io.on('connection', (socket) => { 

    const username = color[ Math.floor(Math.random() * 6) ]; //랜덤으로 이름 

    socket.broadcast.emit( 'join',  {  username  } ); //들어왔을때 다른사람들한테 보내줌 

    socket.on('client message', (data) => { //socket on으로 계속 받을 준비중 
        io.emit('server message', { //emit은 연결된 모든사람한테 전달 
            username,
            message : data.message
        });
    });
    // socket.on('client message', (data) => {
    //     socket.broadcast.emit('server message', { //braodcast사용하면 나를 제외하고 뿌림 ex)누구누구님이 입장했습니다.
    //         message : data.message
    //     });
    // });
    socket.on('disconnect', () => {
        socket.broadcast.emit('leave', { username });
    });


});

/* 
        프론트              서버                    서버            프론트
    ClientMassage       ClientMassage         ServerMassage         ServerMassage
        Emit                socket.on               Emit                socket.io
*/