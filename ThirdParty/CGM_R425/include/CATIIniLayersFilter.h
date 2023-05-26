// COPYRIGHT Dassault Systemes 2004
//===================================================================

/** 
  * @CAA2Level L1
  * @CAA2Usage U3
  */ 

#ifndef CATIIniLayersFilter_H
#define CATIIniLayersFilter_H

#include "UIModelInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIIniLayersFilter;
#else
extern "C" const IID IID_CATIIniLayersFilter ;
#endif

class CATUnicodeString;

//------------------------------------------------------------------

/**
 * Interface to a layers filter.
 * <b>Role</b>:
 * This interface gives a read access to a layers filter.
 * <br>This interface is implemented on all the filters. The @href CATIIniDocumentFiltersDefinition interface returns pointers to CATIIniLayersFilter
 * and you can use CATIIniLayersFilter methods to retrieve the name or the comment of the corresponding filter.
 */
class ExportedByUIModelInterfaces CATIIniLayersFilter: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

   /** 
     * Retrieves the filter name.
     * @param oName
     *   The name of the filter.
     * @return
     * <br><b>Legal values</b>:<ul>
     * <li>S_OK if the read access succeeded</li>
     * <li>E_FAIL if the interface pointer is wrong</li></ul>
     */
    virtual HRESULT GetName (CATUnicodeString  & oName) = 0;

   /** 
     * Read the filter description.
     * <b>Role</b>:
     * Return the filter description in NLS. The filter description is the logical layer combination which defines the filter.
     * For exemple, "(Layer > 2 & Layer <=4) + Layer = 0" defines a filter where only layers 3, 4 and 0 are visible.
     * See Visualization Filters interactive command for more help.
     * @param iFormat
     *   The filter description format.<ul>
     *   <li>0: As displayed - NLS contents (Default Value). The description is returned as it appears in the user interface
                (see Visualization Filters interactive command)</li>
     *   <li>1: As stored. The description is returned as stored in the document.</li></ul>
     * @param oDescription
     *   The filter description.
     * @return
     * <br><b>Legal values</b>:<ul>
     * <li>S_OK if the read access succeeded</li>
     * <li>E_FAIL if the interface pointer is wrong</li></ul>
     */
    virtual HRESULT GetContents (CATUnicodeString & oDescription, const int iFormat = 0) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif
