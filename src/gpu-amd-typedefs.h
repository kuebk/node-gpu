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

#ifndef GPU_AMD_TYPEDEFS_H
#define GPU_AMD_TYPEDEFS_H

#include "include/adl_sdk.h"

//adl.h
typedef int ( *ADL_MAIN_CONTROL_CREATE )(ADL_MAIN_MALLOC_CALLBACK, int);
typedef int ( *ADL_MAIN_CONTROL_DESTROY )();
typedef int ( *ADL_MAIN_CONTROL_REFRESH )();

//adapter.h
typedef int ( *ADL_ADAPTER_ACTIVE_GET )(int, int *);
typedef int ( *ADL_ADAPTER_NUMBEROFADAPTERS_GET )(int *);
typedef int ( *ADL_ADAPTER_ADAPTERINFO_GET )(LPAdapterInfo, int);
typedef int ( *ADL_ADAPTER_ASICFAMILYTYPE_GET )(int, int *, int *);
typedef int ( *ADL_ADAPTER_SPEED_CAPS )(int, int *, int *);
typedef int ( *ADL_ADAPTER_SPEED_GET )(int, int *, int *);
typedef int ( *ADL_ADAPTER_SPEED_SET )(int, int);
typedef int ( *ADL_ADAPTER_ACCESSIBILITY_GET )(int ,int *);
typedef int ( *ADL_ADAPTER_VIDEOBIOSINFO_GET )(int, ADLBiosInfo *);
typedef int ( *ADL_ADAPTER_ID_GET )(int, int *);
typedef int ( *ADL_ADAPTER_CROSSFIRE_CAPS )(int, int *, int *, ADLCrossfireComb **);
typedef int ( *ADL_ADAPTER_CROSSFIRE_GET )(int, ADLCrossfireComb *, ADLCrossfireInfo *);
typedef int ( *ADL_ADAPTER_CROSSFIRE_SET )(int, ADLCrossfireComb *);
typedef int ( *ADL_ADAPTER_MEMORYINFO_GET )(int, ADLMemoryInfo *);
typedef int ( *ADL_ADAPTER_CLOCKINFO_GET )(int, ADLClockInfo *);
typedef int ( *ADL_DISPLAY_ADAPTERID_GET )(int, int *);

//appprofiles.h
typedef int ( *ADL_APPLICATIONPROFILES_SYSTEM_RELOAD )();
typedef int ( *ADL_APPLICATIONPROFILES_USER_LOAD )();
typedef int ( *ADL_APPLICATIONPROFILES_USER_UNLOAD )();

//controller.h
typedef int ( *ADL_CONTROLLER_COLOR_SET )(int, int, ADLGamma);
typedef int ( *ADL_CONTROLLER_COLOR_GET )(int, int, ADLGamma *, ADLGamma *, ADLGamma *, ADLGamma *);

//crossdisplay.h
typedef int ( *ADL_ADAPTER_CROSSDISPLAYADAPTERROLE_CAPS )(int, int *, int *, int *, int **, int *, int **, int *);
typedef int ( *ADL_ADAPTER_CROSSDISPLAYINFO_GET )(int, int *, int *, int *, int **, int *, int **, int *);
typedef int ( *ADL_ADAPTER_CROSSDISPLAYINFO_SET )(int, int, int, int, int *);

