//PHDL Windows library version 2.7.0.6
//PHDL Linux library version 2.7.0.1
//PHDL MacOSX library version 2.7.0.1

#pragma once

#ifndef PHONEHOMEAPI

#include <stdlib.h>
#ifdef _WIN32 
#include <wchar.h>

#ifdef UNICODE
#define _TT(x) _T(x)
#endif

#else
#undef _TT
#define _TT(x) x
#endif

#if LIB_BUILD
#define PHONEHOMEAPI DSYExport
#else
    #if USING_PHDL_DLL
    #define PHONEHOMEAPI DSYImport
    #else
    #define PHONEHOMEAPI
    #endif
#endif
#include "DSYExport.h"

#endif

#ifdef __cplusplus
extern "C" {
#endif

	typedef enum _Phdl_SendDataAsyncStatus
	{
		InProgress = 1,
		Successful = 2,
		Failed = 3,
		Disabled = 4
	} Phdl_EnumSendDataAsyncStatus;

	typedef enum _Phdl_EventType
	{
		Undefined,
		Legal,
		Evaluation,
		Educational,
		Unlicensed,
		UnlicensedProjectFile
	} Phdl_EnumEventType;

	typedef enum _EnumPhdlInfoField
	{
		LastAccessedFile,
		Features,
		Trigger,
		ServiceRelease,
		LicenseSerialNumber,
		LicensedTo,
		LicenseExpiryDate,
		EventType,
		AdditionalInfo,
		ValidLicenseInfo,
		PiracyLicenseInfo,
		PiracyAuthorID,
		Custom1,
		Custom2,
		Custom3,
		Custom4,
		Custom5,
		ApplicationInstallDate,
		LicenseType,
		CurrentConnectionSessions,
		MaxCurrentConnectionSessions,
		Heartbeat,
		ServiceGUID,
	} EnumPhdlInfoField;

	typedef enum _EnumPhdlHashingMode
	{
		NoClientSideHashing,
		HashBasedOnServerSettings,
		AlwaysHashOnClient
	} EnumPhdlHashingMode;

#ifdef _WIN32
	typedef enum _EnumPhdlSendOption
	{
		JavaScriptIESend,
		DirectDataSend,
		IESend
	} EnumPhdlSendOption;
#endif

	typedef struct _PhdlOptions
	{
		char *Username;
		char *Password;
		char *ProductName;
		char *ProductVersion;
		char *PathToStorageFile;

		size_t NumberOfServerUrls;
		char **ArrayOfServerUrls;

		unsigned char *EncryptionKey;
		int DataObfuscated;

		int IncludeInstalledApplications;
#if defined(__linux__) || defined(__APPLE__)
		int StoreServerDataOnDisk;
#endif

		unsigned int TimeBetweenCapturesSec;
		unsigned int TimeBetweenSendSec;
		unsigned int MaxStorageFileCaptures;

		int UseRetryBasedBackupURLs;
		unsigned int SendRetryCount;
		unsigned int SendRetryIntervalMs;

	} PhdlOptions, *PPhdlOptions;

#ifdef _WIN32
	typedef struct _PhdlOptionsW
	{
		wchar_t *Username;
		wchar_t *Password;
		wchar_t *ProductName;
		wchar_t *ProductVersion;
		wchar_t *PathToStorageFile;

		size_t NumberOfServerUrls;
		wchar_t **ArrayOfServerUrls;

		unsigned char *EncryptionKey;
		bool DataObfuscated;

		int IncludeInstalledApplications;

		unsigned int TimeBetweenCapturesSec;
		unsigned int TimeBetweenSendSec;
		unsigned int MaxStorageFileCaptures;

		int UseRetryBasedBackupURLs;
		unsigned int SendRetryCount;
		unsigned int SendRetryIntervalMs;

	} PhdlOptionsW, *PPhdlOptionsW;
#endif

	typedef struct _PhdlResponse
	{
		char **UrlList;
		char **CustomMessages;
		char *Error;
		char *InAppMessage;

		size_t NumberOfMessages;
		size_t NumberOfUrls;

		int IsValid;
		int AppStatus;
	} PhdlResponse, *PPhdlResponse;

#ifdef _WIN32
	typedef struct _PhdlResponseW
	{
		wchar_t **UrlList;
		wchar_t **CustomMessages;
		wchar_t *Error;
		wchar_t *InAppMessage;

		size_t NumberOfMessages;
		size_t NumberOfUrls;

		int IsValid;
		int AppStatus;
	} PhdlResponseW, *PPhdlResponseW;
#endif

	//Phdl_InitializeOptions - Call this function as a constructor to the PhdlOptions or PhdlOptionsW structs
	PHONEHOMEAPI int Phdl_IO(PhdlOptions *options);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_IOW(PhdlOptionsW *options);
#endif

	//Phdl_IsCaptureConfigurationSet - This is useful for detecting if the configuration has already been set in the past, in order to prevent overriding settings
	PHONEHOMEAPI int Phdl_ICCS(void);

	//Phdl_InitializeConfiguration - This function initializes the PHDL internal configuration with custom options
	//The PHDL internal configuration needs to be initialized before using the library capturing and data-sending functionalities
	//Call this function after initializing the PhdlOptions struct, using the Phdl_InitializeOptions function (Phdl_IO)
	PHONEHOMEAPI int Phdl_IC(const PhdlOptions *options);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_ICW(const PhdlOptionsW *options);
#endif

	//Phdl_InitializeConfigFromFile - This function initializes the configuration from an existing PHDL settings file
	PHONEHOMEAPI int Phdl_ICFF(void);

	//Phdl_RecordAdditionalInformation - This function can be called to register an application-specific information or event (for example "User has tried to print a page")
	PHONEHOMEAPI int Phdl_RAI(const char *information, int overwriteInformation);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_RAIW(const wchar_t *information, int overwriteInformation);
#endif

	//Phdl_RecordValidLicenseInformation - This function can be called to update License Information (mLI)
	PHONEHOMEAPI int Phdl_RVLI(const char *li, int overwriteInformation);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_RVLIW(const wchar_t *li, int overwriteInformation);
#endif

	//Phdl_RecordPiracyLicenseInformation - This function can be called to update Piracy License Information (mPLI) and Piracy Author ID (mPAI)
	PHONEHOMEAPI int Phdl_RPLI(const char *pli, const char *pai, int overwriteInformation);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_RPLIW(const wchar_t *pli, const wchar_t *pai, int overwriteInformation);
#endif

	//Phdl_SetInformationField - This function is used to set the information contained by various Phdl internal fields, present in the EnumPhdlInfoField enum
	PHONEHOMEAPI int Phdl_SIF(EnumPhdlInfoField infoField, void const *value);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_SIFW(EnumPhdlInfoField infoField, void const *value);
#endif

	//Phdl_SetAllowCapture - This is the function that sets the flag which allows or disables data capturing
	PHONEHOMEAPI int Phdl_SAC(int allow);

	//Phdl_StartCaptureSession - This function can be called when the product has been started, in order to begin automatic capturing 
	//Note that you'll need to call Phdl_SAC(1) beforehand, so that the capturing is allowed
	PHONEHOMEAPI int Phdl_StaCS(void);

	//Phdl_StopCaptureSession - This function can be called before the product has exited, in order to end the automatic capturing
	PHONEHOMEAPI int Phdl_StoCS(void);

	//Phdl_ForceSendDataOnline - This function can be called during a capture session to force a data send to the server
	//The 'G' versions return an array of GUIDs, one for each entry sent
	PHONEHOMEAPI int Phdl_FSDO(void);
	PHONEHOMEAPI int Phdl_FSDOG(char ***guid, size_t *outSize);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_FSDOGW(wchar_t ***guid, size_t *outSize);
#endif

	//Phdl_StoreDataToDisk - This function can be called when a storage file is configured in order to create a capture and store it.
	//The 'G' versions return the entry GUID
	PHONEHOMEAPI int Phdl_SDTD(void);
	PHONEHOMEAPI int Phdl_SDTDG(char **guid);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_SDTDGW(wchar_t ** guid);
#endif

	//Phdl_SendDataOnTheFly - This function is useful for sending just 1 PHDL entry to the server, on the fly
	//The 'G' versions return the entry GUID
	PHONEHOMEAPI int Phdl_SDOTF(void);
	PHONEHOMEAPI int Phdl_SDOTFG(char **guid);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_SDOTFGW(wchar_t **guid);
#endif

	//Phdl_SendDataOnTheFlyAsync - This function is similar in scope to its Phdl_SDOTF counterpart, with the addition that it performs the data-sending on a separate thread (async)
	//This function returns whether the thread creation was successful or not
	//The 'G' versions return the entry GUID
	PHONEHOMEAPI int Phdl_SDOTFA(void);
	PHONEHOMEAPI int Phdl_SDOTFAG(char **guid);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_SDOTFAGW(wchar_t **guid);
#endif

	//Phdl_SendDataOnTheFlyAsyncWithCallback - This function is mostly the same as the Phdl_SDOTFA function, but takes a function pointer as a parameter and calls that function when it finishes processing
	//This function returns whether the thread creation was successful or not
	//The 'G' versions return the entry GUID
	PHONEHOMEAPI int Phdl_SDOTFAC(void(*callback)(int success, void *), void *callbackParam);
	PHONEHOMEAPI int Phdl_SDOTFACG(void(*callback)(int success, void *), void *callbackParam, char **guid);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_SDOTFACGW(void(*callback)(int success, void *), void *callbackParam, wchar_t **guid);
#endif

	//Phdl_GetSendDataAsyncStatus - Gets the status of the latest async method call (from Phdl_SDOTFA)
	PHONEHOMEAPI int Phdl_GSDAS(void);

	//Phdl_GetBackupServerUrlsOffline - This function reads the file at the path set in the PhdlOptions - PathToCommandsFile (or the windows registry for windows applications) and returns a list of backup urls
	PHONEHOMEAPI int Phdl_GBSUOf(char ***results, size_t *outSize);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_GBSUOfW(wchar_t ***results, size_t *outSize);
#endif

	//Phdl_GetBackupServerUrlsOnline - This function calls the web service and requests a list of backup urls
	PHONEHOMEAPI int Phdl_GBSUOn(char ***results, size_t *outSize);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_GBSUOnW(wchar_t ***results, size_t *outSize);
#endif
	//Phdl_GetInAppMessage - This function can be used to retrieve the latest in application message that SmartFlow Gateway server had send to the library
	PHONEHOMEAPI char * Phdl_GIAM(void);
#ifdef _WIN32
	PHONEHOMEAPI wchar_t * Phdl_GIAMW(void);
#endif

	//Phdl_GetCustomCommandsOffline - This function reads the file at the path set in the PhdlOptions - PathToCommandsFile (or the windows registry for windows applications) and returns a list of custom commands
	PHONEHOMEAPI int Phdl_GCCOf(char ***results, size_t *outSize);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_GCCOfW(wchar_t ***results, size_t *outSize);
#endif

	//Phdl_GetCustomCommandsOnline - This function calls the web service and requests a list of custom commands
	PHONEHOMEAPI int Phdl_GCCOn(char ***results, size_t *outSize);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_GCCOnW(wchar_t ***results, size_t *outSize);
#endif

	//Phdl_GetLatestResponse - Get a wrapper containing the latest server response
	PHONEHOMEAPI int Phdl_GLR(PhdlResponse *response);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_GLRW(PhdlResponseW *response);
#endif

	//Phdl_IsApplicationEnabled - This function's return value specifies whether the Red Button has been pressed (false) or not (true) on the server
	PHONEHOMEAPI int Phdl_IAE(void);

	//Phdl_GetLibraryVersion - This function returns the current version of the library
	PHONEHOMEAPI int Phdl_GLV(char **version);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_GLVW(wchar_t **version);
#endif

	//Phdl_EnableLogging - This function can be used when integrating PHDL into a product, to create logs and determine if there are any problems
	PHONEHOMEAPI int Phdl_EL(const char *filePath);
#ifdef _WIN32
	PHONEHOMEAPI int Phdl_ELW(const wchar_t *filePath);
#endif

	//These functions can be used to free memory that was allocated inside the library and returned to the main application
	//Call these for any functions that return char* or char**
	PHONEHOMEAPI void Phdl_FreeChar(char *buffer);
	PHONEHOMEAPI void Phdl_FreeChar2D(char **buffer, size_t size);
#ifdef _WIN32
	PHONEHOMEAPI void Phdl_FreeWchar(wchar_t *buffer);
	PHONEHOMEAPI void Phdl_FreeWchar2D(wchar_t **buffer, size_t size);
#endif
	//PerformInternalCleanup - This function is used to free all the internal components and structures within the library
	PHONEHOMEAPI int Phdl_PIC(void);

	//Data reporting configuration functions

	//GetDataReportingConfiguration - Reads the data gathering configuration from registry
	PHONEHOMEAPI int Phdl_CFGDRC(long long *value);

	//SetDataReportingConfiguration - Will set the data gathering configuration to registry only if it is not set already
	PHONEHOMEAPI int Phdl_CFSDRC(long long reportingConfig);

	//AddDataReportingField - Adds data gathering configurations flags
	PHONEHOMEAPI int Phdl_CFADRF(long long reportingConfig);

	//RemoveDataReportingField - Removes data gathering configurations flags
	PHONEHOMEAPI int Phdl_CFRDRF(long long reportingConfig);

	//NoRandomDelaySupport - by default the first asynchronous send is delayed by a random value between 0 and 10 minutes
	// the first periodical send is moved with a maximum +/-10% of the sending interval value 
	// use this function after Phdl Initialization to disable the feature
	PHONEHOMEAPI int Phdl_NRDS(void);

	//SetHashingMode - Sets hashing mode and returns the previous hasing mode or -1 on error
	PHONEHOMEAPI int Phdl_SHM(EnumPhdlHashingMode hashingMode);

	//RemoveHashConfig - Removes hashing config flags and returns the previous hasing mode or -1 on error
	PHONEHOMEAPI int Phdl_RHC(int hashingConfig);

	//GetDataAsString - Read the storage data from file to memory buffer
	PHONEHOMEAPI int Phdl_GDAS(char **storageData);

#ifdef _WIN32
	//GetDataAsString - Read the storage data from file to memory buffer
	PHONEHOMEAPI int Phdl_GDASW(wchar_t **storageData);
#endif

	//SendDataFromString - Send the memory buffer containing storage data to server (see GetDataAsString)
	PHONEHOMEAPI int Phdl_SDFS(char *storage);

#ifdef _WIN32
	//SendDataFromString - Send the memory buffer containing storage data to server (see GetDataAsString)
	PHONEHOMEAPI int Phdl_SDFSW(wchar_t *storage);
#endif

#ifdef _WIN32
	//Phdl_SetDataSendOptionPriority - Sets the priority for the specified data send method. -1 disables that sending method
	PHONEHOMEAPI int Phdl_SDSOP(EnumPhdlSendOption dataSendOption, int priority);
#endif

#ifdef __cplusplus
}
#endif


