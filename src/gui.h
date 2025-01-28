#pragma once
#include "sokol_app.h"

#if defined(__cplusplus)
extern "C" {
#endif

void gui_setup(int sample_count);
void gui_shutdown(void);
void gui_draw(void);
void gui_event(const sapp_event* e);
bool gui_event_with_retval(const sapp_event* e);

#if defined(__cplusplus)
}
#endif
