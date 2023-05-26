/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2006
#ifndef CATIPLMTransferOptions_H
#define CATIPLMTransferOptions_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"

#include "CATBaseUnknown.h"

class CATListValCATString;
class CATListValCATUnicodeString;
class CATString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMTransferOptions;
#else
extern "C" const IID IID_CATIPLMTransferOptions ;
#endif

/**
 * This interface enables to get and set options related to the data transfer.
 * <br>
 * <ul>
 *   <li>These information are used by  @href  CATIPLMTransferToProvider</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMTransferOptions: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/** 
 * Gets the list of geometric format options for this transfer.
 *
 * @param olistOfGeometricFormatOptions [out]
 *   The list of possible options for geometric formats.
 *
 * @param olistOfAssociatedNLS [out]
 *   The list of associated NLS message corresponding to options
 *
 * @param oDefaultOption [out]
 *   The index of the default option in the list 
 *
 */
 virtual void GetGeometricFormatOptions(CATListValCATString& olistOfGeometricFormatOptions,
										CATListValCATUnicodeString& olistOfAssociatedNLS,
										int oDefaultOption)= 0;

/** 
 * Sets the geometric format option for this transfer.
 *
 * @param iGeometricFormatOption [in]
 *   The chosen geometric format option.
 *
 * @return
 *   <code>S_OK</code> 
 *   <code>S_FALSE</code> 
 *   <code>E_FAIL</code> 
 *
 */
  virtual HRESULT SetGeometricFormatOption(CATString& iGeometricFormatOption)= 0;

  virtual HRESULT SetEnv(const CATString& iEnv)= 0;

	/** 
 * Sets one option value for the current transfer.
 *
 * @param iParamName [in]
 *   The chosen option name.
 * Legal values for iParameterName are: "CGR.Wireframe" and "Geometrical.Format"

 * @param iParamValue [in]
 *   The chosen option value.
 *  Legal value for iParamValue is "NO LINEIC" for "CGR.Wireframe" and "uvr", "uv" or "xmlxmesh" for "Geometrical.Format"
 *
 * @return
 *   <code>S_OK</code> 
 *   <code>S_FALSE</code> if some inconsistency is found between different options (No Wireframe but with XML mesh for instance)
 *   <code>E_FAIL</code> 
 *
 */
  virtual HRESULT SetOption(CATString & iParamName, CATString & iParamValue) = 0;

	/**
	* Gets one option value for the current transfer.
	*
	* @param iParamName [in]
	*   The chosen option name.
	* Legal values for iParameterName are: "CGR.Wireframe" and "Geometrical.Format"

	* @param oParamValue [out]
	*   The chosen option value.
	*  Legal value returned for oParamValue is "WITH ALL LINEIC ELEMENTS" or "NO LINEIC" for "CGR.Wireframe" and "uvr", "uv" or "xmlxmesh" for "Geometrical.Format"
	*
	* @return
	*   <code>S_OK</code>
	*   <code>E_FAIL</code>
	*
	*/
	virtual HRESULT GetOption(CATString & iParamName, CATString & oParamValue) = 0;
  
};
CATDeclareHandler( CATIPLMTransferOptions, CATBaseUnknown );
#endif