//PHDL error codes
#define PHDL_ERR_NOT_INITIALIZED -1 //PHDL was not initialized - most actions are not possible

#define PHDL_SUCCESS 0

#define PHDL_ERR_MEM_ALLOC_FAILED 1 //Memory allocation failed inside PHDL
#define PHDL_ERR_NULL_PARAMETER 2 //Received parameter was NULL

#define PHDL_ERR_GATHER_FAILED 3 //Send data on the fly - failed to gather data
#define PHDL_ERR_SEND_FAILED 4 //Send data on the fly - failed to send data
#define PHDL_ERR_SEND_IN_PROGRESS 5 //Operation not permitted, a send is in progress
#define PHDL_ERR_CAPTURE_CONFIG_EMPTY 6 //The capture config is 0 (no fields are captured)
#define PHDL_ERR_UNKNOWN_TYPE 7 //Returned by Phdl_SIF when the info field is unknown (outside the EnumPhdlInfoField range)
#define PHDL_ERR_INVALID_INFO_FIELD_VALUE 8 //Returned by Phdl_SIF when the info field value is outside the allowed range
#define PHDL_ERR_INVALID_DATA_SEND_OPTION 9 //Returned by Phdl_SDSOP when the dataSendOption parameter is outside the enum range
#define PHDL_ERR_INVALID_CAPTURE_MASK 10 //Returned by functions that modify the capture mask, if the capture mask would become 0 as a result
#define PHDL_STORAGE_FILE_NOT_CONFIGURED 11 //Returned by Phdl_SDTD when the capture cannot be saved into the storage file
#define PHDL_INIT_UNKNOWN_CLASS_MEMBER 12
#define PHDL_ADDITIONAL_INFO_CUSTOM_INFO_BOTH_USED 13	//Returned by Phdl_SIF when setting custom fields 1-5 if the additional info field is already in use.
														//Returned by Phdl_RAI when setting a custom field if one of custom fields 1-5 is already in use
