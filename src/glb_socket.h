/*
 * Copyright (C) 2008 Codership Oy <info@codership.com>
 *
 * $Id: glb_socket.h 31 2008-06-30 17:17:14Z alex $
 */

#ifndef _glb_socket_h_
#define _glb_socket_h_

#include <stdbool.h>
#include <string.h> // for memcmp() and stuff
#include <netinet/in.h>

typedef struct sockaddr_in glb_sockaddr_t;

static inline bool
glb_socket_addr_is_equal (const glb_sockaddr_t* left,
                          const glb_sockaddr_t* right)
{
    return (!memcmp(left, right, sizeof (glb_sockaddr_t)));
}

// behaves like inet_ntoa() - returns static buffer
extern const char*
glb_socket_addr_to_string (const glb_sockaddr_t* addr);
 
// Initialize glb_sockaddr_t struct
extern long
glb_socket_addr_init (glb_sockaddr_t* addr,
                      const char*     hostname,
                      uint16_t        port);

extern void
glb_socket_addr_set_port (glb_sockaddr_t* addr, uint16_t port);

extern short
glb_socket_addr_get_port (glb_sockaddr_t* addr);

// Returns socket (file descriptor) bound to a given address.
extern int
glb_socket_create (const glb_sockaddr_t* addr);

#endif // _glb_socket_h_
