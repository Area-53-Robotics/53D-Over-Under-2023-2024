#include "main.h"

lv_obj_t * keybindScr = lv_obj_create(NULL);

void OpenKeybindMenu() {
    lv_scr_load_anim(keybindScr, LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
    
    CreateMenuRectangle();
    
    lv_obj_t * label = lv_obj_get_child(menuRectangle, 0);

    lv_label_set_text(label,
                    "Last Updated: 11/19/23\n"
                    "-----------------------------------------------------\n"
                    "A: Toggle Direction\n"
                    "B:\n"
                    "X:\n"
                    "Y:\n"
                    "Up:\n"
                    "Down:\n"
                    "Left: Open/Close Wings\n"
                    "Right:\n"
                    "L1: Outtake\n"
                    "L2:\n"
                    "R1: Intake\n"
                    "R2: Start/Stop Cata Movement"
    );
}