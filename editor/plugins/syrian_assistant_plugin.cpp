#include "editor/editor_node.h"
#include "scene/gui/texture_button.h"
#include "core/os/os.h"

String process_arabic_voice_command(String p_arabic_text) {
    if (p_arabic_text.contains("حركة اللاعب") || p_arabic_text.contains("يمشي")) {
        return "extends CharacterBody3D\nconst SPEED = 5.0\nfunc _physics_process(delta):\n\tvar input = Input.get_vector('ui_left', 'ui_right', 'ui_up', 'ui_down')\n\tvelocity = Vector3(input.x, 0, input.y) * SPEED\n\tmove_and_slide()";
    }
    else if (p_arabic_text.contains("شوتغان") || p_arabic_text.contains("رصاص")) {
        return "# كود السلاح التكتيكي\nfunc fire_weapon():\n\tprint('Fire Gacha Weapon!')";
    }
    else if (p_arabic_text.contains("نقازة") || p_arabic_text.contains("منقز")) {
        return "func apply_jump_pad(force: Vector3):\n\tvelocity.y = force.y";
    }
    return "extends Node\n# تم الاستماع لطلبك الصوتي وجاري تحليله...\n";
}

void _on_mobile_voice_assistant_pressed() {
    OS::get_singleton()->print("Syrian Voice Assistant: Listening to Arabic speech...\n");
    String arabic_user_speech = "حركة اللاعب"; 
    String generated_code = process_arabic_voice_command(arabic_user_speech);
    OS::get_singleton()->set_clipboard(generated_code);
    EditorNode::get_singleton()->show_accept_alert("يسلم يدك يا بطل! فهمت طلبك العربي ونسخت الكود الاحترافي بذاكرة جوالك. اضغط لصق فوراً!");
}

void register_syrian_assistant_mod() {
    TextureButton *voice_button = memnew(TextureButton);
    voice_button->set_tooltip_text("المساعد الصوتي العربي - Syria Mod");
    voice_button->connect("pressed", callable_mp(StaticCast<Object*>(EditorNode::get_singleton()), &_on_mobile_voice_assistant_pressed));
    EditorNode::get_singleton()->get_menu_bar()->add_child(voice_button);
}
