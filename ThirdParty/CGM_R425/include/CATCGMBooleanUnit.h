#ifndef CATCGMBooleanUnit_h
#define CATCGMBooleanUnit_h

#include "BONEWOPE.h"
#include "CATCGMUnit.h"
#include "CATDynOperatorDef.h"


//class CATBody;
class CATGeoFactory;
class CATTopOperator;
class CATTopData;
class CATCGMJournalList;

class ExportedByBONEWOPE CATCGMBooleanUnit : public CATCGMUnit
{
 public:
   CATCGMBooleanUnit(CATGeoFactory* f, CATTopData * iData, CATCGMJournalList* iJournal);
   virtual ~CATCGMBooleanUnit();

   virtual void Dump (CATCGMOutput & ioWhereToWrite, int Index = 0,  int iIndent = 0);

   virtual CATCGMUnitType GetType();

   virtual void UpdateOperatorWithNewEntry (CATBody *iOldBody, CATBody *iNewBody);
   virtual int RunOperator (CATBoolean WithFast=FALSE, CATCGMChainLinkManager *iLink=NULL);

   //virtual int  RunOperator ();

   virtual void GetLinkedGeometry (CATLISTP(CATICGMObject) & CGMLinkedObjectList);

  // void SetType  (CATDynBooleanType _iType);
  // CATDynBooleanType& GetType  ();


private :
	void SetNewInputs (CATLISTP(CATBody)& Inputs);
    CATLISTP(CATBody) _NewInputs;
	//CATDynBooleanType _Type;

};

ExportedByBONEWOPE CATCGMBooleanUnit* CATCreateCGMBooleanUnit (CATGeoFactory* ifactory, CATTopData * iData, CATCGMJournalList* iJournal);

#endif
