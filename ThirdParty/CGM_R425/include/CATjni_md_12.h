/**
* @quickreview <AVE> <05/02/22> R424AssessedForLinux
*/
//------------------------------------------------------------
//------------------------  aix_a   --------------------------
//------------------------------------------------------------
#ifdef _AIX_SOURCE

#ifndef _DS_PLATEFORME_64

/* 
 * @(#)src/contract/jvm/pfm/jni_md.h, xadev, xa122, 19991109 1.2.1.2
 * ===========================================================================
 * Licensed Materials - Property of IBM
 * IBM Java(tm)2 SDK, Standard Edition, v 1.2 
 *
 * (C) Copyright IBM Corp. 1999 All Rights Reserved.
 * Copyright 1996-1998 by Sun Microsystems Inc.,
 * ===========================================================================
 */

#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

#define JNIEXPORT_PROTOTYPE                                           /*ibm.54*/
#define JNIEXPORT
#define JNIIMPORT
#define JNICALL

#ifdef _LP64 /* 64-bit Solaris */
typedef int jint;
#else
typedef long jint;
#endif
typedef long long jlong;
typedef signed char jbyte;

#endif /* !_JAVASOFT_JNI_MD_H_ */

#else // _DS_PLATEFORME_64

#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

#include <sys/inttypes.h>             /*ibm@32560*/

#define JNIEXPORT_PROTOTYPE                                           /*ibm.54*/
#define JNIEXPORT
#define JNIIMPORT
#define JNICALL
#define XJNICALL                                                   /*ibm@9653*/

typedef int32_t jint;                 /*ibm@13822*/
typedef int64_t jlong;                /*ibm@13822*/
typedef signed char jbyte;

#endif /* !_JAVASOFT_JNI_MD_H_ */

#endif //  _DS_PLATEFORME_64

#endif // _AIX_SOURCE


//------------------------------------------------------------
//------------------------  hpux_a   --------------------------
//------------------------------------------------------------
#ifdef _HPUX_SOURCE

/*
 * @(#)jni_md.h	1.10 98/09/15
 *
 * Copyright 1996-1998 by Sun Microsystems, Inc.,
 * 901 San Antonio Road, Palo Alto, California, 94303, U.S.A.
 * All rights reserved.
 *
 * This software is the confidential and proprietary information
 * of Sun Microsystems, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Sun.
 */

#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

#define JNIEXPORT 
#define JNIIMPORT
#define JNICALL

#ifdef _LP64 /* 64-bit Solaris */
typedef int jint;
#else
typedef long jint;
#endif
typedef long long jlong;
typedef signed char jbyte;

#endif /* !_JAVASOFT_JNI_MD_H_ */

#endif // _HPUX_SOURCE


//------------------------------------------------------------
//------------------------  intel_a   --------------------------
//------------------------------------------------------------
#ifdef _WINDOWS_SOURCE

/*
 * @(#)jni_md.h	1.9 98/09/21
 *
 * Copyright 1996-1998 by Sun Microsystems, Inc.,
 * 901 San Antonio Road, Palo Alto, California, 94303, U.S.A.
 * All rights reserved.
 * 
 * This software is the confidential and proprietary information
 * of Sun Microsystems, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Sun.
 */

#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

#define JNIEXPORT __declspec(dllexport)
#define JNIIMPORT __declspec(dllimport)
#define JNICALL __stdcall

typedef long jint;
typedef __int64 jlong;
typedef signed char jbyte;

#endif /* !_JAVASOFT_JNI_MD_H_ */

#endif // _WINDOWS_SOURCE


//------------------------------------------------------------
//------------------------  irix_a   --------------------------
//------------------------------------------------------------
#ifdef _IRIX_SOURCE

/*
 * @(#)jni_md.h	1.10 98/09/15
 *
 * Copyright 1996-1998 by Sun Microsystems, Inc.,
 * 901 San Antonio Road, Palo Alto, California, 94303, U.S.A.
 * All rights reserved.
 *
 * This software is the confidential and proprietary information
 * of Sun Microsystems, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Sun.
 */

