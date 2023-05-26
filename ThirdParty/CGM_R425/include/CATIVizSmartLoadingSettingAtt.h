// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIVizSmartLoadingSettingAtt.h
// Define the CATIVizSmartLoadingSettingAtt interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Feb 2005  Creation: Code generated by the CAA wizard  pam
//===================================================================
#ifndef CATIVizSmartLoadingSettingAtt_H
#define CATIVizSmartLoadingSettingAtt_H

#include "SGInfra.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySGInfra IID IID_CATIVizSmartLoadingSettingAtt;
#else
extern "C" const IID IID_CATIVizSmartLoadingSettingAtt ;
#endif

class CATSettingInfo;
class CATUnicodeString;

//------------------------------------------------------------------

/**  
 * The interface to access a CATIVizSmartLoadingSettingAtt.
 * This interface may be used to read or modify in the CATIA\Tools\Option\General\Display.... the settings values
 * of the CATIASmartLoading sheet.
 */
class ExportedBySGInfra CATIVizSmartLoadingSettingAtt: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    //***********************************************************************
    // Ensure consistency with the IDL interface that will delegate its work
    // Check allowed signatures in System.CATSysSettingController
    //***********************************************************************
    /**
     * Retrieves the SelectiveLoading attribute.
     */
     virtual HRESULT GetSelectiveLoading( CATBoolean&  ioSelectiveLoading ) = 0;

    /**
     * Sets the SelectiveLoading attribute.
     */
     virtual HRESULT SetSelectiveLoading( const CATBoolean    iSelectiveLoading ) = 0;

    /** 
     * Retrieves information about the SelectiveLoading setting parameter.
     * <br>Refer to @href CATSysSettingController for a detailed description.
     */
     virtual HRESULT GetSelectiveLoadingInfo( CATSettingInfo*    oInfo ) = 0;
     
    /** 
     * Locks or unlocks the SelectiveLoading setting parameter.
     * <br>Refer to @href CATSysSettingController for a detailed description.
     */
     virtual HRESULT SetSelectiveLoadingLock( unsigned char      iLocked ) = 0;
     
    
    /**
     * Retrieves the Unload attribute.
     */
     virtual HRESULT GetUnload( CATBoolean&  ioUnload ) = 0;

    /**
     * Sets the Unload attribute.
     */
     virtual HRESULT SetUnload( const CATBoolean    iUnload ) = 0;

    /** 
     * Retrieves information about the Unload setting parameter.
     * <br>Refer to @href CATSysSettingController for a detailed description.
     */
     virtual HRESULT GetUnloadInfo( CATSettingInfo*    oInfo ) = 0;

    /** 
     * Locks or unlocks the Unload setting parameter.
     * <br>Refer to @href CATSysSettingController for a detailed description.
     */
     virtual HRESULT SetUnloadLock( unsigned char      iLocked ) = 0;


    /**
     * Retrieves the UnloadMB attribute.
     */
     virtual HRESULT GetUnloadMB( unsigned int&  ioUnloadMB ) = 0;

    /**
     * Sets the UnloadMB attribute.
     */
     virtual HRESULT SetUnloadMB( const unsigned int iUnloadMB ) = 0;

    /** 
     * Retrieves information about the UnloadMB setting parameter.
     * <br>Refer to @href CATSysSettingController for a detailed description.
     */
     virtual HRESULT GetUnloadMBInfo( CATSettingInfo*    oInfo ) = 0;

    /** 
     * Locks or unlocks the UnloadMBLock setting parameter.
     * <br>Refer to @href CATSysSettingController for a detailed description.
     */
     virtual HRESULT SetUnloadMBLock( unsigned char iLocked ) = 0;

    /**
     * Retrieves the VoxelsAccuracy attribute.
     */
     virtual HRESULT GetVoxelsAccuracy( CATBoolean & ioVoxelsAccuracy ) = 0;

    /**
     * Sets the VoxelsAccuracy attribute.
     */
     virtual HRESULT SetVoxelsAccuracy( const CATBoolean iVoxelsAccuracy ) = 0;

    /** 
     * Retrieves information about the VoxelsAccuracy setting parameter.
     * <br>Refer to @href CATSysSettingController for a detailed description.
     */
     virtual HRESULT GetVoxelsAccuracyInfo( CATSettingInfo*    oInfo ) = 0;

    /** 
     * Locks or unlocks the VoxelsAccuracyLock setting parameter.
     * <br>Refer to @href CATSysSettingController for a detailed description.
     */
     virtual HRESULT SetVoxelsAccuracyLock( unsigned char      iLocked ) = 0;

    /**
     * Retrieves the VoxelsAccuracyPercent attribute.
     */
     virtual HRESULT GetVoxelsAccuracyPercent( unsigned int&  ioVoxelsAccuracy ) = 0;

    /**
     * Sets the VoxelsAccuracyPercent attribute.
     */
     virtual HRESULT SetVoxelsAccuracyPercent( const unsigned int    iVoxelsAccuracy ) = 0;

    /** 
     * Retrieves information about the VoxelsAccuracyPercent setting parameter.
     * <br>Refer to @href CATSysSettingController for a detailed description.
     */
     virtual HRESULT GetVoxelsAccuracyPercentInfo( CATSettingInfo*    oInfo ) = 0;

    /** 
     * Locks or unlocks the VoxelsAccuracyPercentLock setting parameter.
     * <br>Refer to @href CATSysSettingController for a detailed description.
     */
     virtual HRESULT SetVoxelsAccuracyPercentLock( unsigned char      iLocked ) = 0;
  
  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif