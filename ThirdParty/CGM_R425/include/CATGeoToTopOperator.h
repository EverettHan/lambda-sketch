#ifndef CATGeoToTopOperator_h
#define CATGeoToTopOperator_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
* @level Protected
* @usage U1
*/ 

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "PrimitivesLight.h"
#include "CATCGMJournal.h"
#include "CATString.h"
#include "CATTopOperator.h"

class CATGeometry;
class CATGeoFactory;
class CATBody;
class CATDomain;
class CATTopologicalOperator;

class CATCGMJournalList;
class CATCGMJournalInfo;
#ifndef NULL
#define NULL 0
#endif


/**
* Base abstract class of the operators that create topology from geometry.
*/
class ExportedByPrimitivesLight CATGeoToTopOperator : public CATTopOperator
{
	
  CATCGMVirtualDeclareClass(CATGeoToTopOperator);
protected:
	/**  @nodoc */
	CATGeoToTopOperator(CATGeoFactory      *iFactory, 
		CATTopData * iData
#ifdef CATIACGMR214CAA
    , CATExtTopOperator *iExtensible = NULL
#endif
    );
  /**  @nodoc */
	CATGeoToTopOperator(CATGeoFactory      *iFactory,
    CATTopData * iData,
		CATBody            *iBodyForCellCreation
#ifdef CATIACGMR214CAA
    , CATExtTopOperator *iExtensible = NULL
#endif
    );
  /**  @nodoc */
	CATGeoToTopOperator(CATGeoFactory      *iFactory, 
		CATBody            *iBodyForCellCreation,
		CATBodyFreezeMode   iBodyFreezeMode=CATBodyFreezeOn,
		CATCGMJournalList  *iReport=NULL
#ifdef CATIACGMR214CAA
    , CATExtTopOperator *iExtensible = NULL
#endif
    );
	/**  @nodoc */
	void FillResultBody();

   /** @nodoc */
   void SetLog(CATLONG32 );
  /** @nodoc */
  CATCGMJournalList*   _OldJournal;
	
public:  
  
  virtual ~CATGeoToTopOperator();
  
	/** 
		* Defines the tolerance for assembling the geometry.
		* <br>Very sensitive point. The default value is the factory resolution, 
		* and it is strongly recommended to keep it.
		* @param iTol
	  * The tolerance for assembling the geometry.
		*/
  void SetTolerance(double iTol);
	
	/**
	 * Returns the tolerance for assembling the geometry.
	 * @return
	 * The tolerance.
	 */
  double GetTolerance()const;

#ifdef CATIACGMR420CAA
  /** @nodoc
	 * To decide if non-cell elements can appear as parents in journal items.
	 */
  void SetUseGeometriesInJournalItems(int iUseGeometriesInJournalItems);
#endif  

  
  /** @nodoc */
	void Report(CATCGMJournal::Type   iType,
		const CATGeometry    *iBeforeObjects,
		const CATGeometry    *iAfterObjects,
		CATCGMJournalInfo    *iOptionalInfo=NULL);

  /**
	 * Returns the pointer to the topological journal associated with <tt>this</tt> operator.
	 * @return
	 * The pointer to the journal. Remember that you give the journal at the operator creation, 
	 * if you want to have a report. So you have to manage the journal cycle life.
	 */
  CATCGMJournalList* GetReport();
  
	
protected:
  /**  @nodoc */
	double	                 _tolerance;
  /**  @nodoc */
	CATBody                * _Draft;
  /**  @nodoc */
	CATDomain              * _manifold;
  /**  @nodoc */
	CATTopologicalOperator * _cleaner;
};



#endif