//display.h
typedef int ( *ADL_DISPLAY_DISPLAYINFO_GET )(int, int *, ADLDisplayInfo **, int);
typedef int ( *ADL_DISPLAY_NUMBEROFDISPLAYS_GET )(int, int *);
typedef int ( *ADL_DISPLAY_PRESERVEDASPECTRATIO_GET )(int, int, int *, int *, int *);
typedef int ( *ADL_DISPLAY_PRESERVEDASPECTRATIO_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_IMAGEEXPANSION_GET )(int, int, int *, int *, int *);
typedef int ( *ADL_DISPLAY_IMAGEEXPANSION_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_POSITION_GET )(int, int, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *);
typedef int ( *ADL_DISPLAY_POSITION_SET )(int, int, int, int);
typedef int ( *ADL_DISPLAY_SIZE_GET )(int, int, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *);
typedef int ( *ADL_DISPLAY_SIZE_SET )(int, int, int, int);
typedef int ( *ADL_DISPLAY_ADJUSTCAPS_GET )(int, int, int *);
typedef int ( *ADL_DISPLAY_CAPABILITIES_GET )(int, int *, int *);
typedef int ( *ADL_DISPLAY_CONNECTEDDISPLAYS_GET )(int, int *);
typedef int ( *ADL_DISPLAY_DEVICECONFIG_GET )(int, int, ADLDisplayConfig *);
typedef int ( *ADL_DISPLAY_PROPERTY_GET )(int, int, ADLDisplayProperty *);
typedef int ( *ADL_DISPLAY_PROPERTY_SET )(int, int, ADLDisplayProperty *);
typedef int ( *ADL_DISPLAY_SWITCHINGCAPABILITY_GET )(int, int *);
typedef int ( *ADL_DISPLAY_DITHERSTATE_GET )(int, int, int *);
typedef int ( *ADL_DISPLAY_DITHERSTATE_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_SUPPORTEDPIXELFORMAT_GET )(int, int, int *);
typedef int ( *ADL_DISPLAY_PIXELFORMAT_GET )(int, int, int *);
typedef int ( *ADL_DISPLAY_PIXELFORMAT_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_ODCLOCKINFO_GET )(int, ADLAdapterODClockInfo *);
typedef int ( *ADL_DISPLAY_ODCLOCKCONFIG_SET )(int, ADLAdapterODClockConfig *);
typedef int ( *ADL_DISPLAY_ADJUSTMENTCOHERENT_GET )(int, int, int *, int *);
typedef int ( *ADL_DISPLAY_ADJUSTMENTCOHERENT_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_REDUCEDBLANKING_GET )(int, int, int *, int *);
typedef int ( *ADL_DISPLAY_REDUCEDBLANKING_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_FORMATSOVERRIDE_GET )(int, int, int *, int *, int *);
typedef int ( *ADL_DISPLAY_FORMATSOVERRIDE_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_MVPUCAPS_GET )(int, ADLMVPUStatus *);
typedef int ( *ADL_DISPLAY_MVPUSTATUS_GET )(int, ADLMVPUStatus *);
typedef int ( *ADL_DISPLAY_CONTROLLEROVERLAYADJUSTMENTCAPS_GET )(int, ADLControllerOverlayInput *, ADLControllerOverlayInfo *);
typedef int ( *ADL_DISPLAY_CONTROLLEROVERLAYADJUSTMENTDATA_GET )(int, ADLControllerOverlayInput *);
typedef int ( *ADL_DISPLAY_CONTROLLEROVERLAYADJUSTMENTDATA_SET )(int, ADLControllerOverlayInput *);
typedef int ( *ADL_DISPLAY_WRITEANDREADI2CREV_GET )(int, int *, int *);
typedef int ( *ADL_DISPLAY_WRITEADNREADI2C )(int, ADLI2C *);
typedef int ( *ADL_DISPLAY_DDCBLOCKACCESS_GET )(int, int, int, int, int, char *, int *, char *);
typedef int ( *ADL_DISPLAY_DDCINFO_GET )(int, int, ADLDDCInfo *);
typedef int ( *ADL_DISPLAY_EDIDDATEA_GET )(int, int, ADLDisplayEDIDData *);
typedef int ( *ADL_DISPLAY_COLORCAPS_GET )(int, int, int *, int *);
typedef int ( *ADL_DISPLAY_COLOR_SET )(int, int, int, int);
typedef int ( *ADL_DISPLAY_COLOR_GET )(int, int, int, int *, int *, int *, int *, int *);
typedef int ( *ADL_DISPLAY_COLORTEMPERATURESOURCE_GET )(int, int, int *);
typedef int ( *ADL_DISPLAY_COLORTEMPERATURESOURCE_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_MODETIMINGOVERRIDE_GET )(int, int, ADLDisplayMode *, ADLDisplayModeInfo *);
typedef int ( *ADL_DISPLAY_MODETIMINGOVERRIDE_SET )(int, int, ADLDisplayModeInfo *, int);
typedef int ( *ADL_DISPLAY_MODETIMINGOVERRIDELIST_GET )(int, int, int, ADLDisplayModeInfo *, int *);
typedef int ( *ADL_DISPLAY_CUSTOMIZEDMODELISTNUM_GET )(int, int, int *);
typedef int ( *ADL_DISPLAY_CUSTOMIZEDMODELIST_GET )(int, int, ADLCustomMode *, int);
typedef int ( *ADL_DISPLAY_CUSTOMIZEDMODE_ADD )(int, int, ADLCustomMode);
typedef int ( *ADL_DISPLAY_CUSTOMIZEDMODE_DELETE )(int, int, int);
typedef int ( *ADL_DISPLAY_CUSTOMIZEDMODE_VALIDATE )(int, int, ADLCustomMode, int *);
typedef int ( *ADL_DISPLAY_UNDERSCAN_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_UNDERSCAN_GET )(int, int, int *, int *, int *, int *, int *);
typedef int ( *ADL_DISPLAY_OVERSCAN_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_OVERSCAN_GET )(int, int, int *, int *, int *, int *, int *);
typedef int ( *ADL_DFP_BASEAUDIOSUPPORT_GET )(int, int, int *);
typedef int ( *ADL_DFP_HDMISUPPORT_GET )(int, int, int *);
typedef int ( *ADL_DFP_MVPUANALOGSUPPORT_GET )(int, int, int *);
typedef int ( *ADL_DFP_PIXELFORMAT_CAPS )(int, int, int *, int *);
typedef int ( *ADL_DFP_PIXELFORMAT_GET )(int, int, int *, int *);
typedef int ( *ADL_DFP_PIXELFORMAT_SET )(int, int, int);
typedef int ( *ADL_DFP_GPUSCALINGENABLE_GET )(int, int, int *, int *, int *);
typedef int ( *ADL_DFP_GPUSCALINGENABLE_SET )(int, int, int);
typedef int ( *ADL_DFP_ALLOWONLYCETIMINGS_GET )(int, int, int *, int *, int *);
typedef int ( *ADL_DFP_ALLOWONLYCETIMINGS_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_TVCAPS_GET )(int, int, int *);
typedef int ( *ADL_TV_STANDARD_SET )(int, int, int);
typedef int ( *ADL_TV_STANDARD_GET )(int, int, int *, int *, int *);
typedef int ( *ADL_CV_DONGLESETTINGS_GET )(int, int, int *, int *, int *);
typedef int ( *ADL_CV_DONGLESETTINGS_SET )(int, int, int);
typedef int ( *ADL_CV_DONGLESETTINGS_RESET )(int, int);
typedef int ( *ADL_DISPLAY_POWERXPRESSVERSION_GET )(int, int *);
typedef int ( *ADL_DISPLAY_POWERXPRESSACTIVEGPU_GET )(int, int *);
typedef int ( *ADL_DISPLAY_POWERXPRESSACTIVEGPU_SET )(int, int, int *);
typedef int ( *ADL_DISPLAY_POWERXPRESS_AUTOSWITCHCONFIG_GET )(int, int *, int *);
typedef int ( *ADL_DISPLAY_POWERXPRESS_AUTOSWITCHCONFIG_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_UNDERSCAN_AUTO_GET )(int, int, int *, int *, int *, int *, int *);
typedef int ( *ADL_DISPLAY_UNDERSCAN_AUTO_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_DEFLICKER_GET )(int, int, int *, int *, int *, int *, int *);
typedef int ( *ADL_DISPLAY_DEFLICKER_SET )(int, int, int);
typedef int ( *ADL_DISPLAY_FILTERSVIDEO_GET )(int, int, int *, int *, int *, int *, int *);
typedef int ( *ADL_DISPLAY_FILTERSVIDEO_SET )(int, int, int);

