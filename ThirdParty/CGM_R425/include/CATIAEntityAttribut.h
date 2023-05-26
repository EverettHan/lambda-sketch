/**
 * @level Protected
 * @usage U1
 */
#ifndef CATIAEntityAttribut_h
#define CATIAEntityAttribut_h
// ====================================================
//   CATIA
//   Version CXR1.0
//   COPYRIGHT DASSAULT SYSTEMES 1996
// ====================================================
//
//   FUNCTION :
//
//        Set of services for the ATTRIBUT function
//
// ====================================================

// ----------------------
// TypeDef
// ----------------------

typedef unsigned char string16[16];
typedef unsigned char string17[17];
typedef unsigned char string70[70];
typedef unsigned char string71[71];

union VALEUR { string71 valatt_c71; int valatt_int; double valatt_dble; };

// -------------------------------------------------------------
// Structure bloc de definition dans le prj ou le prjmodel
// -------------------------------------------------------------

struct BLOC_ATTRIBUT
{
  unsigned char  owner[8];
  int            numatt;
  int            ibid;
  double         unite;
  string16       idatt;
  string70       comment;
  unsigned char  cbid[2];
  unsigned char  cappli[8];
};

// -----------------------------------
// Pour acceder aux Attributs Discrets
// -----------------------------------

struct DISCRET
{
  int numatt;
  int numval;
};

// -------------------------------------
// Pour acceder aux attributs numeriques
// -------------------------------------

struct NUMERIC
{
  int numatt;
  int ibid;
  double valeur;
};

// ------------------------------------------
// Pour acceder aux attributs alphanumeriques
// ------------------------------------------

struct ALPHANUM  
{
  int numatt;
  int nbcara;
};  

// -------------------------------
// Pour la CATLISTP de sortie de CATAttrGirvae.
// -------------------------------

struct REFERENCE
{
  string17      idatt; 
  union VALEUR  valeur;
  int           format;
};  

// ----------------------------
// Quelques constantes globales
// ----------------------------

const int idsprj_att = 280; // Itydes de la description attributs du
                            // prjmodel
const int ilhead = 16;   // Longueur bloc header de la description attributs
                         // du prjmodel
const int ilbloc = 15;   // Longueur bloc de definition d attribut
                         // au niveau du prj ou du prjmodel

#endif