#define PHDL_GATHER_IN_PROGRESS 14 //Operation not permitted, a data gathering is in progress
#define PHDL_LIBRARY_IN_UNSTABLE_STATE 15 //Operation not permitted, library is in an unstable state
#define PHDL_PERIODIC_LOCK_BLOCK 16

#define PHDL_ERR_NOT_IMPLEMENTED 10000

//Initialization error codes
#define PHDL_ERR_NULL_SERVER_URLS 100 //ArrayOfServerUrls is NULL
#define PHDL_ERR_SERVER_URLS_CONTAINS_NULL 101 //ArrayOfServerUrls contains a NULL pointer
#define PHDL_ERR_INVALID_NUMBER_OF_URLS 102 //NumberOfServerUrls is equal to 0
#define PHDL_ERR_INVALID_SEND_RETRY_INTERVAL 103 //SendRetryIntervalMs is lower than 1000
#define PHDL_ERR_INVALID_CAPTURE_INTERVAL 104 //TimeBetweenCapturesSec is lower than 3600
#define PHDL_ERR_INVALID_SEND_INTERVAL 105 //TimeBetweenSendSec is lower than 3600
#define PHDL_ERR_INVALID_PRODUCT_NAME 106 //ProductName is NULL
#define PHDL_ERR_INVALID_PRODUCT_VERSION 107 //ProductVersion is NULL
#define PHDL_ERR_INVALID_CAPTURE_INTERVAL2 108 // TimeBetweenCaptures greater than maximum allowed (1.000.000)
#define PHDL_ERR_INVALID_SEND_INTERVAL2 109 // TimeBetweenSend greater than maximum allowed (1.000.000)
#define PHDL_ERR_INVALID_CAPTURE_SEND_INTERVAL 110 // Both TimeBetweenCaptures and TimeBetweenSend greater than maximum allowed (1.000.000)
#define PHDL_ERR_NULL_ENCRYPTION_KEY 111 // Encryption key is NULL
#define PHDL_ERR_LIBRARY_ALREADY_INITIALISED 112 // Library should not be initialised if it is already

