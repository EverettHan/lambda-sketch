/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
/**
 *  CATRollAvailability :
 *  Classe pour le declenchement du roll (implementation dans ApplicationFrame)
 *
 */
//=============================================================================
#ifndef __CATRollAvailability_h
#define __CATRollAvailability_h

/**
 * @level Private
 * @usage U1
 */

#include "CATCommand.h"
#include "CATBooleanDef.h"
#include "CATEventSubscriber.h"
#include "AC0XXLNK.h"

class ExportedByAC0XXLNK CATRollAvailability: public CATEventSubscriber {

public:

  CATDeclareClass;
  
  static CATRollAvailability * GetInstance ();

  CATDefineCBEvent (RollAvailable)

  virtual boolean CanRoll () const = 0;

protected:

  static boolean               SetInstance (CATRollAvailability *);

  CATRollAvailability ();
  CATRollAvailability (const CATRollAvailability &);
  CATRollAvailability & operator = (const CATRollAvailability &);
  virtual ~CATRollAvailability ();

  static CATRollAvailability * _instance;

};

#endif//__CATRollAvailability_h
