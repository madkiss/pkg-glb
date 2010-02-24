/*
 * Copyright (C) 2008 Codership Oy <info@codership.com>
 *
 * $Id: glb_signal.h 36 2008-07-15 16:23:15Z alex $
 */

#ifndef _glb_signal_h_
#define _glb_signal_h_

#include <signal.h>

extern volatile sig_atomic_t
glb_terminate;

// The signal to be sent to parent to confirm that child has started fine.
#define GLB_SIGNAL_OK SIGUSR1

extern void
glb_signal_set_handler();

#endif // _glb_signal_h_
