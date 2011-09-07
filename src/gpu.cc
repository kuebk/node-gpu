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

#include <v8.h>
#include <node.h>
#include <stdlib.h>
#include <string.h>
#include "gpu-helpers.h"
#include "gpu-bindings.h"

namespace {
	static v8::Handle<v8::Value> ADL_Main_Control_Create(const v8::Arguments& args){
		v8::HandleScope scope;

		if(args.Length() == 0 || !args[0]->IsNumber()){
			return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be a number")));
		}

		int iEnumConnectedAdapters = (int)v8::Local<v8::Integer>::Cast(args[0])->Int32Value();

		int ADL_STATUS = Bindings::AMD::ADL_Main_Control_Create(Bindings::AMD::ADL_Main_Memory_Alloc, iEnumConnectedAdapters);
		return scope.Close(ToJson::Result(ADL_STATUS));
	}

	static v8::Handle<v8::Value> ADL_Main_Control_Destroy(const v8::Arguments& args){
		v8::HandleScope scope;

		int ADL_STATUS = Bindings::AMD::ADL_Main_Control_Destroy();
		return scope.Close(ToJson::Result(ADL_STATUS));
	}

	static v8::Handle<v8::Value> ADL_Adapter_NumberOfAdapters_Get(const v8::Arguments& args){
		v8::HandleScope scope;

		int iNumberOfAdapters;

		int ADL_STATUS = Bindings::AMD::ADL_Adapter_NumberOfAdapters_Get( &iNumberOfAdapters);
		return scope.Close(ToJson::Result(ADL_STATUS, iNumberOfAdapters));
	}

	static v8::Handle<v8::Value> ADL_Adapter_AdapterInfo_Get(const v8::Arguments& args){
		v8::HandleScope scope;

		if(args.Length() == 0 || !args[0]->IsNumber()){
			return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be a number")));
		}

		int iNumberOfAdapters = (int)v8::Local<v8::Integer>::Cast(args[0])->Int32Value();

		LPAdapterInfo lpAdapterInfo = (LPAdapterInfo)malloc(sizeof(AdapterInfo) * iNumberOfAdapters);
		memset(lpAdapterInfo, '\0', sizeof(AdapterInfo) * iNumberOfAdapters);

		int ADL_STATUS = Bindings::AMD::ADL_Adapter_AdapterInfo_Get(lpAdapterInfo, sizeof(AdapterInfo) * iNumberOfAdapters);
		v8::Handle<v8::Value> result = scope.Close(ToJson::Result(ADL_STATUS, ToJson::AMD::sAdapterInfo(iNumberOfAdapters, lpAdapterInfo)));

		void * ptr = lpAdapterInfo;
		Bindings::AMD::ADL_Main_Memory_Free(&ptr);

		return result;
	}

	static v8::Handle<v8::Value> ADL_Adapter_Active_Get(const v8::Arguments& args){
		v8::HandleScope scope;

		if(args.Length() == 0 || !args[0]->IsNumber()){
			return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be a number")));
		}

		int iAdapterIndex = (int)v8::Local<v8::Integer>::Cast(args[0])->Int32Value();

		int lpStatus = -1;

		int ADL_STATUS = Bindings::AMD::ADL_Adapter_Active_Get(iAdapterIndex, &lpStatus);
		return scope.Close(ToJson::Result(ADL_STATUS, lpStatus));
	}

	static v8::Handle<v8::Value> ADL_Overdrive5_ODParameters_Get(const v8::Arguments& args){
		v8::HandleScope scope;

		if(args.Length() == 0 || !args[0]->IsNumber()){
			return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be a number")));
		}

		int iAdapterIndex = (int)v8::Local<v8::Integer>::Cast(args[0])->Int32Value();

		::ADLODParameters odParameters;
		odParameters.iSize = sizeof(odParameters);

		int ADL_STATUS = Bindings::AMD::ADL_Overdrive5_ODParameters_Get(iAdapterIndex, &odParameters);
		return scope.Close(ToJson::Result(ADL_STATUS, ToJson::AMD::ADLODParameters(odParameters)));
	}

