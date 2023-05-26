#ifndef CATTopRelimitBodyByBox_H
#define CATTopRelimitBodyByBox_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2020
//
// CATTopRelimitBodyByBox
//
// DESCRIPTION :
//    
// 
// History
//
// 20200428 CLO2 Creation
//=============================================================================

#include "CATTopOperator.h" 
#include "BONEWOPE.h" // ExportedBy
#include "CATCGMVirtualMacros.h"

#include "CATGeoFactory.h"
#include "CATTopData.h"
#include "CATExtCGMReplay.h"
//#include "CATExtRelimitBodyByBox.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATExtRelimitBodyByBox;
class CATMathAdvancedBox;

class ExportedByBONEWOPE CATTopRelimitBodyByBox : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopRelimitBodyByBox);
public:

  /**
  * Destructor
  */
  virtual ~CATTopRelimitBodyByBox();

  /** @nodoc
* cannot be called
*/
// Please, call CATCreatePolyRelimitBodyTopOper() method to create an instance
  static CATTopRelimitBodyByBox * New(CATGeoFactory * iFactory, CATTopData * iTopData, CATExtRelimitBodyByBox * iExtension);

  // ------------------
// CGMReplay Methods
// ------------------
/** @nodoc
 * @nocgmitf
*/
  static const CATString * GetDefaultOperatorId();

  /** @nodoc @nocgmitf : CATCGMReplay */
  void RequireDefinitionOfInputAndOutputObjects();

protected:

  /** @nodoc @nocgmitf */
  int RunOperator();


  /** @nodoc
  * cannot be called
  */
  // Constructor
  /**
 * Virtual constructor of a <tt>CATTopRelimitBodyByBox</tt> operator.<br>
 * Do not call this constructor, instead use the <tt>CATCreateTopRelimitBodyByBox</tt> global function
 * to create a CATTopRelimitBody operator.
 */
  CATTopRelimitBodyByBox( CATGeoFactory           * ipFactory,
                          CATTopData              * ipTopData,
                          CATExtTopOperator       * ipExtensible);



private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================

  CATTopRelimitBodyByBox();
  CATTopRelimitBodyByBox(const CATTopRelimitBodyByBox& iOneOf);
  CATTopRelimitBodyByBox& operator =(const CATTopRelimitBodyByBox& iOneOf);

};

///**
// * Creates a CATTopRelimitBodyByBox operator.
// * @param iFactory
// * The factory of the geometry. 
// * @param iTopData
// * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
// * is <tt>NULL</tt>, it is not filled. 
// * @param iBodyToSplit
// * The pointer to the target body which might be modified by either removing matter.
// * @param iAdvBox
// * Advanced Box that will relimit the iBodyToRelimit
// * @return [out, IUnknown#Release]
// * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
// */
ExportedByBONEWOPE CATTopRelimitBodyByBox * CATCreateTopRelimitBodyByBox( CATGeoFactory * iFactory,
                                                                          CATTopData * iTopData,
                                                                          CATBody * iBodyToRelimit,
                                                                          const CATMathAdvancedBox & iAdvBox
);

#endif
