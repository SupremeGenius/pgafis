/**
 * pgAFIS - Automated Fingerprint Identification System support for PostgreSQL
 * Project Home: https://github.com/hjort/pgafis
 *
 * Authors:
 * Rodrigo Hjort <rodrigo.hjort@gmail.com>
 */

#ifndef PGAFIS_H
#define PGAFIS_H

#include <stdio.h>
#include <unistd.h>

#define get_progname pg_get_progname
#include <postgres.h>
#undef get_progname
#define bz_match nbis_bz_match
#include <bozorth.h>
#undef bz_match

#include "fmgr.h"
#include "utils/builtins.h"

#include <wsq.h>
#include <lfs.h>
#include <imgtype.h>
#include <imgboost.h>

#include "xyt.h"

extern Datum pg_wsq_encode(PG_FUNCTION_ARGS);
extern Datum pg_min_detect(PG_FUNCTION_ARGS);
extern Datum pg_bz_match(PG_FUNCTION_ARGS);

struct xyt_struct * load_xyt(char*);
int extract_minutiae_xytq(unsigned char**, int*, int, unsigned char*);
int decode_grayscale_image(int *oimg_type,
	unsigned char **odata, int *olen,
	int *ow, int *oh, int *od, int *oppi);
//, int *ointrlvflag, int *hor_sampfctr, int *vrt_sampfctr, int *on_cmpnts);
int write_minutiae(unsigned char **odata, int *osize, const MINUTIAE *minutiae);

#define ushort unsigned short

int debug = 1;

#endif   /* PGAFIS_H */