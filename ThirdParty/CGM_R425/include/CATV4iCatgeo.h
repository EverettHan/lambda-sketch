#ifndef  CATV4iCatgeo_h
#define  CATV4iCatgeo_h

// COPYRIGHT DASSAULT SYSTEMES 2002
/**
* @level Protected
* @usage U1
*/

#include "ExportedByCATIAEntity.h"
#include "swapHeader.h"

class CATIAModel;

union decodeR8
  {
    double R8    ;
    int    I4[2] ;
    short  I2[4] ;
    char   C1[8] ;
  } ;

#ifdef PLATEFORME_DS64

/* Read a text asociated to a space element */
  ExportedByCATIAEntity int girtex(int &iMnum, const int &iJele, const int &iNumtex,
                                   int &oNbc, char oTxt[80], double oPt[3], int &oSize, int &oDir,
                                   int &ier);

/* Read the text characteristics associated to a space element with advanced parameters */
  ExportedByCATIAEntity int girtxt(int &iMnum, const int &iJele, const int &iNumtex,
                                   int &oNbc, char oTxt[80], double oPt[3], double oBase[3], double oUp[3],
                                   char oFont[9], int &oCol, int &oAngle, int &oEpais, int &oSize,
                                   int &oCenter, int &oFixed, int &oItalic, int &oShow, int &ier);
  
/* Read the layer's value of an element */
  ExportedByCATIAEntity int girlay(int &iMnum, const int &iJele, int &oLayer, int &ier);
 
/* Read the graphic attributes of an element */
  ExportedByCATIAEntity int girvis(int &iMnum, const int &iJele, int &oShow,
                                   int &oPick, int &oCol, int &oBlink, int &oThick, int &oLine,
                                   int &ier);

/* Read caracteristics of an element : */
  ExportedByCATIAEntity int girele(int &iMnum, const int &iJele, int &oPerm, 
                                   int &oNum, int &oWsp, int &oSet, int &oPlan, int &ier);
  
// Ajout OGM le 08/12/2005
// L'objectif est le support du dév de migration des données CompositeV4
// Je me demande meme si cela n'aurait pas un sens pour tous les autres ...
extern "C" 
{
/* Read elements linked to an applicative element */
  ExportedByCATIAEntity int gmarel(int &iMnum, const int &iJeleAppl, int &oNbRel,int &ier);
}

/* Scan the links of an entity */
  ExportedByCATIAEntity int gmlesc(int &iMnum, const int &iJele, const int &idprev,
                                   int &idlnk, int &iend, int &ier);
/* Analyse an ultra-weak link */
  ExportedByCATIAEntity int gmlanl (int &iMnum, const int &iJele, const int &iIdLink,
                                    int &oUserInfo, int &oJeleRef, int &oUpdated, int &ier);

/* Analyse a space ditto */
  ExportedByCATIAEntity int girwdi (int &iMnum, const int &iJeleDitto, int &oJeleDetail, 
                                  double* oTrans, int &ier );
  
  ExportedByCATIAEntity int giuwrw(int &iMnum, const int &iCode, const int &iJele, const int &iLinkNum,
                                   int &ioApply, int &ier );

  ExportedByCATIAEntity int giuwrl(int &iMnum, const int &iJele, const int &iLinkNum,
                                   int &oJelePointed, int &ier );
  
  ExportedByCATIAEntity int giuwuq(int &iMnum, const int &iJele, const int &iLinkNum, 
                                   const int &iJeleRef, int &oUpdated, int &ier );

  ExportedByCATIAEntity int girmat (int &iMnum, const int &iJele, int &iBlockLength,
                                    double* &oDescrBlock, int &ier );

  ExportedByCATIAEntity int girema (int &iMnum, const int &iJele, const int &iCompoNum,
                                    int &oMathLength, double* &oMathBlock,  int &ier );

  ExportedByCATIAEntity int girevi(int &iMnum, const int &iJele, int & oVisu, int &ier );

  ExportedByCATIAEntity int gircom(int &iMnum, const int &iJeleDetail, int & oFound, 
                                   char comment[48], int &ier );

  ExportedByCATIAEntity int girad1( int &iMnum, const int &iType, const int &iCarNbr, char iIdent[72], 
                                    int &oJeleElement, int &ier );


#else /* PLATEFORME_DS64 */

/* Read a text asociated to a space element */
  ExportedByCATIAEntity int girtex(CATIAModel* const &iModel, const int &iJele, const int &iNumtex,
                                   int &oNbc, char oTxt[80], double oPt[3], int &oSize, int &oDir,
                                   int &ier);

/* Read the text characteristics associated to a space element with advanced parameters */
  ExportedByCATIAEntity int girtxt(CATIAModel* const &iModel, const int &iJele, const int &iNumtex,
                                   int &oNbc, char oTxt[80], double oPt[3], double oBase[3], double oUp[3],
                                   char oFont[9], int &oCol, int &oAngle, int &oEpais, int &oSize,
                                   int &oCenter, int &oFixed, int &oItalic, int &oShow, int &ier);
  
/* Read the layer's value of an element */
  ExportedByCATIAEntity int girlay(CATIAModel* const &iModel, const int &iJele, int &oLayer, int &ier);
 
/* Read the graphic attributes of an element */
  ExportedByCATIAEntity int girvis(CATIAModel* const &iModel, const int &iJele, int &oShow,
                                   int &oPick, int &oCol, int &oBlink, int &oThick, int &oLine,
                                   int &ier);

/* Read caracteristics of an element : */
  ExportedByCATIAEntity int girele(CATIAModel* const &iModel, const int &iJele, int &oPerm, 
                                   int &oNum, int &oWsp, int &oSet, int &oPlan, int &ier);
  
