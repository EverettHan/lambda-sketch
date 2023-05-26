/**
* @level Private
* @usage U1
*/
#ifndef __CATOmbLinkSet_H
#define __CATOmbLinkSet_H

class CATOmbLink;

class CATOmbLinkSet
{
public:
  virtual ~CATOmbLinkSet() = 0;

  virtual CATOmbLink * Next() = 0;

  virtual int Size() = 0;
};

#endif
