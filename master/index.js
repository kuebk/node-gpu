/*
 * Copyright (C) 2011 by Jakub Lekstan <kuebzky@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

var net = require('net'), http = require('http');
var hosts = ['czupakabra', 'bitcoin-1', 'bitcoin-2', 'bitcoin-3', 'bitcoin-4'], port = 8888, httpServerPort = 8080;

var sckCallback = function(){};

var activeHosts = [];
var activeSockets = hosts.length, connectedSockets = 0;
var tmpSockets = [], sockets = [], socket;

var httpServer, httpServerRunning = false;

for(var i = 0, l = hosts.length; i < l; i++){
	socket = new net.createConnection(port, hosts[i]);
	socket.num = i;
	socket.on('connect', function(){
		connectedSockets++;
		tmpSockets[this.num] = this;
		createHttpServer();
	});
	socket.on('data', function(d){
		sckCallback(d, this.num);
	});
	socket.on('error', function(){
		activeSockets--;
		createHttpServer();
	});
	socket.on('close', function(){
		if(httpServerRunning){
			httpServer.close();

			delete tmpSockets[this.num];

			reindexSockets();

			httpServer.listen(httpServerPort);
		}
	});
	/*socket.on('timeout', function(){
		console.log('timeout', arguments);
	});*/
	socket.setKeepAlive(true);
	socket.setNoDelay(true);
}

var reindexSockets = function(){
	sockets = [];

	var socketIndex = 0;

	for(var key in tmpSockets){
		tmpSockets[key].num = socketIndex;
		sockets[socketIndex] = tmpSockets[key];
		activeHosts[socketIndex] = hosts[key];
		socketIndex++;
	}

	tmpSockets = sockets;
};

var createHttpServer = function(){
	if(activeSockets != connectedSockets) return;

	//rewriting indexes
	reindexSockets();

	httpServer = http.createServer(function(request, response){
		var data = [], c = 0, tmp = [];

		var fnc = function(){
			if(sockets.length != ++c) return;

			var body = JSON.stringify(data);

			response.setHeader("Content-length", body.length);
			response.setHeader("Access-Control-Allow-Origin", "*");
			response.writeHead(200, {"Content-type": "application/json"});
			response.end(body);
		}

		sckCallback = function(d, i){
			try{
				data[i] = {
					name: activeHosts[i],
					data: JSON.parse(tmp[i] + d)
				};
				fnc();
			}catch(e){
				tmp[i] = tmp[i] + d.toString();
			}
		};
		for(var i = 0, l = sockets.length; i < l; i++){
			if(sockets[i].writable){
				tmp[i] = '';
				if(request.url.indexOf('getInfo') !== -1){
					sockets[i].write('getInfo');
				}else{
					sockets[i].write('getData');
				}
			}
		}
		httpServerRunning = true;
	});
	httpServer.listen(httpServerPort);
};
