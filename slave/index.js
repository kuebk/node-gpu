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

var net = require('net');
var gpu = require('../bin/gpu.node');

//initializing adl3
try{
	var create = gpu.amd.ADL_Main_Control_Create(1);
	if(create.status != gpu.amd.ADL_OK) throw -1;

	var numberOfAdapters = gpu.amd.ADL_Adapter_NumberOfAdapters_Get();
	if(numberOfAdapters.status != gpu.amd.ADL_OK) throw -2;

	var allAdaptersData = gpu.amd.ADL_Adapter_AdapterInfo_Get(numberOfAdapters.data), activeAdaptersData = [], tmp;
	if(allAdaptersData.status != gpu.amd.ADL_OK) throw -3;

	for(var i = 0, l = allAdaptersData.data.length; i < l; i++){
		tmp = gpu.amd.ADL_Adapter_Active_Get(i);
		
		if(tmp.status == gpu.amd.ADL_OK && tmp.data == gpu.amd.ADL_TRUE){
			activeAdaptersData.push(allAdaptersData.data[i]);
		}
	}
}catch(e){
	console.log('Failed to init ADL:', e.message);
	gpu.amd.ADL_Main_Control_Destroy();
	process.exit(1);
}

process.on('exit', function(){
	gpu.amd.ADL_Main_Control_Destroy();
}).on('uncaughtException', function(e){
	console.log('Uncaught exception:', e.message);
	gpu.amd.ADL_Main_Control_Destroy();
	process.exit(1);
});

var server = net.createServer({
	allowHalfOpen: true
},function(socket){
	socket.setNoDelay(true);
	socket.on('data', function(buffer){
		console.log('data received');

		var data = [];

		if(buffer.toString() == 'getInfo'){
			for(var i = 0, l = activeAdaptersData.length; i < l; i++){
				data.push(activeAdaptersData[i].strAdapterName);	
			}
		}else{
			var tmp, temperature, fan, activity;

			for(var i = 0, l = activeAdaptersData.length; i < l; i++){
				tmp = {
					temperature: 0,
					fanspeed: 0,
					activity: 0,
					core: 0,
					memory: 0
				};
	
				temperature = gpu.amd.ADL_Overdrive5_Temperature_Get(activeAdaptersData[i].iAdapterIndex, 0);
				if(temperature.status == gpu.amd.ADL_OK){
					tmp.temperature = temperature.data.iTemperature/1000;
				}

				fan = gpu.amd.ADL_Overdrive5_FanSpeed_Get(activeAdaptersData[i].iAdapterIndex, 0);
				if(fan.status == gpu.amd.ADL_OK){
					tmp.fanspeed = fan.data.iFanSpeed;
				}

				activity = gpu.amd.ADL_Overdrive5_CurrentActivity_Get(activeAdaptersData[i].iAdapterIndex);
				if(activity.status == gpu.amd.ADL_OK){
					tmp.activity = activity.data.iActivityPercent;
					tmp.core = activity.data.iEngineClock/100;
					tmp.memory = activity.data.iMemoryClock/100;
				}

				data.push(tmp);
			}
		}

		console.log('sending data');
		socket.write(JSON.stringify(data));
		console.log('sent');
	});
}).listen(8888);
