#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([escu], [1.0], [dorif@sportloto.com])
AC_CONFIG_SRCDIR([src/pwd.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE(escu,1.0)
# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UID_T

# Checks for library functions.
AC_CHECK_FUNCS([getcwd strerror strstr])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
