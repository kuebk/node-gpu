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

#include "gpu-helpers.h"

namespace ToJson {
	v8::Local<v8::Object> Result(int status, v8::Local<v8::Object> data){
		v8::Local<v8::Object> tmp = v8::Object::New();
		tmp->Set(v8::String::New("status"), v8::Integer::New(status));
		tmp->Set(v8::String::New("data"), data);

		return tmp;
	}

	v8::Local<v8::Object> Result(int status, int data){
		v8::Local<v8::Object> tmp = v8::Object::New();
		tmp->Set(v8::String::New("status"), v8::Integer::New(status));
		tmp->Set(v8::String::New("data"), v8::Integer::New(data));

		return tmp;
	}

	v8::Local<v8::Object> Result(int status, char* data){
		v8::Local<v8::Object> tmp = v8::Object::New();
		tmp->Set(v8::String::New("status"), v8::Integer::New(status));
		tmp->Set(v8::String::New("error"), v8::String::New(data));

		return tmp;
	}

	v8::Local<v8::Object> Result(int status){
		v8::Local<v8::Object> tmp = v8::Object::New();
		tmp->Set(v8::String::New("status"), v8::Integer::New(status));

		return tmp;
	}

	namespace AMD {

		v8::Local<v8::Object> ODParameterRange(ADLODParameterRange sADLODParameterRange){
			v8::Local<v8::Object> data = v8::Object::New();
			data->Set(v8::String::New("iMin"), v8::Integer::New(sADLODParameterRange.iMin));
			data->Set(v8::String::New("iMax"), v8::Integer::New(sADLODParameterRange.iMax));
			data->Set(v8::String::New("iStep"), v8::Integer::New(sADLODParameterRange.iStep));

			return data;
		}

		v8::Local<v8::Object> ADLODParameters(::ADLODParameters sADLODParameters){
			v8::Local<v8::Object> data = v8::Object::New();
			data->Set(v8::String::New("iSize"), v8::Integer::New(sADLODParameters.iSize));
			data->Set(v8::String::New("iNumberOfPerformanceLevels"), v8::Integer::New(sADLODParameters.iNumberOfPerformanceLevels));
			data->Set(v8::String::New("iActivityReportingSupported"), v8::Integer::New(sADLODParameters.iActivityReportingSupported));
			data->Set(v8::String::New("iDiscretePerformanceLevels"), v8::Integer::New(sADLODParameters.iDiscretePerformanceLevels));
			data->Set(v8::String::New("iReserved"), v8::Integer::New(sADLODParameters.iReserved));
			data->Set(v8::String::New("sEngineClock"), ODParameterRange(sADLODParameters.sEngineClock));
			data->Set(v8::String::New("sMemoryClock"), ODParameterRange(sADLODParameters.sMemoryClock));
			data->Set(v8::String::New("sVddc"), ODParameterRange(sADLODParameters.sVddc));
	
			return data;
		}

		v8::Local<v8::Object> sAdapterInfo(int iNumberOfAdapters, LPAdapterInfo adapterInfo){
			v8::Local<v8::Array> data = v8::Array::New(iNumberOfAdapters);

			for(int i = 0; i < iNumberOfAdapters; i++){
				v8::Local<v8::Object> row = v8::Object::New();

				row->Set(v8::String::New("iSize"), v8::Integer::New(adapterInfo[i].iSize));
				row->Set(v8::String::New("iAdapterIndex"), v8::Integer::New(adapterInfo[i].iAdapterIndex));
				row->Set(v8::String::New("strUDID"), v8::String::New(adapterInfo[i].strUDID));
				row->Set(v8::String::New("iBusNumber"), v8::Integer::New(adapterInfo[i].iBusNumber));
				row->Set(v8::String::New("iFunctionNumber"), v8::Integer::New(adapterInfo[i].iFunctionNumber));
				row->Set(v8::String::New("iVendorID"), v8::Integer::New(adapterInfo[i].iVendorID));
				row->Set(v8::String::New("strAdapterName"), v8::String::New(adapterInfo[i].strAdapterName));
				row->Set(v8::String::New("strDisplayName"), v8::String::New(adapterInfo[i].strDisplayName));

				#if defined (_WIN32) || defined (_WIN64)
					row->Set(v8::String::New("iExist"), v8::Integer::New(adapterInfo[i].iExist));
					row->Set(v8::String::New("strDriverPath"), v8::String::New(adapterInfo[i].strDriverPath));
					row->Set(v8::String::New("strDriverPathExt"), v8::String::New(adapterInfo[i].strDriverPathExt));
					row->Set(v8::String::New("strPNPString"), v8::String::New(adapterInfo[i].strPNPString));
					row->Set(v8::String::New("iOSDisplayIndex"), v8::Integer::New(adapterInfo[i].iOSDisplayIndex));
				#endif
				#if defined (LINUX)
					row->Set(v8::String::New("iXScreenNum"), v8::Integer::New(adapterInfo[i].iXScreenNum));
					row->Set(v8::String::New("iDrvIndex"), v8::Integer::New(adapterInfo[i].iDrvIndex));
					row->Set(v8::String::New("strXScreenConfigName"), v8::String::New(adapterInfo[i].strXScreenConfigName));
				#endif

				data->Set(v8::Integer::New(i), row);
			}

			return data;
		}

