#ifndef CATDynShellBody_H_
#define CATDynShellBody_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATDynOperator.h"
#include "ListPOfCATFace.h"
class CATBody;
class CATTopData;

   #define CATDynShellBody_WithTopData "NLD021019 (à terme, deflaggage complet tous sources et headers y compris fw de test)"

/**
 * Interface representing the topological creation of a shell domain.
 * This operator takes a list of faces in input, builds the shell domain and put the
 * result in a new body.
 * As all the topological operators, the input objects are not modified. The resulting body is
 * a new one, that you can get by using the <tt>CATDynOperator::GetResult</tt> method.<br>
 * The faces must have the same orientation and define an open shell, but these properties
 * are not tested.
 */
class ExportedByBODYNOPE CATDynShellBody : public CATDynOperator
{
  CATCGMVirtualDeclareClass(CATDynShellBody);
 public:
/**
 * Virtual constructor of a CATDynShellBody operator.<br>
 * Can never be called. Use the <tt>CATDynCreateShellBody</tt> global function
 * to create a CATDynShellBody operator.
 */
  CATDynShellBody (CATGeoFactory    * iContainer,
                   CATCGMJournalList* iJournal  = NULL);

#ifdef CATDynShellBody_WithTopData
/**
 * Virtual constructor of a CATDynShellBody operator.<br>
 * Can never be called. Use the <tt>CATCreateDynShellBody</tt> global function
 * to create a CATDynShellBody operator.
 */
  CATDynShellBody (CATGeoFactory    * iContainer,
                   CATTopData       * iTopData  );
#endif

  virtual ~CATDynShellBody();

};


// Creation EntryPoints
/**
 * Creates a CATDynShellBody operator.
 * @param iForResultingBody
 * Where to create the resulting CATBody. 
 * @param iFaces
 * The list of faces used to create the shell domain. The faces must have the
 * same orientation, and define an open shell.
 * @param iJournal
 * A pointer to the topological journal. If NULL, no line will be writen.
 */
ExportedByBODYNOPE CATDynShellBody* CATDynCreateShellBody (      CATGeoFactory    * iFactory         ,
                                                           const CATLISTP(CATFace)& iFaces           ,
                                                                 CATCGMJournalList* iJournal         = NULL);

#ifdef CATDynShellBody_WithTopData
ExportedByBODYNOPE CATDynShellBody* CATDynCreateShellBody (      CATGeoFactory    * iFactory         ,
                                                                 CATTopData       * iTopData         ,
                                                           const CATLISTP(CATFace)& iFaces           );
#endif
#endif
