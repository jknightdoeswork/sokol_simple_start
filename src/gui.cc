
#include "sokol_gfx.h"
#include "sokol_app.h"
#include "sokol_log.h"
#include "imgui.h"
#define SOKOL_IMGUI_IMPL
#include "sokol_imgui.h"
#define SOKOL_GFX_IMGUI_IMPL
#include "sokol_gfx_imgui.h"

extern "C" {

static sgimgui_t sgimgui;

void gui_setup(int sample_count) {
	// setup debug inspection header(s)
	const sgimgui_desc_t desc = { };
	sgimgui_init(&sgimgui, &desc);

	// setup the sokol-imgui utility header
	simgui_desc_t simgui_desc = { };
	simgui_desc.sample_count = sample_count;
	simgui_desc.logger.func = slog_func;
	simgui_setup(&simgui_desc);
}

void gui_shutdown(void) {
	sgimgui_discard(&sgimgui);
	simgui_shutdown();
}

void gui_draw(void) {
	simgui_new_frame({ sapp_width(), sapp_height(), sapp_frame_duration(), sapp_dpi_scale() });
	ImGui::Text("FPS: %f", 1.0 / sapp_frame_duration());
	//if (ImGui::BeginMainMenuBar()) {
	//    sgimgui_draw_menu(&sgimgui, "sokol-gfx");
	//    ImGui::EndMainMenuBar();
	//}
	sgimgui_draw(&sgimgui);
	simgui_render();
}

void gui_event(const sapp_event* e) {
	simgui_handle_event(e);
}

bool gui_event_with_retval(const sapp_event* e) {
	return simgui_handle_event(e);
}
}