	static v8::Handle<v8::Value> ADL_Overdrive5_ODPerformanceLevels_Get(const v8::Arguments& args){
		v8::HandleScope scope;

		if(args.Length() < 2 || !args[0]->IsNumber() || !args[1]->IsNumber()){
			return v8::ThrowException(v8::Exception::TypeError(v8::String::New("This function requires 2 numeric arguments")));
		}

		int iAdapterIndex = (int)v8::Local<v8::Integer>::Cast(args[0])->Int32Value();
		int iNumberOfPerformanceLevels = (int)v8::Local<v8::Integer>::Cast(args[1])->Int32Value();

		int pLevelsSize = sizeof(::ADLODPerformanceLevels) + sizeof(::ADLODPerformanceLevel) * (iNumberOfPerformanceLevels -1);
		::ADLODPerformanceLevels * pLevels = (::ADLODPerformanceLevels *) malloc(pLevelsSize);
		pLevels->iSize = pLevelsSize;

		int ADL_STATUS = Bindings::AMD::ADL_Overdrive5_ODPerformanceLevels_Get(iAdapterIndex, 0, pLevels);
		v8::Handle<v8::Value> result = scope.Close(ToJson::Result(ADL_STATUS, ToJson::AMD::ADLODPerformanceLevels(iNumberOfPerformanceLevels, pLevels)));

		void * ptr = pLevels;
		Bindings::AMD::ADL_Main_Memory_Free(&ptr);

		return result;
	}

	static v8::Handle<v8::Value> ADL_Overdrive5_FanSpeedInfo_Get(const v8::Arguments& args){
		v8::HandleScope scope;

		if(args.Length() == 0 || !args[0]->IsNumber()){
			return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be a number")));
		}

		int iAdapterIndex = (int)v8::Local<v8::Integer>::Cast(args[0])->Int32Value();

		::ADLFanSpeedInfo fanSpeed;
		fanSpeed.iSize = sizeof(::ADLFanSpeedInfo);

		int ADL_STATUS = Bindings::AMD::ADL_Overdrive5_FanSpeedInfo_Get(iAdapterIndex, 0, &fanSpeed);
		return scope.Close(ToJson::Result(ADL_STATUS, ToJson::AMD::ADLFanSpeedInfo(fanSpeed)));
	}

	static v8::Handle<v8::Value> ADL_Overdrive5_CurrentActivity_Get(const v8::Arguments& args){
		v8::HandleScope scope;

		if(args.Length() == 0 || !args[0]->IsNumber()){
			return v8::ThrowException(v8::Exception::TypeError(v8::String::New("AdapterIndex must be number")));
		}

		int iAdapterIndex = (int)v8::Local<v8::Integer>::Cast(args[0])->Int32Value();

		::ADLPMActivity lpActivity;
		lpActivity.iSize = sizeof(::ADLPMActivity);

		int ADL_STATUS = Bindings::AMD::ADL_Overdrive5_CurrentActivity_Get(iAdapterIndex, &lpActivity);
		return scope.Close(ToJson::Result(ADL_STATUS, ToJson::AMD::ADLPMActivity(lpActivity)));
	}

	static v8::Handle<v8::Value> ADL_Overdrive5_Temperature_Get(const v8::Arguments& args){
		v8::HandleScope scope;

		if(args.Length() == 0 || !args[0]->IsNumber() || !args[1]->IsNumber()){
			return v8::ThrowException(v8::Exception::TypeError(v8::String::New("adapterIndex and thermalControllerIndex must be numbers")));
		}

		int iAdapterIndex = (int)v8::Local<v8::Integer>::Cast(args[0])->Int32Value();
		int iThermalControllerIndex = (int)v8::Local<v8::Integer>::Cast(args[1])->Int32Value();

		::ADLTemperature lpTemperature;
		lpTemperature.iSize = sizeof(::ADLTemperature);

		int ADL_STATUS = Bindings::AMD::ADL_Overdrive5_Temperature_Get(iAdapterIndex, iThermalControllerIndex, &lpTemperature);
		return scope.Close(ToJson::Result(ADL_STATUS, ToJson::AMD::ADLTemperature(lpTemperature)));
	}

