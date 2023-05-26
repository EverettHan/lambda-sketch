//===================================================================
// COPYRIGHT Dassault 2010
//===================================================================
// SWXUtPacketSimpleParameter.h
//===================================================================

#ifndef SWXUtPacketSimpleParameter_H
#define SWXUtPacketSimpleParameter_H

#include "SWXUtBasePacket.h"
#include "SWXUtPacketParameter.h"

#include "CATListOfCATUnicodeString.h"

class CATMathPoint;
class CATMathPoint2D;

class CATMathVector;
class CATUnicodeString;
class SWXUtPacket;
class SWXUtPacketParameter;

//-----------------------------------------------------------------------

class ExportedBySWXUtBasePacket SWXUtPacketSimpleParameter : public SWXUtPacketParameter
{
	CATDeclareClass;
public:
	SWXUtPacketSimpleParameter(const CATUnicodeString& iName,
		const CATUnicodeString& iTypeString,
		const CATUnicodeString& iRestriction, 
		SWXUtPacket* iPacket,
		SWXUtPacketParameter* iParent);

	virtual SWXUtPacketParameter* Clone( const CATUnicodeString& iNamePrefix, SWXUtPacketParameter* iParent) override;

	virtual ~SWXUtPacketSimpleParameter();


	virtual HRESULT SetValue(const CATUnicodeString &iValue) override;
	virtual HRESULT GetValue(CATUnicodeString &oValue) override;
	virtual HRESULT SetValue(int iValue);
	virtual HRESULT GetValue(int &oValue);
	virtual HRESULT SetValue(bool iValue);
	virtual HRESULT GetValue(bool &oValue);
	virtual HRESULT SetValue(double iValue);
	virtual HRESULT GetValue(double &oValue);
	virtual HRESULT SetValue(const CATMathPoint& iValue);
	virtual HRESULT GetValue(CATMathPoint& oValue);
	virtual HRESULT SetValue(const CATMathVector& iValue);
	virtual HRESULT GetValue(CATMathVector& oValue);
	virtual HRESULT SetValue(const CATMathPoint2D& iValue);
	virtual HRESULT GetValue(CATMathPoint2D& oValue);

	virtual HRESULT LoadParameter(CATICkeParm* iParam) override;
	virtual HRESULT ApplyParameter(CATICkeParm* iParam) override;
	virtual HRESULT CopyValueTo(SWXUtPacketParameter* iTo) override;

protected:
	// constructor for Clone()
	SWXUtPacketSimpleParameter(const SWXUtPacketSimpleParameter& iOriginal, const CATUnicodeString& iNamePrefix, SWXUtPacketParameter* iParent);

	bool mBoolValue;
	int mIntValue;
	CATUnicodeString mStringValue;
	SWXUtVector<double> mDoubles;

private:
	enum types { 
		ENUM_INVALID = -1,
		ENUM_STRING = 0, 
		ENUM_SCALAR = 1, 
		ENUM_3DVECTOR = 2, 
		ENUM_3DPOINT = 3, 
		ENUM_INTEGER = 4,
		ENUM_2DPOINT = 5,
		ENUM_BOOLEAN = 6 } mEnumType;
};

#endif
