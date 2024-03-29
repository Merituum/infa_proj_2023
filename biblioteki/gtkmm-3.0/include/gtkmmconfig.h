#ifndef _GTKMM_CONFIG_H
#define _GTKMM_CONFIG_H

#include <gdkmmconfig.h>

/* Defined when the -Dbuild-atkmm-api=true configure argument was given */
#define GTKMM_ATKMM_ENABLED 1

/* Define to omit deprecated API from gtkmm. */
/* #undef GTKMM_DISABLE_DEPRECATED */

/* Major version number of gtkmm. */
#define GTKMM_MAJOR_VERSION 3

/* Minor version number of gtkmm. */
#define GTKMM_MINOR_VERSION 24

/* Micro version number of gtkmm. */
#define GTKMM_MICRO_VERSION 8

/* Define when building gtkmm as a static library. */
/* #undef GTKMM_STATIC_LIB */

/* Enable DLL-specific stuff only when not building a static library  nor using gendef. */
#if !defined(__CYGWIN__) && defined(_WIN32) && \
    !defined(GTKMM_STATIC_LIB) && !defined(GTKMM_USE_GENDEF)
# define GTKMM_DLL 1
#endif

#ifdef GTKMM_DLL
# if defined(GTKMM_BUILD)
#  define GTKMM_API __declspec(dllexport)
# elif !defined (__GNUC__)
#  define GTKMM_API __declspec(dllimport)
# else /* don't dllimport classes/methods on GCC/MinGW */
#  define GTKMM_API
# endif
#else
/* Build a static library or a non-native Windows library or gendef is used. */
# define GTKMM_API
#endif /* GTKMM_DLL */

#endif /* !_GTKMM_CONFIG_H */
