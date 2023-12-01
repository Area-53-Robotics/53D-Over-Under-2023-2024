#include "main.h"

lv_obj_t * notesScr = lv_obj_create(NULL);

void OpenNotesMenu() {
    lv_scr_load_anim(notesScr, LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
    
    CreateMenuRectangle();
    
    lv_obj_t * label = lv_obj_get_child(menuRectangle, 0);

    lv_label_set_text(label,
                    "Last Updated: 11/19/23\n"
                    "-----------------------------------------------------\n"
                    "- Don't sell Makhi"
    );
}