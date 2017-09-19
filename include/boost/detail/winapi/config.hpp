//  config.hpp  --------------------------------------------------------------//

//  Copyright 2013 Andrey Semashev
//  Copyright 2017 James E. King, III

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_CONFIG_HPP_INCLUDED_
#define BOOST_DETAIL_WINAPI_CONFIG_HPP_INCLUDED_

#include <boost/predef/platform.h>

// BOOST_WINAPI_IS_MINGW indicates that the target Windows SDK is provided by MinGW (http://mingw.org/).
// BOOST_WINAPI_IS_MINGW_W64 indicates that the target Windows SDK is provided by MinGW-w64 (http://mingw-w64.org).
#if BOOST_PLAT_MINGW
#if defined __MINGW64_VERSION_MAJOR
#define BOOST_WINAPI_IS_MINGW_W64
#else
#define BOOST_WINAPI_IS_MINGW
#endif
#endif

// These constants reflect _WIN32_WINNT_* macros from sdkddkver.h
// See also: http://msdn.microsoft.com/en-us/library/windows/desktop/aa383745%28v=vs.85%29.aspx#setting_winver_or__win32_winnt
#define BOOST_WINAPI_VERSION_NT4 0x0400
#define BOOST_WINAPI_VERSION_WIN2K 0x0500
#define BOOST_WINAPI_VERSION_WINXP 0x0501
#define BOOST_WINAPI_VERSION_WS03 0x0502
#define BOOST_WINAPI_VERSION_WIN6 0x0600
#define BOOST_WINAPI_VERSION_VISTA 0x0600
#define BOOST_WINAPI_VERSION_WS08 0x0600
#define BOOST_WINAPI_VERSION_LONGHORN 0x0600
#define BOOST_WINAPI_VERSION_WIN7 0x0601
#define BOOST_WINAPI_VERSION_WIN8 0x0602
#define BOOST_WINAPI_VERSION_WINBLUE 0x0603
#define BOOST_WINAPI_VERSION_WINTHRESHOLD 0x0A00
#define BOOST_WINAPI_VERSION_WIN10 0x0A00

// These constants reflect NTDDI_* macros from sdkddkver.h
#define BOOST_WINAPI_NTDDI_WIN2K 0x05000000
#define BOOST_WINAPI_NTDDI_WIN2KSP1 0x05000100
#define BOOST_WINAPI_NTDDI_WIN2KSP2 0x05000200
#define BOOST_WINAPI_NTDDI_WIN2KSP3 0x05000300
#define BOOST_WINAPI_NTDDI_WIN2KSP4 0x05000400

#define BOOST_WINAPI_NTDDI_WINXP 0x05010000
#define BOOST_WINAPI_NTDDI_WINXPSP1 0x05010100
#define BOOST_WINAPI_NTDDI_WINXPSP2 0x05010200
#define BOOST_WINAPI_NTDDI_WINXPSP3 0x05010300
#define BOOST_WINAPI_NTDDI_WINXPSP4 0x05010400

#define BOOST_WINAPI_NTDDI_WS03 0x05020000
#define BOOST_WINAPI_NTDDI_WS03SP1 0x05020100
#define BOOST_WINAPI_NTDDI_WS03SP2 0x05020200
#define BOOST_WINAPI_NTDDI_WS03SP3 0x05020300
#define BOOST_WINAPI_NTDDI_WS03SP4 0x05020400

#define BOOST_WINAPI_NTDDI_WIN6 0x06000000
#define BOOST_WINAPI_NTDDI_WIN6SP1 0x06000100
#define BOOST_WINAPI_NTDDI_WIN6SP2 0x06000200
#define BOOST_WINAPI_NTDDI_WIN6SP3 0x06000300
#define BOOST_WINAPI_NTDDI_WIN6SP4 0x06000400

#define BOOST_WINAPI_NTDDI_VISTA BOOST_WINAPI_NTDDI_WIN6
#define BOOST_WINAPI_NTDDI_VISTASP1 BOOST_WINAPI_NTDDI_WIN6SP1
#define BOOST_WINAPI_NTDDI_VISTASP2 BOOST_WINAPI_NTDDI_WIN6SP2
#define BOOST_WINAPI_NTDDI_VISTASP3 BOOST_WINAPI_NTDDI_WIN6SP3
#define BOOST_WINAPI_NTDDI_VISTASP4 BOOST_WINAPI_NTDDI_WIN6SP4

#define BOOST_WINAPI_NTDDI_LONGHORN  BOOST_WINAPI_NTDDI_VISTA

#define BOOST_WINAPI_NTDDI_WS08 BOOST_WINAPI_NTDDI_WIN6SP1
#define BOOST_WINAPI_NTDDI_WS08SP2 BOOST_WINAPI_NTDDI_WIN6SP2
#define BOOST_WINAPI_NTDDI_WS08SP3 BOOST_WINAPI_NTDDI_WIN6SP3
#define BOOST_WINAPI_NTDDI_WS08SP4 BOOST_WINAPI_NTDDI_WIN6SP4

#define BOOST_WINAPI_NTDDI_WIN7 0x06010000
#define BOOST_WINAPI_NTDDI_WIN7SP1 0x06010100 // Not defined in Windows SDK
#define BOOST_WINAPI_NTDDI_WIN8 0x06020000
#define BOOST_WINAPI_NTDDI_WINBLUE 0x06030000
#define BOOST_WINAPI_NTDDI_WINTHRESHOLD 0x0A000000
#define BOOST_WINAPI_NTDDI_WIN10 0x0A000000
#define BOOST_WINAPI_NTDDI_WIN10_TH2 0x0A000001
#define BOOST_WINAPI_NTDDI_WIN10_RS1 0x0A000002
#define BOOST_WINAPI_NTDDI_WIN10_RS2 0x0A000003