//Capture flag bits
#define PHDL_CAPTURE_PRODUCT_NAME							((long long) (1) << 0)
#define PHDL_CAPTURE_PRODUCT_VERSION						((long long) (1) << 1)
#define PHDL_CAPTURE_SERVICE_RELEASE						((long long) (1) << 2)
#define PHDL_CAPTURE_LICENSE_INFORMATION					((long long) (1) << 3)
#define PHDL_CAPTURE_LICENSED_TO							((long long) (1) << 4)
#define PHDL_CAPTURE_LICENSE_EXPIRY_DATE					((long long) (1) << 5)
#define PHDL_CAPTURE_LICENSE_SERIAL_NUMBER					((long long) (1) << 6)
#define PHDL_CAPTURE_PIRACY_LICENSE_INFORMATION				((long long) (1) << 7)
#define PHDL_CAPTURE_ADDITIONAL_INFORMATION					((long long) (1) << 8)
#define PHDL_CAPTURE_HARD_DISK_ID							((long long) (1) << 9)
#define PHDL_CAPTURE_SYSTEM_ID								((long long) (1) << 10)
#define PHDL_CAPTURE_MACHINE_ID								((long long) (1) << 11)
#define PHDL_CAPTURE_NETWORK_DEFAULT_MAC_ADDRESS			((long long) (1) << 12)
#define PHDL_CAPTURE_TIMESTAMP								((long long) (1) << 13)
#define PHDL_CAPTURE_SEND_TIME								((long long) (1) << 14)
#define PHDL_CAPTURE_SESSION_ID								((long long) (1) << 15)

