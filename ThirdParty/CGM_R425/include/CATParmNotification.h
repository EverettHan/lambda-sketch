#ifndef CATParmNotification_H
#define CATParmNotification_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U1 
 */


/*  CAA2Reviewed by FRH */

// export module
#include "CATLifSpecs.h"

// inherited from 
#include "CATNotification.h"

// class used
#include "CATCke.h"
#include "CATUnicodeString.h"


/**   
 * Notification class for value modification.
 * <b>Role</b>: Used to notify events in LiteralFeatures.<br>
 * @see CATIParmEvents, CATIRelationEvents
 */
class ExportedByCATLifSpecs CATParmNotification : public CATNotification
{

   public:

    CATDeclareClass ;
/**
 * Constructor.
 * @param iObject  object dispatching event
 */
CATParmNotification(const CATBaseUnknown_var &iObject);


/**
 * Destructor.
 */
virtual ~CATParmNotification();

/**
 * Returns the object dispatching the event.
 */
CATBaseUnknown_var GetInterfaceObject() const;

/**
 * Indicates if change value is effective or just a valuation attempt.
 * @return  CATCke::Boolean : true (valuation and modification) false (valuation attempt).
 */
CATCke::Boolean EffectiveChange () const;

/**
 * Defines if change value is effective or just a valuation attempt.
 * @param b  true (valuation and modification) false (valuation attempt)
 */
void            SetEffectiveChange (const CATCke::Boolean &b);

   protected:

        // spec object that as emited the notification
        CATBaseUnknown_var _object;
        // indicates if change value has been effective or not
        CATCke::Boolean ec_;

};

#endif
