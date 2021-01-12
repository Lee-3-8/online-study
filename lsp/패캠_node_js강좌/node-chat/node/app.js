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

io.on('connection', (socket) => { 

    // socket.on('client message', (data) => {
    //     io.emit('server message', { //emit은 연결된 모든사람한테 전달 
    //         message : data.message
    //     });
    // });
    socket.on('client message', (data) => {
        socket.broadcast.emit('server message', { //braodcast사용하면 나를 제외하고 뿌림 ex)누구누구님이 입장했습니다.
            message : data.message
        });
    });

});