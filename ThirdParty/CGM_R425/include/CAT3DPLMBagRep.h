#ifndef CAT3DPLMBagRep_H
#define CAT3DPLMBagRep_H

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "SGInfra.h"
#include "CAT3DFilterBagRep.h"
#include "CATVisPLMRenderingStyleManager.h"

class ExportedBySGInfra CAT3DPLMBagRep : public CAT3DFilterBagRep
{
  friend class CAT3DFinalPLMBagRep;
  friend class CAT3DLDHBagRep;
  friend class CAT3DFilterBagRepWithToleranceScale;

  CATDeclareClass;
public:

  static CAT3DPLMBagRep* CreateRep();

protected:

  BEGIN_MIGRATE_REP_CTOR_PRIVATE
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CAT3DFinalPLMBagRep to derive from" )
#endif
    /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DPLMBagRep ();
  END_MIGRATE_REP_CTOR

protected:

  virtual ~CAT3DPLMBagRep ();
    
public:
  void SetPLMRenderingStyle(unsigned int iPLMViewMode, unsigned int iDataID);
    
  virtual unsigned int GetPLMRenderingStyle(unsigned int iPLMViewMode);

private :
  unsigned int _plmRenderingStyle[CATVISPLMMAXVIEWMODE];
};

#endif
