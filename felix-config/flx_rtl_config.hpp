#ifndef __FLX_RTL_CONFIG_H__
#define __FLX_RTL_CONFIG_H__

#define FLX_STATIC_LINK 1
#define FLX_MARMALADE 1
#define FLX_HAVE_VSNPRINTF 1
#define FLX_HAVE_BOOL 1
#define FLX_HAVE_LONGLONG 1
#define FLX_HAVE_LONGDOUBLE 1
#define FLX_HAVE_GNU 0
#define FLX_HAVE_GNU_X86 0
#define FLX_HAVE_GNU_X86_64 0
#define FLX_UNLIKELY(x) x
#define FLX_LIKELY(x) x
#define FLX_HAVE_CGOTO 0
#define FLX_USE_REGPARM3 0
#define FLX_HAVE_ASM_LABELS 0
#define FLX_HAVE_DLOPEN 0
#define FLX_MACOSX 0
#define FLX_LINUX 0
#define FLX_WIN32 0
#define FLX_WIN64 0
#define FLX_CYGWIN 0
#define FLX_POSIX 1
#define FLX_SOLARIS 0
#define FLX_HAVE_MSVC 1
#define FLX_HAVE_KQUEUE_DEMUXER 0
#define FLX_HAVE_POLL 0
#define FLX_HAVE_EPOLL 0
#define FLX_HAVE_EVTPORTS 0
#define FLX_HAVE_OPENMP 0
#include "setjmp.h"

#define FLX_SAVE_REGS \
  jmp_buf reg_save_on_stack; \
  setjmp (reg_save_on_stack)

//
#if FLX_HAVE_CGOTO && FLX_HAVE_ASM_LABELS
#define FLX_CGOTO 1
#else
#define FLX_CGOTO 0
#endif

#if FLX_WIN32 && !defined(_WIN32_WINNT)
#define _WIN32_WINNT 0x0600 // Require Windows NT5 (2K, XP, 2K3)
#endif

#if FLX_WIN32 && !defined(WINVER)
#define WINVER 0x0600 // Require Windows NT5 (2K, XP, 2K3)
#endif

#if FLX_WIN32
// vs windows.h just LOVES to include winsock version 1 headers by default.
// that's bad for everyone, so quit it.
#define _WINSOCKAPI_

// windows.h defines min/max macros, which can cause all sorts of confusion.
#ifndef NOMINMAX
#define NOMINMAX
#endif
#endif


#if !defined(FLX_STATIC_LINK) && FLX_WIN32
#define FLX_EXPORT __declspec(dllexport)
#define FLX_IMPORT __declspec(dllimport)
#else
#define FLX_EXPORT
#define FLX_IMPORT
#endif


#ifdef BUILD_RTL
#define RTL_EXTERN FLX_EXPORT
#else
#define RTL_EXTERN FLX_IMPORT
#endif

#if FLX_MACOSX && !FLX_HAVE_DLOPEN
#define FLX_MACOSX_NODLCOMPAT 1
#else
#define FLX_MACOSX_NODLCOMPAT 0
#endif

#if FLX_HAVE_GNU
#define FLX_ALWAYS_INLINE __attribute__ ((always_inline))
#define FLX_NOINLINE __attribute__ ((noinline))
#define FLX_CONST __attribute__ ((const))
#define FLX_PURE __attribute__ ((pure))
#define FLX_GXX_PARSER_HACK (void)0,
#define FLX_UNUSED __attribute__((unused))
#else
#define FLX_ALWAYS_INLINE
#define FLX_NOINLINE
#define FLX_CONST
#define FLX_PURE
#define FLX_GXX_PARSER_HACK
#define FLX_UNUSED
#endif

typedef unsigned FLX_RAWADDRESS;
#define FLX_MAX_ALIGN 8

// get variant index code and pointer from packed variant rep
#define FLX_VP(x) ((void*)((FLX_RAWADDRESS)(x) & ~(FLX_RAWADDRESS)0x03))
#define FLX_VI(x) ((int)((FLX_RAWADDRESS)(x) & (FLX_RAWADDRESS)0x03))

// make a packed variant rep from index code and pointer
#define FLX_VR(i,p) ((void*)((FLX_RAWADDRESS)(p)|(FLX_RAWADDRESS)(i)))


// get variant index code and pointer from nullptr variant rep
#define FLX_VNP(x) (x)
#define FLX_VNI(x) ((int)(x!=0))

// make a nullptr variant rep from index code and pointer
#define FLX_VNR(i,p) (p)


#endif
