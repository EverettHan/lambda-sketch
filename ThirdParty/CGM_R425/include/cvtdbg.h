

/**
 * @level Private
 * @usage U1
 */

#ifndef cvtdbg_h
#define cvtdbg_h

//===================================================================
//     PROTO DE DEBUG CATAIX NT
//===================================================================
#include<ExportedByCATIAEntity.h>

extern "C"
{
         //------------------------------------------------------------------------------
         //    cvtdbg_new  : amorcage du traitement cataix
         //    cvtdbg_spec : fin traitement description generale, debut desc. specifique
         //    cvtdbg_ier  : detection d'une erreur au cours du traitement
         //    cvtdbg_del  : terminaison du traitement cataix
         //------------------------------------------------------------------------------

ExportedByCATIAEntity  void cvtdbg_new ( const int& igra, const double& blocdata);
ExportedByCATIAEntity  void cvtdbg_spec( const int& igra);
ExportedByCATIAEntity  void cvtdbg_gen ( const int& igra, const int &itpdes, const int &when);
ExportedByCATIAEntity  void cvtdbg_ier ( const int& igra);
ExportedByCATIAEntity  void cvtdbg_del ( const int& igra);
  
         //------------------------------------------------------------------------------
         //    cvtdbg_set  : definition d'une zone d'octet en cours de conversion
         //    cvtdbg_fin  : fin de traitement du model et sortie des stats
         //------------------------------------------------------------------------------

ExportedByCATIAEntity  void cvtdbg_set( const char*, const int&, const char&, int& );
ExportedByCATIAEntity  void cvtdbg_fin();

}

int GetCATAIXTools();

#endif
