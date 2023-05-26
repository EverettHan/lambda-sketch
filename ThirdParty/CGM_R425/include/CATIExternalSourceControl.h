// COPYRIGHT Dassault Systemes 2001
//===================================================================
//
// CATIExternalSourceControl.h
// Define the CATIExternalSourceControl interface
//
//===================================================================
//
// Usage notes:
//   New interface: 
//   Example1: Synchronize(..., ESCCurrentVersion|ESCEditVersion);
//   should lead to 
//      -staying to current uuid if edition right are available 
//      or jumping to a next version having edition capability 
//
//
//   Example2  IsSynchronized(....ESCLastVersion|ESCEditVersion) test is the pointed uuid is the latest edited revision
//
//   Example3  IsSynchronized(....ESCLastVersion|ESCReleaseVersion) test is the pointed uuid is the latest "released"/"Frozen" revision
//
// of course what means Release is dependant from implementation related to the control of the uuid... 
//
//-------------------------------------------------------------------
//Advice to Implementer: 
// 
//1) if you only support some kind of source, 
//   check for that support before accepting it (SetSourceControl)  
//
//2) for special implementation case the source control can be the source itself
//   a typical example being pointing to a CATDocument, 
//   the pointed element (the CATDocument) is then implicitely transformed by the PDM process  
//   in PDM pointed element (PDM CATDocument)... 
//   then, Get/Set Source Control has to return itself 
//
//3)As list of meaning full synchronization mode (CATIExternalSourceControlFlavor) can expand in the future, 
//We advise you to explicitely test all flavor supported for IsSynchronized & Synchronize
//if you only support ESCCurrentVersion (minimum expected) & ESCEditVersion, then add this test:  
//  if ((ESCCurrentVersion|ESCEditVersion) & synchronization_mode != synchronization_mode) then 
//     return E_FAIL;
//otherwise if you want to test if ESCLastVersion is in the synchronization mode, program this way
//  if (synchronization_mode & ESCDecodeVersion == ESCLastVersion) then ...
//if you want to test that ESCLastVersion is not in the synchronization mode, program this way
//  if (synchronization_mode & ESCDecodeVersion != ESCLastVersion) then ...
//if you want to test that ESCNoControl is there 
//  if (synchronization_mode & ESCDecodeVersion == ESCNoControl) then ...
//
//
//===================================================================
#ifndef CATIExternalSourceControl_H
#define CATIExternalSourceControl_H

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "sequence_octet.h"

#include "AD0XXBAS.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAD0XXBAS IID IID_CATIExternalSourceControl ;
#else
extern "C" const IID IID_CATIExternalSourceControl ;
#endif

//------------------------------------------------------------------

/**
 * Kind of Control on a source (not restricted list)
 * <b>Role</b>:
 *     Manage and combine different flavor in the purpose of synchronization
 *
 *     @param ESCNoControl
 *         NoControl alone enables to check/leave a controled source mode (if possible) 
 *             
 *     @param ESCFirstVersion
 *         or Related to the first available version (when combined with Edit or Release)
 *     @param ESCPreviousVersion
 *         or Related to a previous version (no sense for IsSynchronized, but S_FALSE (not yet) or E_FAIL (don't know)
 *     @param ESCCurrentVersion
 *         Related to current version (uuid is not expected to change a synchronization, but rather the projection will be loaded) 
 *     @param ESCNextVersion
 *         or Related to a next version (no sense for IsSynchronized, but S_FALSE (not yet) or E_FAIL (don't know)
 *     @param ESCLastVersion
 *         or Related to the last available version (when combined with Edit or Released) 
 *         It is not decided at now if one superseed one other or not (they should not be used jointly for now) 
 *
 *     @param ESCSuperseededVersion
 *         uuid is known to be superseeded by another one  
 *
 *     @param ESCEditVersion
 *         uuid has user edition right
 *     @param ESCReleasedVersion
 *         uuid is meant to be released and shared with other people (generally a released version is not editable) 
 *         
 */

typedef unsigned short CATIExternalSourceControlFlavor;


#define ESCNoControl          0x00  //Testing/Removing Control (For IsSynchronized/Synchronize purpose)

//Version traversal
#define ESCDecodeVersion      0x3F  //used to decode safely the version  

#define ESCCurrentVersion     0x04  //Testing Current Version (For IsSynchronized/Synchronize purpose)

#define ESCPreviousVersion    0x02  //Changing Version (For Synchronize purpose)  
#define ESCNextVersion        0x20  //Changing Version (For Synchronize purpose)  

#define ESCFirstVersion       0x01  //Testing/Changing Version (For IsSynchronized/Synchronize purpose)
#define ESCLastVersion        0x10  //Testing/Changing Version (For IsSynchronized/Synchronize purpose)  
#define ESCBestVersion        0x10  //DO NOT USE: Prefer LastVersion Testing/Changing Version 

#define ESCSuperseededVersion 0x08  //Testing/Changing Version (For IsSynchronized/Synchronize purpose) 

//Addtionnal information that could be combined with version
#define ESCDecodeAdditional   0xB0  //used to decode safely other properties  

//      EditVersion can be combined with any previous but could also imply Current + Next + editable from current
#define ESCEditVersion        0x40  //  | ESCCurrentVersion | ESCNextVersion ? 

