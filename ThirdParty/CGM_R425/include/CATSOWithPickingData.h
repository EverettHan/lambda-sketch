#ifndef CATSOWithPickingData_h
#define CATSOWithPickingData_h

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "SceneGraphManager.h"
#include "CATBaseUnknown.h"
#include "list.h"

class CATPickPath;
class CATPickPathList;
class CATPathElement;
class CATSysSimpleHashTable;
class CATSOPickingData;

class ExportedBySceneGraphManager CATSOWithPickingData : public CATBaseUnknown
{
    friend class CATManipulatorMediator;

    CATDeclareClass;

public:
    CATSOWithPickingData ();
    virtual ~CATSOWithPickingData();

    // sert a recuperer les pathelements de la liste d'entree 
    const CATPathElement * operator [] (int iIndex) const ;

    // permet d'ajouter un path filtre dans la liste des path filtres
    void AddElement(CATPathElement *iPath, unsigned int iPos);

    // cette fonction dot etre appelee
    // a la fin de l'ajout des path filtres
    // elle permet notemment de supprimer les doublons.
    void EndAddElements();

    // permet de recuperer le nombre de path dans la liste de sortie
    unsigned int GetSize();

    // cette fonction remplit un liste de CATPickPath, avec des
    // CATPickPath crees a partir des path filtres contenus dans cet objet.
    void FillPickPathList(CATPickPathList& iList);

    static unsigned int GetKey(void*);
    static int Compare(void*, void*);

private :  
    HRESULT AddInitialElement (CATPathElement *iPath, CATPickPath* iPickingPath);

    CATSysSimpleHashTable* _initialPathes;
    list<CATSOPickingData> _data;
    unsigned int           _finalSize;
};

#endif
