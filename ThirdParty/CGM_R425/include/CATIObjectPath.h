#ifndef CATIObjectPath_h
#define CATIObjectPath_h
/* COPYRIGHT DASSAULT SYSTEMES 1999 */

#include <IUnknown.h>

/**
 */
class CATIObjectPath : public IUnknown
{
public:
  
  /**
   */
  virtual HRESULT DescendantCount(unsigned int * oDescendants) const = 0;
  
  /**
   */
  virtual HRESULT DescendantItem(const unsigned int iDescendantPosition,
				 IUnknown ** oDescendant) const = 0;
  
  /**
   */
  virtual HRESULT SiblingCount(const unsigned int iDescendantPosition,
			       unsigned int * oSiblings) const = 0;
  
  /**
   */
  virtual HRESULT SiblingItem(const unsigned int iDescendantPosition,
			      const unsigned int iSiblingPosition,
			      IUnknown ** oSibling) const = 0;
  
  /**
   */
  virtual HRESULT GetSubPath(const IID * iIID,
			     CATIObjectPath ** oSubPath) const = 0;
  
  /**
   */
  virtual HRESULT AddObject(const unsigned int iDescendantPosition,
			    IUnknown * iObject) = 0;
  
  /**
   */
  virtual HRESULT AddSiblingObject(const unsigned int iDescendantPosition,
				   const unsigned int iSiblingPosition,
				   IUnknown * iObject) = 0;
};

/* 8D29A9C5-C23C-0000-0280-020F32000000 */
extern "C" const IID IID_CATIObjectPath;

#endif
