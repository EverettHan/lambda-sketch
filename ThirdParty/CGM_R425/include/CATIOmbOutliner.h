#ifndef CATIOmbOutliner_H
#define CATIOmbOutliner_H

/**
 * @level Protected 
 * @usage U3
 */
#include "CATBaseUnknown.h"
#include "CATOmbImportExport.h"
#include "CATOmxKeyValueBlock.h"

extern ExportedByCATOmbImportExport IID IID_CATIOmbOutliner ;

/**
 * This interface allow to implement a component able to outline some data of the model.
 * It would be able to compute data from geometry for example.
 * To fullfill the contract, the Outliner has to :
 *  - Implement this interface
 *  - Manage its component instantiation through OMFactory mechanism
 *  - Create an Entry in a XDefinition file, definning its Outliner.
 *    One XDefinition file can contain several declarations of components such Outliner, Exporter, Importer, Converter, etc
 *    Only one declaration per line
 *    For an outliner you'll have to declare the From & Create fields. So it would look like this:
       Outliner[myOutliner] From[type, sous_type] Create[type_created]
 */

class ExportedByCATOmbImportExport CATIOmbOutliner: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
 
    /** 
     * Implement this interface to compute the data that has to be extracted from the model.
     * @param iComponent
     * The component that contains the model
     * @param oBlock
     * The key value block that will be filled with the data computed.
     * @return
     * S_OK if the data outlining is successful, 
     * E_INVALIDARGS if oBlock provided is not empty or iComponent not set,
     * E_FAIL otherwise
    */
	virtual HRESULT GetOutlinedData(CATBaseUnknown const * iComponent, CATOmxKeyValueBlock& oBlock) = 0;
    
};


CATDeclareHandler( CATIOmbOutliner, CATBaseUnknown );


#endif

