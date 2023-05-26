#ifndef CATIProdWorkMode_H
#define CATIProdWorkMode_H
#include "UIModelInterfaces.h"
 
// COPYRIGHT DASSAULT SYSTEMES 2004-2007
// protected CATInteractiveInterfacesUUID.m and CATInteractiveInterfaces.m
 
//=============================================================================
//
// CATIProdWorkMode.h
// Define the CATIProdWorkMode interface
//
//=============================================================================
//
// Usage notes:
//   Interface for "Selective Loading"
//   Used by the Search command
//
//=============================================================================
 
#include "CATBaseUnknown.h"
 
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h" 
 
 
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIProdWorkMode;
#else
extern "C" const IID IID_CATIProdWorkMode ;
#endif
 
//------------------------------------------------------------------
 
/**
 * Interface for "Selective Loading"
 */
class ExportedByUIModelInterfaces CATIProdWorkMode : public CATBaseUnknown
{
  
  CATDeclareInterface;  
  
public:   
 
  /** @nodoc
  * For each aggregated representation, computes its work mode and retrieves its name.
  * Work modes and names are respectively stored in 2 lists, with matching indexes.
  * @param oListWorkMode
  *   The list of computed work modes.
  * <br><b>Legal values</b>: <ul>
  * <li><tt>"PLMMode"</tt>.</li>
  * <li><tt>"VisuMode"</tt>.</li>
  * <li><tt>"LinkableMode"</tt>.</li>
  * <li><tt>"EditMode"</tt>.</li>
  * <li><tt>"DMUMode"</tt>.</li>
  * </ul>
  * @param oListRepInstName
  *   The list of all Representation Instances names.
  */
  virtual HRESULT ComputeAllRepsMode (CATListOfCATUnicodeString & oListWorkMode, CATListOfCATUnicodeString & oListRepInstName) = 0;
 
  /** @nodoc
  * Switches to work mode "iNewWorkMode" for a given Representation Instance name "iRepInstName".
  * @param iNewWorkMode
  *   The work mode.
  * <br><b>Legal values</b>: <ul>
  * <li><tt>"PLMMode"</tt>.</li>
  * <li><tt>"VisuMode"</tt>.</li>
  * <li><tt>"LinkableMode"</tt>.</li>
  * <li><tt>"EditMode"</tt>.</li>
  * <li><tt>"DMUMode"</tt>.</li>
  * </ul>
  * @param iRepInstName
  *     The Representation Instance name  
  */
  virtual HRESULT ChangeRepMode (CATUnicodeString & iNewWorkMode, CATUnicodeString & iRepInstName) = 0;  
};
 
//------------------------------------------------------------------
//                             Handler
//------------------------------------------------------------------
 
CATDeclareHandler (CATIProdWorkMode, CATBaseUnknown);
 
#endif
