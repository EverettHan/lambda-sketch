#ifndef CATIndicateEvent_H
#define CATIndicateEvent_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATVisFoundation.h"
#include "CATViewerEvent.h"
#include "CATMathPoint.h"

class CATViewpoint;
class CATMathPointf;

/**
* Event sent to the indicator.
* <b>Role</b>: do not use.
*/
class ExportedByCATVisFoundation CATIndicateEvent : public CATViewerEvent
{
  CATDeclareClass;

public:
  virtual ~CATIndicateEvent();

  /** @nodoc */
  CATIndicateEvent();

  /** @nodoc */
  CATIndicateEvent(const CATMathPointf  & iNearPoint,
                   const CATMathPointf  & iFarPoint, 
                   const CATViewpoint   * iViewpoint, 
                   const CATViewerEvent * iEvent = NULL);

   /** @nodoc */
  CATIndicateEvent(const CATMathPoint  & iNearPoint,
                   const CATMathPoint  & iFarPoint, 
                   const CATViewpoint   * iViewpoint, 
                   const CATViewerEvent * iEvent = NULL);
  
  /** @nodoc */
  CATIndicateEvent & operator = (const CATIndicateEvent & iIndicateEvent);

  /** @nodoc */
  CATMathPointf GetNearPoint() const;
  
  /** @nodoc */
  CATMathPointf GetFarPoint() const;
  
  /** @nodoc */
  CATMathPoint GetNearPointD() const;
  
  /** @nodoc */
  CATMathPoint GetFarPointD() const;
  
    /** @nodoc */
  CATViewpoint * GetViewpoint() const;
  
protected:
  CATMathPoint	 _NearPoint;
  CATMathPoint	  _FarPoint;
  CATViewpoint	* _viewpoint;
};

#endif // CATIndicateEvent_H