#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

#define JNIEXPORT 
#define JNIIMPORT
#define JNICALL

#ifdef _LP64 /* 64-bit Solaris */
typedef int jint;
#else
typedef long jint;
#endif
typedef long long jlong;
typedef signed char jbyte;

#endif /* !_JAVASOFT_JNI_MD_H_ */

#endif // _IRIX_SOURCE


//------------------------------------------------------------
//------------------------  solaris_a   --------------------------
//------------------------------------------------------------
#ifdef _SUNOS_SOURCE

/*
 * @(#)jni_md.h	1.10 98/09/15
 *
 * Copyright 1996-1998 by Sun Microsystems, Inc.,
 * 901 San Antonio Road, Palo Alto, California, 94303, U.S.A.
 * All rights reserved.
 *
 * This software is the confidential and proprietary information
 * of Sun Microsystems, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Sun.
 */

#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

#define JNIEXPORT 
#define JNIIMPORT
#define JNICALL

#ifdef _LP64 /* 64-bit Solaris */
typedef int jint;
#else
typedef long jint;
#endif
typedef long long jlong;
typedef signed char jbyte;

#endif /* !_JAVASOFT_JNI_MD_H_ */

#endif // _SUNOS_SOURCE


//------------------------------------------------------------
//------------------------  win_a   --------------------------
//------------------------------------------------------------
#ifdef _WIN98_SOURCE

/*
 * @(#)jni_md.h	1.9 98/09/21
 *
 * Copyright 1996-1998 by Sun Microsystems, Inc.,
 * 901 San Antonio Road, Palo Alto, California, 94303, U.S.A.
 * All rights reserved.
 * 
 * This software is the confidential and proprietary information
 * of Sun Microsystems, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Sun.
 */

#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

#define JNIEXPORT __declspec(dllexport)
#define JNIIMPORT __declspec(dllimport)
#define JNICALL __stdcall

typedef long jint;
typedef __int64 jlong;
typedef signed char jbyte;

#endif /* !_JAVASOFT_JNI_MD_H_ */

#endif // _WIN98_SOURCE


//------------------------------------------------------------
//------------------------  linux_a   --------------------------
//------------------------------------------------------------
#ifdef _LINUX_SOURCE

/*
 * @(#)jni_md.h	1.10 98/09/15
 *
 * Copyright 1996-1998 by Sun Microsystems, Inc.,
 * 901 San Antonio Road, Palo Alto, California, 94303, U.S.A.
 * All rights reserved.
 *
 * This software is the confidential and proprietary information
 * of Sun Microsystems, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Sun.
 */

#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

#define JNIEXPORT DSYExport
#define JNIIMPORT DSYImport
#define JNICALL

#include "DSYExport.h"

#ifdef _LP64 /* 64-bit Solaris */
typedef int jint;
#else
typedef long jint;
#endif
typedef long long jlong;
typedef signed char jbyte;

#endif /* !_JAVASOFT_JNI_MD_H_ */

#endif // _SUNOS_SOURCE

//------------------------------------------------------------
//------------------------  darwin   --------------------------
//------------------------------------------------------------
#ifdef _DARWIN_SOURCE

/*
 * @(#)jni_md.h	1.10 98/09/15
 *
 * Copyright 1996-1998 by Sun Microsystems, Inc.,
 * 901 San Antonio Road, Palo Alto, California, 94303, U.S.A.
 * All rights reserved.
 *
 * This software is the confidential and proprietary information
 * of Sun Microsystems, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Sun.
 */

#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

#define JNIEXPORT 
#define JNIIMPORT
#define JNICALL

#ifdef _LP64 /* 64-bit Solaris */
typedef int jint;
#else
typedef long jint;
#endif
typedef long long jlong;
typedef signed char jbyte;

#endif /* !_JAVASOFT_JNI_MD_H_ */

#endif // _SUNOS_SOURCE

