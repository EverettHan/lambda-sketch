#ifndef  CATVisCommonInput_h
#define  CATVisCommonInput_h
// Soft
// Version 1 Release 0
// Copyright DASSAULT SYSTEMES 1997
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
//     Gestion de l'interpretation syntaxique
//     (Classe abstraite pour les fichiers 
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
//   Revision 1.0  29/04/1997   CPI : Initial Revision (JLM)
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


//#define TRUE  1
//#define FALSE 0

#include "SceneGraphManager.h"

class ExportedBySceneGraphManager CATVisCommonInput 
{
   public:

    // --- Constructeur par defaut 

    CATVisCommonInput()  ;

    // --- Destructeur 

    virtual ~CATVisCommonInput() ;

    // --- Gestion de la position du curseur dans le fichier
    // --- * Lecture du caractere suivant (deplacement avant du curseur)

    virtual int Get( char &c ) = 0 ;

    // --- * Remet un ou plusieurs caracteres (Deplacement arriere du curseur)

    virtual void PutBack( char c ) = 0 ;
    virtual void PutBack( const char *string ) = 0 ;

    // --- * La fin de fichier est'elle atteinte ?

    virtual int IsEof() const = 0 ;

    // --- * Passage a la ligne suivante suivant (deplacement avant du curseur)

    int    SkipLine() ;

    // --- * Passage au caractere non blanc suivant (deplacement avant du curseur)
    // ---   +++ Attention a la gestion des commentaires +++

    int    SkipWhiteSpace() ;

    // -------------------------------------
    // --- Lecture d'un bloc de donnees ----
    // -------------------------------------

    // --- Lecture du prochain caractere non "blanc"

    int    Read( char &c ) ;

    // --- Lecture de la chaine de caractere suivante
    // --- * La chaine de caracteres est soit entre " (double cote)
    // ---   ou limitee par un caractere blanc

    int    Read( const char * &s ) ;

    // --- Lecture de la chaine de caractere suivante limite
    // --- * La chaine de caracteres est limitee par une serie
    // ---   de separateur defini en entree
    // --- * La chaine en sortie peut etre vide
    // --- * Les caracteres blancs en tete ne sont pas sautes

    int Read(       int           NbSeparator
            , const char ** const Separator
            , const char * &      String
            ,       int  &        FoundSeparator ) ;

     // --- Lecture d'une valeur entiere

    int    Read( int            &i ) ;
    int    Read( unsigned int   &i ) ;

    // --- Lecture d'une valeur reelle

    int    Read( double         &d ) ;

    // --- Lecture d'un token
    // --- * Decodage d'un mot particulier
    // --- * Decodage d'un caractere particulier

    int     ReadToken( const char * const Token ) ;
    int     ReadToken( const char         Token ) ;

    // --- Lecture d'un token
    // --- (Decodage d'un mot particulier sans tenir compte de la casse Majuscule/Minuscule)
    // --- NB : Le token doit etre donne en majuscule

    int ReadTokenUpCase( const char * const Token ) ;

    // --- Lecture de la ligne courante

    int    GetCurrentLineNumber() const ;

  protected :
    int           _lineNum         ;

    char *        _readString      ;
    int	          _readStringSize  ;		
    int	          _readStringIndex ;		

    char *        _readToken       ;
    int	          _readTokenSize   ;		
    int	          _readTokenIndex  ;		

    // --- Methode de lecture interne 

    int    _readInteger( long &l ) ;
    int	   _readUnsignedInteger( unsigned long &l ) ;

    int	   _readReal( double &d ) ;

    int	   _readUnsignedIntegerString( char *str ) ;

    int	   _readDigits( char *string ) ;
    int	   _readHexDigits( char *string ) ;

    int	   _readChar( char *string , char charToRead ) ;
} ;

#endif
