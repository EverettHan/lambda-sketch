/**
 * @level Protected
 * @usage U1
 */
 /* CATGEOBasic.h : COPYRIGHT DASSAULT SYSTEMES 1996 */
#ifndef  CATGEOBasic_h
#define  CATGEOBasic_h

#include "ExportedByCATIAEntity.h"

     /*---------------------------------------------------*/
     /*  Liste des CATGEO's basique du Data Modeler CATIA */
     /*---------------------------------------------------*/
class CATIAModel;

extern "C" 
{

#ifdef PLATEFORME_DS64
     /*---------------------------------------------------*/
     /*  Services de parcours sur des donnees CATGEO     */
     /*---------------------------------------------------*/

ExportedByCATIAEntity int gisfws(int &iMnum, const int &numovl, \
     int &jwsp, int &ier);

ExportedByCATIAEntity int giswsp(int &iMnum, const int &jadp, \
     int &jadf, int &itypw, int &ifin, int &ier);

ExportedByCATIAEntity int gisset(int &iMnum, const int &jadp, \
     int &jadf, int &ifin, int &ier);

ExportedByCATIAEntity int gisels(int &iMnum, const int &jset, const int &jadp, \
     int &jadf, int &ifin, int &ier);

ExportedByCATIAEntity int gieras(int &iMnum, const int &jele, int &ier);

     /*------------------*/
     /*  Typage CATGEO   */
     /*------------------*/

ExportedByCATIAEntity int girtps(int &iMnum, const int &jele, \
          int &itypp, int &ityps, int &itemp, int &ier);

     /*---------------------------------------------------*/
     /*  Gestion du document structure en modele CATIA    */
     /*---------------------------------------------------*/
  
ExportedByCATIAEntity int girtol(int &iMnum, double &courbe,  \
     double &point, double &infinite, double &fleche, double &sag, int &ier);
  
ExportedByCATIAEntity int giruni(int &iMnum, \
     double &unite, int &ier);

ExportedByCATIAEntity int gimdel(int &iMnum, int &ier);

     /*---------------------------------------------------*/
     /*  Gestion des identificateur d'elements CATIA      */
     /*---------------------------------------------------*/

ExportedByCATIAEntity int giride(int &iMnum, const int &jele, \
     int &lngIdent, char identificateur[72], int &ier);

#else /* PLATEFORME_DS64 */
     /*---------------------------------------------------*/
     /*  Services de parcours sur des donnees CATGEO     */
     /*---------------------------------------------------*/
ExportedByCATIAEntity int gisfws(CATIAModel *const &iModel, const int &numovl, \
     int &jwsp, int &ier);

ExportedByCATIAEntity int giswsp(CATIAModel *const &iModel, const int &jadp, \
     int &jadf, int &itypw, int &ifin, int &ier);

ExportedByCATIAEntity int gisset(CATIAModel *const &iModel, const int &jadp, \
     int &jadf, int &ifin, int &ier);

ExportedByCATIAEntity int gisels(CATIAModel *const &iModel, const int &jset, const int &jadp, \
     int &jadf, int &ifin, int &ier);

ExportedByCATIAEntity int gieras(CATIAModel *const &iModel, const int &jele, int &ier);

     /*------------------*/
     /*  Typage CATGEO   */
     /*------------------*/

ExportedByCATIAEntity int girtps(CATIAModel *const &iModel, const int &jele, \
          int &itypp, int &ityps, int &itemp, int &ier);

     /*---------------------------------------------------*/
     /*  Gestion du document structure en modele CATIA    */
     /*---------------------------------------------------*/
  
ExportedByCATIAEntity int girtol(CATIAModel *const &iModel, double &courbe,  \
     double &point, double &infinite, double &fleche, double &sag, int &ier);
  
ExportedByCATIAEntity int giruni(CATIAModel *const &iModel, \
     double &unite, int &ier);

ExportedByCATIAEntity int gimdel(CATIAModel *const &iModel, int &ier);

     /*---------------------------------------------------*/
     /*  Gestion des identificateur d'elements CATIA      */
     /*---------------------------------------------------*/

ExportedByCATIAEntity int giride(CATIAModel *const &iModel, const int &jele, \
     int &lngIdent, char identificateur[72], int &ier);

#endif /* PLATEFORME_DS64 */
}
#endif   /* CATGEOBasic_h */
