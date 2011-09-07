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

#include "gpu-bindings.h"
#include <dlfcn.h>
#include <stdlib.h>

namespace Bindings {
	namespace AMD {
		void * __stdcall ADL_Main_Memory_Alloc(int iSize){
			void * lpBuffer = malloc(iSize);
			return lpBuffer;
		}
		void __stdcall ADL_Main_Memory_Free(void ** lpBuffer){
			if(* lpBuffer != NULL){
				free(* lpBuffer);
				* lpBuffer = NULL;
			}
		}

		ADL_MAIN_CONTROL_CREATE ADL_Main_Control_Create;
		ADL_MAIN_CONTROL_DESTROY ADL_Main_Control_Destroy;
		ADL_MAIN_CONTROL_REFRESH ADL_Main_Control_Refresh;

		ADL_ADAPTER_ACTIVE_GET ADL_Adapter_Active_Get;
		ADL_ADAPTER_NUMBEROFADAPTERS_GET ADL_Adapter_NumberOfAdapters_Get;
		ADL_ADAPTER_ADAPTERINFO_GET ADL_Adapter_AdapterInfo_Get;
		ADL_ADAPTER_ASICFAMILYTYPE_GET ADL_Adapter_ASICFamilyType_Get;
		ADL_ADAPTER_SPEED_CAPS ADL_Adapter_Speed_Caps;
		ADL_ADAPTER_SPEED_GET ADL_Adapter_Speed_Get;
		ADL_ADAPTER_SPEED_SET ADL_Adapter_Speed_Set;
		ADL_ADAPTER_ACCESSIBILITY_GET ADL_Adapter_Accessibility_Get;
		ADL_ADAPTER_VIDEOBIOSINFO_GET ADL_Adapter_VideoBiosInfo_Get;
		ADL_ADAPTER_ID_GET ADL_Adapter_ID_Get;
		ADL_ADAPTER_CROSSFIRE_CAPS ADL_Adapter_Crossfire_Caps;
		ADL_ADAPTER_CROSSFIRE_GET ADL_Adapter_Crossfire_Get;
		ADL_ADAPTER_CROSSFIRE_SET ADL_Adapter_Crossfire_Set;
		ADL_ADAPTER_MEMORYINFO_GET ADL_Adapter_MemoryInfo_Get;
		ADL_ADAPTER_CLOCKINFO_GET ADL_Adapter_ClockInfo_Get;
		ADL_DISPLAY_ADAPTERID_GET ADL_Display_AdapterID_Get;

		ADL_APPLICATIONPROFILES_SYSTEM_RELOAD ADL_ApplicationProfiles_System_Reload;
		ADL_APPLICATIONPROFILES_USER_LOAD ADL_ApplicationProfiles_User_Load;
		ADL_APPLICATIONPROFILES_USER_UNLOAD ADL_ApplicationProfiles_User_Unload;

		ADL_CONTROLLER_COLOR_SET ADL_Controller_Color_Set;
		ADL_CONTROLLER_COLOR_GET ADL_Controller_Color_Get;

		ADL_ADAPTER_CROSSDISPLAYADAPTERROLE_CAPS ADL_Adapter_CrossdisplayAdaterRole_Caps;
		ADL_ADAPTER_CROSSDISPLAYINFO_GET ADL_Adapter_CrossdisplayInfo_Get;
		ADL_ADAPTER_CROSSDISPLAYINFO_SET ADL_Adapter_CrossdisplayInfo_Set;

