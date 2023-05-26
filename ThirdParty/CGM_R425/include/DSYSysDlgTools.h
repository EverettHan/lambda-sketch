//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 1996                                          *
//*===========================================================================*
//*                                                                           *
//*  CATHttpCookie                                                            *
//*                                                                           *
//*  Usage Notes:  Client Http V1.0                                           *
//*===========================================================================*
//*  Creation novembre 2016                                        sip        *
//*===========================================================================*
#ifndef DSYSYSDLGTOOLS_H
#define DSYSYSDLGTOOLS_H

#include "DSYString.h"
#include "JS0HTTP.h"   // ExportedByJS0HTTP


HRESULT ExportedByJS0HTTP GetCollabPassword(CATUnicodeString &RTCPwd);
HRESULT ExportedByJS0HTTP FindHtmlForAlias(const CATUnicodeString& iAppInstance, char **oUrl);


#endif //DSYSYSDLGTOOLS_H
