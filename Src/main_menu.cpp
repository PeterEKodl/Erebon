//#include <cstdint>
//#include <cstring>

//#include "main_menu.hpp"
//#include "drawing_handler.hpp"

//#define TITLE_LENGTH 52
//#define CHOICES_COUNT 3


//constexpr static const char * const menu_choices[CHOICES_COUNT] = {

//    "Play",
//    "[Options]",
//    "Quit"

//};

////source: http://www.patorjk.com/software/taag/#p=display&h=1&v=1&f=THIS&t=Erebon
//constexpr static const wchar_t * const title_text[] = {
//    L"",
//    L" ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▀█▄▄   ▄▀▀▀▀▄   ▄▀▀▄ ▀▄ ",
//    L"▐  ▄▀   ▐ █   █   █ ▐  ▄▀   ▐ ▐ ▄▀   █ █      █ █  █ █ █ ",
//    L"  █▄▄▄▄▄  ▐  █▀▀█▀    █▄▄▄▄▄    █▄▄▄▀  █      █ ▐  █  ▀█ ",
//    L"  █    ▌   ▄▀    █    █    ▌    █   █  ▀▄    ▄▀   █   █  ",
//    L" ▄▀▄▄▄▄   █     █    ▄▀▄▄▄▄    ▄▀▄▄▄▀    ▀▀▀▀   ▄▀   █   ",
//    L" █    ▐   ▐     ▐    █    ▐   █    ▐            █    ▐   ",
//    L" ▐                   ▐        ▐                 ▐        ",
//    L"",
//    L"",
//    L" Programmed by Peter E. Kodl"

//};

//constexpr static int title_rows = sizeof(title_text)/sizeof(title_text[0]);

//Option main_menu(DrawingHandler & drawing_handler){

//    #define MENU_WIDTH 20
//    #define MENU_HEIGHT 10

//    MENU * menu;
//    ITEM ** items {new ITEM * [CHOICES_COUNT+1]};

//    // The upper left corner coordinates of the title.
//    int x = (drawing_handler.term_width-TITLE_LENGTH)/2;
//    int y = (drawing_handler.term_height-(title_rows + MENU_HEIGHT + 2))/2;

//    // Create the items.
//    for (size_t index = 0; index < CHOICES_COUNT; ++index) items[index] = new_item(menu_choices[index], "");

//    // The last element of the items array has to be NULL.
//    items[CHOICES_COUNT] = NULL;

//    menu = new_menu(items);
 
//    WindowWrapper main_menu {MENU_WIDTH, MENU_HEIGHT, (drawing_handler.term_width-MENU_WIDTH)/2, y+title_rows+2};
//    WindowWrapper menu_subwin {main_menu, MENU_WIDTH-3, MENU_HEIGHT-3, 3, 2};
    
//    set_menu_win(menu, main_menu);
//    set_menu_sub(menu, menu_subwin);

//    // Some aesthetic options like the marker that indicates the selected option.
//    set_menu_mark(menu, "* ");
//    set_menu_fore(menu, COLOR_PAIR(drawing_handler.get_color_pair(25, 0)));
//    set_menu_back(menu, COLOR_PAIR(drawing_handler.get_color_pair(25, 0)));
    
    
//    // Draw the title.
//    {

//        attron(COLOR_PAIR(drawing_handler.get_color_pair(2, 0)));

//        for (uint16_t row_index = 0; row_index < title_rows; ++row_index){

//            mvaddwstr(y+row_index, x, title_text[row_index]);
        
//        }

//        attroff(COLOR_PAIR(drawing_handler.get_color_pair(2, 0)));

//        refresh();

//    }

//    post_menu(menu);
//    wrefresh(main_menu);
    

//    Option selected_option = Option::none;

//    // Keep looping until [selected_option] is set to have a return value, which is later used to either quit the game or open another window.
//    while (selected_option == Option::none){

//        wrefresh(main_menu);

//        switch(getch())
//        {
            
//        case KEY_UP:
//            menu_driver(menu, REQ_UP_ITEM);
//            break;

//        case KEY_DOWN:
//            menu_driver(menu, REQ_DOWN_ITEM);
//            break;

//        case KEY_F(1):
//            selected_option = Option::quit;
//            break;
            
//        case KEY_KEYBOARD_ENTER:
//            selected_option = static_cast<Option>(item_index(current_item(menu)) + 1);
//            break;

//        default:
//            break;

//        }

//    }

//    unpost_menu(menu);

//    // Deallocate all storage.
//    for (uint8_t index = 0; index < CHOICES_COUNT; ++index) free_item(items[index]);
//    delete[] items;
//    free_menu(menu);

//    return selected_option;

    

//}




 
