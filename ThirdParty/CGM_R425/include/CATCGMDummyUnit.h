#ifndef CATCGMDummyUnit_h
#define CATCGMDummyUnit_h

#include "BONEWOPE.h"
#include "CATCGMUnit.h"
#include "CATDynOperatorDef.h"
#include "CATUnicodeString.h"


//class CATBody;
class CATGeoFactory;
class CATTopOperator;
class CATTopData;
class CATCGMJournalList;

class ExportedByBONEWOPE CATCGMDummyUnit : public CATCGMUnit
{
 public:
   CATCGMDummyUnit(CATGeoFactory* f, CATTopData * iData, CATCGMJournalList* iJournal);
   virtual ~CATCGMDummyUnit();

   virtual void Dump (CATCGMOutput & ioWhereToWrite, int Index = 0,  int iIndent = 0);


   virtual CATCGMUnitType GetType();

   virtual void UpdateOperatorWithNewEntry (CATBody *iOldBody, CATBody *iNewBody);
   virtual int  RunOperator (CATBoolean WithFast=FALSE, CATCGMChainLinkManager *iLink=NULL);

   virtual void GetLinkedGeometry (CATLISTP(CATICGMObject) & CGMLinkedObjectList);

   void SetDummyName (const char * Id);
   const char * GetDummyName ();

   virtual void       SetOperator (CATTopOperator * iOp);


public :

   virtual void	 Stream (CATCGMStream * iStream);
   virtual void  Unstream (CATCGMStream * iStream );

protected :
  virtual void StreamHeader (CATCGMStream* iStream );
 

private :
	CATUnicodeString  _DummyName;


};

ExportedByBONEWOPE CATCGMDummyUnit* CATCreateCGMDummyUnit (CATGeoFactory* ifactory, CATTopData * iData, CATCGMJournalList* iJournal);

#endif
