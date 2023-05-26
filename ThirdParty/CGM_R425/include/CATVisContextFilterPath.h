#ifndef CATVisContextFilterPath_H
#define CATVisContextFilterPath_H
//
// CATIA Version 5 Release 15 Framework Visualization
// Copyright Dassault Systemes 2004

#include "CATVisContextFilterValue.h"

#ifndef NULL 
#define NULL 0
#endif

class CATPathElement;
class CATVisContextFilterData;
class CATVisPublisher;
class CATVisContextFilterPath 
{
public :
	CATVisContextFilterPath(CATPathElement* path, const CATVisContextFilterValue& value);
	~CATVisContextFilterPath() ;

	void Destroy();

	inline CATPathElement* GetPath();

	inline unsigned int IsInvisible()         const;
	inline unsigned int IsLowIntensified()    const;
	inline unsigned int IsNotPickable()       const; 
	inline unsigned int IsViewModeOverload()  const; 
	inline unsigned int IsViewMeshOverload()  const;
	inline unsigned int GetViewMesh()         const;
	inline unsigned int IsViewEdgeOverload()  const;
	inline unsigned int GetViewEdge()         const;
	inline unsigned int IsViewLineOverload()  const;
	inline unsigned int GetViewLine()         const;
	inline unsigned int IsViewAxisOverload()  const;
	inline unsigned int GetViewAxis()         const;
	inline unsigned int IsViewPointOverload() const;
	inline unsigned int GetViewPoint()        const;

	inline unsigned int IsColorOverload()				const;
	inline unsigned int	GetColorRGBA()					const;
	inline void			GetColorRGB( 
								unsigned int& oRed, 
								unsigned int& oGreen, 
								unsigned int& oBlue)	const;
	inline unsigned int IsTransparencyOverload()		const;
	inline unsigned int GetTransparency()				const;

	inline void SetValue(const CATVisContextFilterValue& value);

	inline void SetData(CATVisContextFilterData* iData);
	inline void UnsetData();

	void Publish(CATVisPublisher& iPublisher);

private : 
	CATPathElement*           _path;
	CATVisContextFilterValue  _value;
	CATVisContextFilterData*  _data;	
};

inline CATPathElement* CATVisContextFilterPath::GetPath() 
{
	return _path;
}

inline void CATVisContextFilterPath::SetValue(const CATVisContextFilterValue& value)
{
	_value = value;
}

inline void CATVisContextFilterPath::SetData(CATVisContextFilterData* iData)
{
	_data = iData;
}

inline void CATVisContextFilterPath::UnsetData()
{
	_data = NULL;
}

inline unsigned int CATVisContextFilterPath::IsNotPickable() const
{
	return _value.IsNotPickable();
}

inline unsigned int CATVisContextFilterPath::IsInvisible() const
{
	return _value.IsInvisible();
}

inline unsigned int CATVisContextFilterPath::IsLowIntensified() const
{
	return _value.IsLowIntensified();
}

inline unsigned int CATVisContextFilterPath::IsViewModeOverload()  const
{
	return _value.IsViewModeOverload();
}

inline unsigned int CATVisContextFilterPath::IsViewMeshOverload()  const
{
	return _value.IsViewMeshOverload();
}

inline unsigned int CATVisContextFilterPath::GetViewMesh()         const
{
	return _value.GetViewMesh();
}

inline unsigned int CATVisContextFilterPath::IsViewEdgeOverload()  const
{
	return _value.IsViewEdgeOverload();
}

inline unsigned int CATVisContextFilterPath::GetViewEdge()         const
{
	return _value.GetViewEdge();
}

inline unsigned int CATVisContextFilterPath::IsViewLineOverload()  const
{
	return _value.IsViewLineOverload();
}

inline unsigned int CATVisContextFilterPath::GetViewLine()         const
{
	return _value.GetViewLine();
}

inline unsigned int CATVisContextFilterPath::IsViewAxisOverload()  const
{
	return _value.IsViewAxisOverload();
}

inline unsigned int CATVisContextFilterPath::GetViewAxis()         const
{
	return _value.GetViewAxis();
}

inline unsigned int CATVisContextFilterPath::IsViewPointOverload() const
{
	return _value.IsViewPointOverload();
}

inline unsigned int CATVisContextFilterPath::GetViewPoint()        const
{
	return _value.GetViewPoint();
}

inline unsigned int CATVisContextFilterPath::IsColorOverload() const
{
	return _value.IsColorOverLoad();
}

inline unsigned int CATVisContextFilterPath::GetColorRGBA()			const
{
	return _value.GetColorRGBA();
}

inline void CATVisContextFilterPath::GetColorRGB( 
								unsigned int& oRed, 
								unsigned int& oGreen, 
								unsigned int& oBlue)	const
{
	_value.GetColorRGB(oRed, oGreen, oBlue);
}

unsigned int CATVisContextFilterPath::IsTransparencyOverload() const
{
	return _value.IsTransparencyOverload();
}


inline unsigned int CATVisContextFilterPath::GetTransparency() const
{
	return _value.GetTransparency();
}

#endif 


