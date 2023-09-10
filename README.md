# TicTacToe
TicTacToe Console Game On C++

Функциональные требования:
1) печать игрового поля
2) ход компьютера с использованием рандомайзера для выбора строки и столбца
3) ход игрока с ввода пользователем строки и стобца
4) определение корректности хода (в соответствующей строке и столбце нет крестика или нолика)
5) определение победителя

Не функциональные требования:
1) командная строка

Иницилизация:
1)создать игрока
2)создать противника "Компьютер"
3)сгенерировать игровое поле
4)начать игру:
  - просим игрока сделать ход
  - проверяем победителя
  - делаем ход компьютером
  - проверяем победителя
  - продолжаем игру до определения победителя

Cущности:
1) доска
2) игрок (абстрактная)
3) игрок (человек)
4) игрок (компьютер)
5) игра

Сущность доска:
1) состояния:
   + местонахождение крестиков и ноликов
2) действия:
   + печать поля
   + умение выдавать есть в ячейке крестик или нолик или выдавать пустоту
   + установка крестика или нолика в заданную позицию

Сущность игрок (абстрактная):
1) состояния:
   + имя
   + каким символом игрет (крестик или нолик)
2) действия:
   + задать имя
   + задать символ для игры
   + вернуть имя
   + вернуть символ для игры
   + куда ходит игрок

Сущность игрок (человек):
1) состояния:
   -
2) действия:
   + куда ходит игрок (запрос у пользователя в какой строке и столбце необходимо поставить символ которым он играет)

Сущность игрок (компьютер):
1) состояния:
   -
2) действия:
   + куда ходит игрок (генерация с помощью рандома строки и столбца для установки символа которым он играет)

Сущность игра:
1) состояния:
   -
2) действия:
   - создать игрока "Человек", узнать его имя и каким символом он будет играть ("Х" или "0")
   - создать игрока "Компьютер" с именем "Компьютер" и символом которым он будет играть противополжным игрока "Человек"
   - узнать у человека куда он хочет совершить ход
   - совершить его
   - проверка на победу
   - провести игру