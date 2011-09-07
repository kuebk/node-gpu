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

#ifndef GPU_BINDINGS_H
#define GPU_BINDINGS_H

#define BINDINGS_FAILED  0
#define BINDINGS_OK  1

#include "gpu-amd-typedefs.h"

namespace Bindings {
		namespace AMD {
		extern ADL_MAIN_CONTROL_CREATE ADL_Main_Control_Create;
		extern ADL_MAIN_CONTROL_DESTROY ADL_Main_Control_Destroy;
		extern ADL_MAIN_CONTROL_REFRESH ADL_Main_Control_Refresh;

		extern ADL_ADAPTER_ACTIVE_GET ADL_Adapter_Active_Get;
		extern ADL_ADAPTER_NUMBEROFADAPTERS_GET ADL_Adapter_NumberOfAdapters_Get;
		extern ADL_ADAPTER_ADAPTERINFO_GET ADL_Adapter_AdapterInfo_Get;
		extern ADL_ADAPTER_ASICFAMILYTYPE_GET ADL_Adapter_ASICFamilyType_Get;
		extern ADL_ADAPTER_SPEED_CAPS ADL_Adapter_Speed_Caps;
		extern ADL_ADAPTER_SPEED_GET ADL_Adapter_Speed_Get;
		extern ADL_ADAPTER_SPEED_SET ADL_Adapter_Speed_Set;
		extern ADL_ADAPTER_ACCESSIBILITY_GET ADL_Adapter_Accessibility_Get;
		extern ADL_ADAPTER_VIDEOBIOSINFO_GET ADL_Adapter_VideoBiosInfo_Get;
		extern ADL_ADAPTER_ID_GET ADL_Adapter_ID_Get;
		extern ADL_ADAPTER_CROSSFIRE_CAPS ADL_Adapter_Crossfire_Caps;
		extern ADL_ADAPTER_CROSSFIRE_GET ADL_Adapter_Crossfire_Get;
		extern ADL_ADAPTER_CROSSFIRE_SET ADL_Adapter_Crossfire_Set;
		extern ADL_ADAPTER_MEMORYINFO_GET ADL_Adapter_MemoryInfo_Get;
		extern ADL_ADAPTER_CLOCKINFO_GET ADL_Adapter_ClockInfo_Get;
		extern ADL_DISPLAY_ADAPTERID_GET ADL_Display_AdapterID_Get;

		extern ADL_APPLICATIONPROFILES_SYSTEM_RELOAD ADL_ApplicationProfiles_System_Reload;
		extern ADL_APPLICATIONPROFILES_USER_LOAD ADL_ApplicationProfiles_User_Load;
		extern ADL_APPLICATIONPROFILES_USER_UNLOAD ADL_ApplicationProfiles_User_Unload;

		extern ADL_CONTROLLER_COLOR_SET ADL_Controller_Color_Set;
		extern ADL_CONTROLLER_COLOR_GET ADL_Controller_Color_Get;

		extern ADL_ADAPTER_CROSSDISPLAYADAPTERROLE_CAPS ADL_Adapter_CrossdisplayAdaterRole_Caps;
		extern ADL_ADAPTER_CROSSDISPLAYINFO_GET ADL_Adapter_CrossdisplayInfo_Get;
		extern ADL_ADAPTER_CROSSDISPLAYINFO_SET ADL_Adapter_CrossdisplayInfo_Set;

