//
//  Xemu.cpp
//  xemu
//
//  Created by Francesco Magoga on 23/09/2021.
//

#include "Xemu.hpp"

#include "qemu/osdep.h"
#include "qemu/module.h"
#include "qemu/thread.h"
#include "qemu/main-loop.h"
#include "qemu/rcu.h"
#include "qemu-version.h"
#include "qemu-common.h"
#include "qapi/error.h"
#include "qapi/qapi-commands-block.h"
#include "qapi/qmp/qdict.h"
#include "ui/console.h"
#include "ui/input.h"
#include "ui/xemu-display.h"
#include "sysemu/runstate.h"
#include "sysemu/runstate-action.h"
#include "sysemu/sysemu.h"
#include "xemu-hud.h"
#include "xemu-input.h"
#include "xemu-settings.h"
#include "xemu-shaders.h"
#include "xemu-version.h"

#include "data/xemu_64x64.png.h"

#include "hw/xbox/smbus.h" // For eject, drive tray
#include "hw/xbox/nv2a/nv2a.h"

using namespace xemu;

Xemu::Xemu()
{
	QemuThread thread;

	#ifdef _WIN32
	if (AttachConsole(ATTACH_PARENT_PROCESS)) {
		// Launched with a console. If stdout and stderr are not associated with
		// an output stream, redirect to parent console.
		if (_fileno(stdout) == -2) {
			freopen("CONOUT$", "w+", stdout);
		}
		if (_fileno(stderr) == -2) {
			freopen("CONOUT$", "w+", stderr);
		}
	} else {
		// Launched without a console. Redirect stdout and stderr to a log file.
		HANDLE logfile = CreateFileA("xemu.log",
			GENERIC_WRITE, FILE_SHARE_WRITE|FILE_SHARE_READ,
			NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (logfile != INVALID_HANDLE_VALUE) {
			freopen("xemu.log", "a", stdout);
			freopen("xemu.log", "a", stderr);
		}
	}
	#endif

	gArgc = argc;
	gArgv = argv;

	sdl2_display_very_early_init(NULL);

	qemu_sem_init(&display_init_sem, 0);
	qemu_thread_create(&thread, "qemu_main", call_qemu_main,
					   NULL, QEMU_THREAD_DETACHED);

	DPRINTF("Main thread: waiting for display_init_sem\n");
	qemu_sem_wait(&display_init_sem);

	gui_grab = 0;
	if (gui_fullscreen) {
		sdl_grab_start(0);
		set_full_screen(&sdl2_console[0], gui_fullscreen);
	}

	/*
	 * FIXME: May want to create a callback mechanism for main QEMU thread
	 * to just run functions to avoid TLS bugs and locking issues.
	 */
	tcg_register_init_ctx();
	// rcu_register_thread();
	qemu_set_current_aio_context(qemu_get_aio_context());

	DPRINTF("Main thread: initializing app\n");
	// rcu_unregister_thread();
}

Xemu::~Xemu()
{
	
}

void Xemu::start()
{
	
}

void Xemu::stop()
{
	
}

void Xemu::reset()
{
	
}

void Xemu::update()
{
	sdl2_gl_refresh(&sdl2_console[0].dcl);
}
