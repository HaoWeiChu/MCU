## 專案介紹
透過UNO板作為燒錄器，將89s51完成之LED霹靂燈電路進行燒錄實作。首先將電路於麵包板上完成，接著使用Arduino IDE 將UNO 變成燒錄器，並使用Keil C 軟體進行程式碼編寫並將程式碼轉換成16進位檔案。最後透過Windows CMD 指令完成燒錄動作。

## 電路圖
![image](https://github.com/HaoWeiChu/MCU/blob/master/UNO_89s51_programming/circuit/circuit.jpg)

## 檔案
* [Arduino ISP](https://github.com/HaoWeiChu/MCU/blob/master/UNO_89s51_programming/code/arduino/arduino_isp.c)
* [Keil_C](https://github.com/HaoWeiChu/MCU/blob/master/UNO_89s51_programming/code/keil%20C/LED.c)
* [Keil_hex file](https://github.com/HaoWeiChu/MCU/blob/master/UNO_89s51_programming/code/keil%20C/LED.hex)
* [CMD](https://github.com/HaoWeiChu/MCU/blob/master/UNO_89s51_programming/code/windows_CMD/windows_cmd_code)

## 成果圖
* [UNO_89s51_programming](https://github.com/HaoWeiChu/MCU/blob/master/UNO_89s51_programming/images/Flashing.jpg)