		ADL_DISPLAY_DISPLAYINFO_GET ADL_Display_DisplayInfo_Get;
		ADL_DISPLAY_NUMBEROFDISPLAYS_GET ADL_Display_NumberOfDisplays_Get;
		ADL_DISPLAY_PRESERVEDASPECTRATIO_GET ADL_Display_PreservedAspectRatio_Get;
		ADL_DISPLAY_PRESERVEDASPECTRATIO_SET ADL_Display_PreservedAspectRatio_Set;
		ADL_DISPLAY_IMAGEEXPANSION_GET ADL_Display_ImageExpansion_Get;
		ADL_DISPLAY_IMAGEEXPANSION_SET ADL_Display_ImageExpansion_Set;
		ADL_DISPLAY_POSITION_GET ADL_Display_Position_Get;
		ADL_DISPLAY_POSITION_SET ADL_Display_Position_Set;
		ADL_DISPLAY_SIZE_GET ADL_Display_Size_Get;
		ADL_DISPLAY_SIZE_SET ADL_Display_Size_Set;
		ADL_DISPLAY_ADJUSTCAPS_GET ADL_Display_AdjustCaps_Get;
		ADL_DISPLAY_CAPABILITIES_GET ADL_Display_Capabilities_Get;
		ADL_DISPLAY_CONNECTEDDISPLAYS_GET ADL_Display_ConnectedDisplays_Get;
		ADL_DISPLAY_DEVICECONFIG_GET ADL_Display_DeviceConfig_Get;
		ADL_DISPLAY_PROPERTY_GET ADL_Display_Property_Get;
		ADL_DISPLAY_PROPERTY_SET ADL_Display_Property_Set;
		ADL_DISPLAY_SWITCHINGCAPABILITY_GET ADL_Display_SwitchingCapability_Get;
		ADL_DISPLAY_DITHERSTATE_GET ADL_Display_DitherState_Get;
		ADL_DISPLAY_DITHERSTATE_SET ADL_Display_DitherState_Set;
		ADL_DISPLAY_SUPPORTEDPIXELFORMAT_GET ADL_Display_SupportedPixelFormat_Get;
		ADL_DISPLAY_PIXELFORMAT_GET ADL_Display_PixelFormat_Get;
		ADL_DISPLAY_PIXELFORMAT_SET ADL_Display_PixelFormat_Set;
		ADL_DISPLAY_ODCLOCKINFO_GET ADL_Display_ODClockInfo_Get;
		ADL_DISPLAY_ODCLOCKCONFIG_SET ADL_Display_ODClockConfig_Set;
		ADL_DISPLAY_ADJUSTMENTCOHERENT_GET ADL_Display_AdjustmentCoherent_Get;
		ADL_DISPLAY_ADJUSTMENTCOHERENT_SET ADL_Display_AdjustmentCoherent_Set;
		ADL_DISPLAY_REDUCEDBLANKING_GET ADL_Display_ReducedBlanking_Get;
		ADL_DISPLAY_REDUCEDBLANKING_SET ADL_Display_ReducedBlanking_Set;
		ADL_DISPLAY_FORMATSOVERRIDE_GET ADL_Display_FormatsOverride_Get;
		ADL_DISPLAY_FORMATSOVERRIDE_SET ADL_Display_FormatsOverride_Set;
		ADL_DISPLAY_MVPUCAPS_GET ADL_Display_MVPUCaps_Get;
		ADL_DISPLAY_MVPUSTATUS_GET ADL_Display_MVPUStatus_Get;
		ADL_DISPLAY_CONTROLLEROVERLAYADJUSTMENTCAPS_GET ADL_Display_ControllerOverlayAdjustmentCaps_Get;
		ADL_DISPLAY_CONTROLLEROVERLAYADJUSTMENTDATA_GET ADL_Display_ControllerOverlayAdjustmentData_Get;
		ADL_DISPLAY_CONTROLLEROVERLAYADJUSTMENTDATA_SET ADL_Display_ControllerOverlayAdjustmentData_Set;
		ADL_DISPLAY_WRITEANDREADI2CREV_GET ADL_Display_WriteAndReadI2CRev_Get;
		ADL_DISPLAY_WRITEADNREADI2C ADL_Display_WriteAndReadI2C;
		ADL_DISPLAY_DDCBLOCKACCESS_GET ADL_Display_DDCBlockAccess_Get;
		ADL_DISPLAY_DDCINFO_GET ADL_Display_DDCInfo_Get;
		ADL_DISPLAY_EDIDDATEA_GET ADL_Display_EdidData_Get;
		ADL_DISPLAY_COLORCAPS_GET ADL_Display_ColorCaps_Get;
		ADL_DISPLAY_COLOR_SET ADL_Display_Color_Set;
		ADL_DISPLAY_COLOR_GET ADL_Display_Color_Get;
		ADL_DISPLAY_COLORTEMPERATURESOURCE_GET ADL_Display_ColorTemperatureSource_Get;
		ADL_DISPLAY_COLORTEMPERATURESOURCE_SET ADL_Display_ColorTemperatureSource_Set;
		ADL_DISPLAY_MODETIMINGOVERRIDE_GET ADL_Display_ModeTimingOverride_Get;
		ADL_DISPLAY_MODETIMINGOVERRIDE_SET ADL_Display_ModeTimingOverride_Set;
		ADL_DISPLAY_MODETIMINGOVERRIDELIST_GET ADL_Display_ModeTimingOverrideList_Get;
		ADL_DISPLAY_CUSTOMIZEDMODELISTNUM_GET ADL_Display_ModeTimingModelListNum_Get;
		ADL_DISPLAY_CUSTOMIZEDMODELIST_GET ADL_Display_CustomizedModeList_Get;
		ADL_DISPLAY_CUSTOMIZEDMODE_ADD ADL_Display_CustomizedMode_Add;
		ADL_DISPLAY_CUSTOMIZEDMODE_DELETE ADL_Display_CustomizedMode_Delete;
		ADL_DISPLAY_CUSTOMIZEDMODE_VALIDATE ADL_Display_CustomizedMode_Validate;
		ADL_DISPLAY_UNDERSCAN_SET ADL_Display_Underscan_Set;
		ADL_DISPLAY_UNDERSCAN_GET ADL_Display_Underscan_Get;
		ADL_DISPLAY_OVERSCAN_SET ADL_Display_Overscan_Set;
		ADL_DISPLAY_OVERSCAN_GET ADL_Display_Overscan_Get;
		ADL_DFP_BASEAUDIOSUPPORT_GET ADL_DFP_BaseAudioSupport_Get;
		ADL_DFP_HDMISUPPORT_GET ADL_DFP_HDMISupport_Get;
		ADL_DFP_MVPUANALOGSUPPORT_GET ADL_DFP_MVPUAnalogSupport_Get;
		ADL_DFP_PIXELFORMAT_CAPS ADL_DFP_PixelFormat_Caps;
		ADL_DFP_PIXELFORMAT_GET ADL_DFP_PixelFormat_Get;
		ADL_DFP_PIXELFORMAT_SET ADL_DFP_PixelFormat_Set;
		ADL_DFP_GPUSCALINGENABLE_GET ADL_DFP_GPUScalingEnable_Get;
		ADL_DFP_GPUSCALINGENABLE_SET ADL_DFP_GPUScalingEnable_Set;
		ADL_DFP_ALLOWONLYCETIMINGS_GET ADL_DFP_AllowOnlyCETimings_Get;
		ADL_DFP_ALLOWONLYCETIMINGS_SET ADL_DFP_AllowOnlyCETimings_Set;
		ADL_DISPLAY_TVCAPS_GET ADL_Display_TVCaps_Get;
		ADL_TV_STANDARD_SET ADL_TV_Standard_Set;
		ADL_TV_STANDARD_GET ADL_TV_Standard_Get;
		ADL_CV_DONGLESETTINGS_GET ADL_CV_DongleSettings_Get;
		ADL_CV_DONGLESETTINGS_SET ADL_CV_DongleSettings_Set;
		ADL_CV_DONGLESETTINGS_RESET ADL_CV_DongleSettings_Reset;
		ADL_DISPLAY_POWERXPRESSVERSION_GET ADL_Display_PowerXpressVersion_Get;
		ADL_DISPLAY_POWERXPRESSACTIVEGPU_GET ADL_Display_PowerXpressActiveGpu_Get;
		ADL_DISPLAY_POWERXPRESSACTIVEGPU_SET ADL_Display_PowerXpressActiveGpu_Set;
		ADL_DISPLAY_POWERXPRESS_AUTOSWITCHCONFIG_GET ADL_Display_PowerXpress_AutoSwitchConfig_Get;
		ADL_DISPLAY_POWERXPRESS_AUTOSWITCHCONFIG_SET ADL_Display_PowerXpress_AutoSwitchConfig_Set;
		ADL_DISPLAY_UNDERSCAN_AUTO_GET ADL_Display_UnderScan_Auto_Get;
		ADL_DISPLAY_UNDERSCAN_AUTO_SET ADL_Display_UnderScan_Auto_Set;
		ADL_DISPLAY_DEFLICKER_GET ADL_Display_Deflicker_Get;
		ADL_DISPLAY_DEFLICKER_SET ADL_Display_Deflicker_Set;
		ADL_DISPLAY_FILTERSVIDEO_GET ADL_Display_FilterSVideo_Get;
		ADL_DISPLAY_FILTERSVIDEO_SET ADL_Display_FilterSVideo_Set;
	
