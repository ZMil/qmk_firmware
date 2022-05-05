EXTRAKEY_ENABLE = yes
RGBLIGHT_ENABLE = yes
ENCODER_ENABLE = no
EXTRAFLAGS += -flto
# VIA_ENABLE = yes
VIAL_ENABLE = yes
RAW_ENABLE = yes
OLED_ENABLE = yes
PROTOCOL_LUFA = yes
SSD1306OLED = yes
# SPLIT_KEYBOARD = yes
# SPLIT_TRANSPORT = custom

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \