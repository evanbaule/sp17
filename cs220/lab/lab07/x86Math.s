   1              		.file	"x86Math.c"
   2              	# GNU C (Debian 4.9.2-10) version 4.9.2 (x86_64-linux-gnu)
   3              	#	compiled by GNU C version 4.9.2, GMP version 6.0.0, MPFR version 3.1.2-p3, MPC version 1.0.2
   4              	# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   5              	# options passed:  -imultiarch x86_64-linux-gnu x86Math.c -mtune=generic
   6              	# -march=x86-64 -g -O1 -Wall -fverbose-asm
   7              	# options enabled:  -faggressive-loop-optimizations
   8              	# -fasynchronous-unwind-tables -fauto-inc-dec -fbranch-count-reg
   9              	# -fcombine-stack-adjustments -fcommon -fcompare-elim -fcprop-registers
  10              	# -fdefer-pop -fdelete-null-pointer-checks -fdwarf2-cfi-asm
  11              	# -fearly-inlining -feliminate-unused-debug-types -fforward-propagate
  12              	# -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique
  13              	# -fguess-branch-probability -fident -fif-conversion -fif-conversion2
  14              	# -finline -finline-atomics -finline-functions-called-once -fipa-profile
  15              	# -fipa-pure-const -fipa-reference -fira-hoist-pressure
  16              	# -fira-share-save-slots -fira-share-spill-slots -fivopts
  17              	# -fkeep-static-consts -fleading-underscore -fmath-errno -fmerge-constants
  18              	# -fmerge-debug-strings -fmove-loop-invariants -fomit-frame-pointer
  19              	# -fpeephole -fprefetch-loop-arrays -freg-struct-return
  20              	# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
  21              	# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
  22              	# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
  23              	# -fsched-stalled-insns-dep -fshow-column -fshrink-wrap -fsigned-zeros
  24              	# -fsplit-ivs-in-unroller -fsplit-wide-types -fstrict-volatile-bitfields
  25              	# -fsync-libcalls -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp
  26              	# -ftree-ccp -ftree-ch -ftree-coalesce-vars -ftree-copy-prop
  27              	# -ftree-copyrename -ftree-cselim -ftree-dce -ftree-dominator-opts
  28              	# -ftree-dse -ftree-forwprop -ftree-fre -ftree-loop-if-convert
  29              	# -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
  30              	# -ftree-parallelize-loops= -ftree-phiprop -ftree-pta -ftree-reassoc
  31              	# -ftree-scev-cprop -ftree-sink -ftree-slsr -ftree-sra -ftree-ter
  32              	# -funit-at-a-time -funwind-tables -fvar-tracking
  33              	# -fvar-tracking-assignments -fverbose-asm -fzero-initialized-in-bss
  34              	# -m128bit-long-double -m64 -m80387 -malign-stringops
  35              	# -mavx256-split-unaligned-load -mavx256-split-unaligned-store
  36              	# -mfancy-math-387 -mfp-ret-in-387 -mfxsr -mglibc -mieee-fp
  37              	# -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone -msse -msse2
  38              	# -mtls-direct-seg-refs
  39              	
  40              		.text
  41              	.Ltext0:
  42              		.section	.rodata.str1.1,"aMS",@progbits,1
  43              	.LC0:
  44 0000 496E766F 		.string	"Invoke as %s <number>\n"
  44      6B652061 
  44      73202573 
  44      203C6E75 
  44      6D626572 
  45              		.section	.rodata.str1.8,"aMS",@progbits,1
  46              		.align 8
  47              	.LC1:
  48 0000 783D2564 		.string	"x=%d, x squared - 4x + 4 =%d divided by x-2=%d\n"
  48      2C207820 
  48      73717561 
  48      72656420 
  48      2D203478 
  49              		.text
  50              		.globl	main
  52              	main:
  53              	.LFB21:
  54              		.file 1 "x86Math.c"
   1:x86Math.c     **** #include <stdio.h>
   2:x86Math.c     **** #include <stdlib.h>
   3:x86Math.c     **** 
   4:x86Math.c     **** int add(int x, int y);
   5:x86Math.c     **** int mult(int x, int y);
   6:x86Math.c     **** int subtract(int x, int y);
   7:x86Math.c     **** int divide(int x, int y);
   8:x86Math.c     **** 
   9:x86Math.c     **** int main(int argc, char **argv) {
  55              		.loc 1 9 0
  56              		.cfi_startproc
  57              	.LVL0:
  58 0000 4883EC08 		subq	$8, %rsp	#,
  59              		.cfi_def_cfa_offset 16
  10:x86Math.c     **** 	if (argc < 2) {
  60              		.loc 1 10 0
  61 0004 83FF01   		cmpl	$1, %edi	#, argc
  62 0007 7F19     		jg	.L2	#,
  11:x86Math.c     **** 		printf("Invoke as %s <number>\n",argv[0]);
  63              		.loc 1 11 0
  64 0009 488B36   		movq	(%rsi), %rsi	# *argv_5(D),
  65              	.LVL1:
  66 000c BF000000 		movl	$.LC0, %edi	#,
  66      00
  67              	.LVL2:
  68 0011 B8000000 		movl	$0, %eax	#,
  68      00
  69 0016 E8000000 		call	printf	#
  69      00
  70              	.LVL3:
  12:x86Math.c     **** 		return 1;
  71              		.loc 1 12 0
  72 001b B8010000 		movl	$1, %eax	#, D.2898
  72      00
  73 0020 EB47     		jmp	.L3	#
  74              	.LVL4:
  75              	.L2:
  76              	.LBB18:
  77              	.LBB19:
  78              		.file 2 "/usr/include/stdlib.h"
   1:/usr/include/stdlib.h **** /* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   2:/usr/include/stdlib.h ****    This file is part of the GNU C Library.
   3:/usr/include/stdlib.h **** 
   4:/usr/include/stdlib.h ****    The GNU C Library is free software; you can redistribute it and/or
   5:/usr/include/stdlib.h ****    modify it under the terms of the GNU Lesser General Public
   6:/usr/include/stdlib.h ****    License as published by the Free Software Foundation; either
   7:/usr/include/stdlib.h ****    version 2.1 of the License, or (at your option) any later version.
   8:/usr/include/stdlib.h **** 
   9:/usr/include/stdlib.h ****    The GNU C Library is distributed in the hope that it will be useful,
  10:/usr/include/stdlib.h ****    but WITHOUT ANY WARRANTY; without even the implied warranty of
  11:/usr/include/stdlib.h ****    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  12:/usr/include/stdlib.h ****    Lesser General Public License for more details.
  13:/usr/include/stdlib.h **** 
  14:/usr/include/stdlib.h ****    You should have received a copy of the GNU Lesser General Public
  15:/usr/include/stdlib.h ****    License along with the GNU C Library; if not, see
  16:/usr/include/stdlib.h ****    <http://www.gnu.org/licenses/>.  */
  17:/usr/include/stdlib.h **** 
  18:/usr/include/stdlib.h **** /*
  19:/usr/include/stdlib.h ****  *	ISO C99 Standard: 7.20 General utilities	<stdlib.h>
  20:/usr/include/stdlib.h ****  */
  21:/usr/include/stdlib.h **** 
  22:/usr/include/stdlib.h **** #ifndef	_STDLIB_H
  23:/usr/include/stdlib.h **** 
  24:/usr/include/stdlib.h **** #include <features.h>
  25:/usr/include/stdlib.h **** 
  26:/usr/include/stdlib.h **** /* Get size_t, wchar_t and NULL from <stddef.h>.  */
  27:/usr/include/stdlib.h **** #define		__need_size_t
  28:/usr/include/stdlib.h **** #ifndef __need_malloc_and_calloc
  29:/usr/include/stdlib.h **** # define	__need_wchar_t
  30:/usr/include/stdlib.h **** # define	__need_NULL
  31:/usr/include/stdlib.h **** #endif
  32:/usr/include/stdlib.h **** #include <stddef.h>
  33:/usr/include/stdlib.h **** 
  34:/usr/include/stdlib.h **** __BEGIN_DECLS
  35:/usr/include/stdlib.h **** 
  36:/usr/include/stdlib.h **** #ifndef __need_malloc_and_calloc
  37:/usr/include/stdlib.h **** #define	_STDLIB_H	1
  38:/usr/include/stdlib.h **** 
  39:/usr/include/stdlib.h **** #if (defined __USE_XOPEN || defined __USE_XOPEN2K8) && !defined _SYS_WAIT_H
  40:/usr/include/stdlib.h **** /* XPG requires a few symbols from <sys/wait.h> being defined.  */
  41:/usr/include/stdlib.h **** # include <bits/waitflags.h>
  42:/usr/include/stdlib.h **** # include <bits/waitstatus.h>
  43:/usr/include/stdlib.h **** 
  44:/usr/include/stdlib.h **** # ifdef __USE_BSD
  45:/usr/include/stdlib.h **** 
  46:/usr/include/stdlib.h **** /* Lots of hair to allow traditional BSD use of `union wait'
  47:/usr/include/stdlib.h ****    as well as POSIX.1 use of `int' for the status word.  */
  48:/usr/include/stdlib.h **** 
  49:/usr/include/stdlib.h **** #  if defined __GNUC__ && !defined __cplusplus
  50:/usr/include/stdlib.h **** #   define __WAIT_INT(status) \
  51:/usr/include/stdlib.h ****   (__extension__ (((union { __typeof(status) __in; int __i; }) \
  52:/usr/include/stdlib.h **** 		   { .__in = (status) }).__i))
  53:/usr/include/stdlib.h **** #  else
  54:/usr/include/stdlib.h **** #   define __WAIT_INT(status)	(*(int *) &(status))
  55:/usr/include/stdlib.h **** #  endif
  56:/usr/include/stdlib.h **** 
  57:/usr/include/stdlib.h **** /* This is the type of the argument to `wait'.  The funky union
  58:/usr/include/stdlib.h ****    causes redeclarations with either `int *' or `union wait *' to be
  59:/usr/include/stdlib.h ****    allowed without complaint.  __WAIT_STATUS_DEFN is the type used in
  60:/usr/include/stdlib.h ****    the actual function definitions.  */
  61:/usr/include/stdlib.h **** 
  62:/usr/include/stdlib.h **** #  if !defined __GNUC__ || __GNUC__ < 2 || defined __cplusplus
  63:/usr/include/stdlib.h **** #   define __WAIT_STATUS	void *
  64:/usr/include/stdlib.h **** #   define __WAIT_STATUS_DEFN	void *
  65:/usr/include/stdlib.h **** #  else
  66:/usr/include/stdlib.h **** /* This works in GCC 2.6.1 and later.  */
  67:/usr/include/stdlib.h **** typedef union
  68:/usr/include/stdlib.h ****   {
  69:/usr/include/stdlib.h ****     union wait *__uptr;
  70:/usr/include/stdlib.h ****     int *__iptr;
  71:/usr/include/stdlib.h ****   } __WAIT_STATUS __attribute__ ((__transparent_union__));
  72:/usr/include/stdlib.h **** #   define __WAIT_STATUS_DEFN	int *
  73:/usr/include/stdlib.h **** #  endif
  74:/usr/include/stdlib.h **** 
  75:/usr/include/stdlib.h **** # else /* Don't use BSD.  */
  76:/usr/include/stdlib.h **** 
  77:/usr/include/stdlib.h **** #  define __WAIT_INT(status)	(status)
  78:/usr/include/stdlib.h **** #  define __WAIT_STATUS		int *
  79:/usr/include/stdlib.h **** #  define __WAIT_STATUS_DEFN	int *
  80:/usr/include/stdlib.h **** 
  81:/usr/include/stdlib.h **** # endif /* Use BSD.  */
  82:/usr/include/stdlib.h **** 
  83:/usr/include/stdlib.h **** /* Define the macros <sys/wait.h> also would define this way.  */
  84:/usr/include/stdlib.h **** # define WEXITSTATUS(status)	__WEXITSTATUS (__WAIT_INT (status))
  85:/usr/include/stdlib.h **** # define WTERMSIG(status)	__WTERMSIG (__WAIT_INT (status))
  86:/usr/include/stdlib.h **** # define WSTOPSIG(status)	__WSTOPSIG (__WAIT_INT (status))
  87:/usr/include/stdlib.h **** # define WIFEXITED(status)	__WIFEXITED (__WAIT_INT (status))
  88:/usr/include/stdlib.h **** # define WIFSIGNALED(status)	__WIFSIGNALED (__WAIT_INT (status))
  89:/usr/include/stdlib.h **** # define WIFSTOPPED(status)	__WIFSTOPPED (__WAIT_INT (status))
  90:/usr/include/stdlib.h **** # ifdef __WIFCONTINUED
  91:/usr/include/stdlib.h **** #  define WIFCONTINUED(status)	__WIFCONTINUED (__WAIT_INT (status))
  92:/usr/include/stdlib.h **** # endif
  93:/usr/include/stdlib.h **** #endif	/* X/Open or XPG7 and <sys/wait.h> not included.  */
  94:/usr/include/stdlib.h **** 
  95:/usr/include/stdlib.h **** __BEGIN_NAMESPACE_STD
  96:/usr/include/stdlib.h **** /* Returned by `div'.  */
  97:/usr/include/stdlib.h **** typedef struct
  98:/usr/include/stdlib.h ****   {
  99:/usr/include/stdlib.h ****     int quot;			/* Quotient.  */
 100:/usr/include/stdlib.h ****     int rem;			/* Remainder.  */
 101:/usr/include/stdlib.h ****   } div_t;
 102:/usr/include/stdlib.h **** 
 103:/usr/include/stdlib.h **** /* Returned by `ldiv'.  */
 104:/usr/include/stdlib.h **** #ifndef __ldiv_t_defined
 105:/usr/include/stdlib.h **** typedef struct
 106:/usr/include/stdlib.h ****   {
 107:/usr/include/stdlib.h ****     long int quot;		/* Quotient.  */
 108:/usr/include/stdlib.h ****     long int rem;		/* Remainder.  */
 109:/usr/include/stdlib.h ****   } ldiv_t;
 110:/usr/include/stdlib.h **** # define __ldiv_t_defined	1
 111:/usr/include/stdlib.h **** #endif
 112:/usr/include/stdlib.h **** __END_NAMESPACE_STD
 113:/usr/include/stdlib.h **** 
 114:/usr/include/stdlib.h **** #if defined __USE_ISOC99 && !defined __lldiv_t_defined
 115:/usr/include/stdlib.h **** __BEGIN_NAMESPACE_C99
 116:/usr/include/stdlib.h **** /* Returned by `lldiv'.  */
 117:/usr/include/stdlib.h **** __extension__ typedef struct
 118:/usr/include/stdlib.h ****   {
 119:/usr/include/stdlib.h ****     long long int quot;		/* Quotient.  */
 120:/usr/include/stdlib.h ****     long long int rem;		/* Remainder.  */
 121:/usr/include/stdlib.h ****   } lldiv_t;
 122:/usr/include/stdlib.h **** # define __lldiv_t_defined	1
 123:/usr/include/stdlib.h **** __END_NAMESPACE_C99
 124:/usr/include/stdlib.h **** #endif
 125:/usr/include/stdlib.h **** 
 126:/usr/include/stdlib.h **** 
 127:/usr/include/stdlib.h **** /* The largest number rand will return (same as INT_MAX).  */
 128:/usr/include/stdlib.h **** #define	RAND_MAX	2147483647
 129:/usr/include/stdlib.h **** 
 130:/usr/include/stdlib.h **** 
 131:/usr/include/stdlib.h **** /* We define these the same for all machines.
 132:/usr/include/stdlib.h ****    Changes from this to the outside world should be done in `_exit'.  */
 133:/usr/include/stdlib.h **** #define	EXIT_FAILURE	1	/* Failing exit status.  */
 134:/usr/include/stdlib.h **** #define	EXIT_SUCCESS	0	/* Successful exit status.  */
 135:/usr/include/stdlib.h **** 
 136:/usr/include/stdlib.h **** 
 137:/usr/include/stdlib.h **** /* Maximum length of a multibyte character in the current locale.  */
 138:/usr/include/stdlib.h **** #define	MB_CUR_MAX	(__ctype_get_mb_cur_max ())
 139:/usr/include/stdlib.h **** extern size_t __ctype_get_mb_cur_max (void) __THROW __wur;
 140:/usr/include/stdlib.h **** 
 141:/usr/include/stdlib.h **** 
 142:/usr/include/stdlib.h **** __BEGIN_NAMESPACE_STD
 143:/usr/include/stdlib.h **** /* Convert a string to a floating-point number.  */
 144:/usr/include/stdlib.h **** extern double atof (const char *__nptr)
 145:/usr/include/stdlib.h ****      __THROW __attribute_pure__ __nonnull ((1)) __wur;
 146:/usr/include/stdlib.h **** /* Convert a string to an integer.  */
 147:/usr/include/stdlib.h **** extern int atoi (const char *__nptr)
 148:/usr/include/stdlib.h ****      __THROW __attribute_pure__ __nonnull ((1)) __wur;
 149:/usr/include/stdlib.h **** /* Convert a string to a long integer.  */
 150:/usr/include/stdlib.h **** extern long int atol (const char *__nptr)
 151:/usr/include/stdlib.h ****      __THROW __attribute_pure__ __nonnull ((1)) __wur;
 152:/usr/include/stdlib.h **** __END_NAMESPACE_STD
 153:/usr/include/stdlib.h **** 
 154:/usr/include/stdlib.h **** #if defined __USE_ISOC99 || defined __USE_MISC
 155:/usr/include/stdlib.h **** __BEGIN_NAMESPACE_C99
 156:/usr/include/stdlib.h **** /* Convert a string to a long long integer.  */
 157:/usr/include/stdlib.h **** __extension__ extern long long int atoll (const char *__nptr)
 158:/usr/include/stdlib.h ****      __THROW __attribute_pure__ __nonnull ((1)) __wur;
 159:/usr/include/stdlib.h **** __END_NAMESPACE_C99
 160:/usr/include/stdlib.h **** #endif
 161:/usr/include/stdlib.h **** 
 162:/usr/include/stdlib.h **** __BEGIN_NAMESPACE_STD
 163:/usr/include/stdlib.h **** /* Convert a string to a floating-point number.  */
 164:/usr/include/stdlib.h **** extern double strtod (const char *__restrict __nptr,
 165:/usr/include/stdlib.h **** 		      char **__restrict __endptr)
 166:/usr/include/stdlib.h ****      __THROW __nonnull ((1));
 167:/usr/include/stdlib.h **** __END_NAMESPACE_STD
 168:/usr/include/stdlib.h **** 
 169:/usr/include/stdlib.h **** #ifdef	__USE_ISOC99
 170:/usr/include/stdlib.h **** __BEGIN_NAMESPACE_C99
 171:/usr/include/stdlib.h **** /* Likewise for `float' and `long double' sizes of floating-point numbers.  */
 172:/usr/include/stdlib.h **** extern float strtof (const char *__restrict __nptr,
 173:/usr/include/stdlib.h **** 		     char **__restrict __endptr) __THROW __nonnull ((1));
 174:/usr/include/stdlib.h **** 
 175:/usr/include/stdlib.h **** extern long double strtold (const char *__restrict __nptr,
 176:/usr/include/stdlib.h **** 			    char **__restrict __endptr)
 177:/usr/include/stdlib.h ****      __THROW __nonnull ((1));
 178:/usr/include/stdlib.h **** __END_NAMESPACE_C99
 179:/usr/include/stdlib.h **** #endif
 180:/usr/include/stdlib.h **** 
 181:/usr/include/stdlib.h **** __BEGIN_NAMESPACE_STD
 182:/usr/include/stdlib.h **** /* Convert a string to a long integer.  */
 183:/usr/include/stdlib.h **** extern long int strtol (const char *__restrict __nptr,
 184:/usr/include/stdlib.h **** 			char **__restrict __endptr, int __base)
 185:/usr/include/stdlib.h ****      __THROW __nonnull ((1));
 186:/usr/include/stdlib.h **** /* Convert a string to an unsigned long integer.  */
 187:/usr/include/stdlib.h **** extern unsigned long int strtoul (const char *__restrict __nptr,
 188:/usr/include/stdlib.h **** 				  char **__restrict __endptr, int __base)
 189:/usr/include/stdlib.h ****      __THROW __nonnull ((1));
 190:/usr/include/stdlib.h **** __END_NAMESPACE_STD
 191:/usr/include/stdlib.h **** 
 192:/usr/include/stdlib.h **** #ifdef __USE_BSD
 193:/usr/include/stdlib.h **** /* Convert a string to a quadword integer.  */
 194:/usr/include/stdlib.h **** __extension__
 195:/usr/include/stdlib.h **** extern long long int strtoq (const char *__restrict __nptr,
 196:/usr/include/stdlib.h **** 			     char **__restrict __endptr, int __base)
 197:/usr/include/stdlib.h ****      __THROW __nonnull ((1));
 198:/usr/include/stdlib.h **** /* Convert a string to an unsigned quadword integer.  */
 199:/usr/include/stdlib.h **** __extension__
 200:/usr/include/stdlib.h **** extern unsigned long long int strtouq (const char *__restrict __nptr,
 201:/usr/include/stdlib.h **** 				       char **__restrict __endptr, int __base)
 202:/usr/include/stdlib.h ****      __THROW __nonnull ((1));
 203:/usr/include/stdlib.h **** #endif /* Use BSD.  */
 204:/usr/include/stdlib.h **** 
 205:/usr/include/stdlib.h **** #if defined __USE_ISOC99 || defined __USE_MISC
 206:/usr/include/stdlib.h **** __BEGIN_NAMESPACE_C99
 207:/usr/include/stdlib.h **** /* Convert a string to a quadword integer.  */
 208:/usr/include/stdlib.h **** __extension__
 209:/usr/include/stdlib.h **** extern long long int strtoll (const char *__restrict __nptr,
 210:/usr/include/stdlib.h **** 			      char **__restrict __endptr, int __base)
 211:/usr/include/stdlib.h ****      __THROW __nonnull ((1));
 212:/usr/include/stdlib.h **** /* Convert a string to an unsigned quadword integer.  */
 213:/usr/include/stdlib.h **** __extension__
 214:/usr/include/stdlib.h **** extern unsigned long long int strtoull (const char *__restrict __nptr,
 215:/usr/include/stdlib.h **** 					char **__restrict __endptr, int __base)
 216:/usr/include/stdlib.h ****      __THROW __nonnull ((1));
 217:/usr/include/stdlib.h **** __END_NAMESPACE_C99
 218:/usr/include/stdlib.h **** #endif /* ISO C99 or use MISC.  */
 219:/usr/include/stdlib.h **** 
 220:/usr/include/stdlib.h **** 
 221:/usr/include/stdlib.h **** #ifdef __USE_GNU
 222:/usr/include/stdlib.h **** /* The concept of one static locale per category is not very well
 223:/usr/include/stdlib.h ****    thought out.  Many applications will need to process its data using
 224:/usr/include/stdlib.h ****    information from several different locales.  Another problem is
 225:/usr/include/stdlib.h ****    the implementation of the internationalization handling in the
 226:/usr/include/stdlib.h ****    ISO C++ standard library.  To support this another set of
 227:/usr/include/stdlib.h ****    the functions using locale data exist which take an additional
 228:/usr/include/stdlib.h ****    argument.
 229:/usr/include/stdlib.h **** 
 230:/usr/include/stdlib.h ****    Attention: even though several *_l interfaces are part of POSIX:2008,
 231:/usr/include/stdlib.h ****    these are not.  */
 232:/usr/include/stdlib.h **** 
 233:/usr/include/stdlib.h **** /* Structure for reentrant locale using functions.  This is an
 234:/usr/include/stdlib.h ****    (almost) opaque type for the user level programs.  */
 235:/usr/include/stdlib.h **** # include <xlocale.h>
 236:/usr/include/stdlib.h **** 
 237:/usr/include/stdlib.h **** /* Special versions of the functions above which take the locale to
 238:/usr/include/stdlib.h ****    use as an additional parameter.  */
 239:/usr/include/stdlib.h **** extern long int strtol_l (const char *__restrict __nptr,
 240:/usr/include/stdlib.h **** 			  char **__restrict __endptr, int __base,
 241:/usr/include/stdlib.h **** 			  __locale_t __loc) __THROW __nonnull ((1, 4));
 242:/usr/include/stdlib.h **** 
 243:/usr/include/stdlib.h **** extern unsigned long int strtoul_l (const char *__restrict __nptr,
 244:/usr/include/stdlib.h **** 				    char **__restrict __endptr,
 245:/usr/include/stdlib.h **** 				    int __base, __locale_t __loc)
 246:/usr/include/stdlib.h ****      __THROW __nonnull ((1, 4));
 247:/usr/include/stdlib.h **** 
 248:/usr/include/stdlib.h **** __extension__
 249:/usr/include/stdlib.h **** extern long long int strtoll_l (const char *__restrict __nptr,
 250:/usr/include/stdlib.h **** 				char **__restrict __endptr, int __base,
 251:/usr/include/stdlib.h **** 				__locale_t __loc)
 252:/usr/include/stdlib.h ****      __THROW __nonnull ((1, 4));
 253:/usr/include/stdlib.h **** 
 254:/usr/include/stdlib.h **** __extension__
 255:/usr/include/stdlib.h **** extern unsigned long long int strtoull_l (const char *__restrict __nptr,
 256:/usr/include/stdlib.h **** 					  char **__restrict __endptr,
 257:/usr/include/stdlib.h **** 					  int __base, __locale_t __loc)
 258:/usr/include/stdlib.h ****      __THROW __nonnull ((1, 4));
 259:/usr/include/stdlib.h **** 
 260:/usr/include/stdlib.h **** extern double strtod_l (const char *__restrict __nptr,
 261:/usr/include/stdlib.h **** 			char **__restrict __endptr, __locale_t __loc)
 262:/usr/include/stdlib.h ****      __THROW __nonnull ((1, 3));
 263:/usr/include/stdlib.h **** 
 264:/usr/include/stdlib.h **** extern float strtof_l (const char *__restrict __nptr,
 265:/usr/include/stdlib.h **** 		       char **__restrict __endptr, __locale_t __loc)
 266:/usr/include/stdlib.h ****      __THROW __nonnull ((1, 3));
 267:/usr/include/stdlib.h **** 
 268:/usr/include/stdlib.h **** extern long double strtold_l (const char *__restrict __nptr,
 269:/usr/include/stdlib.h **** 			      char **__restrict __endptr,
 270:/usr/include/stdlib.h **** 			      __locale_t __loc)
 271:/usr/include/stdlib.h ****      __THROW __nonnull ((1, 3));
 272:/usr/include/stdlib.h **** #endif /* GNU */
 273:/usr/include/stdlib.h **** 
 274:/usr/include/stdlib.h **** 
 275:/usr/include/stdlib.h **** #ifdef __USE_EXTERN_INLINES
 276:/usr/include/stdlib.h **** __BEGIN_NAMESPACE_STD
 277:/usr/include/stdlib.h **** __extern_inline int
 278:/usr/include/stdlib.h **** __NTH (atoi (const char *__nptr))
 279:/usr/include/stdlib.h **** {
 280:/usr/include/stdlib.h ****   return (int) strtol (__nptr, (char **) NULL, 10);
  79              		.loc 2 280 0
  80 0022 488B7E08 		movq	8(%rsi), %rdi	# MEM[(char * *)argv_5(D) + 8B], MEM[(char * *)argv_5(D) + 8B]
  81              	.LVL5:
  82 0026 BA0A0000 		movl	$10, %edx	#,
  82      00
  83 002b BE000000 		movl	$0, %esi	#,
  83      00
  84              	.LVL6:
  85 0030 E8000000 		call	strtol	#
  85      00
  86              	.LVL7:
  87 0035 4889C6   		movq	%rax, %rsi	#, D.2900
  88              	.LVL8:
  89              	.LBE19:
  90              	.LBE18:
  91              	.LBB20:
  92              	.LBB21:
  13:x86Math.c     **** 	}
  14:x86Math.c     **** 	int x=atoi(argv[1]);
  15:x86Math.c     **** 	int ans=mult(x,x);
  16:x86Math.c     **** 	int term=mult(4,x);
  17:x86Math.c     **** 	ans=subtract(ans,term);
  18:x86Math.c     **** 	ans=add(ans,4);
  19:x86Math.c     **** 	term=subtract(x,2);
  20:x86Math.c     **** 	int check=divide(ans,term);
  21:x86Math.c     **** 	printf("x=%d, x squared - 4x + 4 =%d divided by x-2=%d\n",x,ans,check);
  22:x86Math.c     **** 	return 0;
  23:x86Math.c     **** }
  24:x86Math.c     **** 
  25:x86Math.c     **** #ifdef SIMPLE
  26:x86Math.c     **** 	int add(int x, int y) { return x+y; }
  27:x86Math.c     **** 	int subtract(int x, int y) { return x-y; }
  28:x86Math.c     **** 	int mult(int x, int y) { return x*y; }
  29:x86Math.c     **** 	int divide(int x, int y) { return x/y; }
  30:x86Math.c     **** #else
  31:x86Math.c     **** 
  32:x86Math.c     **** 	int add(int x, int y) {
  33:x86Math.c     **** 		int op1=x;
  34:x86Math.c     **** 		int op2=y;
  35:x86Math.c     **** 		int res=op1+op2;
  36:x86Math.c     **** 		return res;
  37:x86Math.c     **** 	}
  38:x86Math.c     **** 
  39:x86Math.c     **** 	int subtract(int x, int y) {
  40:x86Math.c     **** 		int op1=x;
  41:x86Math.c     **** 		int op2=y;
  42:x86Math.c     **** 		int res=op1-op2;
  43:x86Math.c     **** 		return res;
  44:x86Math.c     **** 	}
  45:x86Math.c     **** 
  46:x86Math.c     **** 	int mult(int x, int y) {
  47:x86Math.c     **** 		int op1=x;
  48:x86Math.c     **** 		int op2=y;
  49:x86Math.c     **** 		int res=op1*op2;
  93              		.loc 1 49 0
  94 0038 89C7     		movl	%eax, %edi	# D.2900, ans
  95 003a 0FAFF8   		imull	%eax, %edi	# D.2900, ans
  96              	.LVL9:
  97              	.LBE21:
  98              	.LBE20:
  99              	.LBB22:
 100              	.LBB23:
 101 003d 8D048500 		leal	0(,%rax,4), %eax	#, term
 101      000000
 102              	.LVL10:
 103              	.LBE23:
 104              	.LBE22:
 105              	.LBB24:
 106              	.LBB25:
  42:x86Math.c     **** 		return res;
 107              		.loc 1 42 0
 108 0044 29C7     		subl	%eax, %edi	# term, ans
 109              	.LVL11:
 110              	.LBE25:
 111              	.LBE24:
 112              	.LBB26:
 113              	.LBB27:
  35:x86Math.c     **** 		return res;
 114              		.loc 1 35 0
 115 0046 83C704   		addl	$4, %edi	#, ans
 116              	.LVL12:
 117              	.LBE27:
 118              	.LBE26:
 119              	.LBB28:
 120              	.LBB29:
  42:x86Math.c     **** 		return res;
 121              		.loc 1 42 0
 122 0049 8D4EFE   		leal	-2(%rsi), %ecx	#, term
 123              	.LVL13:
 124              	.LBE29:
 125              	.LBE28:
 126              	.LBB30:
 127              	.LBB31:
  50:x86Math.c     **** 		return res;
  51:x86Math.c     **** 	}
  52:x86Math.c     **** 
  53:x86Math.c     **** 	int divide(int x, int y) {
  54:x86Math.c     **** 		int op1=x;
  55:x86Math.c     **** 		int op2=y;
  56:x86Math.c     **** 		int res=op1/op2;
 128              		.loc 1 56 0
 129 004c 89F8     		movl	%edi, %eax	# ans, check
 130 004e 99       		cltd
 131 004f F7F9     		idivl	%ecx	# term
 132              	.LVL14:
 133 0051 89C1     		movl	%eax, %ecx	# check, check
 134              	.LVL15:
 135              	.LBE31:
 136              	.LBE30:
  21:x86Math.c     **** 	return 0;
 137              		.loc 1 21 0
 138 0053 89FA     		movl	%edi, %edx	# ans,
 139 0055 BF000000 		movl	$.LC1, %edi	#,
 139      00
 140              	.LVL16:
 141 005a B8000000 		movl	$0, %eax	#,
 141      00
 142              	.LVL17:
 143 005f E8000000 		call	printf	#
 143      00
 144              	.LVL18:
  22:x86Math.c     **** }
 145              		.loc 1 22 0
 146 0064 B8000000 		movl	$0, %eax	#, D.2898
 146      00
 147              	.LVL19:
 148              	.L3:
  23:x86Math.c     **** 
 149              		.loc 1 23 0
 150 0069 4883C408 		addq	$8, %rsp	#,
 151              		.cfi_def_cfa_offset 8
 152 006d C3       		ret
 153              		.cfi_endproc
 154              	.LFE21:
 156              		.globl	add
 158              	add:
 159              	.LFB22:
  32:x86Math.c     **** 		int op1=x;
 160              		.loc 1 32 0
 161              		.cfi_startproc
 162              	.LVL20:
  35:x86Math.c     **** 		return res;
 163              		.loc 1 35 0
 164 006e 8D0437   		leal	(%rdi,%rsi), %eax	#, res
 165              	.LVL21:
  37:x86Math.c     **** 
 166              		.loc 1 37 0
 167 0071 C3       		ret
 168              		.cfi_endproc
 169              	.LFE22:
 171              		.globl	subtract
 173              	subtract:
 174              	.LFB23:
  39:x86Math.c     **** 		int op1=x;
 175              		.loc 1 39 0
 176              		.cfi_startproc
 177              	.LVL22:
  42:x86Math.c     **** 		return res;
 178              		.loc 1 42 0
 179 0072 89F8     		movl	%edi, %eax	# x, res
 180 0074 29F0     		subl	%esi, %eax	# y, res
 181              	.LVL23:
  44:x86Math.c     **** 
 182              		.loc 1 44 0
 183 0076 C3       		ret
 184              		.cfi_endproc
 185              	.LFE23:
 187              		.globl	mult
 189              	mult:
 190              	.LFB24:
  46:x86Math.c     **** 		int op1=x;
 191              		.loc 1 46 0
 192              		.cfi_startproc
 193              	.LVL24:
  49:x86Math.c     **** 		return res;
 194              		.loc 1 49 0
 195 0077 89F8     		movl	%edi, %eax	# x, res
 196 0079 0FAFC6   		imull	%esi, %eax	# y, res
 197              	.LVL25:
  51:x86Math.c     **** 
 198              		.loc 1 51 0
 199 007c C3       		ret
 200              		.cfi_endproc
 201              	.LFE24:
 203              		.globl	divide
 205              	divide:
 206              	.LFB25:
  53:x86Math.c     **** 		int op1=x;
 207              		.loc 1 53 0
 208              		.cfi_startproc
 209              	.LVL26:
 210              		.loc 1 56 0
 211 007d 89F8     		movl	%edi, %eax	# x, res
 212 007f 99       		cltd
 213 0080 F7FE     		idivl	%esi	# y
 214              	.LVL27:
  57:x86Math.c     **** 		return res;
  58:x86Math.c     **** 	}
 215              		.loc 1 58 0
 216 0082 C3       		ret
 217              		.cfi_endproc
 218              	.LFE25:
 220              	.Letext0:
 221              		.file 3 "/usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h"
 222              		.file 4 "/usr/include/x86_64-linux-gnu/bits/types.h"
 223              		.file 5 "/usr/include/libio.h"
 224              		.file 6 "/usr/include/stdio.h"
