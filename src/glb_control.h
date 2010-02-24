/*
 * Copyright (C) 2008 Codership Oy <info@codership.com>
 *
 * $Id: glb_control.h 41 2008-09-14 12:18:24Z alex $
 */

#ifndef _glb_ctrl_h_
#define _glb_ctrl_h_

#include "glb_socket.h"
#include "glb_router.h"
#include "glb_pool.h"

typedef struct glb_ctrl glb_ctrl_t;

/*!
 * Creates control thread
 * @param router
 * @param port
 *        default destination port
 * @param fifo_name
 *        unix socket name
 * @param inet_addr
 *        interface address for ctrl form another host, may be NULL
 */
extern glb_ctrl_t*
glb_ctrl_create (glb_router_t*         router,
                 glb_pool_t*           pool,
                 uint16_t              port,
                 const char*           fifo_name,
                 const glb_sockaddr_t* inet_addr);

extern void
glb_ctrl_destroy (glb_ctrl_t* ctrl);

#endif // _glb_ctrl_h_