//      ReleasedVersion can be combined with any previous but could also imply Current + Next + editable from current
#define ESCReleasedVersion    0x80  // ESCLastVersion | ESCReleasedVersion ? means Last Released Version 

/**
 * Interface to manage synchronization of elements (as an extension to CATIExternalLink & CATISynchronize).
 * <b>Role</b>: a owner of a link between a pointing element and a pointed element (the source)
 *              provides a model link (See CATIExternalLink).
 *              
 *              this owner may also have kind of control over the source to select it.
 *              we call the mechanism a source control. 
 *
 *              the source control can simply be the adress of a source server (distant object, not yet in session) 
 *              which adressed by its environment can solve the source, or can be more generally   
 *              an objet (in session) which solve the source. 
 * 
 */
class ExportedByAD0XXBAS CATIExternalSourceControl: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

   //Work Process impact
   enum SourceUsage
   {
		  In,        //is configured by source content
		  Out,       //is providing full source content
		  Neutral,   //peer to peer (informative)
      UndefUsage //Cannot be defined 
   };

   //Data Ownership
   enum SourceOwnership
   {
		  Owned,           //pointed external source is owned by the link that recycles it
      Referenced,      //pointed external source is just pointed  
      UndefOwnership   //Cannot be defined
   };

   //
   enum SourceExtraction
   {
      Primary,         //pointed external source is primary source of information, thus required in pointing object definition   
		  Derivative,      //pointed external source is used as a derivative form of the information (this derivative form is thus optional and can be rebuilt) 
      UndefExtraction  //Cannot be defined
   };

  /**
   * Retrieves the source ownership status (source can be owned by at most one object).
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   * <br>S_OK    : the element can determine the kind of ownership
   * <br>E_FAIL  : ownership cannot be dertemined 
   */
   virtual HRESULT GetSourceOwnership(CATIExternalSourceControl::SourceOwnership &oSourceOwnership) = 0;

  /**
   * Retrieves the source usage regarding work process (which determines work process is impacted or impacting it)
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   * <br>S_OK    : the element can determine the kind of source control 
   * <br>E_FAIL  : usage has no meaning 
   */
   virtual HRESULT GetSourceUsage(CATIExternalSourceControl::SourceUsage &oSourceUsage) = 0;

  /**
   * Retrieves the source extraction status (which is relevant regarding the capability to work without it (temporary/permanently).
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   * <br>S_OK    : the element can determine the way the pointing information extract information from the pointed source
   * <br>E_FAIL  : synchronization has no meaning for the reference 
   */
   virtual HRESULT GetSourceExtraction(CATIExternalSourceControl::SourceExtraction &oSourceExtraction) = 0;

  /**
   * Retrieves the source synchronize status.
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, S_FALSE, E_FAIL
   * <br>S_OK    : the element is synchronized regarding all asked flavors. 
   * <br>S_FALSE : the element is not synchronized regarding one of the asked flavors (but might be attempted to be synchronized). 
   * <br>E_FAIL  : synchronization has no meaning for the reference or one of the asked flavor 
   */
	virtual HRESULT IsSynchronized(CATIExternalSourceControlFlavor synchronization_mode=ESCCurrentVersion) = 0;

   /**
   * ask for synchronization
   * @param oSynchronizeStatus
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, S_FALSE, E_FAIL 
   * <br>S_OK    : the element is synchronized regarding all asked flavors 
   * <br>S_FALSE : the element is partially synchronized for all asked flavors
   * <br>E_FAIL  : synchronization cannot be acheived for this element or the asked flavor 
   */
   virtual HRESULT Synchronize(CATIExternalSourceControlFlavor synchronization_mode=ESCCurrentVersion) = 0;

   /**
   * ask for SourceName
   * @param oModelLink
   *         an empty sequence means local is not set
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL 
   * <br>S_OK    : Local is available and provided 
   * <br>E_FAIL  : there is no local on that one 
   */
   virtual HRESULT GetSourceName_B(_SEQUENCE_octet& oModelLink) const=0; 

   /**
   * set SourceName
   * @param iModelLink
   *        an empty sequence means reset
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL 
   * <br>S_OK    : Local has been set to that one 
   * <br>E_FAIL  : Local cannot be set to that one.  
   */

   virtual HRESULT SetSourceName_B(const _SEQUENCE_octet& iModelLink)=0; 
 
   /**
   * ask for SourceControlName
   * @param oModelLink
   *         an empty sequence means External is not set
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL 
   * <br>S_OK    : External is available and provided 
   * <br>E_FAIL  : there is no External on that one 
   */
   virtual HRESULT GetSourceControlName_B(_SEQUENCE_octet& oModelLink) const=0;
 
   /**
   * set External
   * @param oModelLink
   *         an empty sequence means External is not set
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL 
   * <br>S_OK    : External is available and has been set accordingly 
   * <br>E_FAIL  : External cannot be set to such value 
   */   
   virtual HRESULT SetSourceControlName_B(const _SEQUENCE_octet& oURLLink)=0; 
};

CATDeclareHandler(CATIExternalSourceControl,CATBaseUnknown);

//------------------------------------------------------------------

#endif
