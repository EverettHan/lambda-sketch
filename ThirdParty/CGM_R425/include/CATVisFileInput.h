#ifndef  CATVisFileInput_h
#define  CATVisFileInput_h
// Soft
// Version 1 Release 0
// Copyright DASSAULT SYSTEMES 1996
// *****************************************************************
//
//   Identification :
//   ---------------
//
//      RESPONSABLE :  Jean-Luc MEDIONI
//      FUNCTION    :  4D Navigator
//      USE         :  4D Navigator
//
// *****************************************************************
//
//   Contenu :
//   --------
//
//     Gestion de l'interpretation syntaxique d'un fichier ASCII
//
// *****************************************************************
//
//   Remarque :
//   ---------
//
// ***************************************************************
//
//   Historique :
//   -----------
//
//   Revision 1.0  13/09/1996   CPI : Initial Revision (JLM)
//   Revision 2.0  25/02/1997   CPI : Extension pour supporter les .stl
//
// ****************************************************************
//
// INSIDE class:
// -------------
//
//
//
// ****************************************************************
// Abstract class    : No
// Template code     : No
// Ilined   Function : No
// ****************************************************************

#include "SceneGraphManager.h"
#include "CATVisCommonInput.h"

class ExportedBySceneGraphManager CATVisFileInput : public CATVisCommonInput 
{
    // --- Constructeur par defaut 

   public:

    CATVisFileInput()  ;

    // --- Destructeur 

    virtual ~CATVisFileInput() ;

    // --- Gestion du fichier a traiter 

    void   SetFileDescriptor( FILE *  FileDesc ) ;
    FILE * GetCurFileDescriptor() const ;

    // --- Gestion de la position du curseur dans le fichier
    // --- * Lecture du caractere suivant (deplacement avant du curseur)

    virtual int Get( char &c ) ;

    // --- * Remet un ou plusieurs caracteres (Deplacement arriere du curseur)

    virtual void PutBack( char c ) ;
    virtual void PutBack( const char *string ) ;

    // --- * La fin de fichier est'elle atteinte ?

    virtual int IsEof() const ;

  private:
    FILE        * _fileDesc   ;

    char *        _backBuffer      ;
    int	          _backBufferSize  ;		
    int	          _backBufferIndex ;		
    char*         _NumericLocale;
} ;

#endif
