// Copyright (C) 2022 Beken Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "ohos_init.h"
#include "wifi_device_util.h"
#include <stdio.h>
#include "common.h"
#include "cmsis_os2.h"

#define WIFI_WAIT_FOREVER 0xFFFFFFFF
#define CHANNEL_80211B_ONLY 14
#define FREQ_OF_CHANNEL_1 2412
#define FREQ_OF_CHANNEL_80211B_ONLY 2484
#define WIFI_MIN_CHANNEL 1
#define WIFI_FREQ_INTERVAL 5

static MutexId g_wifiGlobalLock = NULL;
static MutexId g_wifiEventLock = NULL;



WifiSecurityType BKSecToHoSec(wifi_security_t mode)
{
	switch (mode) 
	{
		case WIFI_SECURITY_NONE:
			return WIFI_SEC_TYPE_OPEN;
		
		case WIFI_SECURITY_WEP:
			return WIFI_SEC_TYPE_WEP;

		case WIFI_SECURITY_WPA_TKIP:
		case WIFI_SECURITY_WPA_AES:
		case WIFI_SECURITY_WPA2_TKIP:
		case WIFI_SECURITY_WPA2_AES:
		case WIFI_SECURITY_WPA2_MIXED:	
			return WIFI_SEC_TYPE_PSK;

		case WIFI_SECURITY_WPA3_SAE:
		case WIFI_SECURITY_WPA3_WPA2_MIXED:
			return WIFI_SEC_TYPE_SAE;
		default:
			return WIFI_SEC_TYPE_INVALID;
	}
}

wifi_security_t HoSecToBKSec(WifiSecurityType mode)
{
	switch(mode)
	{
		case WIFI_SEC_TYPE_OPEN:
			return WIFI_SECURITY_NONE;
		case WIFI_SEC_TYPE_WEP:
			return WIFI_SECURITY_WEP;
		case WIFI_SEC_TYPE_PSK:
			return WIFI_SECURITY_WPA2_MIXED;
		case WIFI_SEC_TYPE_SAE:
			return WIFI_SECURITY_WPA3_WPA2_MIXED;
		default:
			return WIFI_SEC_TYPE_INVALID;
	}
}


static void InitWifiGlobalLock(void)
{
	printf("core init : InitWifiGlobalLock\n");
	
	if (g_wifiGlobalLock == NULL) 
	{
		osMutexAttr_t globalMutexAttr = 
		{
			"WifiGloablLock",
			osMutexRecursive | osMutexPrioInherit,
			NULL,
			0U
		};
		g_wifiGlobalLock = osMutexNew(&globalMutexAttr);
	}
	
	if (g_wifiEventLock == NULL) 
	{
		osMutexAttr_t eventMutexAttr = 
		{
			"WifiEventLock",
			osMutexRecursive | osMutexPrioInherit,
			NULL,
			0U
		};
		g_wifiEventLock = osMutexNew(&eventMutexAttr);
	}
}

WifiErrorCode LockWifiGlobalLock(void)
{
	if (g_wifiGlobalLock == NULL) 
	{
		return ERROR_WIFI_UNKNOWN;
	}

	osStatus_t ret = osMutexAcquire(g_wifiGlobalLock, WIFI_WAIT_FOREVER);
	if (ret != osOK) 
	{
		printf("[wifi_service] osMutexAcquire failed \n");
		return ERROR_WIFI_UNKNOWN;
	}

	return WIFI_SUCCESS;
}

WifiErrorCode UnlockWifiGlobalLock(void)
{
	if (g_wifiGlobalLock == NULL) 
	{
		return ERROR_WIFI_UNKNOWN;
	}
	osStatus_t ret = osMutexRelease(g_wifiGlobalLock);
	if (ret != osOK) 
	{
		printf("[wifi_service] osMutexUnlock failed \n");
		return ERROR_WIFI_UNKNOWN;
	}
	return WIFI_SUCCESS;
}

WifiErrorCode LockWifiEventLock(void)
{
	if (g_wifiEventLock == NULL) 
	{
		return ERROR_WIFI_UNKNOWN;
	}
	osStatus_t ret = osMutexAcquire(g_wifiEventLock, WIFI_WAIT_FOREVER);
	if (ret != osOK) 
	{
		printf("[wifi_service] osMutexAcquire event failed \n");
		return ERROR_WIFI_UNKNOWN;
	}
	return WIFI_SUCCESS;
}

WifiErrorCode UnlockWifiEventLock(void)
{
	if (g_wifiEventLock == NULL) 
	{
		return ERROR_WIFI_UNKNOWN;
	}

	osStatus_t ret = osMutexRelease(g_wifiEventLock);
	if (ret != osOK) 
	{
		printf("[wifi_service] osMutexUnlock event failed \n");
		return ERROR_WIFI_UNKNOWN;
	}
	return WIFI_SUCCESS;
}
unsigned int ChannelToFrequency(unsigned int channel)
{
	if (channel <= 0) 
	{
		return 0;
	}
	if (channel == CHANNEL_80211B_ONLY) 
	{
		return FREQ_OF_CHANNEL_80211B_ONLY;
	}
	return (((channel - WIFI_MIN_CHANNEL) * WIFI_FREQ_INTERVAL) + FREQ_OF_CHANNEL_1);
}

unsigned int FrequencyToChannel(unsigned int frequency)
{
	if (frequency == FREQ_OF_CHANNEL_80211B_ONLY) 
	{
		return CHANNEL_80211B_ONLY;
	}

	if (frequency < FREQ_OF_CHANNEL_1) 
	{
		return 0;
	}

	return (frequency - FREQ_OF_CHANNEL_1) / WIFI_FREQ_INTERVAL + WIFI_MIN_CHANNEL;
}

CORE_INIT(InitWifiGlobalLock);
