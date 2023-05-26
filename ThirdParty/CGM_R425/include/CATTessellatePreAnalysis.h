// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//______________________________________________________________________
//
// CATTessellatePreAnalysis.h
//______________________________________________________________________
//
// Usage notes:
// Checks whether a body can be tessellated with the given CATTessSettings
//______________________________________________________________________
//
// Jul 2014 Creation: WMN
//______________________________________________________________________

#ifndef CATTessellatePreAnalysis_h
#define CATTessellatePreAnalysis_h

#include "TessAPI.h"          // ExportedBy

#include "CATBoolean.h"

class CATBody;
class CATTessSettings;
class CATSoftwareConfiguration;

/**
 * Checks whether a body can be tessellated with the given CATTessSettings
 */

class ExportedByTessAPI CATTessellatePreAnalysis
{
public:

 /**
  * no public constructor
  * Please, call CATCreateTessellatePreAnalysis global function
  * defined at the end of this header
  */

 /**
  * Destructor
  * Please, call delete function to remove the operator instance
  */  
  virtual ~CATTessellatePreAnalysis() {};

  /**
   * Run the operator.
   * @return
   *        TRUE if tessellation is evaluated as safe
   *        FALSE  otherwise
   */
  virtual CATBoolean Run()=0;

  /**
   * Get safe accuracy value.
   * @param oAccuracy
   *        An accuracy value thought to be safe to tessellate the given body.
   * @return
   *        TRUE if oAccuracy can be used     : a consistent accuracy value was found.
   *        FALSE  if oAccuracy can not be used : a consistent accuracy value was NOT found.
   *        FALSE  will be returned if Run has not been called before.
   *        TRUE will be returned with the original accuracy requested if Run returned TRUE.
   */
  virtual CATBoolean GetSafeAccuracyValue(double & oAccuracy)=0;

};

ExportedByTessAPI
CATTessellatePreAnalysis * CATCreateTessellatePreAnalysis(CATBody * iBody,
                                                          CATTessSettings & iSettings,
                                                          CATSoftwareConfiguration * iConfig);

#endif // CATTessellatePreAnalysis_H
