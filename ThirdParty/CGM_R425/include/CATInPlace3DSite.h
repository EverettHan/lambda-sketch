#ifndef __CATInPlace3DSite_h
#define __CATInPlace3DSite_h


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATMathTransformation;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATInPlace3DSite;
#else
extern "C" const IID IID_CATInPlace3DSite;
#endif


class ExportedByCATAfrItf CATInPlace3DSite : public CATBaseUnknown {

  CATDeclareInterface;

public:

  // cette methode renvoie la matrice de transformation
  // permettant de passer du repere du site de plus au
  // repere du site sur lequel cette methode est appelee
  // ex: lorsque cette methode est appelee sur un sketch
  // appartenant a un assemblage, elle renvoie la matrice 
  // de transfo permettant de passer du repere de l'assemblage
  // au repere du sketch
  virtual HRESULT   GetModelMatrix      (CATMathTransformation * oTransfo) = 0;

  // Appelee sur le site fils, cette methode renvoie la
  // matrice de transformation permettant de passer
  // du repere du site pere au repere du site fils
  // iUserData peut servir a passer le site pere au site fils
  // afin de lui permettre de calculer la transformation
  // ex: Sketch->GetLocalTransfo (oTransfo, Part)
  virtual HRESULT   GetLocalTransfo     (CATMathTransformation * oTransfo,
					 CATBaseUnknown        * iFatherSite) = 0;

  // Cette methode permet au site sur lequel elle est appelee de 
  // calculer la valeur de sa ModeMatrix. Un pointeur sur le 
  // site pere doit etre passe en argument. Il peut etre utile
  // pour calculer ModelMatrix
  virtual HRESULT   ComputeModelMatrix  (CATInPlace3DSite      * iFatherSite) = 0;

  // Cette methode est appelee par l'objet ui-actif, l'argument
  // iActiveObject permet au site de connaitre l'appelant
  // le site repond S_OK si il autorise l'objet ui-actif a
  // dessiner une bounding-box. Il renvoie S_FALSE sinon.
  virtual HRESULT   CanDrawBoundingBox  (CATBaseUnknown        * iActiveObject) = 0;

};


CATDeclareHandler (CATInPlace3DSite, CATBaseUnknown);


#endif//__CATInPlace3DSite_h
