/*
                     Copyright (C) 1991,1995 by

                      MATRA DATAVISION, FRANCE

This software is furnished in accordance with the terms and conditions
of the contract and with the inclusion of the above copyright notice
This software or any other copy thereof may not be provided or otherwise
be made available to any other person. No title to an ownership of the
software is hereby transferred

At the termination of the contract, the software and all copies of this
software must be deleted

Facility : CAS-CADE V1.3A

*/
#ifndef	_Stream_WNT_H
#define _Stream_WNT_H

//#ifdef _DEBUG

//#undef _DEBUG	
//#include <istream.h>
//#include <iomanip.h>
//#include <fstream.h>
//#define _DEBUG

//#else
//#include <istream.h>
//#include <iomanip.h>
//#include <fstream.h>

//#endif

/** @c++ansi fbq 2004-08-06.16:54:56 [error C2039: 'nocreate' : is not a member of 'std::basic_ios<_Elem,_Traits>'] **/
#ifdef _CAT_ANSI_STREAMS
//static const int input= (ios::in);
#else
//static const int input= (ios::in) | (ios::nocreate);
#endif // _CAT_ANSI_STREAMS
//static const int output= (ios::out);
#endif


