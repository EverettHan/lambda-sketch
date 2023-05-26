/* -*-c++-*- */
#ifndef CATAttribEdgeRep_H
#define CATAttribEdgeRep_H
// COPYRIGHT DASSAULT SYSTEMES  1998
//=============================================================================
//
// CATAttribEdgeRep:
//
// Classe de debug pour shell/thickness 
//
//=============================================================================
// Usage notes:
//
// Devrait deriver de la future classe attribut
// 
//=============================================================================
// Nov. 98  Creation                                               L. Alt
// Sep. 01  Les attributs deviennent streamables                   chu
//=============================================================================

#include "Thick.h"
#include "CATTopDef.h"

#include "CATCGMStreamAttribute.h"
#include "CATCGMNewArray.h"
#include "CATThrowForNullPointer.h"


class CATEdge;
class CATCGMOutput;
class CATCGMStream;
class CATSurface;


//-----------------------------------------------------------------------------
class ExportedByThick CATAttribEdgeRep  : public CATCGMStreamAttribute 
{
  public:

  CATCGMDeclareAttribute (CATAttribEdgeRep, CATCGMStreamAttribute);
  CATCGMNewClassArrayDeclare; 

    //----------------------------------------------------------------
    // Constructeur
    //----------------------------------------------------------------
    CATAttribEdgeRep( CATEdge    * iEdge, 
			                CATLONG32         iEdgeRepNumber, 
											void       * iAttribute,
											void      (* iAttributeDumpCallback)( void *, CATCGMOutput & ),
                      CATLONG32      (* iAttributeGetNbSidesCallback)( void * ),
                      CATSide   (* iAttributeGetSideCallback)( void *, CATLONG32, CATSurface ** ),
                      void       * iSideGuessGraphicData);

    CATAttribEdgeRep();

    //----------------------------------------------------------------
    // Destructeur
    //----------------------------------------------------------------
    ~CATAttribEdgeRep();

    //----------------------------------------------------------------
    // Stream / Unstream
    //----------------------------------------------------------------
    void Stream(CATCGMStream & ioStream) const;
    void UnStream(CATCGMStream& ioStr );

    //----------------------------------------------------------------
    // Retourne un numero specifique a l'attribut 
    //----------------------------------------------------------------
		CATLONG32    GetEdgeRepNumber();

    //----------------------------------------------------------------
    // Affiche le contenu de l'attribut
    //----------------------------------------------------------------
		void    Dump( CATCGMOutput & os );

    //----------------------------------------------------------------
    // Retourne le nombre de cotes matiere que l'attribut connait
    //----------------------------------------------------------------
    CATLONG32  GetNbSides();

    //----------------------------------------------------------------
    // Retourne le cote matiere estime de l'attribut (de type  edge)
    // par rapport a la surface (enfin, par rapport aux faces a cons-
    // truire sur cette surface), et les donnees de visu du side-guess
    //----------------------------------------------------------------
    CATSide GetSide( CATLONG32 iIndex, CATSurface ** iSurface );
    void *  GetSideGuessGraphicData();

    //----------------------------------------------------------------
    // Affichage du label dans la visu de l'atelier NCGM
    //----------------------------------------------------------------

    static short GetShowLabel();
    static void SetShowLabel( short iShowLabel );

  private :

		CATEdge    * _Edge;
		CATLONG32         _EdgeRepNumber;
		// Pointeur sur l'attribut lui-meme (ici : une CAThkEdgeRep) 
    void       * _Attribute;
		// Pointeur sur la methode de dump de l'attribut 
		void      (* _AttributeDumpCallback)(void *, CATCGMOutput &);
		// Pointeur sur la methode de get nb-sides de l'attribut 
		CATLONG32      (* _AttributeGetNbSidesCallback)(void * );
		// Pointeur sur la methode de get side de l'attribut 
		CATSide   (* _AttributeGetSideCallback)(void *, CATLONG32, CATSurface ** iSurface );
    // Faut-il visualiser les side-guess (petites droites) et comment
    // Ce void* est destine a pointer vers une petite structure qui permettra
    // de faire du "tuning" (ex: couleur) sur la maniere de visualiser l'edge-rep, 
    // pour l'instant, s'il est non nul, on fait des petites droites
    void       * _SideGuessGraphicData;

    // Acces direct a la variable statique s_ShowLabel
    static short & GetShowLabel_priv();
};

#endif
