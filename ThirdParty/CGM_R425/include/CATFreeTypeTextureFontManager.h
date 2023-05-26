//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2011/10/24
//===================================================================
// CATFreeTypeTextureFontManager.cpp
// 
//===================================================================
//
// Usage notes:
//
//===================================================================
//===================================================================

#ifndef CATFreeTypeTextureFontManager_H
#define CATFreeTypeTextureFontManager_H

#include "CATBaseUnknown.h"
#include "CATFreeType.h"
#include "vector.h"

class CATFreeTypeTextGP;
class CATFreeTypeTextFormat;
class CATFreeTypeTextureFont;
class CATFreeTypeTextureAtlas;
class CATGraphicMaterial;


class ExportedBySGInfra CATFreeTypeTextureFontManager: public CATBaseUnknown
{
   //CATDeclareClass;

public:
	CATFreeTypeTextureFontManager();
	virtual ~CATFreeTypeTextureFontManager();

	struct Resource {
		CATFreeTypeTextureFont* font;
		CATFreeTypeTextureAtlas* atlas;
		CATGraphicMaterial* material;
	};

	//! Find a suitable  texture-font resource to render a given text format
	CATFreeTypeTextureFontManager::Resource GetRenderingResource(CATFreeTypeTextFormat const* iFormat);

	//! Free unreferenced texture fonts
	void GC();

protected:
	void CreateMaterials();
	void DestroyMaterials();
	void DestroyFonts();
	CATFreeTypeTextureFont* CreateTextureFont(CATFreeTypeTextureAtlas* iAtlas, CATFreeTypeTextFormat const* iFormat);
	CATFreeTypeTextureAtlas* CreateTextureAtlas(unsigned int iWidth, unsigned int iHeight);


private:
	struct FontRec {
		CATFreeTypeTextureFont*		_font;
		size_t					_materialIndex;
	};
	struct MaterialRec {
		CATGraphicMaterial*		_material;
		CATFreeTypeTextureAtlas* _atlas;
		CATFreeType::FormatHint _formatHint;
		int						_renderFlags;
	};
	typedef vector<FontRec>		FontList;
	typedef vector<MaterialRec>	MaterialList;

private:
	FontList		_fonts;
	MaterialList	_materials;
	size_t			_numOpenFonts;
};


#endif // CATFreeTypeTextureFontManager_H 
