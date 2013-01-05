/*
Copyright Redshift Software, Inc. 2008-2012
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef BOOST_PREDEF_COMPILER_MINGW_H
#define BOOST_PREDEF_COMPILER_MINGW_H

#include <boost/predef/version_number.h>
#include <boost/predef/make.h>

/*`
[heading `BOOST_COMP_MINGW`]

[@http://en.wikipedia.org/wiki/MinGW MinGW] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`____`] [__predef_detection__]]

    [[`____`] [V.R.P]]
    ]
 */

#define BOOST_COMP_MINGW BOOST_VERSION_NUMBER(0,0,0)

#if defined(__MINGW32__) || defined(__MINGW64__)
#   include <_mingw.h>
#   undef BOOST_COMP_MINGW
#   if defined(__MINGW64_VERSION_MAJOR) && defined(__MINGW64_VERSION_MINOR)
#       define BOOST_COMP_MINGW \
            BOOST_VERSION_NUMBER(__MINGW64_VERSION_MAJOR,__MINGW64_VERSION_MINOR,0)
#   elif defined(__MINGW32_VERSION_MAJOR) && defined(__MINGW32_VERSION_MINOR)
#       define BOOST_COMP_MINGW \
            BOOST_VERSION_NUMBER(__MINGW32_MAJOR_VERSION,__MINGW32_MINOR_VERSION,0)
#   else
#       define BOOST_COMP_MINGW BOOST_VERSION_NUMBER(0,0,1)
#   endif
#endif

#define BOOST_COMP_MINGW_NAME "MinGW"

#include <boost/predef/detail/test.h>
BOOST_PREDEF_DECLARE_TEST(BOOST_COMP_MINGW,BOOST_COMP_MINGW_NAME)


#endif
