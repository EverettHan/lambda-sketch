/**
 * @level Protected
 * @usage U1
 */
 /* CATGEOBasic.h : COPYRIGHT DASSAULT SYSTEMES 1996 */
#ifndef  CATGEOBasicExt_h
#define  CATGEOBasicExt_h

#include "ExportedByCATIAEntity.h"

     /*---------------------------------------------------*/
     /*  Liste des CATGEO's basique du Data Modeler CATIA */
     /*---------------------------------------------------*/
extern "C" 
{
     /*---------------------------------------------------*/
     /*  Services de parcours sur des donnees CATGEO     */
     /*---------------------------------------------------*/

ExportedByCATIAEntity int gisfws(int &mnum, const int &numovl, \
     int &jwsp, int &ier);

ExportedByCATIAEntity int giswsp(int &mnum, const int &jadp, \
     int &jadf, int &itypw, int &ifin, int &ier);

ExportedByCATIAEntity int gisset(int &mnum, const int &jadp, \
     int &jadf, int &ifin, int &ier);

ExportedByCATIAEntity int gisels(int &mnum, const int &jset, const int &jadp, \
     int &jadf, int &ifin, int &ier);

ExportedByCATIAEntity int gieras(int &mnum, const int &jele, int &ier);

     /*------------------*/
     /*  Typage CATGEO   */
     /*------------------*/

ExportedByCATIAEntity int girtps(int &mnum, const int &jele, \
          int &itypp, int &ityps, int &itemp, int &ier);

     /*---------------------------------------------------*/
     /*  Gestion du document structure en modele CATIA    */
     /*---------------------------------------------------*/
  
ExportedByCATIAEntity int girtol(int &mnum, double &courbe,  \
     double &point, double &infinite, double &fleche, double &sag, int &ier);
  
ExportedByCATIAEntity int giruni(int &mnum, \
     double &unite, int &ier);

ExportedByCATIAEntity int gimdel(int &mnum, int &ier);

     /*---------------------------------------------------*/
     /*  Gestion des identificateur d'elements CATIA      */
     /*---------------------------------------------------*/

ExportedByCATIAEntity int giride(int &mnum, const int &jele, \
     int &lngIdent, char identificateur[72], int &ier);
}
#endif   /* CATGEOBasic_h */
