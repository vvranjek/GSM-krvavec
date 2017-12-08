
**Build**

To compile run 'make'

To upload run 'make upload' or 

Troubleshooting: 
http://digistump.com/wiki/digispark/tutorials/linuxtroubleshooting
https://digistump.com/wiki/digispark/tutorials/connecting

**Project Setup**

To setup the project use these basic steps. It shouldn't be necessary because all these files should already be in the repo.

git clone https://github.com/micronucleus/micronucleus micronucleus.git
cd micronucleus.git/commandline
make
sudo make install
sudo chmod 0755 /usr/local/bin/micronucleus 

```
wget https://github.com/pymobile/Arduino-mk-Digispark/archive/master.zip
unzip master.zip
wget https://github.com/digistump/DigistumpArduino/releases/download/1.6.5a/digistump-avr.zip 
# or
# wget https://github.com/digistump/DigistumpArduino/releases/download/1.6.5a/digistump-sam.zip

unzip digistump-avr.zip 
mv 1.6.5 digispark
```


**Fuses**

Recently correct and working fuses are: E:FF, H:DF, L:F1


Read fuses:
```
sudo avrdude -c usbtiny -p attiny84 -U lfuse:r:low_fuse_val.hex:h -U hfuse:r:high_fuse_val.hex:h
```

Write fuses:
```
sudo avrdude -c usbtiny -p attiny85 -U lfuse:w:0xf1:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m   
```




