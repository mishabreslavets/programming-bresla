# Лабораторна робота No13.   Взаємодія з файлами
## Розробник:
* Бреславець Михайло Юрійович
* KН-921A

## Завдання:
- Розробити програму, що в заданому файлі створює суцільний рівнобедрений трикутник із
   заданих символів (наприклад, зірочок). Висота трикутника, символ заповнювача та ширина
   основи задається у вхідному файлу. Наприклад, при висоті 4, ширині 7 та заповнювачі *
   результат у файлі потрібен бути наступним:
```
      * 
    * * *
  * * * * *
* * * * * * *     
```
### Перелік вхідних данних:
- Висота та ширіна трикутника. Символ яким його буде програма виводити.
```
  4 7 o
 ```
### Дослідження результатів программи:
- Щоб знайти числа ми проходимо весь масив и перевіряємо чи є символ цифрою, якщо так, то ми його виводимо. Якщо ні - то, виводимо " ", бо це кінець числа
Отримуем наступне:
```
   o
  ooo
 ooooo
ooooooo
```
valgrind пише:
```
ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```

Структора проекту:
```
├── CMakeLists.txt
├── assets
│   └── input.txt
├── doc
│   └── lab10.md
├── Doxyfile
├── README.md
├── src
│   ├── lib.c
│   ├── lib.h
│   └── main.c
└── test
    └── test.c

```
## Висновки:
Вивчили та закріпили навички використання файлів.