	static v8::Handle<v8::Value> ADL_Overdrive5_FanSpeed_Get(const v8::Arguments& args){
		v8::HandleScope scope;

		if(args.Length() == 0 || !args[0]->IsNumber() || !args[1]->IsNumber()){
			return v8::ThrowException(v8::Exception::TypeError(v8::String::New("adapterIndex and thermalControllerIndex must be numbers")));
		}

		int iAdapterIndex = (int)v8::Local<v8::Integer>::Cast(args[0])->Int32Value();
		int iThermalControllerIndex = (int)v8::Local<v8::Integer>::Cast(args[1])->Int32Value();

		::ADLFanSpeedValue lpFanSpeedValue;
		lpFanSpeedValue.iSize = sizeof(::ADLFanSpeedValue);

		int ADL_STATUS = Bindings::AMD::ADL_Overdrive5_FanSpeed_Get(iAdapterIndex, iThermalControllerIndex, &lpFanSpeedValue);
		return scope.Close(ToJson::Result(ADL_STATUS, ToJson::AMD::ADLFanSpeedValue(lpFanSpeedValue)));
	}
}

extern "C" void init (v8::Handle<v8::Object> target){
	v8::HandleScope scope;

	int adl = Bindings::AMD::init();

	if(adl == BINDINGS_FAILED){
		target->Set(v8::String::New("error"), v8::String::New("ADL library not found"));
	}else{

		v8::Local<v8::Object> amd = v8::Object::New();

		NODE_SET_METHOD(amd, "ADL_Main_Control_Create", ADL_Main_Control_Create);
		NODE_SET_METHOD(amd, "ADL_Main_Control_Destroy", ADL_Main_Control_Destroy);
		NODE_SET_METHOD(amd, "ADL_Adapter_NumberOfAdapters_Get", ADL_Adapter_NumberOfAdapters_Get);
		NODE_SET_METHOD(amd, "ADL_Adapter_AdapterInfo_Get", ADL_Adapter_AdapterInfo_Get);
		NODE_SET_METHOD(amd, "ADL_Adapter_Active_Get", ADL_Adapter_Active_Get);
		NODE_SET_METHOD(amd, "ADL_Overdrive5_ODParameters_Get", ADL_Overdrive5_ODParameters_Get);
		NODE_SET_METHOD(amd, "ADL_Overdrive5_ODPerformanceLevels_Get", ADL_Overdrive5_ODPerformanceLevels_Get);
		NODE_SET_METHOD(amd, "ADL_Overdrive5_FanSpeedInfo_Get", ADL_Overdrive5_FanSpeedInfo_Get);
		NODE_SET_METHOD(amd, "ADL_Overdrive5_CurrentActivity_Get", ADL_Overdrive5_CurrentActivity_Get);
		NODE_SET_METHOD(amd, "ADL_Overdrive5_Temperature_Get", ADL_Overdrive5_Temperature_Get);
		NODE_SET_METHOD(amd, "ADL_Overdrive5_FanSpeed_Get", ADL_Overdrive5_FanSpeed_Get);

		//setting constants;
		amd->Set(v8::String::NewSymbol("ADL_OK"), v8::Integer::New(ADL_OK));
		amd->Set(v8::String::NewSymbol("ADL_TRUE"), v8::Integer::New(ADL_TRUE));
		amd->Set(v8::String::NewSymbol("ADL_FALSE"), v8::Integer::New(ADL_FALSE));

		target->Set(v8::String::New("amd"), amd);
	}
}