// Ajout OGM le 08/12/2005
// L'objectif est le support du dév de migration des données CompositeV4
// Je me demande meme si cela n'aurait pas un sens pour tous les autres ...
extern "C" 
{
/* Read elements linked to an applicative element */
  ExportedByCATIAEntity int gmarel(CATIAModel* const &iModel, const int &iJeleAppl, int &oNbRel,int &ier);
}

/* Scan the links of an entity */
  ExportedByCATIAEntity int gmlesc(CATIAModel* const &iModel, const int &iJele, const int &idprev,
                                   int &idlnk, int &iend, int &ier);
/* Analyse an ultra-weak link */
  ExportedByCATIAEntity int gmlanl (CATIAModel* const &iModel, const int &iJele, const int &iIdLink,
                                    int &oUserInfo, int &oJeleRef, int &oUpdated, int &ier);

/* Analyse a space ditto */
  ExportedByCATIAEntity int girwdi (CATIAModel* const &iModel, const int &iJeleDitto, int &oJeleDetail, 
                                  double* oTrans, int &ier );
 
  ExportedByCATIAEntity int giuwrw(CATIAModel* const &iModel, const int &iCode, const int &iJele, const int &iLinkNum,
                                   int &ioApply, int &ier );

  ExportedByCATIAEntity int giuwrl(CATIAModel* const &iModel, const int &iJele, const int &iLinkNum,
                                   int &oJelePointed, int &ier );
  
  ExportedByCATIAEntity int giuwuq(CATIAModel* const &iModel, const int &iJele, const int &iLinkNum, 
                                   const int &iJeleRef, int &oUpdated, int &ier );

  ExportedByCATIAEntity int girmat (CATIAModel* const &iModel, const int &iJele, int &iBlockLength,
                                    double* &oDescrBlock, int &ier );

  ExportedByCATIAEntity int girema (CATIAModel* const &iModel, const int &iJele, const int &iCompoNum,
                                    int &oMathLength, double* &oMathBlock,  int &ier );

  ExportedByCATIAEntity int girevi(CATIAModel* const &iModel, const int &iJele, int & oVisu, int &ier );

  ExportedByCATIAEntity int gircom(CATIAModel* const &iModel, const int &iJeleDetail, int & oFound, 
                                   char comment[48], int &ier );

  ExportedByCATIAEntity int girad1( CATIAModel* const &iModel, const int &iType, const int &iCarNbr, char iIdent[72], 
                                    int &oJeleElement, int &ier );


#endif /* PLATEFORME_DS64 */

  ExportedByCATIAEntity void grvpri(const int &iIgra,int &oPrimitive);
  
  ExportedByCATIAEntity int gmuela(const int &iJeleAppl,int &igraAppl, int &ier  );

  ExportedByCATIAEntity int gmuwla(const int &iIgraDetail, int &oAppropriate, char* oApplicationString,
                                   int &oPrivate);
  
  ExportedByCATIAEntity int rectrd (const int &iCurWsp, int &oAdRep);
  
  ExportedByCATIAEntity int giuspe (const int &iTypp);
  ExportedByCATIAEntity int giudre (const int &iTypp);
  
  ExportedByCATIAEntity int giuema (const int &iIgra, const int &iCompoNum,
                                      int &oMathLength, double* &oMathBlock,  int &ier );
/*  ExportedByCATIAEntity int adrpel(const int &iIgra, const int &iNum, double* oDataAdress, int &oDataLength, int &ier);
*/
  ExportedByCATIAEntity int adrlne(const int &iIgra, int &oMathLength, double* &oMathAddress,
                                   double* &oLimitAddress, int &oTypSec);
  ExportedByCATIAEntity int adrcan(const int &iIgra, int &oMathLength, double* &oMathAddress, 
                                   int &oTypSec, int &oCan, double* &oPlanAddress);
  ExportedByCATIAEntity int adrcrb(const int &iIgra, int &oMathLength, double* &oMathAddress,
                                   double* &oLimitAddress, int &oTypSec, int &oArcNbr);

  //ExportedByCATIAEntity void decode(char *zone, int iof, int *ival);
/*
  ExportedByCATIAEntity int girgvs( CATIAModel* const &iMnum, const int &iJele, char iKeyWord[17], 
                                    int &oValue, int &ier );
  ExportedByCATIAEntity int giuckw(char iExternKeyWord[17], char iInternKeyWord[17], int &ier);
  ExportedByCATIAEntity int giugvs(const int &iIgra, const int &iMode, const char iKeyWord[17], 
                                   int oValues[3], int &ierlis);
  ExportedByCATIAEntity int gragvs(const int &iIgra, const int &iMode, const char iParam[9], int &oValue, int &ier);
  ExportedByCATIAEntity int socovi(const int &iMode, const int &iIgra, int &oVisuCode, int &ier);
  ExportedByCATIAEntity int solgvs(const int &iIgra, const int &iMode, const char iVisuMode[9], const char iParam[9], int &oValue, int &ier);
  ExportedByCATIAEntity int sofral(const int &iIgra, const int &iFrNum, double* &oFrAddress, int &oFrLength, int &oFrType, int &ier);
  ExportedByCATIAEntity void sofrlh(const double* iMathAdd,int &oSommNum, int &oSousVolNum, int &oBarresNum, int &oBarresAdd);
  ExportedByCATIAEntity int sofraa(const int &iIgra, int &ioBrepType, const int &iFrNum, int &oFrIgra, int &ier);
  */
 
#endif

