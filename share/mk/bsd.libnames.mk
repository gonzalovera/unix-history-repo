#	$Id: bsd.libnames.mk,v 1.18 1998/09/17 09:34:57 phk Exp $
#
# The include file <bsd.libnames.mk> define library names. 
# Other include files (e.g. bsd.prog.mk, bsd.lib.mk) include this 
# file where necessary.


LIBCRT0?=	${DESTDIR}${LIBDIR}/crt0.o
LIBKZHEAD?=	${DESTDIR}${LIBDIR}/kzhead.o
LIBKZTAIL?=	${DESTDIR}${LIBDIR}/kztail.o

LIBALIAS?=	${DESTDIR}${LIBDIR}/libalias.a
LIBATM?=	${DESTDIR}${LIBDIR}/libatm.a
LIBC?=		${DESTDIR}${LIBDIR}/libc.a
LIBC_PIC=	${DESTDIR}${LIBDIR}/libc_pic.a
LIBCALENDAR?=	${DESTDIR}${LIBDIR}/libcalendar.a
LIBCAM?=	${DESTDIR}${LIBDIR}/libcam.a
LIBCIPHER?=	${DESTDIR}${LIBDIR}/libcipher.a	# XXX in secure dist, not base
LIBCOM_ERR=	${DESTDIR}${LIBDIR}/libcom_err.a
LIBCOMPAT?=	${DESTDIR}${LIBDIR}/libcompat.a
LIBCRYPT?=	${DESTDIR}${LIBDIR}/libcrypt.a
LIBCURSES?=	${DESTDIR}${LIBDIR}/libcurses.a
LIBDES?=	${DESTDIR}${LIBDIR}/libdes.a	# XXX in secure dist, not base
LIBDEVSTAT?=	${DESTDIR}${LIBDIR}/libdevstat.a
LIBDIALOG?=	${DESTDIR}${LIBDIR}/libdialog.a
LIBDISK?=	${DESTDIR}${LIBDIR}/libdisk.a
LIBEDIT?=	${DESTDIR}${LIBDIR}/libedit.a
LIBF2C?=	${DESTDIR}${LIBDIR}/libf2c.a
LIBFL?=		"don't use LIBFL, use LIBL"
LIBFORMS?=	${DESTDIR}${LIBDIR}/libforms.a
LIBFTPIO?=	${DESTDIR}${LIBDIR}/libftpio.a
LIBGPLUSPLUS?=	${DESTDIR}${LIBDIR}/libg++.a
LIBGCC?=	${DESTDIR}${LIBDIR}/libgcc.a
LIBGCC_PIC?=	${DESTDIR}${LIBDIR}/libgcc_pic.a
LIBGMP?=	${DESTDIR}${LIBDIR}/libgmp.a
LIBGNUREGEX?=	${DESTDIR}${LIBDIR}/libgnuregex.a
LIBIPX?=	${DESTDIR}${LIBDIR}/libipx.a
LIBKDB?=	${DESTDIR}${LIBDIR}/libkdb.a	# XXX in secure dist, not base
LIBKRB?=	${DESTDIR}${LIBDIR}/libkrb.a	# XXX in secure dist, not base
LIBKEYCAP?=	${DESTDIR}${LIBDIR}/libkeycap.a
LIBKVM?=	${DESTDIR}${LIBDIR}/libkvm.a
LIBL?=		${DESTDIR}${LIBDIR}/libl.a
LIBLN?=		"don't use, LIBLN, use LIBL"
LIBM?=		${DESTDIR}${LIBDIR}/libm.a
LIBMD?=		${DESTDIR}${LIBDIR}/libmd.a
LIBMP?=		${DESTDIR}${LIBDIR}/libmp.a
LIBMYTINFO?=	${DESTDIR}${LIBDIR}/libmytinfo.a
LIBNCURSES?=	${DESTDIR}${LIBDIR}/libncurses.a
LIBOBJC?=	${DESTDIR}${LIBDIR}/libobjc.a
LIBOPIE?=	${DESTDIR}${LIBDIR}/libopie.a
LIBPAM?=	${DESTDIR}${LIBDIR}/libpam.a	# XXX doesn't exist
LIBPC?=		${DESTDIR}${LIBDIR}/libpc.a	# XXX doesn't exist
LIBPCAP?=	${DESTDIR}${LIBDIR}/libpcap.a
LIBPERL?=	${DESTDIR}${LIBDIR}/libperl.a
LIBPLOT?=	${DESTDIR}${LIBDIR}/libplot.a	# XXX doesn't exist
LIBRADIUS?=	${DESTDIR}${LIBDIR}/libradius.a
LIBREADLINE?=	${DESTDIR}${LIBDIR}/libreadline.a
LIBRESOLV?=	${DESTDIR}${LIBDIR}/libresolv.a	# XXX doesn't exist
LIBRPCSVC?=	${DESTDIR}${LIBDIR}/librpcsvc.a
LIBSCRYPT?=	"don't use LIBSCRYPT, use LIBCRYPT"
LIBSCSI?=	${DESTDIR}${LIBDIR}/libscsi.a
LIBSKEY?=	${DESTDIR}${LIBDIR}/libskey.a
LIBSS?=		${DESTDIR}${LIBDIR}/libss.a
LIBSTDCPLUSPLUS?= ${DESTDIR}${LIBDIR}/libstdc++.a
LIBTACPLUS?=	${DESTDIR}${LIBDIR}/libtacplus.a
LIBTCL?=	${DESTDIR}${LIBDIR}/libtcl.a
LIBTELNET?=	${DESTDIR}${LIBDIR}/libtelnet.a
LIBTERMCAP?=	${DESTDIR}${LIBDIR}/libtermcap.a
LIBTERMLIB?=	"don't use LIBTERMLIB, use LIBTERMCAP"
LIBUTIL?=	${DESTDIR}${LIBDIR}/libutil.a
LIBXPG4?=	${DESTDIR}${LIBDIR}/libxpg4.a
LIBY?=		${DESTDIR}${LIBDIR}/liby.a
LIBZ?=		${DESTDIR}${LIBDIR}/libz.a