//displaymanager.h
typedef int ( *ADL_ADAPTER_ACTIVE_SET )(int, int, int *);
typedef	int	( *ADL_ADAPTER_ACTIVE_SETPREFER )(int, int, int, ADLDisplayTarget *, int *);
typedef	int	( *ADL_ADAPTER_PRIMARY_GET )(int *);
typedef	int	( *ADL_ADAPTER_PRIMARY_SET )(int);
typedef	int	( *ADL_ADAPTER_MODESWITCH )(int);
typedef	int	( *ADL_DISPLAY_MODES_GET )(int, int, int *, ADLMode **);
typedef	int	( *ADL_DISPLAY_MODES_SET )(int, int, int, ADLMode *);
typedef	int	( *ADL_DISPLAY_POSSIBLEMODE_GET )(int, int *, ADLMode **);
typedef	int	( *ADL_DISPLAY_FORCIBLEDISPLAY_GET )(int, int, int *);
typedef	int	( *ADL_DISPLAY_FORCIBLEDISPLAY_SET )(int, int, int);
typedef	int ( *ADL_ADAPTER_NUMBEROFACTIVATABLESOURCES_GET )(int, int *, ADLActivatableSource **);
typedef	int	( *ADL_ADAPTER_DISPLAY_CAPS )(int, int *, ADLAdapterDisplayCap **);
typedef	int	( *ADL_DISPLAY_DISPLAYMAPCONFIG_GET )(int, int *, ADLDisplayMap **, int *, ADLDisplayTarget **, int);
typedef	int	( *ADL_DISPLAY_DISPLAYMAPCONFIG_SET )(int, int, ADLDisplayMap *, int, ADLDisplayTarget *);
typedef	int ( *ADL_DISPLAY_POSSIBLEMAPPING_GET )(int, int, ADLPossibleMapping *, int, int *, ADLPossibleMapping **);
typedef	int	( *ADL_DISPLAY_DISPLAYMAPCONFIG_VALIDATE )(int, int, ADLPossibleMap *, int *, ADLPossibleMapResult **);
typedef	int	( *ADL_DISPLAY_DISPLAYMAPCONFIG_POSSIBLEADDANDREMOVE )(int, int, ADLDisplayMap *, int, ADLDisplayTarget *, int *, ADLDisplayTarget **, int *, ADLDisplayTarget **);
typedef	int	( *ADL_DISPLAY_SLSGRID_CAPS )(int, int *, ADLSLSGrid **, int);
typedef	int	( *ADL_DISPLAY_SLSMAPINDEXLIST_GET )(int, int *, int **, int);
typedef	int	( *ADL_DISPLAY_SLSMAPINDEX_GET )(int, int, ADLDisplayTarget *, int *);
typedef	int	( *ADL_DISPLAY_SLSMAPCONFIG_GET )(int, int, ADLSLSMap *, int *, ADLSLSTarget **, int *, ADLSLSMode **, int *, ADLBezelTransientMode **, int *, ADLBezelTransientMode **, int *, ADLSLSOffset **, int);
typedef	int	( *ADL_DISPLAY_SLSMAPCONFIG_CREATE )(int, ADLSLSMap, int, ADLSLSTarget *, int, int *, int);
typedef	int	( *ADL_DISPLAY_SLSMAPCONFIG_DELETE )(int, int);
typedef	int	( *ADL_DISPLAY_SLSMAPCONFIG_SETSTATE )(int, int, int);
typedef int	( *ADL_DISPLAY_SLSMAPCONFIG_REARRANGE )(int, int, int, ADLSLSTarget *, ADLSLSMap, int);
typedef int	( *ADL_DISPLAY_POSSIBLEMODE_WINXP_GET )(int, int, ADLDisplayTarget *, int, int, int *, ADLMode **);
typedef	int ( *ADL_DISPLAY_BEZELOFFSETSTEPPINGSIZE_GET )(int, int *, ADLBezelOffsetSteppingSize **);
typedef	int	( *ADL_DISPLAY_BEZELOFFSET_SET )(int, int, int, LPADLSLSOffset, ADLSLSMap, int);
typedef	int	( *ADL_DISPLAY_BEZELSUPPORTED_VALIDATE )(int, int, LPADLPossibleSLSMap, int *, LPADLPossibleMapResult *);

