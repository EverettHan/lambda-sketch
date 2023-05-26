#ifndef CATTopAdaptiveClone_H
#define CATTopAdaptiveClone_H


#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "BODYNOPE.h"
#include "CATTopMultiResult.h"
#ifndef NULL
#define NULL 0
#endif

class CATGeoFactory;

#if defined ( CATIACGMV5R22 ) 
// @nodoc  enum does not work for forward declaration
#define CATCGMObjectsVersion int 
#endif


class ExportedByBODYNOPE CATTopAdaptiveClone : public CATTopMultiResult
{
  CATCGMVirtualDeclareClass(CATTopAdaptiveClone);

public: 
  /**
 * Destructor.
 */
  virtual ~CATTopAdaptiveClone();

  /**
 *  Set stream version that will be used to identify the incompatibles Objects
 */
  virtual void SetTargetVersion(CATCGMStreamVersion & iTargetVersion) = 0;

  /**
 * Set Input Objects.
 */
  virtual void SetInputObjects(CATLISTP(CATICGMObject)&  iInputObjects) = 0;
 
  /**
 * Get All Results.
 */
  virtual void GetAllResults( CATLISTP(CATICGMObject)&  oObjectList) = 0;

protected:
   /**
 * @nodoc
 * Virtual constructor of a CATTopAdaptiveClone.<br>
 * Cannot be called. Use the <tt>CATCreateXxx</tt> global function
 * to create the Xxx operator.
 */
  CATTopAdaptiveClone(CATGeoFactory* iFactory, CATTopData& iTopData);



};

ExportedByBODYNOPE CATTopAdaptiveClone* CATCreateTopAdaptiveClone (CATGeoFactory*   iFactory,
                                                                     CATTopData& iTopData);

#endif


