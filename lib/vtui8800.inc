VTUI_LIB        = $8800;

VTUI_initialize	= VTUI_LIB+0;
VTUI_screen_set	= VTUI_LIB+2;
VTUI_set_bank	= VTUI_LIB+5;
VTUI_set_stride	= VTUI_LIB+8;
VTUI_set_decr	= VTUI_LIB+11;
VTUI_clr_scr	= VTUI_LIB+14;
VTUI_gotoxy	    = VTUI_LIB+17;
VTUI_plot_char	= VTUI_LIB+20;
VTUI_scan_char	= VTUI_LIB+23;
VTUI_hline	    = VTUI_LIB+26;
VTUI_vline	    = VTUI_LIB+29;
VTUI_print_str	= VTUI_LIB+32;
VTUI_fill_box	= VTUI_LIB+35;
VTUI_pet2scr	= VTUI_LIB+38;
VTUI_scr2pet	= VTUI_LIB+41;
VTUI_border	    = VTUI_LIB+44;
VTUI_save_rect	= VTUI_LIB+47;
VTUI_rest_rect	= VTUI_LIB+50;
VTUI_input_str	= VTUI_LIB+53;
VTUI_get_bank	= VTUI_LIB+56;
vtui_get_stride	= VTUI_LIB+59;
vtui_get_decr	= VTUI_LIB+62;
