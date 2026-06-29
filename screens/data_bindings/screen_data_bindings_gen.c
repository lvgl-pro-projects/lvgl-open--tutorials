/**
 * @file screen_data_bindings_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_data_bindings_gen.h"
#include "../../tutorials.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * screen_data_bindings_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_list;
    static lv_style_t style_chevron;
    static lv_style_t style_list_selected;

    static bool style_inited = false;

    if (!style_inited) {
        #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
        if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
            lv_style_init(&style_main);
            lv_style_set_text_color(&style_main, lv_color_hex(0x000000));

            lv_style_init(&style_list);
            lv_style_set_bg_color(&style_list, lv_color_hex(0xFFFFFF));
            lv_style_set_bg_opa(&style_list, (255 * 100 / 100));
            lv_style_set_text_color(&style_list, lv_color_hex(0x000000));
            lv_style_set_border_color(&style_list, lv_color_hex3(0xf00));
            lv_style_set_border_width(&style_list, 1);
            lv_style_set_radius(&style_list, 4);
            lv_style_set_pad_all(&style_list, 4);

            lv_style_init(&style_chevron);
            lv_style_set_bg_image_src(&style_chevron, flower_data);

            lv_style_init(&style_list_selected);
            lv_style_set_bg_color(&style_list_selected, lv_color_hex3(0xf00));
            lv_style_set_text_color(&style_list_selected, lv_color_hex3(0x000));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_dropdown_0 = lv_dropdown_create(NULL);
        lv_obj_set_name_static(lv_dropdown_0, "screen_data_bindings_#");

        lv_obj_remove_style_all(lv_dropdown_0);
        lv_obj_add_style(lv_dropdown_0, &style_main, 0);
        lv_obj_add_style(lv_dropdown_0, &style_chevron, LV_PART_INDICATOR);
        lv_obj_t * lv_dropdown_list_0 = lv_dropdown_get_list(lv_dropdown_0);
        lv_obj_add_style(lv_dropdown_list_0, &style_list, 0);
        lv_obj_add_style(lv_dropdown_list_0, &style_list_selected, LV_PART_SELECTED | LV_STATE_CHECKED);

        the_root = lv_dropdown_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

