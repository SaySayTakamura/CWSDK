#ifndef CUBE_INVENTORYWIDGET_H
#define CUBE_INVENTORYWIDGET_H
#include "BaseWidget.h"
#include "ItemStack.h"
#include "../plasma/Node.h"
#include <list>
namespace cube {
class Game;
class InventoryWidget : public cube::BaseWidget {
    public:
        std::vector<std::vector<cube::ItemStack>>* itemVector; // &std::vector<std::vector<cube::Item*>>
        int64_t field_1F0;
        int64_t field_1F8;
        int64_t field_200;
        int64_t field_208;
        cube::Game* game;
        plasma::Node* field_218;
        int64_t field_220;
        plasma::Node* field_228;
        plasma::Node* up_button;
        plasma::Node* up_button_related;
        plasma::Node* down_button_related;
        plasma::Node* scroll_button_related;
        plasma::Node* left_button_related;
        plasma::Node* wideitembox;
        std::list<void*> unk_list_0x260_node_size_0x18;
        int32_t mouse_hover_item_tab;
        int32_t mouse_hover_item_id;
        int32_t preview_item_tab;
        int32_t preview_item_id;
        int32_t selected_tab_type;
        int32_t field_284;
        int64_t scroll_bar_ptr; // pointer to the scroll value of each tabs.
        int64_t field_290; // same ptr than 298
        int64_t field_298; // same ptr than 290
        bool field_2A0; // set to zero at each draw.
        bool field_2A1;
        bool field_2A2;
        bool field_2A3;
        int32_t scroll_size; // default: 1. define the number of scroll you can do. 
        int32_t grid_item_size_x;   
        int32_t grid_item_size_y;
        int32_t mouse_hover_tab_select;
        int32_t selected_tab_id;
        int64_t field_2B8;
        int64_t field_2C0;
        int64_t field_2C8;
    };
}

static_assert(sizeof(cube::InventoryWidget) == 0x2D0, "cube::InventoryWidget is not the correct size.");

#endif // CUBE_INVENTORYWIDGET_H
