#pragma once

#include "CATPolyVisuPlayRepBuilder.h"


class CATPolyVisuNavRepBuilder : public CATPolyVisuPlayRepBuilder
{

public:

  inline CATPolyVisuNavRepBuilder (CATSoftwareConfiguration* iSoftwareConfiguration = 0) :
    CATPolyVisuPlayRepBuilder (iSoftwareConfiguration) {}

  ~CATPolyVisuNavRepBuilder () {}

};


class CATPolyVisuNavRepBuilderObserver : public CATPolyVisuPlayRepBuilderObserver
{
};