//graphics.h
typedef int	( *ADL_GRAPHICS_PLATFORM_GET )(int *);

//lnx.h
typedef int	( *ADL_DESKTOPCONFIG_GET )(int, int *);
typedef int	( *ADL_DESKTOPCONFIG_SET )(int, int);
typedef	int	( *ADL_NUMBEROFDISPLAYENABLE_GET )(int, int *);
typedef	int	( *ADL_DISPLAYENABLE_SET )(int, int *, int, int);
typedef	int	( *ADL_DISPLAY_IDENTIFYDISPLAY )(int, int, int, int, int, int, int);
typedef	int	( *ADL_DISPLAY_LUTCOLOR_SET )(int, int, ADLGamma);
typedef	int	( *ADL_DISPLAY_LUTCOLOR_GET )(int, int, ADLGamma *, ADLGamma *, ADLGamma *, ADLGamma *);
typedef	int	( *ADL_ADAPTER_XSCREENINFO_GET )(LPXScreenInfo, int);
typedef	int	( *ADL_DISPLAY_XRANDRDISPLAYNAME_GET )(int, int, char *, int);

//overdrive5.h
typedef int	( *ADL_OVERDRIVE5_CURRENTACTIVITY_GET )(int, ADLPMActivity *);
typedef	int	( *ADL_OVERDRIVE5_THERMALDEVICES_ENUM )(int, int, ADLThermalControllerInfo *);
typedef	int	( *ADL_OVERDRIVE5_TEMPERATURE_GET )(int, int, ADLTemperature *);
typedef	int	( *ADL_OVERDRIVE5_FANSPEEDINFO_GET )(int, int, ADLFanSpeedInfo *);
typedef	int	( *ADL_OVERDRIVE5_FANSPEED_GET )(int, int, ADLFanSpeedValue *);
typedef	int	( *ADL_OVERDRIVE5_FANSPEED_SET )(int, int, ADLFanSpeedValue *);
typedef	int	( *ADL_OVERDRIVE5_FANSPEEDTODEFAULT_SET )(int, int);
typedef	int	( *ADL_OVERDRIVE5_ODPARAMETERS_GET )(int, ADLODParameters *);
typedef	int	( *ADL_OVERDRIVE5_ODPERFORMANCELEVELS_GET )(int, int, ADLODPerformanceLevels *);
typedef	int	( *ADL_OVERDRIVE5_ODPERFORMANCELEVELS_SET )(int, ADLODPerformanceLevels *);

