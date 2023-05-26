/* -*-c++-*- */
#ifndef CATAttribVertexRep_H
#define CATAttribVertexRep_H
// COPYRIGHT DASSAULT SYSTEMES  1998
//=============================================================================
//
// CATAttribVertexRep:
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

#include "CATCGMStreamAttribute.h"
#include "CATCGMNewArray.h"
#include "CATThrowForNullPointer.h"


class CATVertex;
class CATCGMOutput;

//-----------------------------------------------------------------------------
class ExportedByThick CATAttribVertexRep  : public CATCGMStreamAttribute 
{
  public:

  CATCGMDeclareAttribute (CATAttribVertexRep, CATCGMStreamAttribute);
  CATCGMNewClassArrayDeclare; 


    //----------------------------------------------------------------
    // Constructeur
    //----------------------------------------------------------------
    CATAttribVertexRep( CATVertex  * iVertex, 
			                  CATLONG32         iVertexRepNumber, 
											  void       * iAttribute,
											  void      (* iAttributeDumpCallback)( void *, CATCGMOutput & ) );

    CATAttribVertexRep();

    //----------------------------------------------------------------
    // Destructeur
    //----------------------------------------------------------------
    ~CATAttribVertexRep();

		CATLONG32 GetVertexRepNumber();

		void Dump( CATCGMOutput & os );

    //----------------------------------------------------------------
    // Stream / Unstream
    //----------------------------------------------------------------
    void Stream(CATCGMStream & ioStream) const;
    void UnStream(CATCGMStream& ioStr );

    //----------------------------------------------------------------
    // Affichage du label dans la visu de l'atelier NCGM
    //----------------------------------------------------------------

    static short GetShowLabel();
    static void SetShowLabel( short iShowLabel );

	private :

		CATVertex  * _Vertex;
		CATLONG32         _VertexRepNumber;
		// Pointeur sur l'attribut lui-meme (ici : un CAThkVertexRep) 
    void       * _Attribute;
		// Pointeur sur la methode de dump de l'attribut 
		void      (* _AttributeDumpCallback)(void *, CATCGMOutput &);

    // Acces direct a la variable statique s_ShowLabel
    static short & GetShowLabel_priv();
};

#endif
