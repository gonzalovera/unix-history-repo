/*
 * Copyright 2010 Nexenta Systems, Inc.  All rights reserved.
 * Copyright 2015 John Marino <draco@marino.st>
 *
 * This source code is derived from the illumos localedef command, and
 * provided under BSD-style license terms by Nexenta Systems, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * CHARMAP file handling for localedef.
 */
#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/types.h>
#include <sys/avl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stddef.h>
#include <unistd.h>
#include "localedef.h"
#include "parser.h"

static avl_tree_t	cmap_sym;
static avl_tree_t	cmap_wc;

typedef struct charmap {
	const char *name;
	wchar_t wc;
	avl_node_t avl_sym;
	avl_node_t avl_wc;
} charmap_t;


/*
 * Array of POSIX specific portable characters.
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"

static const struct {
	char	*name;
	int	ch;
} portable_chars[] = {
	{ "NUL",		'\0' },
	{ "alert",		'\a' },
	{ "backspace",		'\b' },
	{ "tab",		'\t' },
	{ "carriage-return",	'\r' },
	{ "newline",		'\n' },
	{ "vertical-tab",	'\v' },
	{ "form-feed",		'\f' },
	{ "space",		' ' },
	{ "exclamation-mark",	'!' },
	{ "quotation-mark",	'"' },
	{ "number-sign",	'#' },
	{ "dollar-sign",	'$' },
	{ "percent-sign",	'%' },
	{ "ampersand",		'&' },
	{ "apostrophe",		'\'' },
	{ "left-parenthesis",	'(' },
	{ "right-parenthesis",	'(' },
	{ "asterisk",		'*' },
	{ "plus-sign",		'+' },
	{ "comma",		 ','},
	{ "hyphen-minus",	'-' },
	{ "hyphen",		'-' },
	{ "full-stop",		'.' },
	{ "period",		'.' },
	{ "slash",		'/' },
	{ "solidus",		'/' },
	{ "zero",		'0' },
	{ "one",		'1' },
	{ "two",		'2' },
	{ "three",		'3' },
	{ "four",		'4' },
	{ "five",		'5' },
	{ "six",		'6' },
	{ "seven",		'7' },
	{ "eight",		'8' },
	{ "nine",		'9' },
	{ "colon",		':' },
	{ "semicolon",		';' },
	{ "less-than-sign",	'<' },
	{ "equals-sign",	'=' },
	{ "greater-than-sign",	'>' },
	{ "question-mark",	'?' },
	{ "commercial-at",	'@' },
	{ "left-square-bracket", '[' },
	{ "backslash",		'\\' },
	{ "reverse-solidus",	'\\' },
	{ "right-square-bracket", ']' },
	{ "circumflex",		'^' },
	{ "circumflex-accent",	'^' },
	{ "low-line",		'_' },
	{ "underscore",		'_' },
	{ "grave-accent",	'`' },
	{ "left-brace",		'{' },
	{ "left-curly-bracket",	'{' },
	{ "vertical-line",	'|' },
	{ "right-brace",	'}' },
	{ "right-curly-bracket", '}' },
	{ "tilde",		'~' },
	{ "A", 'A' },
	{ "B", 'B' },
	{ "C", 'C' },
	{ "D", 'D' },
	{ "E", 'E' },
	{ "F", 'F' },
	{ "G", 'G' },
	{ "H", 'H' },
	{ "I", 'I' },
	{ "J", 'J' },
	{ "K", 'K' },
	{ "L", 'L' },
	{ "M", 'M' },
	{ "N", 'N' },
	{ "O", 'O' },
	{ "P", 'P' },
	{ "Q", 'Q' },
	{ "R", 'R' },
	{ "S", 'S' },
	{ "T", 'T' },
	{ "U", 'U' },
	{ "V", 'V' },
	{ "W", 'W' },
	{ "X", 'X' },
	{ "Y", 'Y' },
	{ "Z", 'Z' },
	{ "a", 'a' },
	{ "b", 'b' },
	{ "c", 'c' },
	{ "d", 'd' },
	{ "e", 'e' },
	{ "f", 'f' },
	{ "g", 'g' },
	{ "h", 'h' },
	{ "i", 'i' },
	{ "j", 'j' },
	{ "k", 'k' },
	{ "l", 'l' },
	{ "m", 'm' },
	{ "n", 'n' },
	{ "o", 'o' },
	{ "p", 'p' },
	{ "q", 'q' },
	{ "r", 'r' },
	{ "s", 's' },
	{ "t", 't' },
	{ "u", 'u' },
	{ "v", 'v' },
	{ "w", 'w' },
	{ "x", 'x' },
	{ "y", 'y' },
	{ "z", 'z' },
	{ NULL, 0 }
};

#pragma GCC diagnostic pop

static int
cmap_compare_sym(const void *n1, const void *n2)
{
	const charmap_t *c1 = n1;
	const charmap_t *c2 = n2;
	int rv;

	rv = strcmp(c1->name, c2->name);
	return ((rv < 0) ? -1 : (rv > 0) ? 1 : 0);
}

static int
cmap_compare_wc(const void *n1, const void *n2)
{
	const charmap_t *c1 = n1;
	const charmap_t *c2 = n2;

	return ((c1->wc < c2->wc) ? -1 : (c1->wc > c2->wc) ? 1 : 0);
}

void
init_charmap(void)
{
	avl_create(&cmap_sym, cmap_compare_sym, sizeof (charmap_t),
	    offsetof(charmap_t, avl_sym));

	avl_create(&cmap_wc, cmap_compare_wc, sizeof (charmap_t),
	    offsetof(charmap_t, avl_wc));
}

static void
add_charmap_impl(char *sym, wchar_t wc, int nodups)
{
	charmap_t	srch;
	charmap_t	*n = NULL;
	avl_index_t	where;

	srch.wc = wc;
	srch.name = sym;

	/*
	 * also possibly insert the wide mapping, although note that there
	 * can only be one of these per wide character code.
	 */
	if ((wc != -1) && ((avl_find(&cmap_wc, &srch, &where)) == NULL)) {
		if ((n = calloc(1, sizeof (*n))) == NULL) {
			errf("out of memory");
			return;
		}
		n->wc = wc;
		avl_insert(&cmap_wc, n, where);
	}

	if (sym) {
		if (avl_find(&cmap_sym, &srch, &where) != NULL) {
			if (nodups) {
				errf("duplicate character definition");
			}
			return;
		}
		if ((n == NULL) && ((n = calloc(1, sizeof (*n))) == NULL)) {
			errf("out of memory");
			return;
		}
		n->wc = wc;
		n->name = sym;

		avl_insert(&cmap_sym, n, where);
	}
}

