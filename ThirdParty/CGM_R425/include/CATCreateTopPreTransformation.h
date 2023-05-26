#ifndef CATCreateTopPreTransformation_H 
#define CATCreateTopPreTransformation_H 

// COPYRIGHT DASSAULT SYSTEMES  2001


#include "BODYNOPE.h"
#include <stdlib.h>
#include "ListPOfCATFace.h"
//
class CATTopPreTransformation;
class CATGeoFactory;
class CATMathNonLinearTransformation;
class CATBody;
class CATTopData;
class CATCGMJournalList;

/**
 * Constructs a CATTopPreTransformation.
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
 * @param iFacestoTransform
 * The pointer to list of faces to transform.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use.
 */
ExportedByBODYNOPE CATTopPreTransformation * 
CATCreateTopPreTransformation(const CATMathNonLinearTransformation  &iMathTransfo,
                                    CATGeoFactory                  * iFactory,
                                    CATTopData                     * iData,
                                    CATBody                        * iBodytoTransform,
                                    ListPOfCATFace                 * iFacestoTransform);

/**
 * Deprecated.
 * Constructs a CATTopPreTransformation.
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
 * @param iFacestoTransform
 * The pointer to list of faces to transform.
 * @param iReport
 * The pointer to the journal. If <tt>NULL</tt>, the journal is not written.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use.
 */
ExportedByBODYNOPE CATTopPreTransformation * 
CATCreateTopPreTransformation(const CATMathNonLinearTransformation  &iMathTransfo,
                                    CATGeoFactory                  * iFactory,
                                    CATBody                        * iBodytoTransform,
                                    ListPOfCATFace                 * iFacestoTransform,
                                    CATCGMJournalList              * iReport=NULL);
//
#endif


