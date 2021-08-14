- I2C sample code for Raspberry Pie4 with C language
- It can show user option menue " All regsiter read ", " One register write " and " One register read ". 
- Using WiringPi library so need to install when you use it
Ex: 
cd /tmp
wget https://project-downloads.drogon.net/wiringpi-latest.deb
sudo dpkg -i wiringpi-latest.deb
- Do not forget to use build command using -lwiringPi
Ex:
gcc -o i2c I2C_sample_menu.c -lwiringPi
- Do not forget to change slave address when you use it
Ex: 
int fd = wiringPiI2CSetup(0x39);
you need to change 0x39 to slave address you use 