		extern ADL_DISPLAY_DISPLAYINFO_GET ADL_Display_DisplayInfo_Get;
		extern ADL_DISPLAY_NUMBEROFDISPLAYS_GET ADL_Display_NumberOfDisplays_Get;
		extern ADL_DISPLAY_PRESERVEDASPECTRATIO_GET ADL_Display_PreservedAspectRatio_Get;
		extern ADL_DISPLAY_PRESERVEDASPECTRATIO_SET ADL_Display_PreservedAspectRatio_Set;
		extern ADL_DISPLAY_IMAGEEXPANSION_GET ADL_Display_ImageExpansion_Get;
		extern ADL_DISPLAY_IMAGEEXPANSION_SET ADL_Display_ImageExpansion_Set;
		extern ADL_DISPLAY_POSITION_GET ADL_Display_Position_Get;
		extern ADL_DISPLAY_POSITION_SET ADL_Display_Position_Set;
		extern ADL_DISPLAY_SIZE_GET ADL_Display_Size_Get;
		extern ADL_DISPLAY_SIZE_SET ADL_Display_Size_Set;
		extern ADL_DISPLAY_ADJUSTCAPS_GET ADL_Display_AdjustCaps_Get;
		extern ADL_DISPLAY_CAPABILITIES_GET ADL_Display_Capabilities_Get;
		extern ADL_DISPLAY_CONNECTEDDISPLAYS_GET ADL_Display_ConnectedDisplays_Get;
		extern ADL_DISPLAY_DEVICECONFIG_GET ADL_Display_DeviceConfig_Get;
		extern ADL_DISPLAY_PROPERTY_GET ADL_Display_Property_Get;
		extern ADL_DISPLAY_PROPERTY_SET ADL_Display_Property_Set;
		extern ADL_DISPLAY_SWITCHINGCAPABILITY_GET ADL_Display_SwitchingCapability_Get;
		extern ADL_DISPLAY_DITHERSTATE_GET ADL_Display_DitherState_Get;
		extern ADL_DISPLAY_DITHERSTATE_SET ADL_Display_DitherState_Set;
		extern ADL_DISPLAY_SUPPORTEDPIXELFORMAT_GET ADL_Display_SupportedPixelFormat_Get;
		extern ADL_DISPLAY_PIXELFORMAT_GET ADL_Display_PixelFormat_Get;
		extern ADL_DISPLAY_PIXELFORMAT_SET ADL_Display_PixelFormat_Set;
		extern ADL_DISPLAY_ODCLOCKINFO_GET ADL_Display_ODClockInfo_Get;
		extern ADL_DISPLAY_ODCLOCKCONFIG_SET ADL_Display_ODClockConfig_Set;
		extern ADL_DISPLAY_ADJUSTMENTCOHERENT_GET ADL_Display_AdjustmentCoherent_Get;
		extern ADL_DISPLAY_ADJUSTMENTCOHERENT_SET ADL_Display_AdjustmentCoherent_Set;
		extern ADL_DISPLAY_REDUCEDBLANKING_GET ADL_Display_ReducedBlanking_Get;
		extern ADL_DISPLAY_REDUCEDBLANKING_SET ADL_Display_ReducedBlanking_Set;
		extern ADL_DISPLAY_FORMATSOVERRIDE_GET ADL_Display_FormatsOverride_Get;
		extern ADL_DISPLAY_FORMATSOVERRIDE_SET ADL_Display_FormatsOverride_Set;
		extern ADL_DISPLAY_MVPUCAPS_GET ADL_Display_MVPUCaps_Get;
		extern ADL_DISPLAY_MVPUSTATUS_GET ADL_Display_MVPUStatus_Get;
		extern ADL_DISPLAY_CONTROLLEROVERLAYADJUSTMENTCAPS_GET ADL_Display_ControllerOverlayAdjustmentCaps_Get;
		extern ADL_DISPLAY_CONTROLLEROVERLAYADJUSTMENTDATA_GET ADL_Display_ControllerOverlayAdjustmentData_Get;
		extern ADL_DISPLAY_CONTROLLEROVERLAYADJUSTMENTDATA_SET ADL_Display_ControllerOverlayAdjustmentData_Set;
		extern ADL_DISPLAY_WRITEANDREADI2CREV_GET ADL_Display_WriteAndReadI2CRev_Get;
		extern ADL_DISPLAY_WRITEADNREADI2C ADL_Display_WriteAndReadI2C;
		extern ADL_DISPLAY_DDCBLOCKACCESS_GET ADL_Display_DDCBlockAccess_Get;
		extern ADL_DISPLAY_DDCINFO_GET ADL_Display_DDCInfo_Get;
		extern ADL_DISPLAY_EDIDDATEA_GET ADL_Display_EdidData_Get;
		extern ADL_DISPLAY_COLORCAPS_GET ADL_Display_ColorCaps_Get;
		extern ADL_DISPLAY_COLOR_SET ADL_Display_Color_Set;
		extern ADL_DISPLAY_COLOR_GET ADL_Display_Color_Get;
		extern ADL_DISPLAY_COLORTEMPERATURESOURCE_GET ADL_Display_ColorTemperatureSource_Get;
		extern ADL_DISPLAY_COLORTEMPERATURESOURCE_SET ADL_Display_ColorTemperatureSource_Set;
		extern ADL_DISPLAY_MODETIMINGOVERRIDE_GET ADL_Display_ModeTimingOverride_Get;
		extern ADL_DISPLAY_MODETIMINGOVERRIDE_SET ADL_Display_ModeTimingOverride_Set;
		extern ADL_DISPLAY_MODETIMINGOVERRIDELIST_GET ADL_Display_ModeTimingOverrideList_Get;
		extern ADL_DISPLAY_CUSTOMIZEDMODELISTNUM_GET ADL_Display_ModeTimingModelListNum_Get;
		extern ADL_DISPLAY_CUSTOMIZEDMODELIST_GET ADL_Display_CustomizedModeList_Get;
		extern ADL_DISPLAY_CUSTOMIZEDMODE_ADD ADL_Display_CustomizedMode_Add;
		extern ADL_DISPLAY_CUSTOMIZEDMODE_DELETE ADL_Display_CustomizedMode_Delete;
		extern ADL_DISPLAY_CUSTOMIZEDMODE_VALIDATE ADL_Display_CustomizedMode_Validate;
		extern ADL_DISPLAY_UNDERSCAN_SET ADL_Display_Underscan_Set;
		extern ADL_DISPLAY_UNDERSCAN_GET ADL_Display_Underscan_Get;
		extern ADL_DISPLAY_OVERSCAN_SET ADL_Display_Overscan_Set;
		extern ADL_DISPLAY_OVERSCAN_GET ADL_Display_Overscan_Get;
		extern ADL_DFP_BASEAUDIOSUPPORT_GET ADL_DFP_BaseAudioSupport_Get;
		extern ADL_DFP_HDMISUPPORT_GET ADL_DFP_HDMISupport_Get;
		extern ADL_DFP_MVPUANALOGSUPPORT_GET ADL_DFP_MVPUAnalogSupport_Get;
		extern ADL_DFP_PIXELFORMAT_CAPS ADL_DFP_PixelFormat_Caps;
		extern ADL_DFP_PIXELFORMAT_GET ADL_DFP_PixelFormat_Get;
		extern ADL_DFP_PIXELFORMAT_SET ADL_DFP_PixelFormat_Set;
		extern ADL_DFP_GPUSCALINGENABLE_GET ADL_DFP_GPUScalingEnable_Get;
		extern ADL_DFP_GPUSCALINGENABLE_SET ADL_DFP_GPUScalingEnable_Set;
		extern ADL_DFP_ALLOWONLYCETIMINGS_GET ADL_DFP_AllowOnlyCETimings_Get;
		extern ADL_DFP_ALLOWONLYCETIMINGS_SET ADL_DFP_AllowOnlyCETimings_Set;
		extern ADL_DISPLAY_TVCAPS_GET ADL_Display_TVCaps_Get;
		extern ADL_TV_STANDARD_SET ADL_TV_Standard_Set;
		extern ADL_TV_STANDARD_GET ADL_TV_Standard_Get;
		extern ADL_CV_DONGLESETTINGS_GET ADL_CV_DongleSettings_Get;
		extern ADL_CV_DONGLESETTINGS_SET ADL_CV_DongleSettings_Set;
		extern ADL_CV_DONGLESETTINGS_RESET ADL_CV_DongleSettings_Reset;
		extern ADL_DISPLAY_POWERXPRESSVERSION_GET ADL_Display_PowerXpressVersion_Get;
		extern ADL_DISPLAY_POWERXPRESSACTIVEGPU_GET ADL_Display_PowerXpressActiveGpu_Get;
		extern ADL_DISPLAY_POWERXPRESSACTIVEGPU_SET ADL_Display_PowerXpressActiveGpu_Set;
		extern ADL_DISPLAY_POWERXPRESS_AUTOSWITCHCONFIG_GET ADL_Display_PowerXpress_AutoSwitchConfig_Get;
		extern ADL_DISPLAY_POWERXPRESS_AUTOSWITCHCONFIG_SET ADL_Display_PowerXpress_AutoSwitchConfig_Set;
		extern ADL_DISPLAY_UNDERSCAN_AUTO_GET ADL_Display_UnderScan_Auto_Get;
		extern ADL_DISPLAY_UNDERSCAN_AUTO_SET ADL_Display_UnderScan_Auto_Set;
		extern ADL_DISPLAY_DEFLICKER_GET ADL_Display_Deflicker_Get;
		extern ADL_DISPLAY_DEFLICKER_SET ADL_Display_Deflicker_Set;
		extern ADL_DISPLAY_FILTERSVIDEO_GET ADL_Display_FilterSVideo_Get;
		extern ADL_DISPLAY_FILTERSVIDEO_SET ADL_Display_FilterSVideo_Set;

