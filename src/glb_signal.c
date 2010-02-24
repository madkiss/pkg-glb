/*
 * Copyright (C) 2008 Codership Oy <info@codership.com>
 *
 * $Id: glb_signal.c 36 2008-07-15 16:23:15Z alex $
 */

#include "glb_log.h"
#include "glb_signal.h"

volatile sig_atomic_t
glb_terminate = 0;

static void
signal_handler(int signum)
{
    switch(signum) {
//    case SIGALRM: should not be getting this signal either
//        break;
    case SIGCHLD:
        glb_log_fatal ("Child unexpectedly terminated.");
        exit (EXIT_FAILURE);
    case GLB_SIGNAL_OK: // used by child to report OK
        exit (EXIT_SUCCESS);
    case SIGHUP:
    case SIGTERM:
    case SIGINT:
    case SIGQUIT:
    case SIGPIPE:
        glb_log_info ("Received signal %d. Terminating.", signum);
        glb_terminate = 1;
        return;
    default: // should never get here
        glb_log_warn ("Received signal %d.", signum);
        abort();
    }
}

void
glb_signal_set_handler()
{
    signal (GLB_SIGNAL_OK, signal_handler);
    signal (SIGCHLD, signal_handler);
    signal (SIGHUP,  signal_handler);
    signal (SIGTERM, signal_handler);
    signal (SIGINT,  signal_handler);
    signal (SIGQUIT, signal_handler);
    signal (SIGPIPE, signal_handler);
}