//workstation.h
typedef int	( *ADL_WORKSTATION_CAPS )(int, int *, int *);
typedef	int	( *ADL_WORKSTATION_STEREO_GET )(int, int *, int *);
typedef	int	( *ADL_WORKSTATION_STEREO_SET )(int, int);
typedef	int	( *ADL_WORKSTATION_ADAPTERNUMOFGLSYNCCONNECTORS_GET )(int, int *);
typedef	int	( *ADL_WORKSTATION_DISPLAYGENLOCKCAPABLE_GET )(int, int, int *);
typedef	int ( *ADL_WORKSTATION_GLSYNCMODULEDETECT_GET )(int, int, ADLGLSyncModuleID *);
typedef	int	( *ADL_WORKSTATION_GLSYNCMODULEINFO_GET )(int, int, int *, int *, int *, int *, ADLGLSyncPortCaps **);
typedef	int	( *ADL_WORKSTATION_GLSYNCGENLOCKCONFIGURATION_GET )(int, int, int, ADLGLSyncGenlockConfig *);
typedef	int	( *ADL_WORKSTATION_GLSYNCGENLOCKCONFIGURATION_SET )(int, int, ADLGLSyncGenlockConfig);
typedef	int	( *ADL_WORKSTATION_GLSYNCPORTSTATE_GET )(int, int, int, int, ADLGlSyncPortInfo *, int **);
typedef	int	( *ADL_WORKSTATION_GLSYNCPORTSTATE_SET )(int, int, ADLGlSyncPortControl);
typedef	int	( *ADL_WORKSTATION_DISPLAYGLSYNCMODE_GET )(int, int, ADLGlSyncMode *);
typedef	int	( *ADL_WORKSTATION_DISPLAYGLSYNCMODE_SET )(int, int, ADLGlSyncMode);
typedef	int	( *ADL_WORKSTATION_GLSYNCSUPPORTEDTOPOLOGY_GET )(int, int, ADLGlSyncMode2 *, int *, ADLGlSyncMode2 **);
typedef	int	( *ADL_WORKSTATION_LOADBALANCING_GET )(int *, int *, int *);
typedef	int	( *ADL_WORKSTATION_LOADBALANCING_SET )(int);
typedef	int	( *ADL_WORKSTATION_LOADBALANCING_CAPS )(int, int *, int *);

#endif
