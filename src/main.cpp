#include "bn_core.h"

#include "bn_keypad.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_menu_load.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_items_spr_bullet.h"

int main()
{
    bn::core::init();

    // sprite
    bn::sprite_ptr bullet = bn::sprite_items::spr_bullet.create_sprite(0);

    // background
    bn::regular_bg_ptr loading_screen = bn::regular_bg_items::menu_load.create_bg(0);
    loading_screen.set_top_left_position(0, 0);
    loading_screen.set_visible(false);

    int index_count = 0;

    while(true)
    {
        if (bn::keypad::left_pressed())
        {
            index_count = index_count == 0 ? 0 : index_count - 1;
            if (bullet.visible())
            {
                bullet.set_item(bn::sprite_items::spr_bullet, index_count);
            }
            else
            {
                loading_screen.set_item(bn::regular_bg_items::menu_load, index_count);
            }
        }
        else if (bn::keypad::right_pressed())
        {
            index_count = index_count == 2 ? 2 : index_count + 1;
            if (bullet.visible())
            {
                bullet.set_item(bn::sprite_items::spr_bullet, index_count);
            }
            else
            {
                loading_screen.set_item(bn::regular_bg_items::menu_load, index_count);
            }
        }
        else if (bn::keypad::a_pressed())
        {
            if (bullet.visible())
            {
                bullet.set_visible(false);
                loading_screen.set_visible(true);
            }
            else
            {
                bullet.set_visible(true);
                loading_screen.set_visible(false);
            }
        }

        bn::core::update();
    }
}
