/*
 * Copyright (C) 2008 Codership Oy <info@codership.com>
 *
 * $Id: glb_listener.h 20 2008-06-22 01:59:06Z alex $
 */

#ifndef _glb_listener_h_
#define _glb_listener_h_

#include "glb_router.h"
#include "glb_pool.h"

typedef struct glb_listener glb_listener_t;

extern glb_listener_t*
glb_listener_create (glb_sockaddr_t* addr,
                     glb_router_t*   router,
                     glb_pool_t*     pool);

extern void
glb_listener_destroy (glb_listener_t* listener);

#endif // _glb_listener_h_
