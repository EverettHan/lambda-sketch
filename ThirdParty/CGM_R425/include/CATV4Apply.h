/**
 * @level Protected
 * @usage U1
 */
/* CATV4Apply.h : COPYRIGHT DASSAULT SYSTEMES 1997 */
#ifndef  CATV4Apply_h
#define  CATV4Apply_h

#include <CATV4UserApplication.h>

  /*---------------------------------------------*/
  /*  Gestion interne du Soft des UAX en CXR1    */
  /*---------------------------------------------*/

const int modePublic=2;
const int modePrive=1;

extern "C"
{

  /*------------------------------------------------------*/
  /* Service INTERNE : Gestion de l'application en cours  */
  /*------------------------------------------------------*/

  ExportedByCATIAEntity  int applyset(const int &mode, const char chaine[8], int &ier);
  ExportedByCATIAEntity  int applyqry(int &mode, char chaine[8], int &ier);
  ExportedByCATIAEntity  int aicquery(int &mode, char chaine[3], int &ier);

  ExportedByCATIAEntity int uaxcur(const int &igra);
  ExportedByCATIAEntity int bastyp(const int &igra);

  /*------------------------------------------*/
  /* Service a eviter car obsolete,redondant  */
  /*------------------------------------------*/

  ExportedByCATIAEntity  unsigned char aprvis();
  ExportedByCATIAEntity  int           uaxpro();
  ExportedByCATIAEntity  void          aprvon();
  ExportedByCATIAEntity  void          aprvof();
  ExportedByCATIAEntity  void          gmutyp(const int &igra, int &itypp, int &ityps);
  ExportedByCATIAEntity  void          uaelec(const int &igra, int &ityps);

  ExportedByCATIAEntity int lecuap(const int &igra, int &lprivate, int &itypp,                                  int &ityps, char chiden[4], char chapply[8]); 
  ExportedByCATIAEntity int lecuax(const int &igra, int &itypp, int &ityps, 
                                 char chiden[4], char chapply[8]);
}

#endif   /* CATV4Apply_h */
