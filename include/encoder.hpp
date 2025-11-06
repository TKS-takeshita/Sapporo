#progma once
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <cstdint>

class AS5601{
public:
    static constexpr uint8_t I2C_ADDR = 0x36;

    enum : uint8_t{
        REG_ZMCO = 0x00,//ゼロ位置を書き込んだ回数
        REG_ZPOS_H = 0x01,//ゼロ位置設定レジスタ高位バイト
        REG_ZPOS_L = 0x02,//ゼロ位置設定レジスタ低位バイト
        REG_STATUS = 0x0B,//磁石検出
        REG_RAW_ANG_H = 0x0C,//生角度(上位4bit)
        REG_RAW_ANG_L = 0x0D,//生角度(下位8bit)
        REG_ANG_H = 0x0E,//内部補正後角度(上位4bit)
        REG_ANG_L = 0x0F,//内部補正後角度(下位8bit)
    }

}