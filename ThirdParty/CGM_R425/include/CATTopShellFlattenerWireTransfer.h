#ifndef CATTopShellFlattenerWireTransfer_H
#define CATTopShellFlattenerWireTransfer_H

#include "ShellFlattener.h"
#include "CATTopOperator.h"
#include "CATCGMJournalList.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATEdge.h"

class CATGeoFactory;
class CATBody;


//Operator transfers the wire from folded to unfolded body and vice-versa
//

class ExportedByShellFlattener CATTopShellFlattenerWireTransfer : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopShellFlattenerWireTransfer);
public:
  /** @nodoc 
    * cannot be called
    * use CATCreateTopShellFlattener to create the operator
    */
  //
  // Constructor
  //
  CATTopShellFlattenerWireTransfer(CATGeoFactory * ipFactory, CATTopData * ipTopData);

  //
  // Destructor
  //
  virtual ~CATTopShellFlattenerWireTransfer();

};

ExportedByShellFlattener CATTopShellFlattenerWireTransfer * CATCreateTopShellFlattenerWireTransfer(
                            CATGeoFactory      * iFactory,
                            CATTopData         * iTopData,
                            CATBody            * iOriginalBody,           //the body to flatten , Must have only one shell
                            CATBody            * iFlattenedBody,          //Must be the result of free form unfold for iOriginalBody
                            CATBody            *  ipWireBody,             //Wire to transfer
                            CATLISTP(CATFace)  & iInputfaceList,          //Face list from input body(iOriginalBody)
                            CATLISTP(CATFace)  & iResultfaceList,         //Face list from flattened body(iFlattenedBody) This should be contain bend faces
                            CATLISTP(CATEdge)  & iBendEdgeList,           //Zero bend radius edges
                            CATLISTP(CATFace)  & iExtraFacesListinOutput, //Faces created corrosponding to zero bend radius edges
                            CATBoolean           iReverse = FALSE);       //TRUE to transfer from flattened to folded body
#endif
