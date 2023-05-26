#ifndef CATTopPatternData_h 
#define CATTopPatternData_h
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATCVMGeoExtract :
// Classe générique permettant la gestion du CopyPaste
//
//=============================================================================
// mars    2007  Création                    Etienne Bartholomot
//=============================================================================
#include "CATIACGMLevel.h"
#if defined (CATIACGMR214CAA)
#include "CATDynOperator.h"
#include "CATBaseUnknown.h"
#include "CATCGMNewArray.h"
#include "CATDataType.h"
#include "CATSoftwareConfiguration.h"

class CATBody;
class CATCGMJournalList;
class CATLISTP(CATBody);
class CATLISTP(CATCGMJournal);

class ExportedByBODYNOPE CATTopPatternData : public CATBaseUnknown 
{
  //------------------------------------------------------------------------------
  // Component declaration for ObjectModeler
  //------------------------------------------------------------------------------
  CATDeclareClass;

  public:
  enum Type
  {
     _Unknown      = 1
   , _CloneAndSew  = 2
  };
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATTopPatternData (CATTopPatternData::Type  iType) ; 
  
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATTopPatternData();
  
  protected:
  virtual void ReleaseData()=0;
  
  public:
  /**
	* @nodoc
	* Return the Type of a CATTopPatternData
	*/
  CATTopPatternData::Type GetTopPatternDataType();

  /**
  * @nodoc
 	* Add a couple of Parts, and the CATCGMJournalList containing CATCells creation and modification events.
	* For a specific transformation, if the instance creation has been computed outside this operator, the resulting 
  * part and CATCGMJournaList must be given to it, using this method after the CATTopPatternData has been completed.
  * @param iPreviousPart
  * The pointers to the ResultIn CATBody linked to the Features to be patterned. The pointers can be
  * set to <tt>NULL</tt> only for the first AddPartsAndJournal usage. After, it must be set to the iNextPart 
  * of the last AddPartsAndJournal usage.
  * If the CATTopPatternData is completed, the pointer must be equal to the last CATBody returned in the 
  * oPartList of the GetIncrementalResults method.
  * @param iNextPart
  * The pointers to the ResultOut CATBody linked to the Features to be patterned. The pointers must not be
  * set to <tt>NULL</tt>.
  * If the CATTopPatternData is completed, the pointer must be equal to the last computed Part outside the 
  * CATTopPattern Operator
  * @param iCGMJournalList
  * The pointer to the CATCGMJournalList object containing creation and modification events.
  */
  virtual HRESULT  AddPartsAndJournal    (CATBody * iPreviousPart, 
                                          CATBody * iNextPart, 
                                          CATCGMJournalList * iCGMJournalList)=0;

 /**
  * @nodoc
 	* Add a list of Wire, Shell or Volume CATBody to be transformed using the smart process of an instance creation.
 	* @param ioToolList
  * A list of pointers to the CATBody to be transformed using the current CATMathTransformation of the instance.
  * This CATBody must contains CATCells used as FirstObject in the events of the iCGMJournalList
  * If not, the corresponding pointer will be removed from the list ioToolList;
  * @param iShape
  * The point to the shape CATBody used to build the iNextPart CATBody. May be NULL
  * @param iCGMJournalList
  * The pointer to the CATCGMJournalList object containing creation and modification events to build the iShape
  * CATBody from the CATBody included in the iToolList List.
  */
  virtual HRESULT  AddToolsAndJournal    (CATLISTP(CATBody) & ioToolList,
                                          CATBody * iShape,
                                          CATCGMJournalList * iCGMJournalList)=0;
    
 /**
  * @nodoc
  * Close the initial definition of a CATTopPatternData Object;
  * The Shapes to be cloned and sewed are defined and no change can be done on this definition
  * Only outside Parts modification can be added using the AddPartsAndJournal method. Adding a tool is not allowed;
  */
  virtual HRESULT  Completed             ()=0;
 
  /**
  * @nodoc
	* Returns the built CATBody sets and their associated CATCGMJournaList. 
  * For N Features to pattern, and for each transformation to compute, there is N CATBody as successive resulting 
  * part and N CATCGMJournalList for that specific transformation. 
  * If the RunNext Operation has failed, oPartList Size and oCGMJournalList Size are <tt>NULL</tt>. In this case, 
  * the solution must be computed outside the operator, and given to it using the method named AddPartsAndJournal.
  * The next Run step can be done only after that.
  * All the created CATBody are returning with their CATCGMJournalListe. 
  * @param oPartImage
  * a list of CATBody pointers. 
  * @param pJournalImage
  * The list of pointers to the successive CATCGMJournalList objects. 
  * @param oToolImage
  * a list of CATBody pointers. 
  */
  virtual HRESULT  GetIncrementalResults (CATLISTP(CATBody)& oPartImage, 
                                          CATLISTP(CATCGMJournal)& oJournalListImage,
                                          CATLISTP(CATBody)& oToolImage)=0;
  /**
  * @nodoc
	* Returns the incremental computed shapes to be added to the Part. 
	* Those shapes are removed from the Factory when the CATTopPatternData object is 
	* deleted. Do not use them after.
	* The last Shape is the overall shape added to part for the N original features
	* @param oShapes
  * a list of N CATBody pointers. 
  */
  virtual HRESULT ReadIncrementalShapes (CATLISTP(CATBody)& oShapes)=0;
  
  //------------------------------------------------------------------------------
  private:
  CATTopPatternData(const CATTopPatternData &);
  void operator = (const CATTopPatternData &);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  Type   _Type;
  
};
/**
* @nodoc
* Create a CATTopPatternData
*/
ExportedByBODYNOPE CATTopPatternData * CATCreateTopPatternData (CATTopPatternData::Type  iType , 
                                                                CATSoftwareConfiguration * iConfig );

#endif
#endif
