#ifndef IVISSGATTRIBUTE_H
#define IVISSGATTRIBUTE_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "VisSceneGraph.h"

#include "VisDataType.h"
#include "VisAttributeID.h"
#include "VisErrorDefinition.h"


class ExportedByVisSceneGraph VisSGAttribute
{
public:

  /**
   * Destructor.
   */
  virtual ~VisSGAttribute();

  virtual HRESULT GetValue(const VisAttributeID iAttributeID, const VisDataType iType, void *oValue) const = 0;
  
  virtual HRESULT SetValue(const VisAttributeID iAttributeID, const VisDataType iType, void *iValue) = 0;

  
protected:

  /**
   * Builds an empty attribute.
   */
  VisSGAttribute();

private:

  VisSGAttribute(const VisSGAttribute&);
  VisSGAttribute & operator=(const VisSGAttribute&);

};

#endif
