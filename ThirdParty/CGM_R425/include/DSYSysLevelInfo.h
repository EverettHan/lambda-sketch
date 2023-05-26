// COPYRIGHT DASSAULT SYSTEMES 2007
#ifndef DSYSysLevelInfo_h
#define DSYSysLevelInfo_h

#include "CATDataType.h"
#include "JS0LIB.h"
#include "CATUnicodeString.h"


/**
* Gets the packaging version short name of the installation. Used above all to display the installation
* version in Help/About dialog box.
* Please note that the same level of code can be used to build several different packaging versions (eg: CATIA V6R2009-1.0 HF6 and
* DELMIA V6R2009-1.1) so the result of this method can be different with the same level of code.
* @return
*   The packaging version short name of the installation, that is the version of the installation (eg: "V6R2008-1.0",
*   "V6B2008-1.0_0746" "V6R2008-1.1 HF6") or 
*   "Unofficial Packaging Version" when the method is called outside an official V6 installation (mkodt, 
*   mkrun, download...)
*   This string MUST NOT be parsed / compared or used in data model. It should only be displayed to the end-user for 
*   general information about the installation version.
*/
ExportedByJS0LIB CATUnicodeString DSYSysGetPackagingVersionShortName();

/**
* Almost same as DSYSysGetPackagingVersionShortName.
* @return
*   "Version 6 Release 2008-1.0"
*   "Version 6 Release 2008-1.0"
*   "Version 6 Release 2008-1.0 Hot-Fix 6"
*   "Unofficial Packaging Version"
*/
ExportedByJS0LIB CATUnicodeString DSYSysGetPackagingVersionLongName();

ExportedByJS0LIB CATUnicodeString DSYSysGetPackagingVersionGAName();

/**
 * @param instpath
 * a CATInstallPath value.
* @return the GA level eg : B417, B418...
*/
ExportedByJS0LIB CATUnicodeString DSYSysGetGALevel(const CATUnicodeString &instpath = CATUnicodeString());

/**
* Gets the build Version.
* @return
*   the build version, that is 6
*/
ExportedByJS0LIB int DSYSysGetBuildVersionId();

/**
* Gets the build Release.
* @return
*   the build version, eg: 204, 205
*/
ExportedByJS0LIB int DSYSysGetBuildReleaseId();


/**
* Gets the build level. Used ONLY to display the build level in Help/About dialog box to help the support team.
* @return
*   the level of the build release (eg: "6.204.1.0")
*   This string MUST NOT be parsed / compared or used in data model.
*/
ExportedByJS0LIB CATUnicodeString DSYSysGetBuildLevelName();


/**
* Gets the build Id name. Used above all to display the build Id in Help/About dialog box to help the support team.
* @return
*   the Id string of the build release (eg: "2008-09-18-2000.00")
*   This string MUST NOT be parsed / compared or used in data model.
*/
ExportedByJS0LIB CATUnicodeString DSYSysGetBuildIdString();


/**
* Gets the build Major Release.
* @return
*   the Major Release ID
*/
ExportedByJS0LIB int DSYSysGetBuildMajorReleaseId();


/*
methodes R204 mais eviter de les utiliser
*/

/**
* Gets the order of this Delivery (formely SP order)
* @return
*   the order of this delivery, eg: 0, 1, 10...
* before using this method, please check that you REALLY need it.
*/
ExportedByJS0LIB int DSYSysGetBuildDeliveryIndexNumber();

/**
* Gets the order of this sub Delivery (formely HF order)
* @return
*   the order of this sub delivery, eg: 0, 3, 5...
* before using this method, please check that you REALLY need it.
*/
ExportedByJS0LIB int DSYSysGetBuildSubDeliveryIndexNumber();



#endif //DSYSysLevelInfo_h
