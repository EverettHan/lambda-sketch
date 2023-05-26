#ifndef CATTopThickWire_H
#define CATTopThickWire_H

// COPYRIGHT DASSAULT SYSTEMES  1999

#include "Parallel.h"
#include "CATTopOperator.h"
#include "CATGeoFactory.h"
#include "CATTopData.h"
#include "CATCGMJournalList.h"
#include "ListPOfCATBody.h"
//

class ExportedByParallel CATTopThickWire : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopThickWire);
  public :

	CATTopThickWire(	CATGeoFactory		* iFactory,
										CATTopData			* iReport);

//	CATTopThickWire(	CATGeoFactory		* iFactory);					
/*
* Destructor
*/
	virtual ~CATTopThickWire();

/*
* BASICS METHODS
*/
	virtual int			Run() = 0;

	virtual CATBody *	GetResult(CATCGMJournalList * ) = 0;

  virtual void SetStraightRelimitation() = 0;
  virtual void SetOffsetValue( double iSecondOffset ) = 0;

};

ExportedByParallel
CATTopThickWire * CreateTopThickWire (CATGeoFactory		*iFactory,
																				CATTopData	*iData,
																			  CATLISTP(CATBody)			*iWires,
																			  CATBody			*iSupport,
																			  double			iOffset);
#endif
