#ifndef CATIVisuAlias_h
#define CATIVisuAlias_h


// COPYRIGHT DASSAULT SYSTEMES 2003


#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATVisController.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisController IID IID_CATIVisuAlias;
#else
extern "C" const IID IID_CATIVisuAlias;
#endif


/**
* Visualization Interface to access the external name of an object. We will use CATIAlias indirectly, CATIAlias being
* in ObjectModelerBase.
*/
class ExportedByCATVisController CATIVisuAlias : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:
  
  
/**
 * Sets an alias to the object.
 * @param iName
 *         alias to associate to the object.
 */	
  virtual void SetAlias(const CATUnicodeString&  iName ) = 0;

  /**
   *@nodoc
   */
  virtual void SetOriginalName() = 0;
  
  /**
  * Returns alias of the object.
  */	
  virtual CATUnicodeString GetAlias(int iIndex, int iTotal) = 0;
  
  
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIVisuAlias , CATBaseUnknown ) ;


#endif
