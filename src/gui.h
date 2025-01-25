#pragma once
#include "sokol_app.h"

#if defined(__cplusplus)
extern "C" {
#endif

extern void gui_setup(int sample_count);
extern void gui_shutdown(void);
extern void gui_draw(void);
extern void gui_event(const sapp_event* e);
extern bool gui_event_with_retval(const sapp_event* e);

#if defined(__cplusplus)
}
#endif
