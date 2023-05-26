#pragma once

#include "CATRma3DSIParser.h"
#include "CATUnicodeString.h"
#include "IVisTexturePtr.h"

#include <functional>
#include <memory>

class CATMaterialApplication;

/**
 * @struct Texture input information.
 * Represents everything needed to fetch a texture buffer.
 */
struct CATRma3DSITextureInInfo
{
	CATUnicodeString uri;
	int offset = 0;
	int size = 0;
	bool transparent = false;
};

/**
 * @struct Texture output information.
 * Represents everyting needed to be used on a material parameter.
 */
struct CATRma3DSITextureOutInfo
{
	IVisTexturePtr texture;
	int offset = 0;
	int size = 0;
	bool transparent = false;
};

/**
 * @class Rendering Material 3D Search Index (3DSI) Parser.
 * Allows to parse 3DSI attributes and returns scene graph materials from them.
 */
class ExportedByCATRma3DSIParser CATRma3DSIMaterialParser
{
public:
	CATRma3DSIMaterialParser();
	~CATRma3DSIMaterialParser();

	// name alias for the texture fetch callback function
	using TextureFetchCallback = std::function<CATRma3DSITextureOutInfo(const CATRma3DSITextureInInfo&)>;

	/** Sets the texture fetch callback function to be used to resolve the texture buffer from an URI.
	 *  @param iCallback Callback function to resolve the texture by URI.
	 */
	void SetTextureFetchCallback(TextureFetchCallback iCallback);

	/** Parse a material from the given connection and visAppearance attributes of 
	 *  the 3D Search Index (aka. progressive expand).
	 *  @param iConnectionAttributes The 3DSI representation of the material connection.
	 *  @param iVisAppearanceAttribute The 3DSI representation of the appearance.
	 *  @param oMaterialApplication The parsed material application.
	 *  @return S_OK on success.
	 *          E_INVALIDARG if the input attributes are invalid.
	 *          E_FAIL if the parsing failed.
	 */
	HRESULT Parse(const CATUnicodeString& iConnectionAttributes, const CATUnicodeString& iVisAppearanceAttribute,
		CATMaterialApplication& oMaterialApplication);

private:
	class Impl;
	std::unique_ptr<Impl> _impl;
};