		v8::Local<v8::Object> ADLODPerformanceLevel(::ADLODPerformanceLevel sADLODPerformanceLevel){
			v8::Local<v8::Object> data = v8::Object::New();

			data->Set(v8::String::New("iEngineClock"), v8::Number::New(sADLODPerformanceLevel.iEngineClock));
			data->Set(v8::String::New("iMemoryClock"), v8::Number::New(sADLODPerformanceLevel.iMemoryClock));
			data->Set(v8::String::New("iVddc"), v8::Number::New(sADLODPerformanceLevel.iVddc));
		
			return data;
		}

		v8::Local<v8::Object> ADLODPerformanceLevels(int iNumberOfPerformanceLevels, ::ADLODPerformanceLevels * sADLODPerformanceLevels){
			v8::Local<v8::Object> data = v8::Object::New();

			data->Set(v8::String::New("iSize"), v8::Number::New(sADLODPerformanceLevels->iSize));
			data->Set(v8::String::New("iReserved"), v8::Number::New(sADLODPerformanceLevels->iReserved));

			v8::Local<v8::Array> aLevels = v8::Array::New(iNumberOfPerformanceLevels);

			for(int i = 0; i< iNumberOfPerformanceLevels; i++){
				aLevels->Set(v8::Number::New(i), ToJson::AMD::ADLODPerformanceLevel(sADLODPerformanceLevels->aLevels[i]));
			}

			data->Set(v8::String::New("aLevels"), aLevels);

			return data;
		}

		v8::Local<v8::Object> ADLFanSpeedInfo(::ADLFanSpeedInfo sADLFanSpeedInfo){
			v8::Local<v8::Object> data = v8::Object::New();

			data->Set(v8::String::New("iSize"), v8::Number::New(sADLFanSpeedInfo.iSize));
			data->Set(v8::String::New("iFlags"), v8::Number::New(sADLFanSpeedInfo.iFlags));
			data->Set(v8::String::New("iMinPercent"), v8::Number::New(sADLFanSpeedInfo.iMinPercent));
			data->Set(v8::String::New("iMaxPercent"), v8::Number::New(sADLFanSpeedInfo.iMaxPercent));
			data->Set(v8::String::New("iMinRPM"), v8::Number::New(sADLFanSpeedInfo.iMinRPM));
			data->Set(v8::String::New("iMaxRPM"), v8::Number::New(sADLFanSpeedInfo.iMaxRPM));

			return data;
		}

		v8::Local<v8::Object> ADLPMActivity(::ADLPMActivity lpActivity){
			v8::Local<v8::Object> data = v8::Object::New();

			data->Set(v8::String::New("iSize"), v8::Number::New(lpActivity.iSize));
			data->Set(v8::String::New("iEngineClock"), v8::Number::New(lpActivity.iEngineClock));
			data->Set(v8::String::New("iMemoryClock"), v8::Number::New(lpActivity.iMemoryClock));
			data->Set(v8::String::New("iVddc"), v8::Number::New(lpActivity.iVddc));
			data->Set(v8::String::New("iActivityPercent"), v8::Number::New(lpActivity.iActivityPercent));
			data->Set(v8::String::New("iCurrentPerformanceLevel"), v8::Number::New(lpActivity.iCurrentPerformanceLevel));
			data->Set(v8::String::New("iCurrentBusSpeed"), v8::Number::New(lpActivity.iCurrentBusSpeed));
			data->Set(v8::String::New("iCurrentBusLanes"), v8::Number::New(lpActivity.iCurrentBusLanes));
			data->Set(v8::String::New("iMaximumBusLanes"), v8::Number::New(lpActivity.iMaximumBusLanes));
			data->Set(v8::String::New("iReserved"), v8::Number::New(lpActivity.iReserved));

			return data;
		}

		v8::Local<v8::Object> ADLTemperature(::ADLTemperature lpTemperature){
			v8::Local<v8::Object> data = v8::Object::New();

			data->Set(v8::String::New("iSize"), v8::Number::New(lpTemperature.iSize));
			data->Set(v8::String::New("iTemperature"), v8::Number::New(lpTemperature.iTemperature));

			return data;
		}

		v8::Local<v8::Object> ADLFanSpeedValue(::ADLFanSpeedValue lpFanSpeedValue){
			v8::Local<v8::Object> data = v8::Object::New();

			data->Set(v8::String::New("iSize"), v8::Number::New(lpFanSpeedValue.iSize));
			data->Set(v8::String::New("iSpeedType"), v8::Number::New(lpFanSpeedValue.iSpeedType));
			data->Set(v8::String::New("iFanSpeed"), v8::Number::New(lpFanSpeedValue.iFanSpeed));
			data->Set(v8::String::New("iFlags"), v8::Number::New(lpFanSpeedValue.iFlags));

			return data;
		}
	}
}