		extern ADL_ADAPTER_ACTIVE_SET ADL_Adapter_Active_Set;
		extern ADL_ADAPTER_ACTIVE_SETPREFER ADL_Adapter_Active_SetPrefer;
		extern ADL_ADAPTER_PRIMARY_GET ADL_Adapter_Primary_Get;
		extern ADL_ADAPTER_PRIMARY_SET ADL_Adapter_Primary_Set;
		extern ADL_ADAPTER_MODESWITCH ADL_Adapter_ModeSwitch;
		extern ADL_DISPLAY_MODES_GET ADL_Display_Modes_Get;
		extern ADL_DISPLAY_MODES_SET ADL_Display_Modes_Set;
		extern ADL_DISPLAY_POSSIBLEMODE_GET ADL_Display_PossibleMode_Get;
		extern ADL_DISPLAY_FORCIBLEDISPLAY_GET ADL_Display_ForcibleDisplay_Get;
		extern ADL_DISPLAY_FORCIBLEDISPLAY_SET ADL_Display_ForcibleDisplay_Set;
		extern ADL_ADAPTER_NUMBEROFACTIVATABLESOURCES_GET ADL_Adapter_NumberOfActivatableSources_Get;
		extern ADL_ADAPTER_DISPLAY_CAPS ADL_Adapter_Display_Caps;
		extern ADL_DISPLAY_DISPLAYMAPCONFIG_GET ADL_Adapter_DisplayMapConfig_Get;
		extern ADL_DISPLAY_DISPLAYMAPCONFIG_SET ADL_Adapter_DisplayMapConfig_Set;
		extern ADL_DISPLAY_POSSIBLEMAPPING_GET ADL_Display_PossibleMapping_Get;
		extern ADL_DISPLAY_DISPLAYMAPCONFIG_VALIDATE ADL_Display_DisplayMapConfig_Validate;
		extern ADL_DISPLAY_DISPLAYMAPCONFIG_POSSIBLEADDANDREMOVE ADL_Display_DisplayMapConfig_PossibleAddAndRemove;
		extern ADL_DISPLAY_SLSGRID_CAPS ADL_Display_SLSGrid_Caps;
		extern ADL_DISPLAY_SLSMAPINDEXLIST_GET ADL_Display_SLSMapIndexList_Get;
		extern ADL_DISPLAY_SLSMAPINDEX_GET ADL_Display_SLSMapIndex_Get;
		extern ADL_DISPLAY_SLSMAPCONFIG_GET ADL_Display_SLSMapConfig_Get;
		extern ADL_DISPLAY_SLSMAPCONFIG_CREATE ADL_Display_SLSMapConfig_Create;
		extern ADL_DISPLAY_SLSMAPCONFIG_DELETE ADL_Display_SLSMapConfig_Delete;
		extern ADL_DISPLAY_SLSMAPCONFIG_SETSTATE ADL_Display_SLSMapConfig_SetState;
		extern ADL_DISPLAY_SLSMAPCONFIG_REARRANGE ADL_Display_SLSMapConfig_RearRange;
		extern ADL_DISPLAY_POSSIBLEMODE_WINXP_GET ADL_Display_PossibleMode_WinXP_Get;
		extern ADL_DISPLAY_BEZELOFFSETSTEPPINGSIZE_GET ADL_Display_BezelOffsetSteppingSize_Get;
		extern ADL_DISPLAY_BEZELOFFSET_SET ADL_Display_BezelOffset_Set;
		extern ADL_DISPLAY_BEZELSUPPORTED_VALIDATE ADL_Display_BezelSupported_Validate;

