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

#ifndef GPU_HELPERS_H
#define GPU_HELPERS_H

#include <v8.h>
#include "include/adl_sdk.h"

namespace ToJson {
	v8::Local<v8::Object> Result(int status, v8::Local<v8::Object> data);
	v8::Local<v8::Object> Result(int status, int data);
	v8::Local<v8::Object> Result(int status, char* data);
	v8::Local<v8::Object> Result(int status);

	namespace AMD {
		v8::Local<v8::Object> ODParameterRange(ADLODParameterRange sADLODParameterRange);
		v8::Local<v8::Object> ADLODParameters(::ADLODParameters sADLODParameters);
		v8::Local<v8::Object> sAdapterInfo(int iNumberOfAdapters, LPAdapterInfo adapterInfo);
		v8::Local<v8::Object> ADLODPerformanceLevel(::ADLODPerformanceLevel sADLPerformanceLevel);
		v8::Local<v8::Object> ADLODPerformanceLevels(int iNumberOfPerformanceLevels, ::ADLODPerformanceLevels * sADLODPerformanceLevels);
		v8::Local<v8::Object> ADLFanSpeedInfo(::ADLFanSpeedInfo sADLFanSpeedInfo);
		v8::Local<v8::Object> ADLPMActivity(::ADLPMActivity lpActivity);
		v8::Local<v8::Object> ADLTemperature(::ADLTemperature lpTemperature);
		v8::Local<v8::Object> ADLFanSpeedValue(::ADLFanSpeedValue lpFanSpeedValue);
	}
}

#endif
