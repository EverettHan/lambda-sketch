#ifndef CATIOccurrencesEditor_h
#define CATIOccurrencesEditor_h

// COPYRIGHT DASSAULT SYSTEMES 2015

/**
  * @level Protected
  * @usage U5
  */

#include "CATBaseUnknown.h"
#include "CATSysBoolean.h"

class CATFrmEditor ;
class CATIPLMOccurrencesBuilder ;

#include "CATObjectModelerItf.h"
extern ExportedByCATObjectModelerItf IID IID_CATIOccurrencesEditor ;

/**
* Interface to manage objects interactivelly.
* <br><b> Role: </b> this interface is dedicated to create and return the editor associated with root object.
* @see CATFrmEditor
*/

class ExportedByCATObjectModelerItf CATIOccurrencesEditor : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
  * Returns the editor associated with the root object that implement this interface.
  * <br>this method creates the editor and build the occurrence tree according the list of path provided by the Open Engine.
  *
  * @param iOccurrenceBuilder [in]
  *   The open engine Object requesting the editor creation. This object provides the list of path resulting of the open query.
  * @param iNewEditorRequested [in]
  *   if TRUE, requests the creation of a new editor in case of an editor on the same root already exists.
  *   else, if an editor already exits on the same root, the occurrence tree of this editor will be enriched.
  */
  virtual CATFrmEditor * GetEditor (CATIPLMOccurrencesBuilder * iOccurrenceBuilder, CATBoolean iNewEditorRequested)=0 ;
};

#endif



