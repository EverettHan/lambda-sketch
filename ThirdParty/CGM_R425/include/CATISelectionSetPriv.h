// COPYRIGHT Dassault Systemes 2004
//===================================================================
/** 
*Interface CATISelectionSetPriv
*<b>Role:</b>This interface is implemented once in MechanicalModelerUI/PrtEnv.m/src/CATSelSetPath.cpp
             <br>Do not re-implement this interface

          <br><br>Interface utilisee uniquement dans CATFecSelectionSetElement::ComputeElementPath
          pour pouvoir appeler du code de MechanicalModelerUI dans FeatureCommands
*/
//
//  Mai 2004  Creation: Code generated by the CAA wizard  cff
//===================================================================
#ifndef CATISelectionSetPriv_H
#define CATISelectionSetPriv_H

#include "UIModelInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATISelectionSetPriv;
#else
extern "C" const IID IID_CATISelectionSetPriv ;
#endif

//------------------------------------------------------------------



class CATPathElement;
//#include "CATListOfCATPathElement.h"
class CATListPtrCATPathElement;

class ExportedByUIModelInterfaces CATISelectionSetPriv: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

/** @nodoc */ 
/* Methode permettant de mettre a jour le path entre en fonction de features visibles.
   Rend le meme resultat que le highlight puisque le code est commun.
   Si l'element dont le path est entre est devenu invisible, la liste contient
    un seul path qui est nul.
   Rq : il se peut qu'un path entre donne plusieurs paths en sortie, dans la cas 
   d'une face qui se retrouve decoupee en 2, par un pocket par exemple.*/
  virtual CATListPtrCATPathElement ExtractPathElement(CATPathElement* iPath) =0;


};

//------------------------------------------------------------------

#endif