		ADL_ADAPTER_ACTIVE_SET ADL_Adapter_Active_Set;
		ADL_ADAPTER_ACTIVE_SETPREFER ADL_Adapter_Active_SetPrefer;
		ADL_ADAPTER_PRIMARY_GET ADL_Adapter_Primary_Get;
		ADL_ADAPTER_PRIMARY_SET ADL_Adapter_Primary_Set;
		ADL_ADAPTER_MODESWITCH ADL_Adapter_ModeSwitch;
		ADL_DISPLAY_MODES_GET ADL_Display_Modes_Get;
		ADL_DISPLAY_MODES_SET ADL_Display_Modes_Set;
		ADL_DISPLAY_POSSIBLEMODE_GET ADL_Display_PossibleMode_Get;
		ADL_DISPLAY_FORCIBLEDISPLAY_GET ADL_Display_ForcibleDisplay_Get;
		ADL_DISPLAY_FORCIBLEDISPLAY_SET ADL_Display_ForcibleDisplay_Set;
		ADL_ADAPTER_NUMBEROFACTIVATABLESOURCES_GET ADL_Adapter_NumberOfActivatableSources_Get;
		ADL_ADAPTER_DISPLAY_CAPS ADL_Adapter_Display_Caps;
		ADL_DISPLAY_DISPLAYMAPCONFIG_GET ADL_Adapter_DisplayMapConfig_Get;
		ADL_DISPLAY_DISPLAYMAPCONFIG_SET ADL_Adapter_DisplayMapConfig_Set;
		ADL_DISPLAY_POSSIBLEMAPPING_GET ADL_Display_PossibleMapping_Get;
		ADL_DISPLAY_DISPLAYMAPCONFIG_VALIDATE ADL_Display_DisplayMapConfig_Validate;
		ADL_DISPLAY_DISPLAYMAPCONFIG_POSSIBLEADDANDREMOVE ADL_Display_DisplayMapConfig_PossibleAddAndRemove;
		ADL_DISPLAY_SLSGRID_CAPS ADL_Display_SLSGrid_Caps;
		ADL_DISPLAY_SLSMAPINDEXLIST_GET ADL_Display_SLSMapIndexList_Get;
		ADL_DISPLAY_SLSMAPINDEX_GET ADL_Display_SLSMapIndex_Get;
		ADL_DISPLAY_SLSMAPCONFIG_GET ADL_Display_SLSMapConfig_Get;
		ADL_DISPLAY_SLSMAPCONFIG_CREATE ADL_Display_SLSMapConfig_Create;
		ADL_DISPLAY_SLSMAPCONFIG_DELETE ADL_Display_SLSMapConfig_Delete;
		ADL_DISPLAY_SLSMAPCONFIG_SETSTATE ADL_Display_SLSMapConfig_SetState;
		ADL_DISPLAY_SLSMAPCONFIG_REARRANGE ADL_Display_SLSMapConfig_RearRange;
		ADL_DISPLAY_POSSIBLEMODE_WINXP_GET ADL_Display_PossibleMode_WinXP_Get;
		ADL_DISPLAY_BEZELOFFSETSTEPPINGSIZE_GET ADL_Display_BezelOffsetSteppingSize_Get;
		ADL_DISPLAY_BEZELOFFSET_SET ADL_Display_BezelOffset_Set;
		ADL_DISPLAY_BEZELSUPPORTED_VALIDATE ADL_Display_BezelSupported_Validate;
	
		ADL_GRAPHICS_PLATFORM_GET ADL_Graphics_Platform_Get;
	
		ADL_DESKTOPCONFIG_GET ADL_DesktopConfig_Get;
		ADL_DESKTOPCONFIG_SET ADL_DesktopConfig_Set;
		ADL_NUMBEROFDISPLAYENABLE_GET ADL_NumberOfDisplayEnable_Get;
		ADL_DISPLAYENABLE_SET ADL_DisplayEnable_Set;
		ADL_DISPLAY_IDENTIFYDISPLAY ADL_Display_IdentifyDisplay;
		ADL_DISPLAY_LUTCOLOR_SET ADL_Display_LUTColor_Set;
		ADL_DISPLAY_LUTCOLOR_GET ADL_Display_LUTColor_Get;
		ADL_ADAPTER_XSCREENINFO_GET ADL_Adapter_XScreenInfo_Get;
		ADL_DISPLAY_XRANDRDISPLAYNAME_GET ADL_Adapter_Display_XrandrDisplayName_Get;
	
		ADL_OVERDRIVE5_CURRENTACTIVITY_GET ADL_Overdrive5_CurrentActivity_Get;
		ADL_OVERDRIVE5_THERMALDEVICES_ENUM ADL_Overdrive5_ThermalDevices_Enum;
		ADL_OVERDRIVE5_TEMPERATURE_GET ADL_Overdrive5_Temperature_Get;
		ADL_OVERDRIVE5_FANSPEEDINFO_GET ADL_Overdrive5_FanSpeedInfo_Get;
		ADL_OVERDRIVE5_FANSPEED_GET ADL_Overdrive5_FanSpeed_Get;
		ADL_OVERDRIVE5_FANSPEED_SET ADL_Overdrive5_FanSpeed_Set;
		ADL_OVERDRIVE5_FANSPEEDTODEFAULT_SET ADL_Overdrive5_FanSpeedToDefault_Set;
		ADL_OVERDRIVE5_ODPARAMETERS_GET ADL_Overdrive5_ODParameters_Get;
		ADL_OVERDRIVE5_ODPERFORMANCELEVELS_GET ADL_Overdrive5_ODPerformanceLevels_Get;
		ADL_OVERDRIVE5_ODPERFORMANCELEVELS_SET ADL_Overdrive5_ODPerformanceLevels_Set;
	
		ADL_WORKSTATION_CAPS ADL_Workstation_Caps;
		ADL_WORKSTATION_STEREO_GET ADL_Workstation_Stereo_Get;
		ADL_WORKSTATION_STEREO_SET ADL_Workstation_Stereo_Set;
		ADL_WORKSTATION_ADAPTERNUMOFGLSYNCCONNECTORS_GET ADL_Workstation_AdapterNumOfGLSyncConnectors_Get;
		ADL_WORKSTATION_DISPLAYGENLOCKCAPABLE_GET ADL_Workstation_DisplayGenlockCapable_Get;
		ADL_WORKSTATION_GLSYNCMODULEDETECT_GET ADL_Workstation_GLSyncModuleDetect_Get;
		ADL_WORKSTATION_GLSYNCMODULEINFO_GET ADL_Workstation_GLSyncModuleInfo_Get;
		ADL_WORKSTATION_GLSYNCGENLOCKCONFIGURATION_GET ADL_Workstation_GLSyncGenlockConfiguration_Get;
		ADL_WORKSTATION_GLSYNCGENLOCKCONFIGURATION_SET ADL_Workstation_GLSyncGenlockConfiguration_Set;
		ADL_WORKSTATION_GLSYNCPORTSTATE_GET ADL_Workstation_GLSyncPortState_Get;
		ADL_WORKSTATION_GLSYNCPORTSTATE_SET ADL_Workstation_GLSyncPortState_Set;
		ADL_WORKSTATION_DISPLAYGLSYNCMODE_GET ADL_Workstation_DisplayGLSyncMode_Get;
		ADL_WORKSTATION_DISPLAYGLSYNCMODE_SET ADL_Workstation_DisplayGLSyncMode_Set;
		ADL_WORKSTATION_GLSYNCSUPPORTEDTOPOLOGY_GET ADL_Workstation_GLSyncSupportedTopology_Get;
		ADL_WORKSTATION_LOADBALANCING_GET ADL_Workstation_LoadBalancing_Get;
		ADL_WORKSTATION_LOADBALANCING_SET ADL_Workstation_LoadBalancing_Set;
		ADL_WORKSTATION_LOADBALANCING_CAPS ADL_Workstation_LoadBalancing_Caps;
	
