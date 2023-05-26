#ifndef CATCreateTopNonLinearTransformation_H 
#define CATCreateTopNonLinearTransformation_H 

// COPYRIGHT DASSAULT SYSTEMES  2000


#include "BODYNOPE.h"
#include <stdlib.h>
#include "CATMathConstant.h"
//
class CATTopNonLinearTransformation;
class CATGeoFactory;
class CATMathNonLinearTransformation;
class CATBody;
class CATTopData;
class CATCGMJournalList;

/**
 * Constructs a CATTopNonLinearTransformation for non-linear transformation.
 * @param iMathTransfo
 * The non-linear transformation to apply. 
 * @param iFactory
 * A pointer to the factory of the resulting objects
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyToTransform
 * The pointer to the body to transform. This body will not be modified. A new resulting
 * body is created, that can be retrieved by the <tt>GetResult</tt> method.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use.
 */
ExportedByBODYNOPE CATTopNonLinearTransformation * 
CATCreateTopNonLinearTransformation(const CATMathNonLinearTransformation  &iMathTransfo,
                                          CATGeoFactory                  * iFactory,
                                          CATTopData                     * iData,
                                          CATBody                        * iBodytoTransform);

/**
 * Deprecated.
 * Constructs a CATTopNonLinearTransformation for non-linear transformation.
 * @param iMathTransfo
 * The non-linear transformation to apply. 
 * @param iFactory
 * A pointer to the factory of the resulting objects
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyToTransform
 * The pointer to the body to transform. This body will not be modified. A new resulting
 * body is created, that can be retrieved by the <tt>GetResult</tt> method.
 * @param iReport
 * The pointer to the journal. If <tt>NULL</tt>, the journal is not written.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use.
 */
ExportedByBODYNOPE CATTopNonLinearTransformation * 
CATCreateTopNonLinearTransformation(const CATMathNonLinearTransformation  &iMathTransfo,
                                          CATGeoFactory                  * iFactory,
                                          CATBody                        * iBodytoTransform,
                                          CATCGMJournalList              * iReport=NULL);
//
#endif


