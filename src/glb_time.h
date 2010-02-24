/*
 * Copyright (C) 2008 Codership Oy <info@codership.com>
 *
 * $Id: glb_time.h 57 2009-04-15 17:36:21Z alex $
 */

#ifndef _glb_time_h_
#define _glb_time_h_

#include <sys/time.h>
#include <time.h>

typedef double glb_time_t;

static inline glb_time_t
glb_time_now() {
    struct timeval tv;
    gettimeofday (&tv, NULL);
    return (1.0e-06 * tv.tv_usec + tv.tv_sec);
}

#endif // _glb_time_h_