#define PHDL_CAPTURE_WIFI_ACCESS_POINTS_LIST				((long long) (1) << 16)
#define PHDL_CAPTURE_ACTIVE_ACCESS_POINTS					((long long) (1) << 17)
#define PHDL_CAPTURE_NETWORK_CARDS_INFO_LIST				((long long) (1) << 18)
#define PHDL_CAPTURE_NETWORK_DOMAIN							((long long) (1) << 19)
#define PHDL_CAPTURE_SYSTEM_HOSTNAME						((long long) (1) << 20)
#define PHDL_CAPTURE_SYSTEM_INSTALLED_APPLICATIONS_LIST		((long long) (1) << 21)
#define PHDL_CAPTURE_NETWORK_LOCAL_IP						((long long) (1) << 22)
#define PHDL_CAPTURE_SYSTEM_LOCALE_INFO						((long long) (1) << 23)
#define PHDL_CAPTURE_SYSTEM_ORGANIZATION_NAME				((long long) (1) << 24)
#define PHDL_CAPTURE_SYSTEM_OS_VERSION						((long long) (1) << 25)
#define PHDL_CAPTURE_PIRACY_AUTHOR_ID						((long long) (1) << 26)
#define PHDL_CAPTURE_SYSTEM_PROCESS_ID						((long long) (1) << 27)
#define PHDL_CAPTURE_SYSTEM_USERNAME						((long long) (1) << 28)
#define PHDL_CAPTURE_CLIENT_VERSION_INFO					((long long) (1) << 29)
#define PHDL_CAPTURE_VM_DETECTION_DETAILS					((long long) (1) << 30)
#define PHDL_CAPTURE_LAST_ACCESSED_FILE						((long long) (1) << 31)
#define PHDL_CAPTURE_FEATURES								((long long) (1) << 32)
#define PHDL_CAPTURE_TRIGGER								((long long) (1) << 33)
#define PHDL_CAPTURE_PIRACY_TYPE							((long long) (1) << 34)
#define PHDL_CAPTURE_DESKTOP_EMAIL_CLIENT					((long long) (1) << 35)
#define PHDL_CAPTURE_BROWSER_EMAIL_LIST						((long long) (1) << 36)
#define PHDL_CAPTURE_APPLICATION_TIME_RUNNING				((long long) (1) << 37)
#define PHDL_CAPTURE_CUSTOM_FIELD_1							((long long) (1) << 38)
#define PHDL_CAPTURE_CUSTOM_FIELD_2							((long long) (1) << 39)
#define PHDL_CAPTURE_CUSTOM_FIELD_3							((long long) (1) << 40)
#define PHDL_CAPTURE_CUSTOM_FIELD_4							((long long) (1) << 41)
#define PHDL_CAPTURE_CUSTOM_FIELD_5							((long long) (1) << 42)
#define PHDL_CAPTURE_PHYSICAL_CPU_NO						((long long) (1) << 43)
#define PHDL_CAPTURE_LOGICAL_CPU_NO							((long long) (1) << 44)
#define PHDL_CAPTURE_CPU_MODEL								((long long) (1) << 45)
#define PHDL_CAPTURE_PHYSICAL_MEMORY_AMMOUNT				((long long) (1) << 46)
#define PHDL_CAPTURE_APP_INSTALL_DATE						((long long) (1) << 47)
#define PHDL_CAPTURE_APP_LICENSE_TYPE						((long long) (1) << 48)
#define PHDL_CAPTURE_APP_CURRENT_CONNECTIONS_SESSIONS		((long long) (1) << 49)
#define PHDL_CAPTURE_APP_MAX_CONNECTIONS_SESSIONS			((long long) (1) << 50)

