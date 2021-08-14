#include <stdio.h>
#include <wiringPiI2C.h>
#include <stdlib.h>
#include <string.h>
 
int main () {
        // put your main code here, to run repeatedly:
        printf("Select MENU and Press Enter\n");
        printf("x= all register read\n");
        printf("r= register read\n");
        printf("w= register write\n");
        
        char s;
        scanf("%c", &s);
        if (s == 'x') {
                // I2C接続
                int fd = wiringPiI2CSetup(0x39);
                int reg = 0x00;
                // 接続の確認
                if (fd == -1) {
                printf("I2C接続に失敗しました。\n");
                }
                // I2Cでスレーブからデータ取得
                for (int i = 0; i < 256; i++) {
                        printf("Add 0x%02X", i);
                        printf(": 0x%02X\n", wiringPiI2CReadReg8(fd,reg));
                        reg++;
                        }
        }
        else if (s =='r') {
                // I2C接続
                int fd = wiringPiI2CSetup(0x39);
                // 接続の確認
                if (fd == -1) {
                printf("I2C接続に失敗しました。\n");
                }
                printf ("Input Slave address ");
                int h;
                scanf("%x", &h);
                printf("Add:0x%x", h);
                // I2Cでスレーブからデータ取得
                printf(":Data:0x%02X\n", wiringPiI2CReadReg8(fd,h));
        }
         else if (s =='w') {
                // I2C接続
                int fd = wiringPiI2CSetup(0x39);
                // 接続の確認
                if (fd == -1) {
                printf("I2C接続に失敗しました。\n");
                }
                printf ("Input Slave address and Write Value, need space between address and data, Eg 41 01: ");
                int h[1];
                scanf("%x %x", &h[0], &h[1]);
                printf("Writing Address: 0x%02X\n", h[0]);
                printf("Writing data: 0x%02X\n", h[1]);
                // I2Cでスレーブからデータ取得
                wiringPiI2CWriteReg8(fd,h[0],h[1]);
                printf("Writing Result 0x%02X\n", wiringPiI2CReadReg8(fd,h[0]));
        }
        else {
                printf("Not support, your input number：%c\n", s);
        }
        return 0;
}