#define BOOST_DETAIL_WINAPI_MAKE_NTDDI_VERSION2(x) x##0000
#define BOOST_DETAIL_WINAPI_MAKE_NTDDI_VERSION(x) BOOST_DETAIL_WINAPI_MAKE_NTDDI_VERSION2(x)

#if !defined(BOOST_USE_WINAPI_VERSION)
#if defined(_WIN32_WINNT)
#define BOOST_USE_WINAPI_VERSION _WIN32_WINNT
#elif defined(WINVER)
#define BOOST_USE_WINAPI_VERSION WINVER
#else
// By default use Windows Vista API on compilers that support it and XP on the others
#if (defined(_MSC_VER) && _MSC_VER < 1500) || defined(BOOST_WINAPI_IS_MINGW)
#define BOOST_USE_WINAPI_VERSION BOOST_WINAPI_VERSION_WINXP
#else
#define BOOST_USE_WINAPI_VERSION BOOST_WINAPI_VERSION_WIN6
#endif
#endif
#endif

#if !defined(BOOST_USE_NTDDI_VERSION)
#if defined(NTDDI_VERSION)
#define BOOST_USE_NTDDI_VERSION NTDDI_VERSION
// Default to respective Windows version with the latest Service Pack
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WIN2K
#define BOOST_USE_NTDDI_VERSION BOOST_WINAPI_NTDDI_WIN2KSP4
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WINXP
#define BOOST_USE_NTDDI_VERSION BOOST_WINAPI_NTDDI_WINXPSP3
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WS03
#define BOOST_USE_NTDDI_VERSION BOOST_WINAPI_NTDDI_WS03SP2
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WIN6
#define BOOST_USE_NTDDI_VERSION BOOST_WINAPI_NTDDI_WIN6SP2
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WIN7
#define BOOST_USE_NTDDI_VERSION BOOST_WINAPI_NTDDI_WIN7SP1
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WIN10
#define BOOST_USE_NTDDI_VERSION BOOST_WINAPI_NTDDI_WIN10_RS2
#else
#define BOOST_USE_NTDDI_VERSION BOOST_DETAIL_WINAPI_MAKE_NTDDI_VERSION(BOOST_USE_WINAPI_VERSION)
#endif
#endif

#if !defined(BOOST_USE_WINAPI_FAMILY)
#if defined(WINAPI_FAMILY)
#define BOOST_USE_WINAPI_FAMILY WINAPI_FAMILY
#else if defined(WINAPI_FAMILY_DESKTOP_APP)
// If none is specified, default to a desktop application which is the most
// backwards compatible to previos ways of doing things, if families are even
// defined.
#define BOOST_USE_WINAPI_FAMILY WINAPI_FAMILY_DESKTOP_APP
#endif
#endif

//
// UWP Support
//
// On platforms without windows family partition support it is assumed one 
// has all APIs and access is controlled by _WIN32_WINNT or similar mechanisms.
//
// Leveraging Boost.Predef here
//

#define BOOST_WINAPI_PARTITION_APP           (BOOST_PLAT_WINDOWS_DESKTOP || BOOST_PLAT_WINDOWS_STORE || BOOST_WINAPI_PARTITION_PHONE)
#define BOOST_WINAPI_PARTITION_PC            (BOOST_PLAT_WINDOWS_STORE)
#define BOOST_WINAPI_PARTITION_PHONE         (BOOST_PLAT_WINDOWS_PHONE)
#define BOOST_WINAPI_PARTITION_SYSTEM        (BOOST_PLAT_WINDOWS_SYSTEM)
#define BOOST_WINAPI_PARTITION_SERVER        (BOOST_PLAT_WINDOWS_SERVER)
#define BOOST_WINAPI_PARTITION_DESKTOP       (BOOST_PLAT_WINDOWS_DESKTOP)

//
// Windows 8.x SDK defines some items in the DESKTOP partition and then Windows SDK 10.0 defines 
// the same items to be in APP or SYSTEM partitions, and APP expands to DESKTOP or PC or PHONE.  
// The definition of BOOST_WINAPI_PARTITION_APP_SYSTEM provides a universal way to get this 
// right as it is seen in a number of places in the SDK.
//
// 10011 is in ntverp.h of the Windows 10 Platform SDK
//

#define BOOST_WINAPI_PARTITION_APP_SYSTEM ( \
        ((BOOST_PLAT_WINDOWS_SDK_VERSION >= BOOST_VERSION_NUMBER(0, 0, 10011)) && (BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM)) || \
        ((BOOST_PLAT_WINDOWS_SDK_VERSION < BOOST_VERSION_NUMBER(0, 0, 10011)) && BOOST_WINAPI_PARTITION_DESKTOP) \
    )

#if defined(BOOST_USE_WINDOWS_H) || defined(BOOST_WINAPI_DEFINE_VERSION_MACROS)
// We have to define the version macros so that windows.h provides the necessary symbols
#if !defined(_WIN32_WINNT)
#define _WIN32_WINNT BOOST_USE_WINAPI_VERSION
#endif
#if !defined(WINVER)
#define WINVER BOOST_USE_WINAPI_VERSION
#endif
#if !defined(NTDDI_VERSION)
#define NTDDI_VERSION BOOST_USE_NTDDI_VERSION
#endif
#if !defined(WINAPI_FAMILY) && defined(BOOST_USE_WINAPI_FAMILY)
#define WINAPI_FAMILY BOOST_USE_WINAPI_FAMILY
#endif
#endif

#include <boost/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#endif // BOOST_DETAIL_WINAPI_CONFIG_HPP_INCLUDED_
