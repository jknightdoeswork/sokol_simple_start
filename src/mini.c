#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_log.h"
#include "sokol_glue.h"
#include "gui.h"

static void init(void) {
	sg_setup(&(sg_desc){
		.environment = sglue_environment(),
		.logger.func = slog_func,
	});
	gui_setup(sapp_sample_count());
}

void frame(void) {
    sg_begin_pass(&(sg_pass){ .swapchain = sglue_swapchain() });
    gui_draw();
    sg_end_pass();
    sg_commit();
}

void cleanup(void) {
	gui_shutdown();
	sg_shutdown();
}

sapp_desc sokol_main(int argc, char* argv[]) {
	(void)argc; (void)argv;
	return (sapp_desc){
		.init_cb = init,
		.frame_cb = frame,
		.cleanup_cb = cleanup,
		.event_cb = gui_event,
		.width = 640,
		.height = 480,
		.window_title = "mini",
		.icon.sokol_default = true,
		.logger.func = slog_func,
	};
}