		int init(){
			#if defined (LINUX)
				if(getenv("DISPLAY") == NULL){
					setenv("DISPLAY", ":0", 0);
				}
			#endif

			void * hDLL = dlopen("libatiadlxx.so", RTLD_LAZY|RTLD_GLOBAL);

			if(hDLL == NULL){
				return BINDINGS_FAILED;
			}else{
				ADL_Main_Control_Create  = (ADL_MAIN_CONTROL_CREATE) dlsym(hDLL, "ADL_Main_Control_Create");
				ADL_Main_Control_Destroy = (ADL_MAIN_CONTROL_DESTROY) dlsym(hDLL, "ADL_Main_Control_Destroy");
				ADL_Main_Control_Refresh = (ADL_MAIN_CONTROL_REFRESH) dlsym(hDLL, "ADL_Main_Control_Refresh");
	
				ADL_Adapter_Active_Get           = (ADL_ADAPTER_ACTIVE_GET) dlsym(hDLL, "ADL_Adapter_Active_Get");
				ADL_Adapter_NumberOfAdapters_Get = (ADL_ADAPTER_NUMBEROFADAPTERS_GET) dlsym(hDLL, "ADL_Adapter_NumberOfAdapters_Get");
				ADL_Adapter_AdapterInfo_Get      = (ADL_ADAPTER_ADAPTERINFO_GET) dlsym(hDLL, "ADL_Adapter_AdapterInfo_Get");
				ADL_Adapter_ASICFamilyType_Get   = (ADL_ADAPTER_ASICFAMILYTYPE_GET) dlsym(hDLL, "ADL_Adapter_ASICFamilyType_Get");
				ADL_Adapter_Speed_Caps           = (ADL_ADAPTER_SPEED_CAPS) dlsym(hDLL, "ADL_Adapter_Speed_Caps");
				ADL_Adapter_Speed_Get            = (ADL_ADAPTER_SPEED_GET) dlsym(hDLL, "ADL_Adapter_Speed_Get");
				ADL_Adapter_Speed_Set            = (ADL_ADAPTER_SPEED_SET) dlsym(hDLL, "ADL_Adapter_Speed_Set");
				ADL_Adapter_Accessibility_Get    = (ADL_ADAPTER_ACCESSIBILITY_GET) dlsym(hDLL, "ADL_Adapter_Accessibility_Get");
				ADL_Adapter_VideoBiosInfo_Get    = (ADL_ADAPTER_VIDEOBIOSINFO_GET) dlsym(hDLL, "ADL_Adapter_VideoBiosInfo_Get");
				ADL_Adapter_ID_Get               = (ADL_ADAPTER_ID_GET) dlsym(hDLL, "ADL_Adapter_ID_Get");
				ADL_Adapter_Crossfire_Caps       = (ADL_ADAPTER_CROSSFIRE_CAPS) dlsym(hDLL, "ADL_Adapter_Crossfire_Caps");
				ADL_Adapter_Crossfire_Get        = (ADL_ADAPTER_CROSSFIRE_GET) dlsym(hDLL, "ADL_Adapter_Crossfire_Get");
				ADL_Adapter_Crossfire_Set        = (ADL_ADAPTER_CROSSFIRE_SET) dlsym(hDLL, "ADL_Adapter_Crossfire_Set");
				ADL_Adapter_MemoryInfo_Get       = (ADL_ADAPTER_MEMORYINFO_GET) dlsym(hDLL, "ADL_Adapter_MemoryInfo_Get");
				ADL_Adapter_ClockInfo_Get        = (ADL_ADAPTER_CLOCKINFO_GET) dlsym(hDLL, "ADL_Adapter_ClockInfo_Get");
				ADL_Display_AdapterID_Get        = (ADL_DISPLAY_ADAPTERID_GET) dlsym(hDLL, "ADL_Display_AdapterID_Get");
	
				ADL_ApplicationProfiles_System_Reload = (ADL_APPLICATIONPROFILES_SYSTEM_RELOAD) dlsym(hDLL, "ADL_ApplicationProfiles_System_Reload");
				ADL_ApplicationProfiles_User_Load     = (ADL_APPLICATIONPROFILES_USER_LOAD) dlsym(hDLL, "ADL_ApplicationProfiles_User_Load");
				ADL_ApplicationProfiles_User_Unload   = (ADL_APPLICATIONPROFILES_USER_UNLOAD) dlsym(hDLL, "ADL_ApplicationProfiles_User_Unload");
	
				ADL_Controller_Color_Set = (ADL_CONTROLLER_COLOR_SET) dlsym(hDLL, "ADL_Controller_Color_Set");
				ADL_Controller_Color_Get = (ADL_CONTROLLER_COLOR_GET) dlsym(hDLL, "ADL_Controller_Color_Get");
	
				ADL_Adapter_CrossdisplayAdaterRole_Caps = (ADL_ADAPTER_CROSSDISPLAYADAPTERROLE_CAPS) dlsym(hDLL, "ADL_Adapter_CrossdisplayAdaterRole_Caps");
				ADL_Adapter_CrossdisplayInfo_Get        = (ADL_ADAPTER_CROSSDISPLAYINFO_GET) dlsym(hDLL, "ADL_Adapter_CrossdisplayInfo_Get");
				ADL_Adapter_CrossdisplayInfo_Set        = (ADL_ADAPTER_CROSSDISPLAYINFO_SET) dlsym(hDLL, "ADL_Adapter_CrossdisplayInfo_Set");

				ADL_Display_DisplayInfo_Get                     = (ADL_DISPLAY_DISPLAYINFO_GET) dlsym(hDLL, "ADL_Display_DisplayInfo_Get");
				ADL_Display_NumberOfDisplays_Get                = (ADL_DISPLAY_NUMBEROFDISPLAYS_GET) dlsym(hDLL, "ADL_Display_NumberOfDisplays_Get");
				ADL_Display_PreservedAspectRatio_Get            = (ADL_DISPLAY_PRESERVEDASPECTRATIO_GET) dlsym(hDLL, "ADL_Display_PreservedAspectRatio_Get");
				ADL_Display_PreservedAspectRatio_Set            = (ADL_DISPLAY_PRESERVEDASPECTRATIO_SET) dlsym(hDLL, "ADL_Display_PreservedAspectRatio_Set");
				ADL_Display_ImageExpansion_Get                  = (ADL_DISPLAY_IMAGEEXPANSION_GET) dlsym(hDLL, "ADL_Display_ImageExpansion_Get");
				ADL_Display_ImageExpansion_Set                  = (ADL_DISPLAY_IMAGEEXPANSION_SET) dlsym(hDLL, "ADL_Display_ImageExpansion_Set");
				ADL_Display_Position_Get                        = (ADL_DISPLAY_POSITION_GET) dlsym(hDLL, "ADL_Display_Position_Get");
				ADL_Display_Position_Set                        = (ADL_DISPLAY_POSITION_SET) dlsym(hDLL, "ADL_Display_Position_Set");
				ADL_Display_Size_Get                            = (ADL_DISPLAY_SIZE_GET) dlsym(hDLL, "ADL_Display_Size_Get");
				ADL_Display_Size_Set                            = (ADL_DISPLAY_SIZE_SET) dlsym(hDLL, "ADL_Display_Size_Set");
				ADL_Display_AdjustCaps_Get                      = (ADL_DISPLAY_ADJUSTCAPS_GET) dlsym(hDLL, "ADL_Display_AdjustCaps_Get");
				ADL_Display_Capabilities_Get                    = (ADL_DISPLAY_CAPABILITIES_GET) dlsym(hDLL, "ADL_Display_Capabilities_Get");
				ADL_Display_ConnectedDisplays_Get               = (ADL_DISPLAY_CONNECTEDDISPLAYS_GET) dlsym(hDLL, "ADL_Display_ConnectedDisplays_Get");
				ADL_Display_DeviceConfig_Get                    = (ADL_DISPLAY_DEVICECONFIG_GET) dlsym(hDLL, "ADL_Display_DeviceConfig_Get");
				ADL_Display_Property_Get                        = (ADL_DISPLAY_PROPERTY_GET) dlsym(hDLL, "ADL_Display_Property_Get");
				ADL_Display_Property_Set                        = (ADL_DISPLAY_PROPERTY_SET) dlsym(hDLL, "ADL_Display_Property_Set");
				ADL_Display_SwitchingCapability_Get             = (ADL_DISPLAY_SWITCHINGCAPABILITY_GET) dlsym(hDLL, "ADL_Display_SwitchingCapability_Get");
				ADL_Display_DitherState_Get                     = (ADL_DISPLAY_DITHERSTATE_GET) dlsym(hDLL, "ADL_Display_DitherState_Get");
				ADL_Display_DitherState_Set                     = (ADL_DISPLAY_DITHERSTATE_SET) dlsym(hDLL, "ADL_Display_DitherState_Set");
				ADL_Display_SupportedPixelFormat_Get            = (ADL_DISPLAY_SUPPORTEDPIXELFORMAT_GET) dlsym(hDLL, "ADL_Display_SupportedPixelFormat_Get");
				ADL_Display_PixelFormat_Get                     = (ADL_DISPLAY_PIXELFORMAT_GET) dlsym(hDLL, "ADL_Display_PixelFormat_Get");
				ADL_Display_PixelFormat_Set                     = (ADL_DISPLAY_PIXELFORMAT_SET) dlsym(hDLL, "ADL_Display_PixelFormat_Set");
				ADL_Display_ODClockInfo_Get                     = (ADL_DISPLAY_ODCLOCKINFO_GET) dlsym(hDLL, "ADL_Display_ODClockInfo_Get");
				ADL_Display_ODClockConfig_Set                   = (ADL_DISPLAY_ODCLOCKCONFIG_SET) dlsym(hDLL, "ADL_Display_ODClockConfig_Set");
				ADL_Display_AdjustmentCoherent_Get              = (ADL_DISPLAY_ADJUSTMENTCOHERENT_GET) dlsym(hDLL, "ADL_Display_AdjustmentCoherent_Get");
				ADL_Display_AdjustmentCoherent_Set              = (ADL_DISPLAY_ADJUSTMENTCOHERENT_SET) dlsym(hDLL, "ADL_Display_AdjustmentCoherent_Set");
				ADL_Display_ReducedBlanking_Get                 = (ADL_DISPLAY_REDUCEDBLANKING_GET) dlsym(hDLL, "ADL_Display_ReducedBlanking_Get");
				ADL_Display_ReducedBlanking_Set                 = (ADL_DISPLAY_REDUCEDBLANKING_SET) dlsym(hDLL, "ADL_Display_ReducedBlanking_Set");
				ADL_Display_FormatsOverride_Get                 = (ADL_DISPLAY_FORMATSOVERRIDE_GET) dlsym(hDLL, "ADL_Display_FormatsOverride_Get");
				ADL_Display_FormatsOverride_Set                 = (ADL_DISPLAY_FORMATSOVERRIDE_SET) dlsym(hDLL, "ADL_Display_FormatsOverride_Set");
				ADL_Display_MVPUCaps_Get                        = (ADL_DISPLAY_MVPUCAPS_GET) dlsym(hDLL, "ADL_Display_MVPUCaps_Get");
				ADL_Display_MVPUStatus_Get                      = (ADL_DISPLAY_MVPUSTATUS_GET) dlsym(hDLL, "ADL_Display_MVPUStatus_Get");
				ADL_Display_ControllerOverlayAdjustmentCaps_Get = (ADL_DISPLAY_CONTROLLEROVERLAYADJUSTMENTCAPS_GET) dlsym(hDLL, "ADL_Display_ControllerOverlayAdjustmentCaps_Get");
				ADL_Display_ControllerOverlayAdjustmentData_Get = (ADL_DISPLAY_CONTROLLEROVERLAYADJUSTMENTDATA_GET) dlsym(hDLL, "ADL_Display_ControllerOverlayAdjustmentData_Get");
				ADL_Display_ControllerOverlayAdjustmentData_Set = (ADL_DISPLAY_CONTROLLEROVERLAYADJUSTMENTDATA_SET) dlsym(hDLL, "ADL_Display_ControllerOverlayAdjustmentData_Set");
				ADL_Display_WriteAndReadI2CRev_Get              = (ADL_DISPLAY_WRITEANDREADI2CREV_GET) dlsym(hDLL, "ADL_Display_WriteAndReadI2CRev_Get");
				ADL_Display_WriteAndReadI2C                     = (ADL_DISPLAY_WRITEADNREADI2C) dlsym(hDLL, "ADL_Display_WriteAndReadI2C");
				ADL_Display_DDCBlockAccess_Get                  = (ADL_DISPLAY_DDCBLOCKACCESS_GET) dlsym(hDLL, "ADL_Display_DDCBlockAccess_Get");
				ADL_Display_DDCInfo_Get                         = (ADL_DISPLAY_DDCINFO_GET) dlsym(hDLL, "ADL_Display_DDCInfo_Get");
				ADL_Display_EdidData_Get                        = (ADL_DISPLAY_EDIDDATEA_GET) dlsym(hDLL, "ADL_Display_EdidData_Get");
				ADL_Display_ColorCaps_Get                       = (ADL_DISPLAY_COLORCAPS_GET) dlsym(hDLL, "ADL_Display_ColorCaps_Get");
				ADL_Display_Color_Set                           = (ADL_DISPLAY_COLOR_SET) dlsym(hDLL, "ADL_Display_Color_Set");
				ADL_Display_Color_Get                           = (ADL_DISPLAY_COLOR_GET) dlsym(hDLL, "ADL_Display_Color_Get");
				ADL_Display_ColorTemperatureSource_Get          = (ADL_DISPLAY_COLORTEMPERATURESOURCE_GET) dlsym(hDLL, "ADL_Display_ColorTemperatureSource_Get");
				ADL_Display_ColorTemperatureSource_Set          = (ADL_DISPLAY_COLORTEMPERATURESOURCE_SET) dlsym(hDLL, "ADL_Display_ColorTemperatureSource_Set");
				ADL_Display_ModeTimingOverride_Get              = (ADL_DISPLAY_MODETIMINGOVERRIDE_GET) dlsym(hDLL, "ADL_Display_ModeTimingOverride_Get");
				ADL_Display_ModeTimingOverride_Set              = (ADL_DISPLAY_MODETIMINGOVERRIDE_SET) dlsym(hDLL, "ADL_Display_ModeTimingOverride_Set");
				ADL_Display_ModeTimingOverrideList_Get          = (ADL_DISPLAY_MODETIMINGOVERRIDELIST_GET) dlsym(hDLL, "ADL_Display_ModeTimingOverrideList_Get");
				ADL_Display_ModeTimingModelListNum_Get          = (ADL_DISPLAY_CUSTOMIZEDMODELISTNUM_GET) dlsym(hDLL, "ADL_Display_ModeTimingModelListNum_Get");
				ADL_Display_CustomizedModeList_Get              = (ADL_DISPLAY_CUSTOMIZEDMODELIST_GET) dlsym(hDLL, "ADL_Display_CustomizedModeList_Get");
				ADL_Display_CustomizedMode_Add                  = (ADL_DISPLAY_CUSTOMIZEDMODE_ADD) dlsym(hDLL, "ADL_Display_CustomizedMode_Add");
				ADL_Display_CustomizedMode_Delete               = (ADL_DISPLAY_CUSTOMIZEDMODE_DELETE) dlsym(hDLL, "ADL_Display_CustomizedMode_Delete");
				ADL_Display_CustomizedMode_Validate             = (ADL_DISPLAY_CUSTOMIZEDMODE_VALIDATE) dlsym(hDLL, "ADL_Display_CustomizedMode_Validate");
				ADL_Display_Underscan_Set                       = (ADL_DISPLAY_UNDERSCAN_SET) dlsym(hDLL, "ADL_Display_Underscan_Set");
				ADL_Display_Underscan_Get                       = (ADL_DISPLAY_UNDERSCAN_GET) dlsym(hDLL, "ADL_Display_Underscan_Get");
				ADL_Display_Overscan_Set                        = (ADL_DISPLAY_OVERSCAN_SET) dlsym(hDLL, "ADL_Display_Overscan_Set");
				ADL_Display_Overscan_Get                        = (ADL_DISPLAY_OVERSCAN_GET) dlsym(hDLL, "ADL_Display_Overscan_Get");
				ADL_DFP_BaseAudioSupport_Get                    = (ADL_DFP_BASEAUDIOSUPPORT_GET) dlsym(hDLL, "ADL_DFP_BaseAudioSupport_Get");
				ADL_DFP_HDMISupport_Get                         = (ADL_DFP_HDMISUPPORT_GET) dlsym(hDLL, "ADL_DFP_HDMISupport_Get");
				ADL_DFP_MVPUAnalogSupport_Get                   = (ADL_DFP_MVPUANALOGSUPPORT_GET) dlsym(hDLL, "ADL_DFP_MVPUAnalogSupport_Get");
				ADL_DFP_PixelFormat_Caps                        = (ADL_DFP_PIXELFORMAT_CAPS) dlsym(hDLL, "ADL_DFP_PixelFormat_Caps");
				ADL_DFP_PixelFormat_Get                         = (ADL_DFP_PIXELFORMAT_GET) dlsym(hDLL, "ADL_DFP_PixelFormat_Get");
				ADL_DFP_PixelFormat_Set                         = (ADL_DFP_PIXELFORMAT_SET) dlsym(hDLL, "ADL_DFP_PixelFormat_Set");
				ADL_DFP_GPUScalingEnable_Get                    = (ADL_DFP_GPUSCALINGENABLE_GET) dlsym(hDLL, "ADL_DFP_GPUScalingEnable_Get");
				ADL_DFP_GPUScalingEnable_Set                    = (ADL_DFP_GPUSCALINGENABLE_SET) dlsym(hDLL, "ADL_DFP_GPUScalingEnable_Set");
				ADL_DFP_AllowOnlyCETimings_Get                  = (ADL_DFP_ALLOWONLYCETIMINGS_GET) dlsym(hDLL, "ADL_DFP_AllowOnlyCETimings_Get");
				ADL_DFP_AllowOnlyCETimings_Set                  = (ADL_DFP_ALLOWONLYCETIMINGS_SET) dlsym(hDLL, "ADL_DFP_AllowOnlyCETimings_Set");
				ADL_Display_TVCaps_Get                          = (ADL_DISPLAY_TVCAPS_GET) dlsym(hDLL, "ADL_Display_TVCaps_Get");
				ADL_TV_Standard_Set                             = (ADL_TV_STANDARD_SET) dlsym(hDLL, "ADL_TV_Standard_Set");
				ADL_TV_Standard_Get                             = (ADL_TV_STANDARD_GET) dlsym(hDLL, "ADL_TV_Standard_Get");
				ADL_CV_DongleSettings_Get                       = (ADL_CV_DONGLESETTINGS_GET) dlsym(hDLL, "ADL_CV_DongleSettings_Get");
				ADL_CV_DongleSettings_Set                       = (ADL_CV_DONGLESETTINGS_SET) dlsym(hDLL, "ADL_CV_DongleSettings_Set");
				ADL_CV_DongleSettings_Reset                     = (ADL_CV_DONGLESETTINGS_RESET) dlsym(hDLL, "ADL_CV_DongleSettings_Reset");
				ADL_Display_PowerXpressVersion_Get              = (ADL_DISPLAY_POWERXPRESSVERSION_GET) dlsym(hDLL, "ADL_Display_PowerXpressVersion_Get");
				ADL_Display_PowerXpressActiveGpu_Get            = (ADL_DISPLAY_POWERXPRESSACTIVEGPU_GET) dlsym(hDLL, "ADL_Display_PowerXpressActiveGpu_Get");
				ADL_Display_PowerXpressActiveGpu_Set            = (ADL_DISPLAY_POWERXPRESSACTIVEGPU_SET) dlsym(hDLL, "ADL_Display_PowerXpressActiveGpu_Set");
				ADL_Display_PowerXpress_AutoSwitchConfig_Get    = (ADL_DISPLAY_POWERXPRESS_AUTOSWITCHCONFIG_GET) dlsym(hDLL, "ADL_Display_PowerXpress_AutoSwitchConfig_Get");
				ADL_Display_PowerXpress_AutoSwitchConfig_Set    = (ADL_DISPLAY_POWERXPRESS_AUTOSWITCHCONFIG_SET) dlsym(hDLL, "ADL_Display_PowerXpress_AutoSwitchConfig_Set");
				ADL_Display_UnderScan_Auto_Get                  = (ADL_DISPLAY_UNDERSCAN_AUTO_GET) dlsym(hDLL, "ADL_Display_UnderScan_Auto_Get");
				ADL_Display_UnderScan_Auto_Set                  = (ADL_DISPLAY_UNDERSCAN_AUTO_SET) dlsym(hDLL, "ADL_Display_UnderScan_Auto_Set");
				ADL_Display_Deflicker_Get                       = (ADL_DISPLAY_DEFLICKER_GET) dlsym(hDLL, "ADL_Display_Deflicker_Get");
				ADL_Display_Deflicker_Set                       = (ADL_DISPLAY_DEFLICKER_SET) dlsym(hDLL, "ADL_Display_Deflicker_Set");
				ADL_Display_FilterSVideo_Get                    = (ADL_DISPLAY_FILTERSVIDEO_GET) dlsym(hDLL, "ADL_Display_FilterSVideo_Get");
				ADL_Display_FilterSVideo_Set                    = (ADL_DISPLAY_FILTERSVIDEO_SET) dlsym(hDLL, "ADL_Display_FilterSVideo_Set");
	
				ADL_Adapter_Active_Set                            = (ADL_ADAPTER_ACTIVE_SET) dlsym(hDLL, "ADL_Adapter_Active_Set");
				ADL_Adapter_Active_SetPrefer                      = (ADL_ADAPTER_ACTIVE_SETPREFER) dlsym(hDLL, "ADL_Adapter_Active_SetPrefer");
				ADL_Adapter_Primary_Get                           = (ADL_ADAPTER_PRIMARY_GET) dlsym(hDLL, "ADL_Adapter_Primary_Get");
				ADL_Adapter_Primary_Set                           = (ADL_ADAPTER_PRIMARY_SET) dlsym(hDLL, "ADL_Adapter_Primary_Set");
				ADL_Adapter_ModeSwitch                            = (ADL_ADAPTER_MODESWITCH) dlsym(hDLL, "ADL_Adapter_ModeSwitch");
				ADL_Display_Modes_Get                             = (ADL_DISPLAY_MODES_GET) dlsym(hDLL, "ADL_Display_Modes_Get");
				ADL_Display_Modes_Set                             = (ADL_DISPLAY_MODES_SET) dlsym(hDLL, "ADL_Display_Modes_Set");
				ADL_Display_PossibleMode_Get                      = (ADL_DISPLAY_POSSIBLEMODE_GET) dlsym(hDLL, "ADL_Display_PossibleMode_Get");
				ADL_Display_ForcibleDisplay_Get                   = (ADL_DISPLAY_FORCIBLEDISPLAY_GET) dlsym(hDLL, "ADL_Display_ForcibleDisplay_Get");
				ADL_Display_ForcibleDisplay_Set                   = (ADL_DISPLAY_FORCIBLEDISPLAY_SET) dlsym(hDLL, "ADL_Display_ForcibleDisplay_Set");
				ADL_Adapter_NumberOfActivatableSources_Get        = (ADL_ADAPTER_NUMBEROFACTIVATABLESOURCES_GET) dlsym(hDLL, "ADL_Adapter_NumberOfActivatableSources_Get");
				ADL_Adapter_Display_Caps                          = (ADL_ADAPTER_DISPLAY_CAPS) dlsym(hDLL, "ADL_Adapter_Display_Caps");
				ADL_Adapter_DisplayMapConfig_Get                  = (ADL_DISPLAY_DISPLAYMAPCONFIG_GET) dlsym(hDLL, "ADL_Adapter_DisplayMapConfig_Get");
				ADL_Adapter_DisplayMapConfig_Set                  = (ADL_DISPLAY_DISPLAYMAPCONFIG_SET) dlsym(hDLL, "ADL_Adapter_DisplayMapConfig_Set");
				ADL_Display_PossibleMapping_Get                   = (ADL_DISPLAY_POSSIBLEMAPPING_GET) dlsym(hDLL, "ADL_Display_PossibleMapping_Get");
				ADL_Display_DisplayMapConfig_Validate             = (ADL_DISPLAY_DISPLAYMAPCONFIG_VALIDATE) dlsym(hDLL, "ADL_Display_DisplayMapConfig_Validate");
				ADL_Display_DisplayMapConfig_PossibleAddAndRemove = (ADL_DISPLAY_DISPLAYMAPCONFIG_POSSIBLEADDANDREMOVE) dlsym(hDLL, "ADL_Display_DisplayMapConfig_PossibleAddAndRemove");
				ADL_Display_SLSGrid_Caps                          = (ADL_DISPLAY_SLSGRID_CAPS) dlsym(hDLL, "ADL_Display_SLSGrid_Caps");
				ADL_Display_SLSMapIndexList_Get                   = (ADL_DISPLAY_SLSMAPINDEXLIST_GET) dlsym(hDLL, "ADL_Display_SLSMapIndexList_Get");
				ADL_Display_SLSMapIndex_Get                       = (ADL_DISPLAY_SLSMAPINDEX_GET) dlsym(hDLL, "ADL_Display_SLSMapIndex_Get");
				ADL_Display_SLSMapConfig_Get                      = (ADL_DISPLAY_SLSMAPCONFIG_GET) dlsym(hDLL, "ADL_Display_SLSMapConfig_Get");
				ADL_Display_SLSMapConfig_Create                   = (ADL_DISPLAY_SLSMAPCONFIG_CREATE) dlsym(hDLL, "ADL_Display_SLSMapConfig_Create");
				ADL_Display_SLSMapConfig_Delete                   = (ADL_DISPLAY_SLSMAPCONFIG_DELETE) dlsym(hDLL, "ADL_Display_SLSMapConfig_Delete");
				ADL_Display_SLSMapConfig_SetState                 = (ADL_DISPLAY_SLSMAPCONFIG_SETSTATE) dlsym(hDLL, "ADL_Display_SLSMapConfig_SetState");
				ADL_Display_SLSMapConfig_RearRange                = (ADL_DISPLAY_SLSMAPCONFIG_REARRANGE) dlsym(hDLL, "ADL_Display_SLSMapConfig_RearRange");
				ADL_Display_PossibleMode_WinXP_Get                = (ADL_DISPLAY_POSSIBLEMODE_WINXP_GET) dlsym(hDLL, "ADL_Display_PossibleMode_WinXP_Get");
				ADL_Display_BezelOffsetSteppingSize_Get           = (ADL_DISPLAY_BEZELOFFSETSTEPPINGSIZE_GET) dlsym(hDLL, "ADL_Display_BezelOffsetSteppingSize_Get");
				ADL_Display_BezelOffset_Set                       = (ADL_DISPLAY_BEZELOFFSET_SET) dlsym(hDLL, "ADL_Display_BezelOffset_Set");
				ADL_Display_BezelSupported_Validate               = (ADL_DISPLAY_BEZELSUPPORTED_VALIDATE) dlsym(hDLL, "ADL_Display_BezelSupported_Validate");
	
				ADL_Graphics_Platform_Get = (ADL_GRAPHICS_PLATFORM_GET) dlsym(hDLL, "ADL_Graphics_Platform_Get");
	
				ADL_DesktopConfig_Get                     = (ADL_DESKTOPCONFIG_GET) dlsym(hDLL, "ADL_DesktopConfig_Get");
				ADL_DesktopConfig_Set                     = (ADL_DESKTOPCONFIG_SET) dlsym(hDLL, "ADL_DesktopConfig_Set");
				ADL_NumberOfDisplayEnable_Get             = (ADL_NUMBEROFDISPLAYENABLE_GET) dlsym(hDLL, "ADL_NumberOfDisplayEnable_Get");
				ADL_DisplayEnable_Set                     = (ADL_DISPLAYENABLE_SET) dlsym(hDLL, "ADL_DisplayEnable_Set");
				ADL_Display_IdentifyDisplay               = (ADL_DISPLAY_IDENTIFYDISPLAY) dlsym(hDLL, "ADL_Display_IdentifyDisplay");
				ADL_Display_LUTColor_Set                  = (ADL_DISPLAY_LUTCOLOR_SET) dlsym(hDLL, "ADL_Display_LUTColor_Set");
				ADL_Display_LUTColor_Get                  = (ADL_DISPLAY_LUTCOLOR_GET) dlsym(hDLL, "ADL_Display_LUTColor_Get");
				ADL_Adapter_XScreenInfo_Get               = (ADL_ADAPTER_XSCREENINFO_GET) dlsym(hDLL, "ADL_Adapter_XScreenInfo_Get");
				ADL_Adapter_Display_XrandrDisplayName_Get = (ADL_DISPLAY_XRANDRDISPLAYNAME_GET) dlsym(hDLL, "ADL_Adapter_Display_XrandrDisplayName_Get");
	
				ADL_Overdrive5_CurrentActivity_Get     = (ADL_OVERDRIVE5_CURRENTACTIVITY_GET) dlsym(hDLL, "ADL_Overdrive5_CurrentActivity_Get");
				ADL_Overdrive5_ThermalDevices_Enum     = (ADL_OVERDRIVE5_THERMALDEVICES_ENUM) dlsym(hDLL, "ADL_Overdrive5_ThermalDevices_Enum");
				ADL_Overdrive5_Temperature_Get         = (ADL_OVERDRIVE5_TEMPERATURE_GET) dlsym(hDLL, "ADL_Overdrive5_Temperature_Get");
				ADL_Overdrive5_FanSpeedInfo_Get        = (ADL_OVERDRIVE5_FANSPEEDINFO_GET) dlsym(hDLL, "ADL_Overdrive5_FanSpeedInfo_Get");
				ADL_Overdrive5_FanSpeed_Get            = (ADL_OVERDRIVE5_FANSPEED_GET) dlsym(hDLL, "ADL_Overdrive5_FanSpeed_Get");
				ADL_Overdrive5_FanSpeed_Set            = (ADL_OVERDRIVE5_FANSPEED_SET) dlsym(hDLL, "ADL_Overdrive5_FanSpeed_Set");
				ADL_Overdrive5_FanSpeedToDefault_Set   = (ADL_OVERDRIVE5_FANSPEEDTODEFAULT_SET) dlsym(hDLL, "ADL_Overdrive5_FanSpeedToDefault_Set");
				ADL_Overdrive5_ODParameters_Get        = (ADL_OVERDRIVE5_ODPARAMETERS_GET) dlsym(hDLL, "ADL_Overdrive5_ODParameters_Get");
				ADL_Overdrive5_ODPerformanceLevels_Get = (ADL_OVERDRIVE5_ODPERFORMANCELEVELS_GET) dlsym(hDLL, "ADL_Overdrive5_ODPerformanceLevels_Get");
				ADL_Overdrive5_ODPerformanceLevels_Set = (ADL_OVERDRIVE5_ODPERFORMANCELEVELS_SET) dlsym(hDLL, "ADL_Overdrive5_ODPerformanceLevels_Set");
	
				ADL_Workstation_Caps                             = (ADL_WORKSTATION_CAPS) dlsym(hDLL, "ADL_Workstation_Caps");
				ADL_Workstation_Stereo_Get                       = (ADL_WORKSTATION_STEREO_GET) dlsym(hDLL, "ADL_Workstation_Stereo_Get");
				ADL_Workstation_Stereo_Set                       = (ADL_WORKSTATION_STEREO_SET) dlsym(hDLL, "ADL_Workstation_Stereo_Set");
				ADL_Workstation_AdapterNumOfGLSyncConnectors_Get = (ADL_WORKSTATION_ADAPTERNUMOFGLSYNCCONNECTORS_GET) dlsym(hDLL, "ADL_Workstation_AdapterNumOfGLSyncConnectors_Get");
				ADL_Workstation_DisplayGenlockCapable_Get        = (ADL_WORKSTATION_DISPLAYGENLOCKCAPABLE_GET) dlsym(hDLL, "ADL_Workstation_DisplayGenlockCapable_Get");
				ADL_Workstation_GLSyncModuleDetect_Get           = (ADL_WORKSTATION_GLSYNCMODULEDETECT_GET) dlsym(hDLL, "ADL_Workstation_GLSyncModuleDetect_Get");
				ADL_Workstation_GLSyncModuleInfo_Get             = (ADL_WORKSTATION_GLSYNCMODULEINFO_GET) dlsym(hDLL, "ADL_Workstation_GLSyncModuleInfo_Get");
				ADL_Workstation_GLSyncGenlockConfiguration_Get   = (ADL_WORKSTATION_GLSYNCGENLOCKCONFIGURATION_GET) dlsym(hDLL, "ADL_Workstation_GLSyncGenlockConfiguration_Get");
				ADL_Workstation_GLSyncGenlockConfiguration_Set   = (ADL_WORKSTATION_GLSYNCGENLOCKCONFIGURATION_SET) dlsym(hDLL, "ADL_Workstation_GLSyncGenlockConfiguration_Set");
				ADL_Workstation_GLSyncPortState_Get              = (ADL_WORKSTATION_GLSYNCPORTSTATE_GET) dlsym(hDLL, "ADL_Workstation_GLSyncPortState_Get");
				ADL_Workstation_GLSyncPortState_Set              = (ADL_WORKSTATION_GLSYNCPORTSTATE_SET) dlsym(hDLL, "ADL_Workstation_GLSyncPortState_Set");
				ADL_Workstation_DisplayGLSyncMode_Get            = (ADL_WORKSTATION_DISPLAYGLSYNCMODE_GET) dlsym(hDLL, "ADL_Workstation_DisplayGLSyncMode_Get");
				ADL_Workstation_DisplayGLSyncMode_Set            = (ADL_WORKSTATION_DISPLAYGLSYNCMODE_SET) dlsym(hDLL, "ADL_Workstation_DisplayGLSyncMode_Set");
				ADL_Workstation_GLSyncSupportedTopology_Get      = (ADL_WORKSTATION_GLSYNCSUPPORTEDTOPOLOGY_GET) dlsym(hDLL, "ADL_Workstation_GLSyncSupportedTopology_Get");
				ADL_Workstation_LoadBalancing_Get                = (ADL_WORKSTATION_LOADBALANCING_GET) dlsym(hDLL, "ADL_Workstation_LoadBalancing_Get");
				ADL_Workstation_LoadBalancing_Set                = (ADL_WORKSTATION_LOADBALANCING_SET) dlsym(hDLL, "ADL_Workstation_LoadBalancing_Set");
				ADL_Workstation_LoadBalancing_Caps               = (ADL_WORKSTATION_LOADBALANCING_CAPS) dlsym(hDLL, "ADL_Workstation_LoadBalancing_Caps");

				return BINDINGS_OK;
			}
		}
	}
}
