1. Скачайте необходимые файлы:
	https://yadi.sk/d/3GQo88CO3Pc2u2

2. Копируйте скаченные файлы в директорию packages:
	cd workspace; mkdir packages; cd packages;

3. Разархивируйте xc32-компилятор:
	tar -xvzf xc32-1.21.tgz

4. Установите avrdude пакет:
	sudo dpkg -i avrdude_5_11_1-1_amd64.deb

5. Перед компиляцией программы добавьте путь к
исполняемому файлу в переменную окружения PATH:
	PATH=$PATH:~/workspace/packages/microchip/xc32/v1.21/bin

P.S У вас может несобираться программа при вызове Makefile
т.к вы работаете на 64 битной версии, следует установить:
sudo apt-get install libc6:i386 libncurses5:i386 libstdc++6:i386