/* -*-c++-*- */
#ifndef CATAttribFaceRep_H
#define CATAttribFaceRep_H
// COPYRIGHT DASSAULT SYSTEMES  1999
//=============================================================================
//
// CATAttribFaceRep:
//
// Classe de debug pour shell/thickness 
//
//=============================================================================
// Usage notes:
//
// Devrait deriver de la future classe attribut
// 
//=============================================================================
// Sep. 99  Creation                                               Church
// Sep. 01  Les attributs deviennent streamables                   chu
//=============================================================================

#include "Thick.h"
#include "CATTopDef.h"

#include "CATCGMStreamAttribute.h"
#include "CATCGMNewArray.h"
#include "CATThrowForNullPointer.h"


class CATFace;
class CATCGMOutput;
class CATSurface;


//-----------------------------------------------------------------------------
class ExportedByThick CATAttribFaceRep  : public CATCGMStreamAttribute 
{
  public:

  CATCGMDeclareAttribute (CATAttribFaceRep, CATCGMStreamAttribute);
  CATCGMNewClassArrayDeclare; 

    //----------------------------------------------------------------
    // Constructeur
    //----------------------------------------------------------------
    CATAttribFaceRep( CATFace    * iFace,
                      CATLONG32         iFaceRepNumber,
                      void       * iFaceRep,
                      void       * iSurfRep,
                      void       * iOfsatt,
                      CATSurface * iImageSurf,
                      const void * iTouch,
                      double       iOffset,
                      short        iOffsetExists,
                      void      (* iAttributeDumpCallback)( void *, CATCGMOutput & ));

    CATAttribFaceRep();

    //----------------------------------------------------------------
    // Destructeur
    //----------------------------------------------------------------
    ~CATAttribFaceRep();

    //----------------------------------------------------------------
    // Stream / Unstream
    //----------------------------------------------------------------
    void Stream(CATCGMStream & ioStream) const;
    void UnStream(CATCGMStream& ioStr );

    //----------------------------------------------------------------
    // Retourne un numero specifique a l'attribut, pour affichage
    //----------------------------------------------------------------
		CATLONG32    GetFaceRepNumber();

    //----------------------------------------------------------------
    // Acces aux donnees, utilisable par le call-back de dump
    //----------------------------------------------------------------
		CATFace * GetFace();
		void *    GetFaceRep();
		void *    GetSurfRep();
    void *    GetOfSurAtt();
		CATSurface * GetImageSurf();
		const void * GetTouch();
		double    GetOffset(short & oExists);

    //----------------------------------------------------------------
    // Affiche le contenu de l'attribut
    //----------------------------------------------------------------
		void    Dump( CATCGMOutput & os );

  private :

		CATFace    * _Face;
		CATLONG32         _FaceRepNumber;
    void       * _FaceRep;
    void       * _SurfRep;
    void       * _OfSurAtt;
    CATSurface * _ImageSurf;
    const void * _Touch;
    double       _Offset;
    short        _OffsetExists;
		// Pointeur sur la methode de dump qui recoit le CATAttribFaceRep*,
    // suivi par le stream de sortie
		void      (* _AttributeDumpCallback)(void *, CATCGMOutput &);
};

#endif
