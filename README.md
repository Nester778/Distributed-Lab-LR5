# Distributed-Lab-LR5
Важливо, у роботі використовується бібліотека Crypto++, тому запускати роботу у Release x64.

Робота складається з 3 файлів - Test_SHA1.cpp, Sha1.cpp, Tests.cpp. У файлі Test_SHA1.cpp знаходиться функція main(). Файл Sha1.cpp містить реалізацію, алгоритму sha1, а файл Tests.cpp, містить тести та порівняння роботи мого алгоритму sha1 з бібліотечною версією.

Алгоритм реалізації

Спочатку вхідний текст переводиться у бінарну форму, використовуючи функцію textToBin(). Потім за допомогою функції puddingBin() бінарна послідовність доповнюється так, щоб вона була кратною 512. Після функції puddingBin() посилання передається у функцію mySha1(). У функції mySha1() бінарне повідомлення переводиться у шістнадцятирічне, для зручності. Потім повідомлення розбивається на блоки по 64 байти, блок розділяється на 16 слів, які розширюються до 80 слів. Далі на 80 словами виконуються побітові операції згідно за документацією sha1. На виході отримаємо геш довжиною 160 біт.

Приклад виконання: 
Спочатку потрібно ввести повідомлення, для гешування. На виході отримаємо геш, та час виконання алгоритму з сторонньої бібліотеки, далі геш, та час виконання мого алгоритму. Потім йдуть 3 тесті згідно з методичними вказівками.

-----------------------------------------
Enter your message
Hello

f7ff9e8b7bb2e09b70935a5d785e0cc5d9d0abf0
Execution time of the library solution: 8.1 milliseconds

f7ff9e8b7bb2e09b70935a5d785e0cc5d9d0abf0
Execution time of my algorithm: 8.101 milliseconds
 - Test messages:
-----------------------------------------
 - Up to one block
Test message - abcde

03de6c570bfe24bfc328ccd7ca46b76eadaf4334
Execution time of the library solution: 8.103 milliseconds

03de6c570bfe24bfc328ccd7ca46b76eadaf4334
Execution time of my algorithm: 8.103 milliseconds
-----------------------------------------
-----------------------------------------
 - More than one block
Test message - ajhsgcbdjkeuhsgdtwndkslanxmchdpeudhsgxnsjdhfyqpskdhcbzmskao

565ae017efc88310b85396ee67f0331e583fceb5
Execution time of the library solution: 8.104 milliseconds

565ae017efc88310b85396ee67f0331e583fceb5
Execution time of my algorithm: 8.105 milliseconds
-----------------------------------------
-----------------------------------------
 - Several blocks
Test message - ajhsgcbdjkeuhsgdtwndkslanxmchdpeudhsgxnsjdhfyqpskdhcbzmskaoajhsgcbdjkeuhsgdtwndkslanxmchdpeudhsgxnsjdhfyqpskdhcbzmskao

d8207cd504df004666b7c4ef1a873f6fe7c57738
Execution time of the library solution: 8.108 milliseconds

d8207cd504df004666b7c4ef1a873f6fe7c57738
Execution time of my algorithm: 8.109 milliseconds
-----------------------------------------