		extern ADL_GRAPHICS_PLATFORM_GET ADL_Graphics_Platform_Get;

		extern ADL_DESKTOPCONFIG_GET ADL_DesktopConfig_Get;
		extern ADL_DESKTOPCONFIG_SET ADL_DesktopConfig_Set;
		extern ADL_NUMBEROFDISPLAYENABLE_GET ADL_NumberOfDisplayEnable_Get;
		extern ADL_DISPLAYENABLE_SET ADL_DisplayEnable_Set;
		extern ADL_DISPLAY_IDENTIFYDISPLAY ADL_Display_IdentifyDisplay;
		extern ADL_DISPLAY_LUTCOLOR_SET ADL_Display_LUTColor_Set;
		extern ADL_DISPLAY_LUTCOLOR_GET ADL_Display_LUTColor_Get;
		extern ADL_ADAPTER_XSCREENINFO_GET ADL_Adapter_XScreenInfo_Get;
		extern ADL_DISPLAY_XRANDRDISPLAYNAME_GET ADL_Adapter_Display_XrandrDisplayName_Get;

		extern ADL_OVERDRIVE5_CURRENTACTIVITY_GET ADL_Overdrive5_CurrentActivity_Get;
		extern ADL_OVERDRIVE5_THERMALDEVICES_ENUM ADL_Overdrive5_ThermalDevices_Enum;
		extern ADL_OVERDRIVE5_TEMPERATURE_GET ADL_Overdrive5_Temperature_Get;
		extern ADL_OVERDRIVE5_FANSPEEDINFO_GET ADL_Overdrive5_FanSpeedInfo_Get;
		extern ADL_OVERDRIVE5_FANSPEED_GET ADL_Overdrive5_FanSpeed_Get;
		extern ADL_OVERDRIVE5_FANSPEED_SET ADL_Overdrive5_FanSpeed_Set;
		extern ADL_OVERDRIVE5_FANSPEEDTODEFAULT_SET ADL_Overdrive5_FanSpeedToDefault_Set;
		extern ADL_OVERDRIVE5_ODPARAMETERS_GET ADL_Overdrive5_ODParameters_Get;
		extern ADL_OVERDRIVE5_ODPERFORMANCELEVELS_GET ADL_Overdrive5_ODPerformanceLevels_Get;
		extern ADL_OVERDRIVE5_ODPERFORMANCELEVELS_SET ADL_Overdrive5_ODPerformanceLevels_Set;

