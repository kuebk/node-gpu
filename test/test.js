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

var gpu = require('../bin/gpu.node');

try {
	var create = gpu.amd.ADL_Main_Control_Create(1);

	if(create.status != gpu.amd.ADL_OK){
		throw '' + -3 + ', ' + create.status;
	}

	var numOfAdapters = gpu.amd.ADL_Adapter_NumberOfAdapters_Get();

	if(numOfAdapters.status != gpu.amd.ADL_OK){
		throw '' + -2 + ',' + numOfAdapters.status;
	}

	var allAdaptersData = gpu.amd.ADL_Adapter_AdapterInfo_Get(numOfAdapters.data), activeAdaptersData = [], tmp;

	if(allAdaptersData.status != gpu.amd.ADL_OK){
		throw '' + -1 + ',' + allAdaptersData.status;
	}

	for(var i = 0, l = allAdaptersData.data.length; i < l; i++){
	    tmp = gpu.amd.ADL_Adapter_Active_Get(i);

		if(tmp.status == gpu.amd.ADL_OK){
			if(tmp.data == gpu.amd.ADL_TRUE){
				activeAdaptersData.push(allAdaptersData.data[i]);
			}
		}
	}
	console.log(activeAdaptersData);
	var od;

	for(var i = 0, l = activeAdaptersData.length; i < l; i++){
		od = gpu.amd.ADL_Overdrive5_ODParameters_Get(activeAdaptersData[i].iAdapterIndex);

		console.log(od.data);
	
		if(od.data.iDiscretePerformanceLevels){
			console.log(gpu.amd.ADL_Overdrive5_ODPerformanceLevels_Get(activeAdaptersData[i].iAdapterIndex, od.data.iNumberOfPerformanceLevels).data);
		}

		console.log(gpu.amd.ADL_Overdrive5_FanSpeedInfo_Get(activeAdaptersData[i].iAdapterIndex));
		console.log(gpu.amd.ADL_Overdrive5_CurrentActivity_Get(activeAdaptersData[i].iAdapterIndex));
		console.log(gpu.amd.ADL_Overdrive5_Temperature_Get(activeAdaptersData[i].iAdapterIndex, 0));
		console.log(gpu.amd.ADL_Overdrive5_FanSpeed_Get(activeAdaptersData[i].iAdapterIndex, 0));
	}
}catch(e){
	console.log(e);
}
gpu.amd.ADL_Main_Control_Destroy();