#define PHDL_CAPTURE_MINIMAL_SELECTION_FIELDS				(PHDL_CAPTURE_PRODUCT_NAME | PHDL_CAPTURE_PRODUCT_VERSION | PHDL_CAPTURE_SERVICE_RELEASE | PHDL_CAPTURE_LICENSE_INFORMATION  | \
															PHDL_CAPTURE_LICENSED_TO | PHDL_CAPTURE_LICENSE_EXPIRY_DATE | PHDL_CAPTURE_LICENSE_SERIAL_NUMBER | PHDL_CAPTURE_PIRACY_LICENSE_INFORMATION | \
															PHDL_CAPTURE_ADDITIONAL_INFORMATION | PHDL_CAPTURE_HARD_DISK_ID | PHDL_CAPTURE_MACHINE_ID | PHDL_CAPTURE_SYSTEM_ID | \
															PHDL_CAPTURE_NETWORK_DEFAULT_MAC_ADDRESS | PHDL_CAPTURE_TIMESTAMP| PHDL_CAPTURE_SEND_TIME | PHDL_CAPTURE_SESSION_ID | PHDL_CAPTURE_CLIENT_VERSION_INFO | \
															PHDL_CAPTURE_APPLICATION_TIME_RUNNING | PHDL_CAPTURE_CUSTOM_FIELD_1 | PHDL_CAPTURE_CUSTOM_FIELD_2 | PHDL_CAPTURE_CUSTOM_FIELD_3 | \
															PHDL_CAPTURE_CUSTOM_FIELD_4 | PHDL_CAPTURE_CUSTOM_FIELD_5)

#define PHDL_CAPTURE_FULL_SELECTION_FIELDS					(((long long) (-1)) & (~PHDL_CAPTURE_BROWSER_EMAIL_LIST))

#define PHDL_HASH_SYSTEM_HOSTNAME							((int) (1) << 0)
#define PHDL_HASH_SYSTEM_USERNAME							((int) (1) << 1)
#define PHDL_HASH_BROWSER_EMAIL_LIST						((int) (1) << 2)
#define PHDL_HASH_DESKTOP_EMAIL_CLIENT						((int) (1) << 3)
#define PHDL_HASH_WIFI_ACCESS_POINTS_LIST					((int) (1) << 4)
#define PHDL_HASH_ACTIVE_ACCESS_POINTS						((int) (1) << 5)
