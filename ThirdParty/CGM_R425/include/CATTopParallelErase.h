/*
=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 1998
 
 DESCRIPTION : CATParallelUtili Operator

=============================================================================
*/
#ifndef CATTopParallelErase_H
#define CATTopParallelErase_H


class CATBody;
class CATCGMJournalList;
class CATGeoFactory;
class CATTopData;

#include "ParallelLight.h"


//-----------------------------------------------------------------------------
//  Decode topologie pour les wires
//-----------------------------------------------------------------------------
//
// recherche des extremites equivqlentes aux extremites du wire G1 original dans
// le resultat du parallele
/*void CATTopParallelErase (CATGeoFactory* factory, CATCGMJournalList* journal, // factory et journal a remplir
                     CATLONG32 nbbodies, CATBody ** ToEraseBodies, // bodies a effacer
                     CATLONG32  nbCopied, CATBody ** CopiedBodies); // bodies encopydans le journal
*/
ExportedByParallelLight void CATTopParallelErase (CATGeoFactory* factory, CATTopData * iData, // factory et journal a remplir
                     CATLONG32 nbbodies, CATBody ** ToEraseBodies, // bodies a effacer
                     CATLONG32  nbCopied, CATBody ** CopiedBodies); // bodies encopydans le journal
#endif
