#ifndef CATExtHybOperator_h_
#define CATExtHybOperator_h_

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
#include "CATHybDef.h"
#include "CATExtTopOperator.h"
#include "CATHybOperator.h"
#include "CATExtTopMultiResult.h"

class CATListPtrListPOfCATCell;


class ExportedByPBELight CATExtHybOperator : public CATExtTopMultiResult
{

  friend class CATHybOperator;


protected:

  //-------------------------------------------------------------------------------------------------------
  // Constructeur 
  //   iOperateur peut etre NULL,  mais ca doit etre reserver au cas tres particuliers sous constructeur
  //   il faut dans ce cas s'empresser de retablir la definition avec la methode SetOperator
  //-------------------------------------------------------------------------------------------------------
  CATExtHybOperator(CATTopOperator * iOperateur = NULL);

public:

  // Destructor
  virtual ~CATExtHybOperator();

  // Surcharge du new/delete
  CATCGMNewClassArrayDeclare;

  virtual CATBody* GetResult(CATCGMJournalList* iJournal)=0;
  virtual CATBody* GetResult()=0;

  virtual short GetFreezeMode() const=0;
  virtual void  SetFreezeMode(short mode=1)=0;

  virtual void SetTolerance(double iTol)=0;
  virtual double GetTolerance() const=0;

  // TO BE SUPPRESS after CATSmModel migration on CATExtHybProject
  virtual double GetDistance(CATDomain* iDomOfResultBody);

  // FSQ(12/01/2009): Call this function to deactivate the new journal
  virtual void ActivateOldJournal();

protected:

  CATBoolean _ActivateOldJournal;
};
#endif