void
add_charmap(char *sym, int c)
{
	add_charmap_impl(sym, c, 1);
}

void
add_charmap_undefined(char *sym)
{
	charmap_t srch;
	charmap_t *cm = NULL;

	srch.name = sym;
	cm = avl_find(&cmap_sym, &srch, NULL);

	if ((undefok == 0) && ((cm == NULL) || (cm->wc == -1))) {
		warn("undefined symbol <%s>", sym);
		add_charmap_impl(sym, -1, 0);
	} else {
		free(sym);
	}
}

void
add_charmap_range(char *s, char *e, int wc)
{
	int	ls, le;
	int	si;
	int	sn, en;
	int	i;

	static const char *digits = "0123456789";

	ls = strlen(s);
	le = strlen(e);

	if (((si = strcspn(s, digits)) == 0) || (si == ls) ||
	    (strncmp(s, e, si) != 0) ||
	    ((int)strspn(s + si, digits) != (ls - si)) ||
	    ((int)strspn(e + si, digits) != (le - si)) ||
	    ((sn = atoi(s + si)) > ((en = atoi(e + si))))) {
		errf("malformed charmap range");
		return;
	}

	s[si] = 0;

	for (i = sn; i <= en; i++) {
		char *nn;
		(void) asprintf(&nn, "%s%0*u", s, ls - si, i);
		if (nn == NULL) {
			errf("out of memory");
			return;
		}

		add_charmap_impl(nn, wc, 1);
		wc++;
	}
	free(s);
	free(e);
}

void
add_charmap_char(char *name, int val)
{
	add_charmap_impl(name, val, 0);
}

/*
 * POSIX insists that certain entries be present, even when not in the
 * orginal charmap file.
 */
void
add_charmap_posix(void)
{
	int	i;

	for (i = 0; portable_chars[i].name; i++) {
		add_charmap_char(portable_chars[i].name, portable_chars[i].ch);
	}
}

int
lookup_charmap(const char *sym, wchar_t *wc)
{
	charmap_t	srch;
	charmap_t	*n;

	srch.name = sym;
	n = avl_find(&cmap_sym, &srch, NULL);
	if (n && n->wc != -1) {
		if (wc)
			*wc = n->wc;
		return (0);
	}
	return (-1);
}

int
check_charmap(wchar_t wc)
{
	charmap_t srch;

	srch.wc = wc;
	return (avl_find(&cmap_wc, &srch, NULL) ? 0 : -1);
}
