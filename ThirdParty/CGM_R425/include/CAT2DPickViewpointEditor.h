#ifndef CATArcRep_H
#define CATArcRep_H

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "CAT2DViewpointEditor.h"
#include "CATVisFoundation.h"

// FBJ : 1/03/2001 (pour le RI 0293109)
// ce viewpointeditor a pour seule difference avec le CAT2DViewpointEditor la suivante :
// si on passe en mode viewpoint du graph actif, et que l'on click dans le vide avec le bouton
// du milieu rien se passe, si on click sur un objet du graph alors celui-ci est recentre
// Avec le CAT2DViewpointEditor, le recentrage est effectue meme si on click dans le vide
class ExportedByCATVisFoundation CAT2DPickViewpointEditor : public CAT2DViewpointEditor
{
public :
	CAT2DPickViewpointEditor( const CATString &iName, CAT2DViewpoint &Viewpoint, const Mode iMode=DefaultMode);
	virtual ~CAT2DPickViewpointEditor();

protected :
	virtual void Center( CATMouseEvent &MouseEvent);
};

#endif 
