var http = require("http");

http.createServer(function (request, responce) {
    responce.writeHead(200, {'Content-Type': 'text/plain'});

    responce.end('Hello, world');
}).listen(8888);

console.log('Server running at http://127.0.0.1:8888/');