		extern ADL_WORKSTATION_CAPS ADL_Workstation_Caps;
		extern ADL_WORKSTATION_STEREO_GET ADL_Workstation_Stereo_Get;
		extern ADL_WORKSTATION_STEREO_SET ADL_Workstation_Stereo_Set;
		extern ADL_WORKSTATION_ADAPTERNUMOFGLSYNCCONNECTORS_GET ADL_Workstation_AdapterNumOfGLSyncConnectors_Get;
		extern ADL_WORKSTATION_DISPLAYGENLOCKCAPABLE_GET ADL_Workstation_DisplayGenlockCapable_Get;
		extern ADL_WORKSTATION_GLSYNCMODULEDETECT_GET ADL_Workstation_GLSyncModuleDetect_Get;
		extern ADL_WORKSTATION_GLSYNCMODULEINFO_GET ADL_Workstation_GLSyncModuleInfo_Get;
		extern ADL_WORKSTATION_GLSYNCGENLOCKCONFIGURATION_GET ADL_Workstation_GLSyncGenlockConfiguration_Get;
		extern ADL_WORKSTATION_GLSYNCGENLOCKCONFIGURATION_SET ADL_Workstation_GLSyncGenlockConfiguration_Set;
		extern ADL_WORKSTATION_GLSYNCPORTSTATE_GET ADL_Workstation_GLSyncPortState_Get;
		extern ADL_WORKSTATION_GLSYNCPORTSTATE_SET ADL_Workstation_GLSyncPortState_Set;
		extern ADL_WORKSTATION_DISPLAYGLSYNCMODE_GET ADL_Workstation_DisplayGLSyncMode_Get;
		extern ADL_WORKSTATION_DISPLAYGLSYNCMODE_SET ADL_Workstation_DisplayGLSyncMode_Set;
		extern ADL_WORKSTATION_GLSYNCSUPPORTEDTOPOLOGY_GET ADL_Workstation_GLSyncSupportedTopology_Get;
		extern ADL_WORKSTATION_LOADBALANCING_GET ADL_Workstation_LoadBalancing_Get;
		extern ADL_WORKSTATION_LOADBALANCING_SET ADL_Workstation_LoadBalancing_Set;
		extern ADL_WORKSTATION_LOADBALANCING_CAPS ADL_Workstation_LoadBalancing_Caps;

		void * __stdcall ADL_Main_Memory_Alloc(int iSize);
		void __stdcall ADL_Main_Memory_Free(void ** lpBuffer);

		int init();
	}
}

#endif
